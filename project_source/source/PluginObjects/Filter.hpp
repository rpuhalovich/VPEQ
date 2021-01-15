// created by Ryan Puhalovich - http://github.com/rpuhalovich

#pragma once

#include <stdio.h>
#include "fxobjects.h"

class Filter : public IAudioSignalProcessor {
public:
    virtual bool reset(double _sampleRate);
    virtual double processAudioSample(double xn);
    virtual bool canProcessAudioFrame();

    int sum(int a, int b);
};
