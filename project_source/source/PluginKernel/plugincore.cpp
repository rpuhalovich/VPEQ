// -----------------------------------------------------------------------------
//    ASPiK Plugin Kernel File:  plugincore.cpp
//
/**
    \file   plugincore.cpp
    \author Will Pirkle
    \date   17-September-2018
    \brief  Implementation file for PluginCore object
    		- http://www.aspikplugins.com
    		- http://www.willpirkle.com
*/
// -----------------------------------------------------------------------------
#include "plugincore.h"
#include "plugindescription.h"

/**
\brief PluginCore constructor is launching pad for object initialization

Operations:
- initialize the plugin description (strings, codes, numbers, see initPluginDescriptors())
- setup the plugin's audio I/O channel support
- create the PluginParameter objects that represent the plugin parameters (see FX book if needed)
- create the presets
*/
PluginCore::PluginCore() {
    // --- describe the plugin; call the helper to init the static parts you setup in plugindescription.h
    initPluginDescriptors();

    // --- default I/O combinations
    // --- for FX plugins
    if (getPluginType() == kFXPlugin) {
        addSupportedIOCombination({ kCFMono, kCFMono });
        addSupportedIOCombination({ kCFMono, kCFStereo });
        addSupportedIOCombination({ kCFStereo, kCFStereo });
    } else { // --- synth plugins have no input, only output
        addSupportedIOCombination({ kCFNone, kCFMono });
        addSupportedIOCombination({ kCFNone, kCFStereo });
    }

    // --- for sidechaining, we support mono and stereo inputs; auxOutputs reserved for future use
    addSupportedAuxIOCombination({ kCFMono, kCFNone });
    addSupportedAuxIOCombination({ kCFStereo, kCFNone });

    // --- create the parameters
    initPluginParameters();

    // --- create the presets
    initPluginPresets();
}

