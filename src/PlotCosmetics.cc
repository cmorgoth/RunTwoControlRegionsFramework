//C++ INCLUDES
#include <iostream>
//ROOT INCLUDES
#include "TLatex.h"
//LOCAL INCLUDES
#include "PlotCosmetics.hh"

void SetStyleData(TH1F* h)
{
  h->SetLineColor( kBlack );
  h->SetMarkerStyle( 20 );
  h->SetMarkerSize( 0.7 );
  
  h->SetTitle( "" );
  h->SetStats( 0 );
};

void SetStyleW(TH1F* h)
{
  h->SetFillColor( kViolet );  
  h->SetTitle( "" );
  h->SetStats( 0 );
};

void SetStyleDY(TH1F* h)
{
  h->SetFillColor( kBlue );
  h->SetTitle( "" );
  h->SetStats( 0 );
};

void SetStyleTT(TH1F* h)
{
  h->SetFillColor( kGreen+2 );
  h->SetTitle( "" );
  h->SetStats( 0 );
};

void SetStyleT(TH1F* h)
{
  h->SetFillColor( kOrange+1 );
  h->SetTitle( "" );
  h->SetStats( 0 );
};

void CreateStackPlot(TH1F* data, TH1F* mc, THStack* s, TLegend* leg,
		     TString fname, TString type)
{
  TCanvas *C = new TCanvas("c", "c",2119,33,800,700);
  C->SetHighLightColor(2);
  //C->Range(-0.6543224,-1290.871,3.177829,8696.391);
  C->SetFillColor(0);
  C->SetBorderMode(0);
  C->SetBorderSize(2);
  C->SetLeftMargin(0.16);
  C->SetRightMargin(0.3);
  C->SetTopMargin(0.07);
  C->SetBottomMargin(0.12);
  C->SetFrameBorderMode(0);
  C->SetFrameBorderMode(0);
  
  TH1F*  RATIO = new TH1F( *data );
  RATIO->Divide( mc );
  TString label;
  SetStyleData( data );
  if(type == "mr"){
    label = "M_{R}";
    data->GetXaxis()->SetRangeUser(-10., 3500.);
    mc->GetXaxis()->SetRangeUser(-10., 3500.);
    RATIO->GetXaxis()->SetRangeUser(-10., 3500.);
    data->SetMaximum(1e4);
    data->SetMinimum(1);
  }else if(type == "rsq" ){
    label = "R^{2}";
    data->GetXaxis()->SetRangeUser(0.0, 2.5);
    mc->GetXaxis()->SetRangeUser(0.0, 2.5);
    RATIO->GetXaxis()->SetRangeUser(0.0, 2.5);
    data->SetMaximum(1e4);
    data->SetMinimum(1);
  }else if(type == "MET"){
    label = "#slash{E}_{T}  GeV";
    s->SetMaximum(10000.);
    data->SetMinimum(0);
  }else if(type == "NJETS"){
    label = "Jet Multiplicity";
    s->SetMaximum(100000.);
    data->SetMinimum(0);
  }else if(type=="mass_twoleptons"){
    label = "M_{ll}";
    data->GetXaxis()->SetRangeUser(0.0, 200.);
    mc->GetXaxis()->SetRangeUser(0.0, 200.);
    RATIO->GetXaxis()->SetRangeUser(0.0, 200.);
    data->SetMaximum(1e7);  
    data->SetMinimum(1);
  }else if(type=="Angle"){
    label = "#Delta#theta";
  }else if(type=="PT_J"){
    label = "P^{J}_{T}";
    s->SetMaximum(3e4);
  }else if(type=="Eta_J"){
    label = "#eta";
    s->SetMaximum(5e4);
  }else if(type=="Phi_J"){
    label = "#phi";
    s->SetMaximum(5e4);
  }else if(type=="PT_mu"){
    label = "P^{#mu}_{T}";
    s->SetMaximum(3e4);
  }else if(type=="Eta_mu"){
    label = "#eta_{#mu}";
    s->SetMaximum(5e4);
  }else if(type=="Phi_mu"){
    label = "#phi_{#mu}";
    s->SetMaximum(5e4);
  }else if(type == "ht"){
    label = "HT";
    data->GetXaxis()->SetRangeUser( 0., 2000.);
    mc->GetXaxis()->SetRangeUser( .0, 2000.);
    RATIO->GetXaxis()->SetRangeUser( .0, 2000.);
    data->SetMaximum(1e5);
    data->SetMinimum(1);
  }else if(type == "Dphi"){
    label = "#Delta#phi(J_{1},J_{2})";
    s->SetMaximum(9e4);
  }else if(type == "mt1lep")
    {
      label = "M^{1l}_{T}";
      data->GetXaxis()->SetRangeUser(0, 200.);
      mc->GetXaxis()->SetRangeUser(0, 200.);
      RATIO->GetXaxis()->SetRangeUser(0, 200.);
      data->SetMaximum(1e4);
      data->SetMinimum(1);
    }
  else{
    delete RATIO;
    delete C;
    return;
  }
  
  RATIO->Divide(data, mc, 1.0, 1.0, "");
  RATIO->GetYaxis()->SetRangeUser(.0, 2.15);
  mc->SetMarkerSize(.7);
  mc->SetStats(0);

  s->SetMinimum(1.);
  
  TPad *pad1 = new TPad("pad1","pad1",0,0.25,1,1);
  pad1->SetBottomMargin(0.0);
  pad1->SetRightMargin(0.04);
  pad1->Draw();
  pad1->cd();
  //s->Draw();
  data->Draw();
  s->Draw("same");
  if(type == "MET"){
    data->GetYaxis()->SetTitle("Events/20 GeV");
  }else{
    data->GetYaxis()->SetTitle("Events");
  }
  data->GetYaxis()->SetLabelSize(0.05);
  data->GetYaxis()->SetTitleSize(0.06);
  data->GetYaxis()->SetTitleOffset(0.8);
  //data->GetYaxis()->SetTitleOffset(1.25);
  gPad->Modified();
  data->SetStats(0);
  data->Draw("same");
  //data->Draw();  
  //s->Draw("same");
  C->cd();
  
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->Draw();

  pad1->SetLogy();
  C->Update();
  
  float lumix = 0.955;
  float lumiy = 0.945;
  float lumifont = 42;
   
  float cmsx = 0.28;
  float cmsy = 0.875;
  TString CMSText = "CMS";
  float cmsTextFont   = 61;  // default is helvetic-bold
  float extrax = cmsx + 0.067;
  float extray = cmsy - 0.04;
  TString extraText   = "Preliminary";
  float extraTextFont = 52;  // default is helvetica-italics
  // ratio of "CMS" and extra text size
  float extraOverCmsTextSize  = 0.76;
  float cmsSize = 0.05;
  TString lumiText = "18.84 fb^{-1} (8TeV)";
  TLatex latex;
  latex.SetNDC();
  latex.SetTextAngle(0);
  latex.SetTextColor(kBlack);    
  float extraTextSize = extraOverCmsTextSize*cmsSize;
  latex.SetTextFont(lumifont);
  latex.SetTextAlign(31); 
  latex.SetTextSize(cmsSize);    
  latex.DrawLatex(lumix, lumiy,lumiText);

  latex.SetTextFont(cmsTextFont);
  latex.SetTextAlign(31); 
  latex.SetTextSize(cmsSize);
  latex.DrawLatex(cmsx, cmsy, CMSText);
   
  latex.SetTextFont(extraTextFont);
  latex.SetTextAlign(31); 
  latex.SetTextSize(extraTextSize);
  latex.DrawLatex(extrax, extray, extraText);
  
  TPad *pad2 = new TPad("pad2","pad2",0,0.0,1,0.25);
  pad2->SetTopMargin(0.01);
  pad2->SetBottomMargin(0.37);
  pad2->SetRightMargin(0.04);
  pad2->SetGridy();
  pad2->Draw();
  pad2->cd();
  RATIO->SetLineColor(4);
  RATIO->SetStats(0);
  RATIO->SetTitle("");
  RATIO->GetXaxis()->SetLabelSize(0.15); 
  RATIO->GetYaxis()->SetLabelSize(0.08); 
  RATIO->GetYaxis()->SetTitleOffset(0.25);
  RATIO->GetXaxis()->SetTitleOffset(0.75);
  RATIO->GetYaxis()->SetTitleSize(0.17);
  RATIO->GetXaxis()->SetTitleSize(0.2);
  RATIO->SetXTitle( label );
  RATIO->SetYTitle("Data/MC");
  RATIO->SetLineColor(4);
  RATIO->SetMarkerSize(.7);
  RATIO->SetMarkerColor(4);
  RATIO->SetMarkerStyle(20);
  RATIO->SetFillColor(4);
  RATIO->Draw();
  C->cd();
  C->SaveAs(fname + ".C");
  C->SaveAs(fname + ".root");
  C->SaveAs(fname + ".pdf");
  C->SaveAs(fname + ".png");

  delete C;
  delete RATIO;
  
};
