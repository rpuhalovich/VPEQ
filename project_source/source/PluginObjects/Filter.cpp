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
    // --- set default pass-through
    coeffs.a0 = 1.0;
    coeffs.c0 = 1.0;
    coeffs.d0 = 0.0;
    
    if (params.type == FilterType::LPF2) {
        // calculate filter coeffs
        double theta_c = (2 * kPi * params.fc) / sampleRate;
        double d = 1 / params.Q;
        double betaNum = 1.0 - ((d / 2.0) * sin(theta_c));
        double betaDen = 1.0 + ((d / 2.0) * sin(theta_c));
        double beta = 0.5 * (betaNum / betaDen);
        double gamma = (0.5 + beta) * (cos(theta_c));
        double alpha = (0.5 + beta - gamma) / 2.0;
        
        // assign filter coeffs
        coeffs.a0 = alpha;
        coeffs.a1 = 2.0 * alpha;
        coeffs.a2 = alpha;
        coeffs.b1 = -2.0 * gamma;
        coeffs.b2 = 2.0 * beta;
        
        biquad.setCoeffs(coeffs);
        return true; // coeffs were calculated
    } else if (params.type == FilterType::HPF2) {
        // calculate filter coeffs
        double theta_c = (2 * kPi * params.fc) / sampleRate;
        double d = 1 / params.Q;
        double betaNum = 1.0 - ((d / 2.0) * sin(theta_c));
        double betaDen = 1.0 + ((d / 2.0) * sin(theta_c));
        double beta = 0.5 * (betaNum / betaDen);
        double gamma = (0.5 + beta) * (cos(theta_c));
        double alpha = (0.5 + beta + gamma) / 2.0;
        
        // assign filter coeffs
        coeffs.a0 = alpha;
        coeffs.a1 = -2.0 * alpha;
        coeffs.a2 = alpha;
        coeffs.b1 = -2.0 * gamma;
        coeffs.b2 = 2.0 * beta;
        
        biquad.setCoeffs(coeffs);
        return true; // coeffs were calculated
    }
    return false; // coeffs were not recalculated
}

FilterParameters Filter::getParameters() { return Filter::params; }

void Filter::setParameters(const FilterParameters& params) {
    // only set parameters if a parameter changes
    if (this->params.boost != params.boost ||
        this->params.fc != params.fc ||
        this->params.Q != params.Q ||
        this->params.type != params.type)
    {
        this->params = params;
    } else {
        return;
    }
    
    // don't allow 0 or (-) values for Q
    if (this->params.Q <= 0) { this->params.Q = 0.707; }
    calculateCoeffs();
}