/**
\brief create all of your plugin parameters here

\return true if parameters were created, false if they already existed
*/
bool PluginCore::initPluginParameters() {
    if (pluginParameterMap.size() > 0)
        return false;

    // --- Add your plugin parameter instantiation code bewtween these hex codes
    PluginParameter* piParam = nullptr;

    // TODO: there's gotta be a better way of doing this...
    // --- filterFC_Hz -----------------------------------------------------------------------------------------------------
    piParam = new PluginParameter(controlID::filterFC_Hz1, "FC1", "Hz", controlVariableType::kDouble, 20.000000, 20480.000000, 1000.000000, taper::kVoltOctaveTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterFC_Hz1, boundVariableType::kDouble);
    addPluginParameter(piParam);    
    
    piParam = new PluginParameter(controlID::filterFC_Hz2, "FC2", "Hz", controlVariableType::kDouble, 20.000000, 20480.000000, 1000.000000, taper::kVoltOctaveTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterFC_Hz2, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterFC_Hz3, "FC3", "Hz", controlVariableType::kDouble, 20.000000, 20480.000000, 1000.000000, taper::kVoltOctaveTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterFC_Hz3, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterFC_Hz4, "FC4", "Hz", controlVariableType::kDouble, 20.000000, 20480.000000, 1000.000000, taper::kVoltOctaveTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterFC_Hz4, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterFC_Hz5, "FC5", "Hz", controlVariableType::kDouble, 20.000000, 20480.000000, 1000.000000, taper::kVoltOctaveTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterFC_Hz5, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterFC_Hz6, "FC6", "Hz", controlVariableType::kDouble, 20.000000, 20480.000000, 1000.000000, taper::kVoltOctaveTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterFC_Hz6, boundVariableType::kDouble);
    addPluginParameter(piParam);    
    
    piParam = new PluginParameter(controlID::filterFC_Hz7, "FC7", "Hz", controlVariableType::kDouble, 20.000000, 20480.000000, 1000.000000, taper::kVoltOctaveTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterFC_Hz7, boundVariableType::kDouble);
    addPluginParameter(piParam);

    // --- filterQ -----------------------------------------------------------------------------------------------------
    piParam = new PluginParameter(controlID::filterQ1, "Q1", "", controlVariableType::kDouble, 0.707000, 20.000000, 0.707000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterQ1, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterQ2, "Q2", "", controlVariableType::kDouble, 0.707000, 20.000000, 0.707000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterQ2, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterQ3, "Q3", "", controlVariableType::kDouble, 0.707000, 20.000000, 0.707000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterQ3, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterQ4, "Q4", "", controlVariableType::kDouble, 0.707000, 20.000000, 0.707000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterQ4, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterQ5, "Q5", "", controlVariableType::kDouble, 0.707000, 20.000000, 0.707000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterQ5, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterQ6, "Q6", "", controlVariableType::kDouble, 0.707000, 20.000000, 0.707000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterQ6, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterQ7, "Q7", "", controlVariableType::kDouble, 0.707000, 20.000000, 0.707000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&filterQ7, boundVariableType::kDouble);
    addPluginParameter(piParam);

    // --- boostCut_dB -----------------------------------------------------------------------------------------------------
    piParam = new PluginParameter(controlID::boostCut_dB1, "Boost/Cut 1", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&boostCut_dB1, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::boostCut_dB2, "Boost/Cut 2", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&boostCut_dB2, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::boostCut_dB3, "Boost/Cut 3", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&boostCut_dB3, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::boostCut_dB4, "Boost/Cut 4", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&boostCut_dB4, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::boostCut_dB5, "Boost/Cut 5", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&boostCut_dB5, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::boostCut_dB6, "Boost/Cut 6", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&boostCut_dB6, boundVariableType::kDouble);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::boostCut_dB7, "Boost/Cut 7", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
    piParam->setParameterSmoothing(true);
    piParam->setSmoothingTimeMsec(20.000000);
    piParam->setBoundVariable(&boostCut_dB7, boundVariableType::kDouble);
    addPluginParameter(piParam);

    // --- filterType -----------------------------------------------------------------------------------------------------
    piParam = new PluginParameter(controlID::filterType1, "Filter Type 1", "Low Pass,High Pass,Band Pass,Band Stop,Low Shelf,High Shelf,Peaking,Off", "Low Pass");
    piParam->setBoundVariable(&filterType1, boundVariableType::kInt);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterType2, "Filter Type 2", "Low Pass,High Pass,Band Pass,Band Stop,Low Shelf,High Shelf,Peaking,Off", "Low Pass");
    piParam->setBoundVariable(&filterType2, boundVariableType::kInt);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterType3, "Filter Type 3", "Low Pass,High Pass,Band Pass,Band Stop,Low Shelf,High Shelf,Peaking,Off", "Low Pass");
    piParam->setBoundVariable(&filterType3, boundVariableType::kInt);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterType4, "Filter Type 4", "Low Pass,High Pass,Band Pass,Band Stop,Low Shelf,High Shelf,Peaking,Off", "Low Pass");
    piParam->setBoundVariable(&filterType4, boundVariableType::kInt);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterType5, "Filter Type 5", "Low Pass,High Pass,Band Pass,Band Stop,Low Shelf,High Shelf,Peaking,Off", "Low Pass");
    piParam->setBoundVariable(&filterType5, boundVariableType::kInt);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterType6, "Filter Type 6", "Low Pass,High Pass,Band Pass,Band Stop,Low Shelf,High Shelf,Peaking,Off", "Low Pass");
    piParam->setBoundVariable(&filterType6, boundVariableType::kInt);
    addPluginParameter(piParam);

    piParam = new PluginParameter(controlID::filterType7, "Filter Type 7", "Low Pass,High Pass,Band Pass,Band Stop,Low Shelf,High Shelf,Peaking,Off", "Low Pass");
    piParam->setBoundVariable(&filterType7, boundVariableType::kInt);
    addPluginParameter(piParam);

    // --- BONUS Parameter
    // --- SCALE_GUI_SIZE
    PluginParameter* piParamBonus = new PluginParameter(SCALE_GUI_SIZE, "Scale GUI", "tiny,small,medium,normal,large,giant", "normal");
    addPluginParameter(piParamBonus);

    // --- create the super fast access array
    initPluginParameterArray();

    return true;
}

