// created by Ryan Puhalovich - http://github.com/rpuhalovich

#pragma once

#include "utils.hpp"
#include <gtest/gtest.h>

namespace unit_tests_utils {

// --- gtest processing functions --------------------------------------------------------------------------------------

static void process_nyquist(IAudioSignalProcessor &processor1, IAudioSignalProcessor &processor2) {
    for (int i = 0; i < PATTERN_LEN; i++) {
        processor1.processAudioSample(utils::nyquist_pattern[i]);
        processor2.processAudioSample(utils::nyquist_pattern[i]);
    }
}

static void process_quater_nyquist(IAudioSignalProcessor &processor1, IAudioSignalProcessor &processor2) {
    for (int i = 0; i < PATTERN_LEN; i++) {
        processor1.processAudioSample(utils::quater_nyquist_pattern[i]);
        processor2.processAudioSample(utils::quater_nyquist_pattern[i]);
    }
}

static void process_dc(IAudioSignalProcessor &processor1, IAudioSignalProcessor &processor2) {
    for (int i = 0; i < PATTERN_LEN; i++) {
        processor1.processAudioSample(utils::dc_pattern[i]);
        processor2.processAudioSample(utils::dc_pattern[i]);
    }
}

static void process_gtest(IAudioSignalProcessor &processor1, IAudioSignalProcessor &processor2) {
    process_nyquist(processor1, processor2);
    EXPECT_EQ(processor1.processAudioSample(utils::nyquist_pattern[0]),
              processor2.processAudioSample(utils::nyquist_pattern[0]));
    
    process_quater_nyquist(processor1, processor2);
    EXPECT_EQ(processor1.processAudioSample(utils::quater_nyquist_pattern[0]),
              processor2.processAudioSample(utils::quater_nyquist_pattern[0]));

    process_dc(processor1, processor2);
    EXPECT_EQ(processor1.processAudioSample(utils::dc_pattern[0]),
              processor2.processAudioSample(utils::dc_pattern[0]));
}

}
