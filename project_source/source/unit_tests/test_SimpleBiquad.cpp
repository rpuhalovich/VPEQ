// created by Ryan Puhalovich - http://github.com/rpuhalovich
// testing the simple biquad against the provided Biquad in fxobjects.h

#include <Catch2/catch.hpp>
#include <fxobjects.h>
#include "pch.hpp"
#include "SimpleBiquad.hpp"

/*
Biquad bi;
BiquadParameters biparams;
SimpleBiquad simpbi;

TEST_CASE("Testing Biquad Calculations", "[SimpleBiquad]") {
    biparams.biquadCalcType = biquadAlgorithm::kDirect;
    bi.setParameters(biparams);
    
    // Nyquist
    double xn = 1.0;
    bi.processAudioSample(xn); simpbi.processAudioSample(xn); xn = -1.0;
    bi.processAudioSample(xn); simpbi.processAudioSample(xn); xn = 1.0;
    REQUIRE(bi.processAudioSample(xn) == simpbi.processAudioSample(xn));
}
*/