/**
\brief initialize object for a new run of audio; called just before audio streams

Operation:
- store sample rate and bit depth on audioProcDescriptor - this information is globally available to all core functions
- reset your member objects here

\param resetInfo structure of information about current audio format

\return true if operation succeeds, false otherwise
*/
bool PluginCore::reset(ResetInfo& resetInfo) {
    // --- save for audio processing
    audioProcDescriptor.sampleRate = resetInfo.sampleRate;
    audioProcDescriptor.bitDepth = resetInfo.bitDepth;
    
    filter1.reset(resetInfo.sampleRate);
    filter2.reset(resetInfo.sampleRate);
    filter3.reset(resetInfo.sampleRate);
    filter4.reset(resetInfo.sampleRate);
    filter5.reset(resetInfo.sampleRate);
    filter6.reset(resetInfo.sampleRate);
    filter7.reset(resetInfo.sampleRate);

    // --- other reset inits
    return PluginBase::reset(resetInfo);
}

/**
\brief one-time initialize function called after object creation and before the first reset( ) call

Operation:
- saves structure for the plugin to use; you can also load WAV files or state information here
*/
bool PluginCore::initialize(PluginInfo& pluginInfo) {
    // --- add one-time init stuff here

    return true;
}

/**
\brief do anything needed prior to arrival of audio buffers

Operation:
- syncInBoundVariables when preProcessAudioBuffers is called, it is *guaranteed* that all GUI control change information
  has been applied to plugin parameters; this binds parameter changes to your underlying variables
- NOTE: postUpdatePluginParameter( ) will be called for all bound variables that are acutally updated; if you need to process
  them individually, do so in that function
- use this function to bulk-transfer the bound variable data into your plugin's member object variables

\param processInfo structure of information about *buffer* processing

\return true if operation succeeds, false otherwise
*/
bool PluginCore::preProcessAudioBuffers(ProcessBufferInfo& processInfo) {
    // --- sync internal variables to GUI parameters; you can also do this manually if you don't
    //     want to use the auto-variable-binding
    syncInBoundVariables();

    return true;
}

/**
\brief frame-processing method

Operation:
- decode the plugin type - for synth plugins, fill in the rendering code; for FX plugins, delete the if(synth) portion and add your processing code
- note that MIDI events are fired for each sample interval so that MIDI is tightly sunk with audio
- doSampleAccurateParameterUpdates will perform per-sample interval smoothing

\param processFrameInfo structure of information about *frame* processing

\return true if operation succeeds, false otherwise
*/
bool PluginCore::processAudioFrame(ProcessFrameInfo& processFrameInfo) {
    doSampleAccurateParameterUpdates();
    updateParameters();
    
    // for each channel, process sample in the filter
    double temp_sample = 0.0;
    for (int i = 0; i < processFrameInfo.numAudioInChannels; i++) {
        temp_sample = filter1.processAudioSample(processFrameInfo.audioInputFrame[i]);
        temp_sample = filter2.processAudioSample(temp_sample);
        temp_sample = filter3.processAudioSample(temp_sample);
        temp_sample = filter4.processAudioSample(temp_sample);
        temp_sample = filter5.processAudioSample(temp_sample);
        temp_sample = filter6.processAudioSample(temp_sample);
        processFrameInfo.audioOutputFrame[i] = filter7.processAudioSample(temp_sample);
    }

    return true;
}


/**
\brief do anything needed prior to arrival of audio buffers

Operation:
- updateOutBoundVariables sends metering data to the GUI meters

\param processInfo structure of information about *buffer* processing

\return true if operation succeeds, false otherwise
*/
bool PluginCore::postProcessAudioBuffers(ProcessBufferInfo& processInfo) {
    // --- update outbound variables; currently this is meter data only, but could be extended
    //     in the future
    updateOutBoundVariables();

    return true;
}

