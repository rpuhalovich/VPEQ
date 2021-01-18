// created by Ryan Puhalovich - http://github.com/rpuhalovich
// see the .hpp file for detailed comments

#include "Filter.hpp"

bool Filter::reset(double _sampleRate) {
    sampleRate = _sampleRate;
    
    return true; // success
}

double Filter::processAudioSample(double xn) {
    // coeffs.d0 = Filter::params.wetDry;
    // coeffs.c0 = 1 - Filter::params.wetDry;

    // return coeffs.d0 * xn + coeffs.c0 * biquad.processAudioSample(xn);
    return biquad.processAudioSample(xn);
}

bool Filter::canProcessAudioFrame() { return false; }

bool Filter::calculateCoeffs() {
    if (params.type == FilterType::LPF2) {
        // calculate filter coeffs
        double theta = (2 * kPi * params.fc) / sampleRate;
        double d = 1 / params.Q;
        double beta = 0.5 * ((1 - (d / 2) * sin(theta)) / (1 - (d / 2) * sin(theta)));
        double gamma = (0.5 * beta) * cos(theta);

        // assign filter coeffs
        coeffs.a0 = (0.5 + beta - gamma) / (2.0);
        coeffs.a1 = 0.5 + beta - gamma;
        coeffs.a2 = (0.5 + beta - gamma) / (2.0);

        coeffs.b1 = -2 * gamma;
        coeffs.b2 = 2 * beta;

        coeffs.c0 = 1.0;
        coeffs.d0 = 0.0;
        
        biquad.setCoeffs(coeffs);
        return true; // coeffs were calculated
    }
    return false; // coeffs were not recalculated
}

FilterParameters Filter::getParameters() { return Filter::params; }

void Filter::setParameters(const FilterParameters& params) {
    if (this->params.boost != params.boost || 
        this->params.fc != params.fc || 
        this->params.Q != params.Q || 
        this->params.type != params.type) {
        this->params = params;
    } else {
        return;
    }

    // don't allow 0 or (-) values for Q
    if (this->params.Q <= 0) { this->params.Q = 0.707; }

    calculateCoeffs();
}
