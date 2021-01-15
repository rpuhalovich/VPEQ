// --- CMAKE generated variables for your plugin

#include "pluginstructures.h"

#ifndef _plugindescription_h
#define _plugindescription_h

#define QUOTE(name) #name
#define STR(macro) QUOTE(macro)
#define AU_COCOA_VIEWFACTORY_STRING STR(AU_COCOA_VIEWFACTORY_NAME)
#define AU_COCOA_VIEW_STRING STR(AU_COCOA_VIEW_NAME)

// --- AU Plugin Cocoa View Names (flat namespace) 
#define AU_COCOA_VIEWFACTORY_NAME AUCocoaViewFactory_0B98EC48E03B391591955421DB4F5DD9
#define AU_COCOA_VIEW_NAME AUCocoaView_0B98EC48E03B391591955421DB4F5DD9

// --- BUNDLE IDs (MacOS Only) 
const char* kAAXBundleID = "developer.aax.aspiktemplate.bundleID";
const char* kAUBundleID = "developer.au.aspiktemplate.bundleID";
const char* kVST3BundleID = "developer.vst3.aspiktemplate.bundleID";

// --- Plugin Names 
const char* kPluginName = "ASPiKTemplate";
const char* kShortPluginName = "ASPiKTemplate";
const char* kAUBundleName = "ASPiKTemplate_AU";

// --- Plugin Type 
const pluginType kPluginType = pluginType::kFXPlugin;

// --- VST3 UUID 
const char* kVSTFUID = "{0b98ec48-e03b-3915-9195-5421db4f5dd9}";

// --- 4-char codes 
const int32_t kFourCharCode = 'PLuG';
const int32_t kAAXProductID = 'PLuG';
const int32_t kManufacturerID = 'ASPK';

// --- Vendor information 
const char* kVendorName = "My Company";
const char* kVendorURL = "www.myplugins.com";
const char* kVendorEmail = "support@myplugins.com";

// --- Plugin Options 
const bool kWantSidechain = false;
const uint32_t kLatencyInSamples = 0;
const double kTailTimeMsec = 0.000000;
const bool kVSTInfiniteTail = false;
const bool kVSTSAA = false;
const uint32_t kVST3SAAGranularity = 1;
const uint32_t kAAXCategory = 2;

#endif
