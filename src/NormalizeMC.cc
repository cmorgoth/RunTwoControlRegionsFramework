//C++ INCLUDES
//ROOT INCLUDES
//LOCAL INCLUDES
#include "NormalizeMC.hh"

void NormalizeTree( TTree* tree, float xsec, float lumi, 
		    float kfactor, float ngen, TString foutName )
{

  float xs_w, xs_w_kf;
  TFile* fout = new TFile( foutName , "RECREATE" );
  TTree* newtree = tree->CloneTree( 0 );
  newtree->Branch( "xs_w", &xs_w, "xs_w/F");
  newtree->Branch( "xs_w_kf", &xs_w_kf, "xs_w_kf/F");
  
  xs_w = lumi*xsec/ngen;
  xs_w_kf = lumi*xsec*kfactor/ngen;
  
  for ( unsigned int i = 0; i < tree->GetEntries(); i++ ){
    tree->GetEntry( i );
    newtree->Fill();
  }

  newtree->Print();
  newtree->AutoSave();
  fout->Close();
};

double GetNgen( TTree* effTree )
{
  std::cout << "debb1" << std::endl;
  effTree->SetBranchStatus("*", 0);
  std::cout << "debb1.1" << std::endl;
  effTree->SetBranchStatus("Npassed_In", 1);
  std::cout << "debb1.2" << std::endl;
  double Npassed_In;
  effTree->SetBranchAddress("Npassed_In", &Npassed_In);
  
  double ngen = 0;
  for ( unsigned int i = 0; i < effTree->GetEntries(); i++ ){
    effTree->GetEntry( i );  
    ngen += Npassed_In;
  }
  
  return ngen;
};
