//C++ INCLUDES
#include <iostream>
//ROOT INCLUDES
//LOCAL INCLUDES
#include "BkgData.hh"

bool BkgData::Loop()
{
  unsigned int  nentries = CSE->tree_->GetEntries();
  std::cout << "[INFO]: Total Entries " << nentries << std::endl;
  for( unsigned int ientry = 0; ientry < CSE->tree_->GetEntries(); ientry++) {       
    CSE->tree_->GetEntry(ientry);
    if (ientry % 100000 == 0) std::cout << "[INFO]: Event " << ientry << std::endl;
    
    //MuMu
    if( abs( CSE->lep1Type ) == 13 && abs( CSE->lep2Type ) == 13 )
      {
	MuMu->FillMr( CSE->MR, CSE->xs_w_kf );
	MuMu->FillRsq( CSE->Rsq, CSE->xs_w_kf );
      }
    
    //EleEle
    if( abs( CSE->lep1Type ) == 11 && abs( CSE->lep2Type ) == 11)
      {
        EleEle->FillMr( CSE->MR, CSE->xs_w_kf );
        EleEle->FillRsq( CSE->Rsq, CSE->xs_w_kf );
      }
    
    //MuEle                                                                              
    if( ( abs( CSE->lep1Type ) == 11 && abs( CSE->lep2Type ) == 13 )  || 
	( abs( CSE->lep1Type ) == 13 && abs( CSE->lep2Type ) == 11 ) )
      {
        MuEle->FillMr( CSE->MR, CSE->xs_w_kf );
        MuEle->FillRsq( CSE->Rsq, CSE->xs_w_kf );
      }
    
  }
};
