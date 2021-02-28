// created by Ryan Puhalovich - http://github.com/rpuhalovich
// utility functions that I may need

#pragma once

#include <cmath>
#include <gtest/gtest.h>
#include <fxobjects.h>

// change to ifdef DEBUG - confusing
#ifdef RELEASE
    #define DEBUG_PRINT(msg_str, var)
#else
    #define DEBUG_PRINT(msg_str, var) std::cout << msg_str << var << std::endl
#endif // RELEASE

#define DEFAULT_SAMPLE_RATE 44100.0f
#define PATTERN_LEN 8

namespace utils {

// remember the static keyword for header file include variables that aren't to be global
static const double nyquist_pattern[PATTERN_LEN] = { 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f };
static const double half_nyquist_pattern[PATTERN_LEN] = { 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, -1.0f };
static const double quater_nyquist_pattern[PATTERN_LEN] = { 0.0f, 0.707f, 1.0f, 0.707f, 0.0f, -0.707f, -1.0f, -0.707f };
static const double dc_pattern[PATTERN_LEN] = { 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };

// compares two doubles based on a precision
static bool dequals(double x, double y, double precision) { return fabs(x - y) < precision; }

// note that passing classes is okay as performance isn't critical
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