/**
\brief update the PluginParameter's value based on GUI control, preset, or data smoothing (thread-safe)

Operation:
- update the parameter's value (with smoothing this initiates another smoothing process)
- call postUpdatePluginParameter to do any further processing

\param controlID the control ID value of the parameter being updated
\param controlValue the new control value
\param paramInfo structure of information about why this value is being udpated (e.g as a result of a preset being loaded vs. the top of a buffer process cycle)

\return true if operation succeeds, false otherwise
*/
bool PluginCore::updatePluginParameter(int32_t controlID, double controlValue, ParameterUpdateInfo& paramInfo) {
    // --- use base class helper
    setPIParamValue(controlID, controlValue);

    // --- do any post-processing
    postUpdatePluginParameter(controlID, controlValue, paramInfo);

    return true; /// handled
}

/**
\brief update the PluginParameter's value based on *normlaized* GUI control, preset, or data smoothing (thread-safe)

Operation:
- update the parameter's value (with smoothing this initiates another smoothing process)
- call postUpdatePluginParameter to do any further processing

\param controlID the control ID value of the parameter being updated
\param normalizedValue the new control value in normalized form
\param paramInfo structure of information about why this value is being udpated (e.g as a result of a preset being loaded vs. the top of a buffer process cycle)

\return true if operation succeeds, false otherwise
*/
bool PluginCore::updatePluginParameterNormalized(int32_t controlID, double normalizedValue, ParameterUpdateInfo& paramInfo) {
    // --- use base class helper, returns actual value
    double controlValue = setPIParamValueNormalized(controlID, normalizedValue, paramInfo.applyTaper);

    // --- do any post-processing
    postUpdatePluginParameter(controlID, controlValue, paramInfo);

    return true; /// handled
}

/**
\brief perform any operations after the plugin parameter has been updated; this is one paradigm for
	   transferring control information into vital plugin variables or member objects. If you use this
	   method you can decode the control ID and then do any cooking that is needed. NOTE: do not
	   overwrite bound variables here - this is ONLY for any extra cooking that is required to convert
	   the GUI data to meaninful coefficients or other specific modifiers.

\param controlID the control ID value of the parameter being updated
\param controlValue the new control value
\param paramInfo structure of information about why this value is being udpated (e.g as a result of a preset being loaded vs. the top of a buffer process cycle)

\return true if operation succeeds, false otherwise
*/
bool PluginCore::postUpdatePluginParameter(int32_t controlID, double controlValue, ParameterUpdateInfo& paramInfo) {
    // --- now do any post update cooking; be careful with VST Sample Accurate automation
    //     If enabled, then make sure the cooking functions are short and efficient otherwise disable it
    //     for the Parameter involved
    /*switch(controlID)
    {
        case 0:
        {
            return true;    /// handled
        }

        default:
            return false;   /// not handled
    }*/

    return false;
}

/**
\brief has nothing to do with actual variable or updated variable (binding)

CAUTION:
- DO NOT update underlying variables here - this is only for sending GUI updates or letting you
  know that a parameter was changed; it should not change the state of your plugin.

WARNING:
- THIS IS NOT THE PREFERRED WAY TO LINK OR COMBINE CONTROLS TOGETHER. THE PROPER METHOD IS
  TO USE A CUSTOM SUB-CONTROLLER THAT IS PART OF THE GUI OBJECT AND CODE.
  SEE http://www.willpirkle.com for more information

\param controlID the control ID value of the parameter being updated
\param actualValue the new control value

\return true if operation succeeds, false otherwise
*/
bool PluginCore::guiParameterChanged(int32_t controlID, double actualValue) {
    /*
    switch (controlID)
    {
    	case controlID::<your control here>
    	{

    		return true; // handled
    	}

    	default:
    		break;
    }*/

    return false; /// not handled
}

