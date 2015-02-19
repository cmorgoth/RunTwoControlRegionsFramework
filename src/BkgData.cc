//C++ INCLUDES
#include <iostream>
#include <stdlib.h>
//ROOT INCLUDES
//LOCAL INCLUDES
#include "BkgData.hh"

BkgData::BkgData(){
  _isData = false;
  pileup = NULL;
  puFname = "";
  //SetPuHisto();
};

BkgData::BkgData( bool isData ){
  _isData = isData;
};

bool BkgData::SetPuHisto()
{
  if ( puFname != "" )
    {
      TFile f( puFname );
      pileup = (TH1F*)f.Get("pileup");
      f.Close();
    }
};

double BkgData::GetPileUpW( float pu )
{
  if( pileup != NULL )return pileup->GetBinContent( pileup->FindBin( pu ) );
  return 1.0;
}

bool BkgData::Loop()
{
  unsigned int  nentries = CSE->tree_->GetEntries();
  std::cout << "[INFO]: Total Entries " << nentries << std::endl;
  for( unsigned int ientry = 0; ientry < CSE->tree_->GetEntries(); ientry++) {       
    CSE->tree_->GetEntry(ientry);
    if (ientry % 100000 == 0) std::cout << "[INFO]: Event " << ientry << std::endl;
    double mass = -99.;
    
    double w = -1.0 ;//lumi event weight
    if ( _isData )
      {
	w = 1.0;
      }
    else
      {
	w = GetPileUpW( CSE->NPU_0 )*CSE->xs_w_kf;//NNLO
	//w = GetPileUpW( CSE->NPU_0 )*CSE->xs_w;//LO
      }
    //std::cout << "MET: " << CSE->MET << std::endl;
    //Baseline Selection
    //if ( CSE->NJets80 < 2 ) continue;
    //if ( CSE->MR < 200.0  || CSE->Rsq < 0.1 ) continue;
    //if ( CSE->HT < 200 ) continue; 
    if ( CSE->MET < 40.0 ) continue;

    //MuMu
    if( abs( CSE->lep1Type ) == 13 && abs( CSE->lep2Type ) == 13
	&& ( CSE->lep1PassLoose == 1  && CSE->lep2PassLoose == 1 )
	/*&& CSE->NBJetsLoose == 0*/ )
      {
	mass  = (CSE->lep1 + CSE->lep2).M();
	MuMu->FillMr( CSE->MR, w );
	MuMu->FillRsq( CSE->Rsq, w );
	MuMu->FillMassTwoLeptons( mass, w );
	MuMu->FillOneLepMT( CSE->lep1MT, w );
	MuMu->FillHT( CSE->HT, w );
      }
    
    //EleEle
    if( abs( CSE->lep1Type ) == 11 && abs( CSE->lep2Type ) == 11
	&& ( CSE->lep1PassLoose == 1  && CSE->lep2PassLoose == 1 )
	&& CSE->NBJetsLoose == 0 )
      {
	mass  = (CSE->lep1 + CSE->lep2).M();
        EleEle->FillMr( CSE->MR, w );
        EleEle->FillRsq( CSE->Rsq, w );
	EleEle->FillMassTwoLeptons( mass, w );
	EleEle->FillOneLepMT( CSE->lep1MT, w );
	EleEle->FillHT( CSE->HT, w );
      }
    
    //MuEle                                                                              
    if( ( abs( CSE->lep1Type ) == 11 && abs( CSE->lep2Type ) == 13 )
	|| ( abs( CSE->lep1Type ) == 13 && abs( CSE->lep2Type ) == 11 ) 
	&& ( CSE->lep1PassLoose == 1  && CSE->lep2PassLoose == 1 )
	&& CSE->NBJetsMedium > 1 )
      {
	mass  = (CSE->lep1 + CSE->lep2).M();
	if ( mass > 60.0  
	     && ( CSE->lep1.Pt() > 22.0 && CSE->lep2.Pt() > 22.0 )
	     )
	  {
	    //std::cout << "mass: " << mass << std::endl;
	    MuEle->FillMr( CSE->MR, w );
	    MuEle->FillRsq( CSE->Rsq, w );
	    MuEle->FillMassTwoLeptons( mass, w );
	    MuEle->FillOneLepMT( CSE->lep1MT, w );
	    MuEle->FillHT( CSE->HT, w );
	  }
      }

    //SingleMu                                                                        
    if( abs( CSE->lep1Type ) == 13  && CSE->lep1PassTight == 1
	&& CSE->lep1.Pt() > 30  && CSE->NBJetsMedium > 0 
	&& ( CSE->lep1MT > 30.0 && CSE->lep1MT < 100.0 ) )
      {
	mass  = (CSE->lep1 + CSE->lep2).M();
	if ( CSE->lep2PassLoose == 0 )
	  {
	    Mu->FillMr( CSE->MR, w );
	    Mu->FillRsq( CSE->Rsq, w );
	    Mu->FillMassTwoLeptons( mass, w );
	    Mu->FillOneLepMT( CSE->lep1MT, w );
	    Mu->FillHT( CSE->HT, w );
	  }
	else if ( CSE->lep2PassLoose == 1  && ( mass > 66.0 && mass < 116 ) ) 
	  {
	    Mu->FillMr( CSE->MR, w );
	    Mu->FillRsq( CSE->Rsq, w );
	    Mu->FillMassTwoLeptons( mass, w );
	    Mu->FillOneLepMT( CSE->lep1MT, w );
	    Mu->FillHT( CSE->HT, w );
	  }
	
      }//end singleMu
    
    //SingleEle                                                                            
    if( abs( CSE->lep1Type ) == 11  && CSE->lep1PassTight == 1
	&& CSE->lep1.Pt() > 30  && CSE->NBJetsMedium > 0 
	&& ( CSE->lep1MT > 30.0 && CSE->lep1MT < 100.0 ) )
      {
	mass  = (CSE->lep1 + CSE->lep2).M();
        if ( CSE->lep2PassLoose == 0 )
          {
            Ele->FillMr( CSE->MR, w );
            Ele->FillRsq( CSE->Rsq, w );
            Ele->FillMassTwoLeptons( mass, w );
            Ele->FillOneLepMT( CSE->lep1MT, w );
	    Ele->FillHT( CSE->HT, w );
          }
        else if ( CSE->lep2PassLoose == 1  && ( mass > 66.0 && mass < 116 ) )
          {
	    Ele->FillMr( CSE->MR, w );
            Ele->FillRsq( CSE->Rsq, w );
            Ele->FillMassTwoLeptons( mass, w );
            Ele->FillOneLepMT( CSE->lep1MT, w );
	    Ele->FillHT( CSE->HT, w );
          }
      }//end singleEle
    
  }//end loop
};
