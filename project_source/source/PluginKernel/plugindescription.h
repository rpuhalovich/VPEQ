// --- CMAKE generated variables for your plugin

#include "pluginstructures.h"

#ifndef _plugindescription_h
#define _plugindescription_h

#define QUOTE(name) #name
#define STR(macro) QUOTE(macro)
#define AU_COCOA_VIEWFACTORY_STRING STR(AU_COCOA_VIEWFACTORY_NAME)
#define AU_COCOA_VIEW_STRING STR(AU_COCOA_VIEW_NAME)

// --- AU Plugin Cocoa View Names (flat namespace) 
<<<<<<< HEAD
#define AU_COCOA_VIEWFACTORY_NAME AUCocoaViewFactory_8302659E133031EAA4F432F4C3C2C80D
#define AU_COCOA_VIEW_NAME AUCocoaView_8302659E133031EAA4F432F4C3C2C80D
=======
#define AU_COCOA_VIEWFACTORY_NAME AUCocoaViewFactory_2A3111860AC736A2ADF42AB5C113F136
#define AU_COCOA_VIEW_NAME AUCocoaView_2A3111860AC736A2ADF42AB5C113F136
>>>>>>> dev

// --- BUNDLE IDs (MacOS Only) 
const char* kAAXBundleID = "developer.aax.vpeq.bundleID";
const char* kAUBundleID = "developer.au.vpeq.bundleID";
const char* kVST3BundleID = "developer.vst3.vpeq.bundleID";

// --- Plugin Names 
const char* kPluginName = "VPEQ";
const char* kShortPluginName = "VPEQ";
const char* kAUBundleName = "VPEQ_AU";

// --- Plugin Type 
const pluginType kPluginType = pluginType::kFXPlugin;

// --- VST3 UUID 
<<<<<<< HEAD
const char* kVSTFUID = "{8302659e-1330-31ea-a4f4-32f4c3c2c80d}";
=======
const char* kVSTFUID = "{2a311186-0ac7-36a2-adf4-2ab5c113f136}";
>>>>>>> dev

// --- 4-char codes 
const int32_t kFourCharCode = 'VPEQ';
const int32_t kAAXProductID = 'VPEQ';
const int32_t kManufacturerID = 'CLHE';

// --- Vendor information 
const char* kVendorName = "cloudyhead";
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
