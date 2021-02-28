// created by Ryan Puhalovich - http://github.com/rpuhalovich
// testing the simple biquad against the provided Biquad in fxobjects.h

#include <fxobjects.h>
#include "pch.hpp"
#include "SimpleBiquad.hpp"

Biquad bi;
BiquadParameters biparams;
SimpleBiquad simpbi;

/*
 void set_defaults() {
 biparams.biquadCalcType = biquadAlgorithm::kDirect;
 }
 
 TEST(SimpleBiquad_vs_Biquad, biquad) {
 set_defaults();
 utils::process_gtest(simpbi, bi);
 }
*/