/**
\brief For Custom View and Custom Sub-Controller Operations

NOTES:
- this is for advanced users only to implement custom view and custom sub-controllers
- see the SDK for examples of use

\param messageInfo a structure containing information about the incoming message

\return true if operation succeeds, false otherwise
*/
bool PluginCore::processMessage(MessageInfo& messageInfo) {
    // --- decode message
    switch (messageInfo.message) {
    // --- add customization appearance here
    case PLUGINGUI_DIDOPEN: {
        return false;
    }

    // --- NULL pointers so that we don't accidentally use them
    case PLUGINGUI_WILLCLOSE: {
        return false;
    }

    // --- update view; this will only be called if the GUI is actually open
    case PLUGINGUI_TIMERPING: {
        return false;
    }

    // --- register the custom view, grab the ICustomView interface
    case PLUGINGUI_REGISTER_CUSTOMVIEW: {

        return false;
    }

    case PLUGINGUI_REGISTER_SUBCONTROLLER:
    case PLUGINGUI_QUERY_HASUSERCUSTOM:
    case PLUGINGUI_USER_CUSTOMOPEN:
    case PLUGINGUI_USER_CUSTOMCLOSE:
    case PLUGINGUI_EXTERNAL_SET_NORMVALUE:
    case PLUGINGUI_EXTERNAL_SET_ACTUALVALUE: {

        return false;
    }

    default:
        break;
    }

    return false; /// not handled
}


/**
\brief process a MIDI event

NOTES:
- MIDI events are 100% sample accurate; this function will be called repeatedly for every MIDI message
- see the SDK for examples of use

\param event a structure containing the MIDI event data

\return true if operation succeeds, false otherwise
*/
bool PluginCore::processMIDIEvent(midiEvent& event) {
    return true;
}

/**
\brief (for future use)

NOTES:
- MIDI events are 100% sample accurate; this function will be called repeatedly for every MIDI message
- see the SDK for examples of use

\param vectorJoysickData a structure containing joystick data

\return true if operation succeeds, false otherwise
*/
bool PluginCore::setVectorJoystickParameters(const VectorJoystickData& vectorJoysickData) {
    return true;
}

/**
\brief use this method to add new presets to the list

NOTES:
- see the SDK for examples of use
- for non RackAFX users that have large paramter counts, there is a secret GUI control you
  can enable to write C++ code into text files, one per preset. See the SDK or http://www.willpirkle.com for details

\return true if operation succeeds, false otherwise
*/
bool PluginCore::initPluginPresets() {
    // **--0xFF7A--**

    // **--0xA7FF--**

    return true;
}

/**
\brief setup the plugin description strings, flags and codes; this is ordinarily done through the ASPiKreator or CMake

\return true if operation succeeds, false otherwise
*/
bool PluginCore::initPluginDescriptors() {
    pluginDescriptor.pluginName = PluginCore::getPluginName();
    pluginDescriptor.shortPluginName = PluginCore::getShortPluginName();
    pluginDescriptor.vendorName = PluginCore::getVendorName();
    pluginDescriptor.pluginTypeCode = PluginCore::getPluginType();

    // --- describe the plugin attributes; set according to your needs
    pluginDescriptor.hasSidechain = kWantSidechain;
    pluginDescriptor.latencyInSamples = kLatencyInSamples;
    pluginDescriptor.tailTimeInMSec = kTailTimeMsec;
    pluginDescriptor.infiniteTailVST3 = kVSTInfiniteTail;

    // --- AAX
    apiSpecificInfo.aaxManufacturerID = kManufacturerID;
    apiSpecificInfo.aaxProductID = kAAXProductID;
    apiSpecificInfo.aaxBundleID = kAAXBundleID;  /* MacOS only: this MUST match the bundle identifier in your info.plist file */
    apiSpecificInfo.aaxEffectID = "aaxDeveloper.";
    apiSpecificInfo.aaxEffectID.append(PluginCore::getPluginName());
    apiSpecificInfo.aaxPluginCategoryCode = kAAXCategory;

    // --- AU
    apiSpecificInfo.auBundleID = kAUBundleID;   /* MacOS only: this MUST match the bundle identifier in your info.plist file */
    apiSpecificInfo.auBundleName = kAUBundleName;

    // --- VST3
    apiSpecificInfo.vst3FUID = PluginCore::getVSTFUID(); // OLE string format
    apiSpecificInfo.vst3BundleID = kVST3BundleID;/* MacOS only: this MUST match the bundle identifier in your info.plist file */
    apiSpecificInfo.enableVST3SampleAccurateAutomation = kVSTSAA;
    apiSpecificInfo.vst3SampleAccurateGranularity = kVST3SAAGranularity;

    // --- AU and AAX
    apiSpecificInfo.fourCharCode = PluginCore::getFourCharCode();

    return true;
}

