#include <Catch2/catch.hpp>
#include <fxobjects.h>
#include <guiconstants.h>
#include "headers.hpp"
#include "Filter.hpp"

AudioFilter afilter;
AudioFilterParameters afilterParams;

Filter filter;
FilterParameters filterParams;

TEST_CASE("Testing Audio Filter against my Filter", "[filter]") {
    filterParams.Q = 0.707f;
    filterParams.fc = 100.0f;
    filterParams.boost = 0.0f;
    filterParams.type = FilterType::LPF2;
    filterParams.wetDry = 1.0f;
    filter.reset(DEFAULT_SAMPLE_RATE);
    filter.setParameters(filterParams);
    
    afilterParams.Q = 0.707f;
    afilterParams.fc = 100.0f;
    afilterParams.boostCut_dB = 0.0f;
    afilterParams.algorithm = filterAlgorithm::kLPF2;
    afilter.reset(DEFAULT_SAMPLE_RATE);
    afilter.setParameters(afilterParams);
    
    // Nyquist
    for (int i = 0; i < PATTERN_LEN; i++) {
        afilter.processAudioSample(utils::nyquist_pattern[i]);
        filter.processAudioSample(utils::nyquist_pattern[i]);
    }
    REQUIRE(afilter.processAudioSample(utils::nyquist_pattern[0]) == filter.processAudioSample(utils::nyquist_pattern[0]));
    
    // Quater Nyquist
    for (int i = 0; i < PATTERN_LEN; i++) {
        afilter.processAudioSample(utils::quater_nyquist_pattern[i]);
        filter.processAudioSample(utils::quater_nyquist_pattern[i]);
    }
    REQUIRE(afilter.processAudioSample(utils::quater_nyquist_pattern[0]) == filter.processAudioSample(utils::quater_nyquist_pattern[0]));

    // DC
    for (int i = 0; i < PATTERN_LEN; i++) {
        afilter.processAudioSample(utils::dc_pattern[i]);
        filter.processAudioSample(utils::dc_pattern[i]);
    }
    REQUIRE(afilter.processAudioSample(utils::dc_pattern[0]) == filter.processAudioSample(utils::dc_pattern[0]));
}
