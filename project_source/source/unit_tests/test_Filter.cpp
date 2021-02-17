// created by Ryan Puhalovich - http://github.com/rpuhalovich
// testing Filter against the provided AudioFilter in fxobjects.h

#include <Catch2/catch.hpp>
#include <fxobjects.h>
#include <guiconstants.h>
#include <Instrumentor/Instrumentor.h>

#include "pch.hpp"
#include "Filter.hpp"


AudioFilter afilter;
AudioFilterParameters afilterParams;

Filter filter;
FilterParameters filterParams;

// --- helper functions ------------------------------------------------------------------------------------------------

void set_defaults() {
    filterParams.Q = 0.707f;
    filterParams.fc = 100.0f;
    filterParams.boost = 0.0f;
    filterParams.type = FilterType::LPF2;
    filter.reset(DEFAULT_SAMPLE_RATE);
    filter.setParameters(filterParams);
    
    afilterParams.Q = 0.707f;
    afilterParams.fc = 100.0f;
    afilterParams.boostCut_dB = 0.0f;
    afilterParams.algorithm = filterAlgorithm::kLPF2;
    afilter.reset(DEFAULT_SAMPLE_RATE);
    afilter.setParameters(afilterParams);
}

// note that passing classes is okay as performance isn't critical
void process_nyquist(Filter filter, AudioFilter afilter) {
    for (int i = 0; i < PATTERN_LEN; i++) {
        afilter.processAudioSample(utils::nyquist_pattern[i]);
        filter.processAudioSample(utils::nyquist_pattern[i]);
    }
}

void process_quater_nyquist(Filter filter, AudioFilter afilter) {
    for (int i = 0; i < PATTERN_LEN; i++) {
        afilter.processAudioSample(utils::quater_nyquist_pattern[i]);
        filter.processAudioSample(utils::quater_nyquist_pattern[i]);
    }
}

void process_dc(Filter filter, AudioFilter afilter) {
    for (int i = 0; i < PATTERN_LEN; i++) {
        afilter.processAudioSample(utils::dc_pattern[i]);
        filter.processAudioSample(utils::dc_pattern[i]);
    }
}

void process(Filter filter, AudioFilter afilter) {
    process_nyquist(filter, afilter);
    REQUIRE(afilter.processAudioSample(utils::nyquist_pattern[0]) == filter.processAudioSample(utils::nyquist_pattern[0]));
    
    process_quater_nyquist(filter, afilter);
    REQUIRE(afilter.processAudioSample(utils::quater_nyquist_pattern[0]) == filter.processAudioSample(utils::quater_nyquist_pattern[0]));

    process_dc(filter, afilter);
    REQUIRE(afilter.processAudioSample(utils::dc_pattern[0]) == filter.processAudioSample(utils::dc_pattern[0]));
}

// --- test cases ------------------------------------------------------------------------------------------------------

TEST_CASE("Testing default Filter against default AudioFilter (LPF vs kLPF2).", "[filter]") {
    set_defaults();
    process(filter, afilter);
}

TEST_CASE("Testing Filter HPF2 against AudioFilter kHPF2.", "[filter]") {
    filterParams.type = FilterType::HPF2;
    afilterParams.algorithm = filterAlgorithm::kHPF2;
    process(filter, afilter);
}

TEST_CASE("Testing Filter BPF against AudioFilter kBPF2.", "[filter]") {
    filterParams.type = FilterType::BPF;
    afilterParams.algorithm = filterAlgorithm::kBPF2;
    process(filter, afilter);
}

TEST_CASE("Testing Filter BSF against AudioFilter kBSF2.", "[filter]") {
    filterParams.type = FilterType::BSF;
    afilterParams.algorithm = filterAlgorithm::kBSF2;
    process(filter, afilter);
}

TEST_CASE("Testing Filter LSF against AudioFilter kLowShelf.", "[filter]") {
    filterParams.type = FilterType::LSF;
    afilterParams.algorithm = filterAlgorithm::kLowShelf;
    process(filter, afilter);
}

TEST_CASE("Testing Filter HSF against AudioFilter kHiShelf.", "[filter]") {
    filterParams.type = FilterType::HSF;
    afilterParams.algorithm = filterAlgorithm::kHiShelf;
    process(filter, afilter);
}

TEST_CASE("Testing Filter PEQ against AudioFilter kResonA.", "[filter]") {
    filterParams.type = FilterType::PEQ;
    afilterParams.algorithm = filterAlgorithm::kResonA;
    process(filter, afilter);
}
