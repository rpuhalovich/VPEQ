// created by Ryan Puhalovich - http://github.com/rpuhalovich
// utility functions that I may need

#pragma once

#include <cmath>
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

static const double nyquist_pattern[PATTERN_LEN] = { 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f };
static const double half_nyquist_pattern[PATTERN_LEN] = { 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, -1.0f };
static const double quater_nyquist_pattern[PATTERN_LEN] = { 0.0f, 0.707f, 1.0f, 0.707f, 0.0f, -0.707f, -1.0f, -0.707f };
static const double dc_pattern[PATTERN_LEN] = { 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };

// compares two doubles based on a precision
static bool dequals(double x, double y, double precision) { return fabs(x - y) < precision; }

}
