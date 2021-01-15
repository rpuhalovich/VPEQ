// created by Ryan Puhalovich - http://github.com/rpuhalovich

#include "SimpleBiquad.hpp"

bool SimpleBiquad::reset(double _sampleRate) {
	return true; // success
}

double SimpleBiquad::processAudioSample(double xn) {
	return 0.0;
}

bool SimpleBiquad::canProcessAudioFrame() {
	return false;
}
