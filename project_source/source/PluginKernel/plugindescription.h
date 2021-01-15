// --- CMAKE generated variables for your plugin

#include "pluginstructures.h"

#ifndef _plugindescription_h
#define _plugindescription_h

#define QUOTE(name) #name
#define STR(macro) QUOTE(macro)
#define AU_COCOA_VIEWFACTORY_STRING STR(AU_COCOA_VIEWFACTORY_NAME)
#define AU_COCOA_VIEW_STRING STR(AU_COCOA_VIEW_NAME)

// --- AU Plugin Cocoa View Names (flat namespace) 
#define AU_COCOA_VIEWFACTORY_NAME AUCocoaViewFactory_2CC73BF4B78C3EBA975349C8403A6832
#define AU_COCOA_VIEW_NAME AUCocoaView_2CC73BF4B78C3EBA975349C8403A6832

// --- BUNDLE IDs (MacOS Only) 
const char* kAAXBundleID = "developer.aax.vparametriceq.bundleID";
const char* kAUBundleID = "developer.au.vparametriceq.bundleID";
const char* kVST3BundleID = "developer.vst3.vparametriceq.bundleID";

// --- Plugin Names 
const char* kPluginName = "VParametricEQ";
const char* kShortPluginName = "VParametricEQ";
const char* kAUBundleName = "VParametricEQ_AU";

// --- Plugin Type 
const pluginType kPluginType = pluginType::kFXPlugin;

// --- VST3 UUID 
const char* kVSTFUID = "{2cc73bf4-b78c-3eba-9753-49c8403a6832}";

// --- 4-char codes 
const int32_t kFourCharCode = 'VEGE';
const int32_t kAAXProductID = 'VEGE';
const int32_t kManufacturerID = 'RYAN';

// --- Vendor information 
const char* kVendorName = "My Company";
const char* kVendorURL = "";
const char* kVendorEmail = "";

// --- Plugin Options 
const bool kWantSidechain = false;
const uint32_t kLatencyInSamples = 0;
const double kTailTimeMsec = 0.000000;
const bool kVSTInfiniteTail = false;
const bool kVSTSAA = false;
const uint32_t kVST3SAAGranularity = 1;
const uint32_t kAAXCategory = 2;

#endif
