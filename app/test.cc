//C++ INCLUDE
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
//ROOT INCLUDE

//LOCAL INCLUDE
#include "ControlSampleEvents.hh"
#include "BoxStructure.hh"
#include "BkgData.hh"
#include "PlotCosmetics.hh"

const int n_mr = 100;
const float mr_l = -10.0;
const float mr_h = 3500.0;

const int n_rsq = 100;
const float rsq_l = 0.0;
const float rsq_h = 2.50;

const int n_dilepton_mass = 50;
const float dilepton_mass_l = 0.0;
const float dilepton_mass_h = 200.0;

const int n_mt1lep = 100;
const float mt1lep_l = 0.0;
const float mt1lep_h = 200.0;

const int n_ht = 50;
const int ht_l = 0.0;
const int ht_h = 2000.0;

int main( )
{
  time_t start, end, diff;
  start = time (NULL);
  //DY
  BkgData* DY = new BkgData( );
  DY->CSE = new ControlSampleEvents( );
  //DY->CSE->LoadChain("InputFiles/DY_Jets_Normalized.txt");
  DY->CSE->LoadChain("InputFiles/DY_Jets_Normalized_Inc.txt"); 
  DY->puFname = "/home/cmorgoth/RunTwo8TeV_Study/CMSSW_5_3_8/src/PileUpCorrection/DYJetsToLL_M-50_TuneZ2Star_All.root";
  
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
  DY->MuMu->SetHTBinning( n_ht, ht_l, ht_h );
  DY->MuMu->CreateHT();
    
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
  DY->EleEle->SetHTBinning( n_ht, ht_l, ht_h );
  DY->EleEle->CreateHT();
  
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
  DY->MuEle->SetHTBinning( n_ht, ht_l, ht_h );
  DY->MuEle->CreateHT();

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
  DY->Mu->SetHTBinning( n_ht, ht_l, ht_h );
  DY->Mu->CreateHT();

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
  DY->Ele->SetHTBinning( n_ht, ht_l, ht_h );
  DY->Ele->CreateHT();

  //W                                                        
  BkgData* W = new BkgData( );
  W->CSE = new ControlSampleEvents( );
  W->CSE->LoadChain("InputFiles/W_Jets_Normalized.txt");
  W->puFname = "/home/cmorgoth/RunTwo8TeV_Study/CMSSW_5_3_8/src/PileUpCorrection/Wpj_400_HT_inf.root";
  //W->CSE->InitUsedVariables();

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
  W->MuMu->SetHTBinning( n_ht, ht_l, ht_h );
  W->MuMu->CreateHT();

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
  W->EleEle->SetHTBinning( n_ht, ht_l, ht_h );
  W->EleEle->CreateHT();

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
  W->MuEle->SetHTBinning( n_ht, ht_l, ht_h );
  W->MuEle->CreateHT();

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
  W->Mu->SetHTBinning( n_ht, ht_l, ht_h );
  W->Mu->CreateHT();
  
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
  W->Ele->SetHTBinning( n_ht, ht_l, ht_h );
  W->Ele->CreateHT();

  //TT
  BkgData* TT = new BkgData( );
  TT->CSE = new ControlSampleEvents( );
  TT->CSE->LoadChain("InputFiles/TT_Jets_Normalized.txt");
  TT->puFname = "/home/cmorgoth/RunTwo8TeV_Study/CMSSW_5_3_8/src/PileUpCorrection/TTj_Semilep.root";
  //TT->CSE->InitUsedVariables();

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
  TT->MuMu->SetHTBinning( n_ht, ht_l, ht_h );
  TT->MuMu->CreateHT();
  
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
  TT->EleEle->SetHTBinning( n_ht, ht_l, ht_h );
  TT->EleEle->CreateHT();
  
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
  TT->MuEle->SetHTBinning( n_ht, ht_l, ht_h );
  TT->MuEle->CreateHT();

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
  TT->Mu->SetHTBinning( n_ht, ht_l, ht_h );
  TT->Mu->CreateHT();
  
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
  TT->Ele->SetHTBinning( n_ht, ht_l, ht_h );
  TT->Ele->CreateHT();
  
  //SinleTop
  BkgData* T = new BkgData( );
  T->CSE = new ControlSampleEvents( );
  T->CSE->LoadChain("InputFiles/T_Jets_Normalized.txt");
  //T->CSE->InitUsedVariables();

  T->MuMu = new BoxStructure( "T_MuMu" );
  T->MuMu->SetMrBinning( n_mr, mr_l, mr_h );
  T->MuMu->CreateMr();
  T->MuMu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  T->MuMu->CreateRsq();
  T->MuMu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
                                      dilepton_mass_h );
  T->MuMu->CreateMassTwoLeptons();
  T->MuMu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  T->MuMu->CreateOneLepMT();
  T->MuMu->SetHTBinning( n_ht, ht_l, ht_h );
  T->MuMu->CreateHT();
  //EleEle
  T->EleEle = new BoxStructure( "T_EleEle" );
  T->EleEle->SetMrBinning( n_mr, mr_l, mr_h );
  T->EleEle->CreateMr();
  T->EleEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  T->EleEle->CreateRsq();
  T->EleEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
                                        dilepton_mass_h );
  T->EleEle->CreateMassTwoLeptons();
  T->EleEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  T->EleEle->CreateOneLepMT();
  T->EleEle->SetHTBinning( n_ht, ht_l, ht_h );
  T->EleEle->CreateHT();
  //MuEle
  T->MuEle = new BoxStructure( "T_MuEle" );
  T->MuEle->SetMrBinning( n_mr, mr_l, mr_h );
  T->MuEle->CreateMr();
  T->MuEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  T->MuEle->CreateRsq();
  T->MuEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
                                       dilepton_mass_h );
  T->MuEle->CreateMassTwoLeptons();
  T->MuEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  T->MuEle->CreateOneLepMT();
  T->MuEle->SetHTBinning( n_ht, ht_l, ht_h );
  T->MuEle->CreateHT();
  //SingleMu                                                                              
  T->Mu = new BoxStructure( "T_SingleMu" );
  T->Mu->SetMrBinning( n_mr, mr_l, mr_h );
  T->Mu->CreateMr();
  T->Mu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  T->Mu->CreateRsq();
  T->Mu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
				    dilepton_mass_h );
  T->Mu->CreateMassTwoLeptons();
  T->Mu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  T->Mu->CreateOneLepMT();
  T->Mu->SetHTBinning( n_ht, ht_l, ht_h );
  T->Mu->CreateHT();
  //SingleEle                                                                                
  T->Ele = new BoxStructure( "T_SingleEle" );
  T->Ele->SetMrBinning( n_mr, mr_l, mr_h );
  T->Ele->CreateMr();
  T->Ele->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  T->Ele->CreateRsq();
  T->Ele->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l,
				     dilepton_mass_h );
  T->Ele->CreateMassTwoLeptons();
  T->Ele->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  T->Ele->CreateOneLepMT();
  T->Ele->SetHTBinning( n_ht, ht_l, ht_h );
  T->Ele->CreateHT();

  //Data                                                      
  BkgData* Data = new BkgData( true );
  Data->CSE = new ControlSampleEvents( );
  //Data->CSE->LoadChain("InputFiles/Data_Jets_Normalized.txt");//Razor Trigger
  //Data->CSE->LoadChain("InputFiles/Data_DoubleMu.txt");//Double Mu PD and Trigger
  //Data->CSE->LoadChain("InputFiles/Data_DoubleMu_NoTrigger.txt");
  //Data->CSE->LoadChain("InputFiles/Data_MuEG.txt");
  Data->CSE->LoadChain("InputFiles/Data_MuEG_NoTrigger.txt");
  //Data->CSE->InitUsedVariables();

  Data->MuMu = new BoxStructure( "Data_MuMu" );
  Data->MuMu->SetMrBinning( n_mr, mr_l, mr_h );
  Data->MuMu->CreateMr();
  Data->MuMu->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  Data->MuMu->CreateRsq();
  Data->MuMu->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l, dilepton_mass_h );
  Data->MuMu->CreateMassTwoLeptons();
  Data->MuMu->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  Data->MuMu->CreateOneLepMT();
  Data->MuMu->SetHTBinning( n_ht, ht_l, ht_h );
  Data->MuMu->CreateHT();
  Data->MuMu->Sumw2();

  Data->EleEle = new BoxStructure( "Data_EleEle" );
  Data->EleEle->SetMrBinning( n_mr, mr_l, mr_h );
  Data->EleEle->CreateMr();
  Data->EleEle->SetRsqBinning( n_rsq, rsq_l, rsq_h );
  Data->EleEle->CreateRsq();
  Data->EleEle->SetMassTwoLeptonsBinning( n_dilepton_mass, dilepton_mass_l, dilepton_mass_h );
  Data->EleEle->CreateMassTwoLeptons();
  Data->EleEle->SetMT1LepBinning( n_mt1lep, mt1lep_l, mt1lep_h );
  Data->EleEle->CreateOneLepMT();
  Data->EleEle->SetHTBinning( n_ht, ht_l, ht_h );
  Data->EleEle->CreateHT();
  Data->EleEle->Sumw2();
  
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
  Data->MuEle->SetHTBinning( n_ht, ht_l, ht_h );
  Data->MuEle->CreateHT();
  Data->MuEle->Sumw2();
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
  Data->Mu->SetHTBinning( n_ht, ht_l, ht_h );
  Data->Mu->CreateHT();
  Data->Mu->Sumw2();
  
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
  Data->Ele->SetHTBinning( n_ht, ht_l, ht_h );
  Data->Ele->CreateHT();
  Data->Ele->Sumw2();
  
  //LOOP THE TREE!
  //DY->Loop();
  TT->Loop();
  W->Loop();
  T->Loop();
  Data->Loop( );
  //end of creating histos
  
  ////////////////////////
  //Creating Stack Plots//
  ///////////////////////
  
  THStack* stack = new THStack("stack", "");
  TLegend* leg;
  //MR MuEle
  SetStyleData( Data->MuEle->h_mr );
  SetStyleW( W->MuEle->h_mr );
  SetStyleDY( DY->MuEle->h_mr );
  SetStyleTT( TT->MuEle->h_mr );

  stack->Add( W->MuEle->h_mr );
  stack->Add( DY->MuEle->h_mr );
  stack->Add( TT->MuEle->h_mr );

  TH1F* mc = new TH1F( *W->MuEle->h_mr );
  mc->Add( DY->MuEle->h_mr );
  mc->Add( TT->MuEle->h_mr );
  
  //legend
  
  leg = new TLegend(0.7,0.7,0.89,0.89,NULL,"brNDC");
  leg->AddEntry(W->MuEle->h_mr,"W + jets","f");
  //leg->AddEntry(Z->MuEle->h_mr,"Z(#nu#nu) + jets","f");
  leg->AddEntry(TT->MuEle->h_mr,"t #bar{t} + jets","f");
  leg->AddEntry(DY->MuEle->h_mr,"Z/#gamma^{*}(ll) + jets","f");
  leg->AddEntry(Data->MuEle->h_mr,"Data","lep");
  CreateStackPlot(Data->MuEle->h_mr, mc, stack, leg,
		  "TESTPLOT", "MR");
  
  delete stack;
  delete mc;
  //RSQ MuEle
  SetStyleData( Data->MuEle->h_rsq );
  SetStyleW( W->MuEle->h_rsq );
  SetStyleDY( DY->MuEle->h_rsq );
  SetStyleTT( TT->MuEle->h_rsq );

  stack = new THStack("stack", "");
  stack->Add( W->MuEle->h_rsq );
  stack->Add( DY->MuEle->h_rsq );
  stack->Add( TT->MuEle->h_rsq );
  
  mc = new TH1F( *W->MuEle->h_rsq );
  mc->Add( DY->MuEle->h_rsq );
  mc->Add( TT->MuEle->h_rsq );

  //legend                                          
  leg = new TLegend(0.7,0.7,0.89,0.89,NULL,"brNDC");
  leg->AddEntry(W->MuEle->h_rsq,"W + jets","f");
  //leg->AddEntry(Z->MuEle->h_rsq,"Z(#nu#nu) + jets","f");       
  leg->AddEntry(TT->MuEle->h_rsq,"t #bar{t} + jets","f");
  leg->AddEntry(DY->MuEle->h_rsq,"Z/#gamma^{*}(ll) + jets","f");
  leg->AddEntry(Data->MuEle->h_rsq,"Data","lep");
  CreateStackPlot(Data->MuEle->h_rsq, mc, stack, leg,
                  "TESTPLOT_RSQ", "RSQ");

  TFile* fout = new TFile("MuEG_NoTrigger_PT_Cut_PuW_NNLO.root", "RECREATE");
  DY->MuMu->h_mr->Write();
  DY->MuMu->h_rsq->Write();
  DY->MuMu->h_mass_twoleptons->Write();
  DY->MuMu->h_mt_1lep->Write();
  DY->MuMu->h_ht->Write();
  
  W->MuMu->h_mr->Write();
  W->MuMu->h_rsq->Write();
  W->MuMu->h_mass_twoleptons->Write();
  W->MuMu->h_mt_1lep->Write();
  W->MuMu->h_ht->Write();
  
  TT->MuMu->h_mr->Write();
  TT->MuMu->h_rsq->Write();
  TT->MuMu->h_mass_twoleptons->Write();
  TT->MuMu->h_mt_1lep->Write();
  TT->MuMu->h_ht->Write();
  
  T->MuMu->h_mr->Write();
  T->MuMu->h_rsq->Write();
  T->MuMu->h_mass_twoleptons->Write();
  T->MuMu->h_mt_1lep->Write();
  T->MuMu->h_ht->Write();
  
  Data->MuMu->h_mr->Write();
  Data->MuMu->h_rsq->Write();
  Data->MuMu->h_mass_twoleptons->Write();
  Data->MuMu->h_mt_1lep->Write();
  Data->MuMu->h_ht->Write();
  
  //EleEle
  DY->EleEle->h_mr->Write();
  DY->EleEle->h_rsq->Write();
  DY->EleEle->h_mass_twoleptons->Write();
  DY->EleEle->h_mt_1lep->Write();
  DY->EleEle->h_ht->Write();
  
  W->EleEle->h_mr->Write();
  W->EleEle->h_rsq->Write();
  W->EleEle->h_mass_twoleptons->Write();
  W->EleEle->h_mt_1lep->Write();
  W->EleEle->h_ht->Write();
  
  TT->EleEle->h_mr->Write();
  TT->EleEle->h_rsq->Write();
  TT->EleEle->h_mass_twoleptons->Write();
  TT->EleEle->h_mt_1lep->Write();
  TT->EleEle->h_ht->Write();

  T->EleEle->h_mr->Write();
  T->EleEle->h_rsq->Write();
  T->EleEle->h_mass_twoleptons->Write();
  T->EleEle->h_mt_1lep->Write();
  T->EleEle->h_ht->Write();
  
  Data->EleEle->h_mr->Write();
  Data->EleEle->h_rsq->Write();
  Data->EleEle->h_mass_twoleptons->Write();
  Data->EleEle->h_mt_1lep->Write();
  Data->EleEle->h_ht->Write();
  
  //MuEle
  DY->MuEle->h_mr->Write();
  DY->MuEle->h_rsq->Write();
  DY->MuEle->h_mass_twoleptons->Write();
  DY->MuEle->h_mt_1lep->Write();
  DY->MuEle->h_ht->Write();
  
  W->MuEle->h_mr->Write();
  W->MuEle->h_rsq->Write();
  W->MuEle->h_mass_twoleptons->Write();
  W->MuEle->h_mt_1lep->Write();
  W->MuEle->h_ht->Write();
  
  TT->MuEle->h_mr->Write();
  TT->MuEle->h_rsq->Write();
  TT->MuEle->h_mass_twoleptons->Write();
  TT->MuEle->h_mt_1lep->Write();
  TT->MuEle->h_ht->Write();
  
  T->MuEle->h_mr->Write();
  T->MuEle->h_rsq->Write();
  T->MuEle->h_mass_twoleptons->Write();
  T->MuEle->h_mt_1lep->Write();
  T->MuEle->h_ht->Write();
  
  Data->MuEle->h_mr->Write();
  Data->MuEle->h_rsq->Write();
  Data->MuEle->h_mass_twoleptons->Write();
  Data->MuEle->h_mt_1lep->Write();
  Data->MuEle->h_ht->Write();

  //SingleMu
  DY->Mu->h_mr->Write();
  DY->Mu->h_rsq->Write();
  DY->Mu->h_mass_twoleptons->Write();
  DY->Mu->h_mt_1lep->Write();
  DY->Mu->h_ht->Write();
  
  W->Mu->h_mr->Write();
  W->Mu->h_rsq->Write();
  W->Mu->h_mass_twoleptons->Write();
  W->Mu->h_mt_1lep->Write();
  W->Mu->h_ht->Write();

  TT->Mu->h_mr->Write();
  TT->Mu->h_rsq->Write();
  TT->Mu->h_mass_twoleptons->Write();
  TT->Mu->h_mt_1lep->Write();
  TT->Mu->h_ht->Write();
  
  T->Mu->h_mr->Write();
  T->Mu->h_rsq->Write();
  T->Mu->h_mass_twoleptons->Write();
  T->Mu->h_mt_1lep->Write();
  T->Mu->h_ht->Write();
  
  Data->Mu->h_mr->Write();
  Data->Mu->h_rsq->Write();
  Data->Mu->h_mass_twoleptons->Write();
  Data->Mu->h_mt_1lep->Write();
  Data->Mu->h_ht->Write();

  //SingleEle
  DY->Ele->h_mr->Write();
  DY->Ele->h_rsq->Write();
  DY->Ele->h_mass_twoleptons->Write();
  DY->Ele->h_mt_1lep->Write();
  DY->Ele->h_ht->Write();
  
  W->Ele->h_mr->Write();
  W->Ele->h_rsq->Write();
  W->Ele->h_mass_twoleptons->Write();
  W->Ele->h_mt_1lep->Write();
  W->Ele->h_ht->Write();
  
  TT->Ele->h_mr->Write();
  TT->Ele->h_rsq->Write();
  TT->Ele->h_mass_twoleptons->Write();
  TT->Ele->h_mt_1lep->Write();
  TT->Ele->h_ht->Write();
  
  T->Ele->h_mr->Write();
  T->Ele->h_rsq->Write();
  T->Ele->h_mass_twoleptons->Write();
  T->Ele->h_mt_1lep->Write();
  T->Ele->h_ht->Write();

  Data->Ele->h_mr->Write();
  Data->Ele->h_rsq->Write();
  Data->Ele->h_mass_twoleptons->Write();
  Data->Ele->h_mt_1lep->Write();
  Data->Ele->h_ht->Write();
  
  fout->Close();
  
  end = time(NULL);
  diff = difftime (end,start);
  //std::cout << "TIME ELAPSED: " << diff << std::endl;
  return 0;
}
