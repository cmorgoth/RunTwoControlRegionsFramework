#ifndef NormalizeMC_HH
#define NormalizeMC_HH

//C++ INCLUDES
#include <iostream>
//ROOT INCLUDES
#include "TFile.h"
#include "TTree.h"
//LOCAL INCLUDES

void NormalizeTree( TTree* tree, float xsec, float Lumi, float kfactor,
		    float ngen, TString foutName );
double GetNgen( TTree* effTree );

#endif
