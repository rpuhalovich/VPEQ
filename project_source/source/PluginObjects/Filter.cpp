// created by Ryan Puhalovich - http://github.com/rpuhalovich
// see the .hpp file for detailed comments

#include "Filter.hpp"

bool Filter::reset(double _sampleRate) {
    return false;
}

double Filter::processAudioSample(double xn) {
    return 0.0;
}

bool Filter::canProcessAudioFrame() {
    return false;
}

int Filter::sum(int a, int b) {
    return a + b;
}
