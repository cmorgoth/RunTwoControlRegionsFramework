#ifndef BkgData_HH
#define BkgData_HH

//C++ INCLUDES
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>

//ROOT INCLUDES
#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TString.h"

//LOCAL INCLUDES
#include "BoxStructure.hh"
#include "ControlSampleEvents.hh"
class BkgData
{
public:
  //tree
  ControlSampleEvents* CSE;
  //
  BoxStructure* MuMu;
  BoxStructure* EleEle;
  BoxStructure* MuEle;
  
  BoxStructure* Mu;
  BoxStructure* Ele;
  
  //Constructor
  BkgData(){};
  
  //BkgData( float*, float* );
  //BkgData( float*, float* , TString box_name );
  //Destructor
  ~BkgData();
  //Methods
  bool Loop();
  
  
private:
  bool _debug;
  bool _info;
    
};

#endif
