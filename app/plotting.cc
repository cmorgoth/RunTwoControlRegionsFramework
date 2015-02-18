//C++ INCLUDES
#include <iostream>
#include <string>
//ROOT INCLUDES
#include "TH1F.h"
#include "THStack.h"
#include "TFile.h"
#include "TLegend.h"
#include "TString.h"
//LOCAL INCLUDES
#include "PlotCosmetics.hh"

int main()
{
  std::string hname[] = {"mr", "rsq", "mass_twoleptons", "mt1lep", "ht"};
  std::string box[] = {"MuEle", "MuMu", "EleEle", "SingleMu", "SingleEle"};
  
  //TFile* f = new TFile("TEST_SingleLepton_LO.root");
  //TFile* f = new TFile("RazorParked_NNLO_NoCut.root");
  //TFile* f = new TFile("RazorParked_LO_NoCut.root");
  //TFile* f = new TFile("Razor_LO_AllCuts.root");
  //TFile* f = new TFile("Razor_LO_AllCuts_2B_MET.root");
  //TFile* f = new TFile("DoubleMuPD_NNLO_NoHTCut.root");
  //TFile* f = new TFile("DoubleMuPD_LO_HT200.root");
  //TFile* f = new TFile("DoubleMu_LO_NoJetCut.root"); 
  //TFile* f = new TFile("DoubleMu_LO_NoJetCut_HTcut.root");
  //TFile* f = new TFile("MuEG_LO_NoJetCut.root");
  //TFile* f = new TFile("MuEG_LO_NoJetCut_HT_Cut.root");
  //TFile* f = new TFile("DoubleMu_LO_AllCuts.root");
  //TFile* f = new TFile("MuEG_LO_AllCuts.root");
  TFile* f = new TFile("MuEG_NoTrigger_LO_AllCuts_2B_MET.root");
  
  TH1F* w;
  TH1F* dy;
  TH1F* tt;
  TH1F* t;
  TH1F* data;
  THStack* stack;
  TLegend* leg;
  TH1F* mc;
  TString outName, type;
  std::string aux;
  for( int i = 0; i < 5; i++ ){
    for( int j = 0; j < 5; j++ ){
      //outfile name
      //aux = "Plots/Razor_LO_AllCuts_2B_MET_"+hname[j]+"_"+box[i];
      aux = "Plots/MuEG_NoTrigger_LO_AllCuts_"+hname[j]+"_"+box[i];
      //aux = "Plots/DoubleMu_LO_AllCuts_"+hname[j]+"_"+box[i];
      outName = aux.c_str();
      
      //getting histos
      aux = "h_"+hname[j]+"_W_"+box[i];
      w = (TH1F*)f->Get(aux.c_str());
      aux = "h_"+hname[j]+"_DY_"+box[i];
      dy = (TH1F*)f->Get(aux.c_str());
      aux = "h_"+hname[j]+"_TT_"+box[i];
      tt = (TH1F*)f->Get(aux.c_str());
      aux = "h_"+hname[j]+"_T_"+box[i];
      t = (TH1F*)f->Get(aux.c_str());
      aux = "h_"+hname[j]+"_Data_"+box[i];
      data = (TH1F*)f->Get(aux.c_str());
      
      stack = new THStack("stack", "");
      //MR MuEle                                                                             
      SetStyleData( data );
      SetStyleW( w );
      SetStyleDY( dy );
      SetStyleTT( tt );
      SetStyleT( t );
      stack->Add( dy );
      stack->Add( t );
      stack->Add( w );
      stack->Add( tt );
      mc = new TH1F( *w );
      mc->Add( dy );
      mc->Add( tt );
      mc->Add( t );
      
      //legend                                                                               
      leg = new TLegend(0.7,0.7,0.89,0.89,NULL,"brNDC");
      leg->AddEntry(w,"W + jets","f");
      //leg->AddEntry(Z->MuEle->h,"Z(#nu#nu) + jets","f");                                
      leg->AddEntry(tt,"t #bar{t} + jets","f");
      leg->AddEntry(t,"t + jets","f");
      leg->AddEntry(dy,"Z/#gamma^{*}(ll) + jets","f");
      leg->AddEntry(data,"Data","lep");
      type = hname[j].c_str();
      CreateStackPlot(data, mc, stack, leg,
		      outName, type);
      
      delete leg, stack, mc;
    }
  }
}
