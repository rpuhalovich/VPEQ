// created by Ryan Puhalovich - http://github.com/rpuhalovich
// simple biquad written by me for practice - using the Transposed Canonical Form

#pragma once

#include <fxobjects.h>

class SimpleBiquad : IAudioSignalProcessor {
public:
    virtual bool reset(double _sampleRate);
    virtual double processAudioSample(double xn);
    virtual bool canProcessAudioFrame();
};