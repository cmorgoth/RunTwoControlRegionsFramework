#ifndef BoxStructure_HH
#define BoxStructure_HH

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

class BoxStructure
{
public:
  //
  TH1F* h_mr;
  TH1F* h_rsq;
  TH1F* h_njet;
  TH1F* h_ht;
  //
  TH1F* h_mt_1lep;
  //
  TH1F* h_mass_twoleptons;
  
  //Constructor
  BoxStructure();

  BoxStructure( TString box_name );
  BoxStructure( float*, float* );
  BoxStructure( float*, float* , TString box_name );
  //Destructor
  ~BoxStructure();
  //Methods
  
  //Creating Histos
  void CreateHistos();
  void CreateMr();
  void CreateRsq();
  void CreateNjet();
  void CreateHT();
  void CreateOneLepMT();
  void CreateMassTwoLeptons();
  
  //Filling Histos
  void FillMr( float val, float weight );
  void FillRsq( float val, float weight );
  void FillNjet( float val, float weight );
  void FillHT( float val, float weight );
  void FillOneLepMT( float val, float weight );
  void FillMassTwoLeptons( float val, float weight );
  
  //Writing Histos to File
  void WriteMr( TFile* f );
  

  void InitVariables();
  void SetDebugLevel( bool debug );
  void SetInfoLevel( bool info );

  void SetMrBinning( int nbins, float*  bins );
  void SetMrBinning( int nbins, float xl, float xh );
  void SetRsqBinning( int nbins, float* bins );
  void SetRsqBinning( int nbins, float xl, float xh );
  
  void SetNjetBinning( int nbins, float xl, float xh );
  void SetHTBinning( int nbins, float xl, float xh );
  void SetMT1LepBinning( int nbins, float xl, float xh );
  void SetMassTwoLeptonsBinning( int nbins, float xl, float xh );
  
private:
  bool _debug;
  bool _info;
  TString box_name;
  
  //MR
  int _Mr_nbins;
  float _Mr_xl;
  float _Mr_xh;
  float* _Mr_binning;
  
  //RSQ
  int _Rsq_nbins;
  float _Rsq_xl;
  float _Rsq_xh;
  float* _Rsq_binning;
  
  //NJets
  int _Njet_nbins;
  float _Njet_xl;
  float _Njet_xh;
  
  //HT
  int _HT_nbins;
  float _HT_xl;
  float _HT_xh;
  
  //MT1Lep
  int _MT1Lep_nbins;
  float _MT1Lep_xl;
  float _MT1Lep_xh;
  
  //MinvTwoLeptons
  int _MassTwoLeptons_nbins;
  float _MassTwoLeptons_xl;
  float _MassTwoLeptons_xh;
  
};

#endif
