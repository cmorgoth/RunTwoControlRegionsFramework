//C++ INCLUDES
#include <iostream>
#include <fstream>
//ROOT INCLUDES
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
//LOCAL INCLUDES
#include "NormalizeMC.hh"

bool _info = false;
bool _debug = true;
TString SaveDir = "/wntmp/cmorgoth/";
//float Lumi = 18.84;//fb-1

int main(){
  
  //std::ifstream mcFile ("InputFiles/NormalizeInput.txt");
  //std::ifstream mcFile ("InputFiles/NormalizeInputTTJets.txt");
  std::ifstream mcFile ("InputFiles/NormalizeInputData.txt");
  std::string fname;
  TString OutName;
  TString InName;
  float xsec, kfactor;
  if ( mcFile.is_open() )
    {
      getline ( mcFile, fname );//read first line
      while ( mcFile.good() )
	{
	  mcFile >> fname >> xsec >> kfactor;
	  InName = fname.c_str();
	  if( _info == true ) std::cout << fname << " " << xsec << " "  
					<< kfactor << std::endl;  
	  int lp = fname.find_last_of("/") + 1;
	  int hp = fname.find(".root") - lp;
	  OutName = SaveDir + fname.substr( lp, hp ) + "_Normalized.root";
	  if ( _debug == true )
	    {
	      std::cout << fname.substr( lp, hp ) << std::endl;
	      std::cout << OutName << std::endl;
	    }
	  
	  TFile* f = new TFile( InName );
	  
	  //TTree* eff = (TTree*)f->Get("effTree");
	  //float ngen = GetNgen( eff );
	  //std::cout << "NGEN: " << ngen << std::endl;
	  TTree* tree = (TTree*)f->Get("ControlSampleEvent");
	  
	  //xsec in lumi have to have the same units
	  xsec = xsec*1000.0;//Scaling to fb
	  //NormalizeTree( tree, xsec, Lumi, kfactor, ngen, OutName );
	  NormalizeTree( tree, 1.0, 1.0, 1.0, 1.0, OutName );
	}//while loop
    }
  else
    {
      std::cerr << "[ERROR]: Unable to Read File: " << std::endl;
    }
  
  return 0;
}
