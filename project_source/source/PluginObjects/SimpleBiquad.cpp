// created by Ryan Puhalovich - http://github.com/rpuhalovich

#include "SimpleBiquad.hpp"

bool SimpleBiquad::reset(double _sampleRate) {
    SimpleBiquad::sampleRate = _sampleRate; // doesn't get used though
    return true; // success
}

double SimpleBiquad::processAudioSample(double xn) {
    // DEBUG_PRINT("xn: ", xn);
    // DEBUG_PRINT("regs.x_z1: ", regs.x_z1);
    
    // 1 - calc yn using diff equation
    double yn = coeffs.a0 * xn + coeffs.a1 * regs.x_z1 + coeffs.a2 * regs.x_z2 - coeffs.b1 * regs.y_z1 - coeffs.b2 * regs.y_z2;
    
    // 2
    checkFloatUnderflow(yn);

    // 3 - update state regs
    regs.x_z2 = regs.x_z1;
    regs.x_z2 = xn;

    regs.y_z2 = regs.y_z1;
    regs.y_z2 = yn;

    return yn;
}

bool SimpleBiquad::canProcessAudioFrame() { return false; }

void SimpleBiquad::setCoeffs(Coefficient _coeffs) {
    // maybe also set if statement to check if coeffs have been changed
    coeffs.a0 = _coeffs.a0;
    coeffs.a1 = _coeffs.a1;
    coeffs.a2 = _coeffs.a2;
    coeffs.b1 = _coeffs.b1;
    coeffs.b2 = _coeffs.b2;
    coeffs.c0 = _coeffs.c0;
    coeffs.d0 = _coeffs.d0;
}
