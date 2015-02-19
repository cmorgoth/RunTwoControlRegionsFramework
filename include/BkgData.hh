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
  BkgData();
  BkgData( bool isData );
  
  //BkgData( float*, float* );
  //BkgData( float*, float* , TString box_name );
  //Destructor
  ~BkgData();
  //Methods
  bool Loop();
  bool SetPuHisto();
  double GetPileUpW( float pu );
  
  //pileup filename
  TString puFname;
  
private:
  bool _debug;
  bool _info;
  bool _isData;
  
  TH1F* pileup;
    
};

#endif
