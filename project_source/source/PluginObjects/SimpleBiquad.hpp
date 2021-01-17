// created by Ryan Puhalovich - http://github.com/rpuhalovich
// simple biquad written by me for practice - using the Transposed Canonical Form

#pragma once

#include <fxobjects.h>

struct Coefficient {
    double a0 = 0.0f;
    double a1 = 0.0f;
    double a2 = 0.0f;
    double b1 = 0.0f;
    double b2 = 0.0f;
    double c0 = 0.0f;
    double d0 = 0.0f;
};

struct StateReg {
    double x_z1 = 0.0f;
    double x_z2 = 0.0f;
    double x_z3 = 0.0f;
    double x_z4 = 0.0f;

    double y_z1 = 0.0f;
    double y_z2 = 0.0f;
    double y_z3 = 0.0f;
    double y_z4 = 0.0f;
};

class SimpleBiquad : IAudioSignalProcessor {
public:
    virtual bool reset(double _sampleRate);
    virtual double processAudioSample(double xn);
    virtual bool canProcessAudioFrame();

    Coefficient coeffs;
    StateReg regs;

    double sampleRate = 44100.0f;
};
