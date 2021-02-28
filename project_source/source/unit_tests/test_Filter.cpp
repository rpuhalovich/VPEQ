// created by Ryan Puhalovich - http://github.com/rpuhalovich
// testing Filter against the provided AudioFilter in fxobjects.h

#include "pch.hpp"
#include "unit_tests_utils.hpp"
#include <gtest/gtest.h>
#include <fxobjects.h>
#include <guiconstants.h>

#include "Filter.hpp"

AudioFilter afilter;
AudioFilterParameters afilterParams;

Filter filter;
FilterParameters filterParams;

// --- helper functions ------------------------------------------------------------------------------------------------

static void set_defaults() {
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

// --- test cases ------------------------------------------------------------------------------------------------------

/*
 TEST(test_macros, macros) {
 EXPECT_EQ(true, true);
 EXPECT_EQ(true, false);
 }
*/

TEST(default_filter_vs_afilter, filter) {
    set_defaults();
    unit_tests_utils::process_gtest(filter, afilter);
}

TEST(HPF_filter_vs_afilter, filter) {
    filterParams.type = FilterType::HPF2;
    afilterParams.algorithm = filterAlgorithm::kHPF2;
    unit_tests_utils::process_gtest(filter, afilter);
}

TEST(BPF_filter_vs_afilter, filter) {
    filterParams.type = FilterType::BPF;
    afilterParams.algorithm = filterAlgorithm::kBPF2;
    unit_tests_utils::process_gtest(filter, afilter);
}

TEST(BSF_filter_vs_afilter, filter) {
    filterParams.type = FilterType::BSF;
    afilterParams.algorithm = filterAlgorithm::kBSF2;
    unit_tests_utils::process_gtest(filter, afilter);
}

TEST(LSF_filter_vs_afilter, filter) {
    filterParams.type = FilterType::LSF;
    afilterParams.algorithm = filterAlgorithm::kLowShelf;
    unit_tests_utils::process_gtest(filter, afilter);
}

TEST(HSF_filter_vs_afilter, filter) {
    filterParams.type = FilterType::HSF;
    afilterParams.algorithm = filterAlgorithm::kHiShelf;
    unit_tests_utils::process_gtest(filter, afilter);
}

TEST(PEQ_filter_vs_afilter, filter) {
    filterParams.type = FilterType::PEQ;
    afilterParams.algorithm = filterAlgorithm::kResonA;
    unit_tests_utils::process_gtest(filter, afilter);
}