// --- static functions required for VST3/AU only --------------------------------------------- //
const char* PluginCore::getPluginBundleName() {
    return kAUBundleName;
}
const char* PluginCore::getPluginName() {
    return kPluginName;
}
const char* PluginCore::getShortPluginName() {
    return kShortPluginName;
}
const char* PluginCore::getVendorName() {
    return kVendorName;
}
const char* PluginCore::getVendorURL() {
    return kVendorURL;
}
const char* PluginCore::getVendorEmail() {
    return kVendorEmail;
}
const char* PluginCore::getAUCocoaViewFactoryName() {
    return AU_COCOA_VIEWFACTORY_STRING;
}
pluginType PluginCore::getPluginType() {
    return kPluginType;
}
const char* PluginCore::getVSTFUID() {
    return kVSTFUID;
}
int32_t PluginCore::getFourCharCode() {
    return kFourCharCode;
}

void PluginCore::updateParameters() {
    // update filter with gui parameters
    FilterParameters filterParams = filter1.getParameters();
    
    // alter the parameter values
    filterParams.fc = filterFC_Hz1;
    filterParams.Q = filterQ1;
    filterParams.boost = boostCut_dB1;
    filterParams.type = convertIntToEnum(filterType1, FilterType);
    
    // set on objects
    filter1.setParameters(filterParams);    
    
    filterParams = filter2.getParameters();
    filterParams.fc = filterFC_Hz2;
    filterParams.Q = filterQ2;
    filterParams.boost = boostCut_dB2;
    filterParams.type = convertIntToEnum(filterType2, FilterType);
    filter2.setParameters(filterParams);

    filterParams = filter3.getParameters();
    filterParams.fc = filterFC_Hz3;
    filterParams.Q = filterQ3;
    filterParams.boost = boostCut_dB3;
    filterParams.type = convertIntToEnum(filterType3, FilterType);
    filter3.setParameters(filterParams);

    filterParams = filter4.getParameters();
    filterParams.fc = filterFC_Hz4;
    filterParams.Q = filterQ4;
    filterParams.boost = boostCut_dB4;
    filterParams.type = convertIntToEnum(filterType4, FilterType);
    filter4.setParameters(filterParams);

    filterParams = filter5.getParameters();
    filterParams.fc = filterFC_Hz5;
    filterParams.Q = filterQ5;
    filterParams.boost = boostCut_dB5;
    filterParams.type = convertIntToEnum(filterType5, FilterType);
    filter5.setParameters(filterParams);

    filterParams = filter6.getParameters();
    filterParams.fc = filterFC_Hz6;
    filterParams.Q = filterQ6;
    filterParams.boost = boostCut_dB6;
    filterParams.type = convertIntToEnum(filterType6, FilterType);
    filter6.setParameters(filterParams);

    filterParams = filter7.getParameters();
    filterParams.fc = filterFC_Hz7;
    filterParams.Q = filterQ7;
    filterParams.boost = boostCut_dB7;
    filterParams.type = convertIntToEnum(filterType7, FilterType);
    filter7.setParameters(filterParams);
}

