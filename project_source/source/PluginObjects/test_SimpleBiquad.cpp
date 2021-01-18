// created by Ryan Puhalovich - http://github.com/rpuhalovich

#include <Catch2/catch.hpp>
#include <fxobjects.h>
#include "SimpleBiquad.hpp"

Biquad bi;
SimpleBiquad simpBi;
Coefficient coeffs;

TEST_CASE("state registers actually updating", "[biquad]") {
    // add coeffs that you've calculated
    
    
    
    
    
    
    
    double xn = 0.5;
    REQUIRE(simpBi.processAudioSample(xn) == bi.processAudioSample(xn));
    xn = 0.5;
    REQUIRE(simpBi.processAudioSample(xn) == bi.processAudioSample(xn));
    xn = 0.5;
    REQUIRE(simpBi.processAudioSample(xn) == bi.processAudioSample(xn));
    xn = 0.5;
    REQUIRE(simpBi.processAudioSample(xn) == bi.processAudioSample(xn));
}
