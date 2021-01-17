// created by Ryan Puhalovich - http://github.com/rpuhalovich
// see the .hpp file for detailed comments

#include "Filter.hpp"

bool Filter::reset(double _sampleRate) {
    sampleRate = _sampleRate;

    return true; // success
}

double Filter::processAudioSample(double xn) {
    biquad.coeffs.d0 = Filter::params.wetDry;
    biquad.coeffs.c0 = 1 / Filter::params.wetDry;

    return biquad.coeffs.d0 * xn + biquad.coeffs.c0 * biquad.processAudioSample(xn);
}

bool Filter::canProcessAudioFrame() { return false; }

bool Filter::calculateCoeffs() {
    double yn = 0.0f;
    double d = 0.0f;
    double beta = 0.0f;
    double gamma = 0.0f;
    double theta = 0.0f;

    if (params.type == FilterType::LPF2) {
        // calculatefilter coeffs
        theta = (2 * M_PI * params.fc) / sampleRate;
        d = 1 / params.Q;
        beta = 0.5 * ((1 - (d / 2) * sin(theta)) / (1 - (d / 2) * sin(theta)));
        gamma = (0.5 * beta) * cos(theta);

        // assign filter coeffs
        biquad.coeffs.a0 = (0.5 + beta - gamma) / (2.0f);
        biquad.coeffs.a1 = 0.5 + beta - gamma;
        biquad.coeffs.a2 = (0.5 + beta - gamma) / (2.0f);

        biquad.coeffs.b1 = -2 * gamma;
        biquad.coeffs.b2 = 2 * beta;

        biquad.coeffs.c0 = 1.0f;
        biquad.coeffs.d0 = 0.0f;

        return biquad.processAudioSample(yn);
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