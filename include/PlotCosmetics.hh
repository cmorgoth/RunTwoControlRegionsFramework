#ifndef PLOT_COSMETICS_HH
#define PLOT_COSMETICS_HH

//C++ INLCUDES
#include <iostream>
//ROOT INCLUDES
#include "TCanvas.h"
#include "TLegend.h"
#include "TH1F.h"
#include "THStack.h"
//LOCAL INCLUDES

void CreateStackPlot(TH1F* data, TH1F* mc, THStack* s, TLegend* leg,
      TString fname, TString type);

void SetStyleData(TH1F* h);
void SetStyleW(TH1F* h);
void SetStyleDY(TH1F* h);
void SetStyleTT(TH1F* h);
void SetStyleT(TH1F* h);

#endif
