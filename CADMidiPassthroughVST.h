//
//  CADMidiPassthroughVST.h
//  CADMidiPassthroughVST
//
//  Created by Andrew Capon on 20/08/2018.
//  Copyright © 2018 Ctrl Alt Delete Ltd. All rights reserved.
//

#ifndef CADMidiPassthroughVST_h
#define CADMidiPassthroughVST_h

#include "audioeffectx.h"

class CADMidiPassthroughVST : public AudioEffectX
{
public:
  CADMidiPassthroughVST(audioMasterCallback audioMaster, VstInt32 numPrograms, VstInt32 numParams);
  virtual ~CADMidiPassthroughVST();
  
  
  virtual VstInt32  getNumMidiInputChannels ()
  {
    return 16;
  }
  
  virtual VstInt32  getNumMidiOutputChannels ()
  {
    return 16;
  }
  
  
  virtual bool      getVendorString (char* text);
  virtual bool      getProductString (char* text);
  virtual VstInt32  getVendorVersion ();
  virtual bool      getEffectName (char* name);


  virtual VstInt32  processEvents(VstEvents* events);
  virtual void      process(float **inputs, float **outputs, VstInt32 sampleFrames);
  virtual void      processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames);
  virtual void      processDoubleReplacing(double** inputs, double** outputs, VstInt32 sampleFrames);

  virtual VstInt32  canDo (char* text);
  


private:
  float             m_fPBRatio;
};

#endif /* CADMidiPassthroughVST_hh */
