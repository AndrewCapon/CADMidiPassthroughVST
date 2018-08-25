//
//  CADMidiPassthroughVST.cpp
//  CADMidiPassthroughVST
//
//  Created by Andrew Capon on 20/08/2018.
//  Copyright © 2018 Ctrl Alt Delete Ltd. All rights reserved.
//
#include <stdio.h>

#include "CADMidiPassthroughVST.h"


AudioEffect* createEffectInstance (audioMasterCallback audioMaster)
{
  CADMidiPassthroughVST *pInstance = new CADMidiPassthroughVST(audioMaster,0,1);
  return pInstance;
}


CADMidiPassthroughVST::CADMidiPassthroughVST(audioMasterCallback audioMaster, VstInt32 numPrograms, VstInt32 numParams)
: AudioEffectX(audioMaster, 0, 0)
{
  setNumInputs(0);
  setNumOutputs(0);
  
  isSynth();
  
  setUniqueID ('Cmpt');
}

CADMidiPassthroughVST::~CADMidiPassthroughVST()
{
  
}


VstInt32 CADMidiPassthroughVST::canDo (char* text)
{
  int result = ((0==strcmp (text, "sendVstMidiEvent")) ||
                (0==strcmp (text, "receiveVstMidiEvent")) ||
                (0==strcmp (text, "sendVstEvents")) ||
                (0==strcmp (text, "receiveVstEvents")) ||
                (0==strcmp (text, "MPE")));

  return result;
}





///////////////////////////////////////////////////////////////////////////
// VST Strings
///////////////////////////////////////////////////////////////////////////

bool CADMidiPassthroughVST::getVendorString (char* text)
{
  vst_strncpy(text, "CAD Ltd.", kVstMaxVendorStrLen);
  return true;
}

bool CADMidiPassthroughVST::getProductString (char* text)
{
  vst_strncpy(text, "Midi Passthrough", kVstMaxProductStrLen);
  return true;
}

bool CADMidiPassthroughVST::getEffectName (char* name)
{
  vst_strncpy(name, "Midi Passthrough", kVstMaxEffectNameLen);
  return true;
}

VstInt32 CADMidiPassthroughVST::getVendorVersion ()
{
  return 0x10000;
}



///////////////////////////////////////////////////////////////////////////
// Processing
///////////////////////////////////////////////////////////////////////////

VstInt32  CADMidiPassthroughVST::processEvents(VstEvents* events)
{
  return sendVstEventsToHost (events);
}

void CADMidiPassthroughVST::process(float **inputs, float **outputs, VstInt32 sampleFrames)
{
}

void CADMidiPassthroughVST::processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames)
{
}

void CADMidiPassthroughVST::processDoubleReplacing(double** inputs, double** outputs, VstInt32 sampleFrames)
{
}

