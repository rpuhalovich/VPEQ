#include <Catch2/catch.hpp>
#include <fxobjects.h>
#include <guiconstants.h>
#include "Headers.hpp"
#include "Filter.hpp"

AudioFilter afilter;
AudioFilterParameters afilterParams;

Filter filter;
FilterParameters filterParams;

TEST_CASE("Testing Audio Filter against my Filter", "[filter]") {
    filter.reset(TEST_SAMPLE_RATE);
    filterParams.Q = 0.707f;
    filterParams.fc = 100.0f;
    filterParams.boost = 0.0f;
    filterParams.type = FilterType::LPF2;
    filterParams.wetDry = 1.0f;
    filter.setParameters(filterParams);
    
    afilter.reset(TEST_SAMPLE_RATE);
    afilterParams.Q = 0.707f;
    afilterParams.fc = 100.0f;
    afilterParams.boostCut_dB = 0.0f;
    afilterParams.algorithm = filterAlgorithm::kLPF2;
    afilter.setParameters(afilterParams);
    
    // Nyquist
    for (int i = 0; i < _pattern_len; i++) {
        afilter.processAudioSample(_nyquist_pattern[i]);
        filter.processAudioSample(_nyquist_pattern[i]);
    }
    REQUIRE(afilter.processAudioSample(_nyquist_pattern[0]) == filter.processAudioSample(_nyquist_pattern[0]));
    
    // DC
    double xn = 1.0;
    afilter.processAudioSample(xn); filter.processAudioSample(xn);
    afilter.processAudioSample(xn); filter.processAudioSample(xn);
    afilter.processAudioSample(xn); filter.processAudioSample(xn);
    REQUIRE(afilter.processAudioSample(xn) == filter.processAudioSample(xn));

    // Quater Nyquist
    for (int i = 0; i < _pattern_len; i++) {
        afilter.processAudioSample(_quater_nyquist_pattern[i]);
        filter.processAudioSample(_quater_nyquist_pattern[i]);
    }
    REQUIRE(afilter.processAudioSample(_quater_nyquist_pattern[0]) == filter.processAudioSample(_quater_nyquist_pattern[0]));
}
