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

class BkgData
{
public:
  //
  BoxStructure* TwoMuon;
  
  //Constructor
  BkgData(){};
  
  //BkgData( float*, float* );
  //BkgData( float*, float* , TString box_name );
  //Destructor
  ~BkgData();
  //Methods
  
  
private:
  bool _debug;
  bool _info;
    
};

#endif
