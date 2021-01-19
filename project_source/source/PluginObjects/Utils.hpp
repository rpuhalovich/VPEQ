// created by Ryan Puhalovich - http://github.com/rpuhalovich
// utility functions that I may need

#pragma once

// change to ifdef DEBUG - confusing
#ifdef RELEASE
    #define DEBUG_PRINT(msg_str, var)
#else
    #define DEBUG_PRINT(msg_str, var) std::cout << msg_str << var << std::endl
#endif // RELEASE

#define TEST_SAMPLE_RATE 44100.0f

#define _PATTERN_LEN 8
static int _pattern_len = _PATTERN_LEN;
static double _nyquist_pattern[_PATTERN_LEN] = { 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f };
static double _half_nyquist_pattern[_PATTERN_LEN] = { 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, -1.0f };
static double _quater_nyquist_pattern[_PATTERN_LEN] = { 0.0f, 0.707f, 1.0f, 0.707f, 0.0f, -0.707f, -1.0f, -0.707f };
static double _dc_pattern[_PATTERN_LEN] = { 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
