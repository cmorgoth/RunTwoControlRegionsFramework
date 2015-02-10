//C++ INCLUDE
#include <iostream>
#include <vector>
#include <map>
//ROOT INCLUDE

//LOCAL INCLUDE
#include "ControlSampleEvents.hh"
#include "BoxStructure.hh"
#include "BkgData.hh"

const int n_mr = 200;
const float mr_l = 0.0;
const float mr_h = 3500.0;

const int n_rsq = 200;
const float rsq_l = 0.0;
const float rsq_h = 2.50;

const int n_dilepton_mass = 50;
const float dilepton_mass_l = 0.0;
const float dilepton_mass_h = 200.0;

const int n_mt1lep = 50;
const float mt1lep_l = 0.0;
const float mt1lep_h = 200.0;

int main( )
{
  //DY
  BkgData* DY = new BkgData( );
  DY->CSE = new ControlSampleEvents( );
  DY->CSE->LoadChain("InputFiles/DY_Jets_Normalized.txt");
  
  DY->MuMu = new BoxStructure( "DY_MuMu" );
  DY->MuMu->SetMrBinning( n_mr, mr_l, mr_h );
  DY->MuMu->CreateMr();
  DY->MuMu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  DY->MuMu->CreateRsq();
  DY->MuMu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
				      dilepton_mass_h );
  DY->MuMu->CreateMassTwoLeptons();
  DY->MuMu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  DY->MuMu->CreateOneLepMT();
    
  DY->EleEle = new BoxStructure( "DY_EleEle" );
  DY->EleEle->SetMrBinning( n_mr, mr_l, mr_h );
  DY->EleEle->CreateMr();
  DY->EleEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  DY->EleEle->CreateRsq();
  DY->EleEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
					dilepton_mass_h );
  DY->EleEle->CreateMassTwoLeptons();
  DY->EleEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  DY->EleEle->CreateOneLepMT();
  
  DY->MuEle = new BoxStructure( "DY_MuEle" );
  DY->MuEle->SetMrBinning( n_mr, mr_l, mr_h );
  DY->MuEle->CreateMr();
  DY->MuEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  DY->MuEle->CreateRsq();
  DY->MuEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
				       dilepton_mass_h );
  DY->MuEle->CreateMassTwoLeptons();
  DY->MuEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  DY->MuEle->CreateOneLepMT();

  //SingleMu
  DY->Mu = new BoxStructure( "DY_SingleMu" );
  DY->Mu->SetMrBinning( n_mr, mr_l, mr_h );
  DY->Mu->CreateMr();
  DY->Mu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  DY->Mu->CreateRsq();
  DY->Mu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
                                       dilepton_mass_h );
  DY->Mu->CreateMassTwoLeptons();
  DY->Mu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  DY->Mu->CreateOneLepMT();

  //SingleEle
  DY->Ele = new BoxStructure( "DY_SingleEle" );
  DY->Ele->SetMrBinning( n_mr, mr_l, mr_h );
  DY->Ele->CreateMr();
  DY->Ele->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  DY->Ele->CreateRsq();
  DY->Ele->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
                                       dilepton_mass_h );
  DY->Ele->CreateMassTwoLeptons();
  DY->Ele->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  DY->Ele->CreateOneLepMT();

  DY->Loop( );
  
  //W                                                        
  BkgData* W = new BkgData( );
  W->CSE = new ControlSampleEvents( );
  W->CSE->LoadChain("InputFiles/W_Jets_Normalized.txt");

  W->MuMu = new BoxStructure( "W_MuMu" );
  W->MuMu->SetMrBinning( n_mr, mr_l, mr_h );
  W->MuMu->CreateMr();
  W->MuMu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  W->MuMu->CreateRsq();
  W->MuMu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
				     dilepton_mass_h );
  W->MuMu->CreateMassTwoLeptons();
  W->MuMu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  W->MuMu->CreateOneLepMT();

  W->EleEle = new BoxStructure( "W_EleEle" );
  W->EleEle->SetMrBinning( n_mr, mr_l, mr_h );
  W->EleEle->CreateMr();
  W->EleEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  W->EleEle->CreateRsq();
  W->EleEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
				       dilepton_mass_h );
  W->EleEle->CreateMassTwoLeptons();
  W->EleEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  W->EleEle->CreateOneLepMT();

  //MuEle
  W->MuEle = new BoxStructure( "W_MuEle" );
  W->MuEle->SetMrBinning( n_mr, mr_l, mr_h );
  W->MuEle->CreateMr();
  W->MuEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  W->MuEle->CreateRsq();
  W->MuEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
				      dilepton_mass_h );
  W->MuEle->CreateMassTwoLeptons();
  W->MuEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  W->MuEle->CreateOneLepMT();

  //SingleMu
  W->Mu = new BoxStructure( "W_SingleMu" );
  W->Mu->SetMrBinning( n_mr, mr_l, mr_h );
  W->Mu->CreateMr();
  W->Mu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  W->Mu->CreateRsq();
  W->Mu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
                                      dilepton_mass_h );
  W->Mu->CreateMassTwoLeptons();
  W->Mu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  W->Mu->CreateOneLepMT();
  
  //SingleEle
  W->Ele = new BoxStructure( "W_SingleEle" );
  W->Ele->SetMrBinning( n_mr, mr_l, mr_h );
  W->Ele->CreateMr();
  W->Ele->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  W->Ele->CreateRsq();
  W->Ele->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
                                      dilepton_mass_h );
  W->Ele->CreateMassTwoLeptons();
  W->Ele->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  W->Ele->CreateOneLepMT();

  W->Loop( );
  
  //TT
  BkgData* TT = new BkgData( );
  TT->CSE = new ControlSampleEvents( );
  TT->CSE->LoadChain("InputFiles/TT_Jets_Normalized.txt");

  TT->MuMu = new BoxStructure( "TT_MuMu" );
  TT->MuMu->SetMrBinning( n_mr, mr_l, mr_h );
  TT->MuMu->CreateMr();
  TT->MuMu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  TT->MuMu->CreateRsq();
  TT->MuMu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
				      dilepton_mass_h );
  TT->MuMu->CreateMassTwoLeptons();
  TT->MuMu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  TT->MuMu->CreateOneLepMT();
  
  TT->EleEle = new BoxStructure( "TT_EleEle" );
  TT->EleEle->SetMrBinning( n_mr, mr_l, mr_h );
  TT->EleEle->CreateMr();
  TT->EleEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  TT->EleEle->CreateRsq();
  TT->EleEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
					dilepton_mass_h );
  TT->EleEle->CreateMassTwoLeptons();
  TT->EleEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  TT->EleEle->CreateOneLepMT();
  
  TT->MuEle = new BoxStructure( "TT_MuEle" );
  TT->MuEle->SetMrBinning( n_mr, mr_l, mr_h );
  TT->MuEle->CreateMr();
  TT->MuEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  TT->MuEle->CreateRsq();
  TT->MuEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
				       dilepton_mass_h );
  TT->MuEle->CreateMassTwoLeptons();
  TT->MuEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  TT->MuEle->CreateOneLepMT();

  //SingleMu
  TT->Mu = new BoxStructure( "TT_SingleMu" );
  TT->Mu->SetMrBinning( n_mr, mr_l, mr_h );
  TT->Mu->CreateMr();
  TT->Mu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  TT->Mu->CreateRsq();
  TT->Mu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
                                       dilepton_mass_h );
  TT->Mu->CreateMassTwoLeptons();
  TT->Mu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  TT->Mu->CreateOneLepMT();
  
  //SingleEle
  TT->Ele = new BoxStructure( "TT_SingleEle" );
  TT->Ele->SetMrBinning( n_mr, mr_l, mr_h );
  TT->Ele->CreateMr();
  TT->Ele->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  TT->Ele->CreateRsq();
  TT->Ele->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
                                       dilepton_mass_h );
  TT->Ele->CreateMassTwoLeptons();
  TT->Ele->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  TT->Ele->CreateOneLepMT();
  
  TT->Loop( );

  //Data                                                      
  BkgData* Data = new BkgData( );
  Data->CSE = new ControlSampleEvents( );
  Data->CSE->LoadChain("InputFiles/Data_Jets_Normalized.txt");

  Data->MuMu = new BoxStructure( "Data_MuMu" );
  Data->MuMu->SetMrBinning( n_mr, mr_l, mr_h );
  Data->MuMu->CreateMr();
  Data->MuMu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  Data->MuMu->CreateRsq();
  Data->MuMu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l, dilepton_mass_h );
  Data->MuMu->CreateMassTwoLeptons();
  Data->MuMu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  Data->MuMu->CreateOneLepMT();

  Data->EleEle = new BoxStructure( "Data_EleEle" );
  Data->EleEle->SetMrBinning( n_mr, mr_l, mr_h );
  Data->EleEle->CreateMr();
  Data->EleEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  Data->EleEle->CreateRsq();
  Data->EleEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l, dilepton_mass_h );
  Data->EleEle->CreateMassTwoLeptons();
  Data->EleEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  Data->EleEle->CreateOneLepMT();
  
  Data->MuEle = new BoxStructure( "Data_MuEle" );
  Data->MuEle->SetMrBinning( n_mr, mr_l, mr_h );
  Data->MuEle->CreateMr();
  Data->MuEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  Data->MuEle->CreateRsq();
  Data->MuEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l, 
					 dilepton_mass_h );
  Data->MuEle->CreateMassTwoLeptons();
  Data->MuEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  Data->MuEle->CreateOneLepMT();

  //SinleMu
  Data->Mu = new BoxStructure( "Data_SingleMu" );
  Data->Mu->SetMrBinning( n_mr, mr_l, mr_h );
  Data->Mu->CreateMr();
  Data->Mu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  Data->Mu->CreateRsq();
  Data->Mu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
					 dilepton_mass_h );
  Data->Mu->CreateMassTwoLeptons();
  Data->Mu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  Data->Mu->CreateOneLepMT();
  
  //SingleEle
  Data->Ele = new BoxStructure( "Data_SingleEle" );
  Data->Ele->SetMrBinning( n_mr, mr_l, mr_h );
  Data->Ele->CreateMr();
  Data->Ele->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  Data->Ele->CreateRsq();
  Data->Ele->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l, 
					 dilepton_mass_h );
  Data->Ele->CreateMassTwoLeptons();
  Data->Ele->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  Data->Ele->CreateOneLepMT();

  Data->Loop( );
  
  TFile* fout = new TFile("TEST_SingleLepton.root", "RECREATE");
  DY->MuMu->h_mr->Write();
  DY->MuMu->h_rsq->Write();
  DY->MuMu->h_mass_twoleptons->Write();
  DY->MuMu->h_mt_1lep->Write();
  W->MuMu->h_mr->Write();
  W->MuMu->h_rsq->Write();
  W->MuMu->h_mass_twoleptons->Write();
  W->MuMu->h_mt_1lep->Write();
  TT->MuMu->h_mr->Write();
  TT->MuMu->h_rsq->Write();
  TT->MuMu->h_mass_twoleptons->Write();
  TT->MuMu->h_mt_1lep->Write();
  Data->MuMu->h_mr->Write();
  Data->MuMu->h_rsq->Write();
  Data->MuMu->h_mass_twoleptons->Write();
  Data->MuMu->h_mt_1lep->Write();
  

  DY->EleEle->h_mr->Write();
  DY->EleEle->h_rsq->Write();
  DY->EleEle->h_mass_twoleptons->Write();
  DY->EleEle->h_mt_1lep->Write();
  W->EleEle->h_mr->Write();
  W->EleEle->h_rsq->Write();
  W->EleEle->h_mass_twoleptons->Write();
  W->EleEle->h_mt_1lep->Write();
  TT->EleEle->h_mr->Write();
  TT->EleEle->h_rsq->Write();
  TT->EleEle->h_mass_twoleptons->Write();
  TT->EleEle->h_mt_1lep->Write();
  Data->EleEle->h_mr->Write();
  Data->EleEle->h_rsq->Write();
  Data->EleEle->h_mass_twoleptons->Write();
  Data->EleEle->h_mt_1lep->Write();
  
  DY->MuEle->h_mr->Write();
  DY->MuEle->h_rsq->Write();
  DY->MuEle->h_mass_twoleptons->Write();
  DY->MuEle->h_mt_1lep->Write();
  W->MuEle->h_mr->Write();
  W->MuEle->h_rsq->Write();
  W->MuEle->h_mass_twoleptons->Write();
  W->MuEle->h_mt_1lep->Write();
  TT->MuEle->h_mr->Write();
  TT->MuEle->h_rsq->Write();
  TT->MuEle->h_mass_twoleptons->Write();
  TT->MuEle->h_mt_1lep->Write();
  Data->MuEle->h_mr->Write();
  Data->MuEle->h_rsq->Write();
  Data->MuEle->h_mass_twoleptons->Write();
  Data->MuEle->h_mt_1lep->Write();

  //SingleMu
  DY->Mu->h_mr->Write();
  DY->Mu->h_rsq->Write();
  DY->Mu->h_mass_twoleptons->Write();
  DY->Mu->h_mt_1lep->Write();
  W->Mu->h_mr->Write();
  W->Mu->h_rsq->Write();
  W->Mu->h_mass_twoleptons->Write();
  W->Mu->h_mt_1lep->Write();
  TT->Mu->h_mr->Write();
  TT->Mu->h_rsq->Write();
  TT->Mu->h_mass_twoleptons->Write();
  TT->Mu->h_mt_1lep->Write();
  Data->Mu->h_mr->Write();
  Data->Mu->h_rsq->Write();
  Data->Mu->h_mass_twoleptons->Write();
  Data->Mu->h_mt_1lep->Write();

  //SingleEle
  DY->Ele->h_mr->Write();
  DY->Ele->h_rsq->Write();
  DY->Ele->h_mass_twoleptons->Write();
  DY->Ele->h_mt_1lep->Write();
  W->Ele->h_mr->Write();
  W->Ele->h_rsq->Write();
  W->Ele->h_mass_twoleptons->Write();
  W->Ele->h_mt_1lep->Write();
  TT->Ele->h_mr->Write();
  TT->Ele->h_rsq->Write();
  TT->Ele->h_mass_twoleptons->Write();
  TT->Ele->h_mt_1lep->Write();
  Data->Ele->h_mr->Write();
  Data->Ele->h_rsq->Write();
  Data->Ele->h_mass_twoleptons->Write();
  Data->Ele->h_mt_1lep->Write();
  
  fout->Close();
  
  return 0;
}
