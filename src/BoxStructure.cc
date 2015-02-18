//C++ INCLUDES
//ROOT INCLUDES
//LOCAL INCLUDES
#include "BoxStructure.hh"

BoxStructure::BoxStructure()
{
  if ( _debug ) std::cout << "[DEBUG]: Accessing Constructure" << std::endl;
  std::cout << "[WARNING]: Undefined Box Name; Use BoxStructure( TString box_name )"
	    << std::endl;
  InitVariables();
};

BoxStructure::BoxStructure( TString box_name )
{
  if ( _debug ) std::cout << "[DEBUG]: Accessing Constructure" << std::endl;
  InitVariables();
  this->box_name = box_name;
};

BoxStructure::~BoxStructure()
{
  delete h_mr, h_rsq, h_njet, h_ht, h_mt_1lep, h_mass_twoleptons;
  if ( _debug ) std::cout << "[DEBUG]: Accessing Destructure"<< std::endl;
};

void BoxStructure::InitVariables()
{
  _debug =  false;
  _info = false;
  box_name = "";

  //MR                                                                           
  _Mr_nbins = 0;
  _Mr_xl = .0;
  _Mr_xh = .0;
  _Mr_binning  = NULL;

  //RSQ                                                                                     
  _Rsq_nbins = 0;
  _Rsq_xl = 0.0;
  _Rsq_xh = 0.0;
  _Rsq_binning = NULL;

  //NJets                                                                           
  _Njet_nbins = 0;
  _Njet_xl = .0;
  _Njet_xh = .0;
  
  //HT
  _HT_nbins = 0;
  _HT_xl = .0;
  _HT_xh = .0;

  //MT1Lep                                                                     
  _MT1Lep_nbins = 0;
  _MT1Lep_xl = .0;
  _MT1Lep_xh = .0;

  //MinvTwoLeptons                                                          
  _MassTwoLeptons_nbins = 0;
  _MassTwoLeptons_xl = .0;
  _MassTwoLeptons_xh = .0;
  
  //HISTOS
  h_mr = NULL;
  h_rsq = NULL;
  h_njet = NULL;
  h_ht = NULL;
  h_mt_1lep = NULL;
  h_mass_twoleptons = NULL;

};
void BoxStructure::SetDebugLevel( bool debug )
{
  _debug = debug;
};

void BoxStructure::SetInfoLevel( bool info )
{
  _info = info;
};

void BoxStructure::SetMrBinning( int nbins, float*  bins = NULL)
{
  _Mr_nbins = nbins;
  _Mr_binning = bins;
};

void BoxStructure::SetMrBinning( int nbins, float xl, float xh )
{
  _Mr_nbins = nbins;
  _Mr_xl = xl;
  _Mr_xh = xh;
};

void BoxStructure::SetRsqBinning( int nbins, float*  bins = NULL )
{
  _Rsq_nbins = nbins;
  _Rsq_binning = bins;
};

void BoxStructure::SetRsqBinning( int nbins, float xl, float xh )
{
  _Rsq_nbins = nbins;
  _Rsq_xl = xl;
  _Rsq_xh = xh;
};

void BoxStructure::SetNjetBinning( int nbins, float xl, float xh )
{
  _Njet_nbins = nbins;
  _Njet_xl = xl;
  _Njet_xh = xh;
};

void BoxStructure::SetHTBinning( int nbins, float xl, float xh )
{
  _HT_nbins = nbins;
  _HT_xl = xl;
  _HT_xh = xh;
};

void BoxStructure::SetMT1LepBinning( int nbins, float xl, float xh )
{
  _MT1Lep_nbins = nbins;
  _MT1Lep_xl = xl;
  _MT1Lep_xh = xh;
};

void BoxStructure::SetMassTwoLeptonsBinning( int nbins, float xl, float xh )
{
  _MassTwoLeptons_nbins = nbins;
  _MassTwoLeptons_xl = xl;
  _MassTwoLeptons_xh = xh;
};

void BoxStructure::CreateMr()
{
  if ( _Mr_nbins > 0 )
    {
      if ( _Mr_binning != NULL )
	{
	  if ( _debug ) std::cout << "[DEBUG]: Creating Mr histo using variable binning" << std::endl;
	  h_mr = new TH1F( "h_mr_" + box_name, "h_mr_" + box_name,
			   _Mr_nbins, _Mr_binning );
	}
      else
	{
	  if ( _debug ) std::cout << "[DEBUG]: Creating Mr histo using fix binning" << std::endl;
	  h_mr = new TH1F( "h_mr_" + box_name, "h_mr_" + box_name,
			   _Mr_nbins, _Mr_xl, _Mr_xh );
	}
    }
  else
    {
      std::cerr << "[ERROR]: Unable to Create Mr Histogram" << std::endl;
    }
};

void BoxStructure::CreateRsq()
{
  if ( _Rsq_nbins > 0 )
    {
      if ( _Rsq_binning != NULL )
        {
          if ( _debug ) std::cout << "[DEBUG]: Creating Rsq histo using variable binning" << std::endl;
          h_rsq = new TH1F( "h_rsq_" + box_name, "h_rsq_" + box_name,
			    _Rsq_nbins, _Rsq_binning );
        }
      else
        {
          if ( _debug ) std::cout << "[DEBUG]: Creating Rsq histo using fix binning" << std::endl;
          h_rsq = new TH1F( "h_rsq_" + box_name, "h_rsq_" + box_name,
			    _Rsq_nbins, _Rsq_xl, _Rsq_xh );
        }
    }
  else
    {
      std::cerr << "[ERROR]: Unable to Create Rsq Histogram" << std::endl;
    }
};

void BoxStructure::CreateNjet()
{
  if ( _Njet_nbins > 0 )
    {
      if ( _debug ) std::cout << "[DEBUG]: Creating Njet histo using fix binning" << std::endl;
      h_njet = new TH1F( "h_njet_" + box_name, "h_njet_" + box_name,
			 _Njet_nbins, _Njet_xl, _Njet_xh );
    }
  else
    {
      std::cerr << "[ERROR]: Unable to Create Njet Histogram" << std::endl;
    }
};

void BoxStructure::CreateHT()
{
  if ( _HT_nbins > 0 )
    {
      if ( _debug ) std::cout << "[DEBUG]: Creating HT histo using fix binning" << std::endl;
      h_ht = new TH1F( "h_ht_" + box_name, "h_ht_" + box_name,
		       _HT_nbins, _HT_xl, _HT_xh );
    }
  else
    {
      std::cerr << "[ERROR]: Unable to Create HT Histogram" << std::endl;
    }
};

void BoxStructure::CreateOneLepMT()
{
  if ( _MT1Lep_nbins > 0 )
    {
      if ( _debug ) std::cout << "[DEBUG]: Creating MT1Lep histo using fix binning" << std::endl;
      h_mt_1lep = new TH1F( "h_mt1lep_" + box_name, "h_mt1lep_" + box_name,
			    _MT1Lep_nbins, _MT1Lep_xl, _MT1Lep_xh );
    }
  else
    {
      std::cerr << "[ERROR]: Unable to Create MT1Lep Histogram" << std::endl;
    }
};

void BoxStructure::CreateMassTwoLeptons()
{
  if ( _MassTwoLeptons_nbins > 0 )
    {
      if ( _debug ) std::cout << "[DEBUG]: Creating MassTwoLeptons histo using fix binning" << std::endl;
      h_mass_twoleptons = 
	new TH1F( "h_mass_twoleptons_" + box_name,
		  "h_mass_twoleptons_" + box_name, _MassTwoLeptons_nbins,
		  _MassTwoLeptons_xl, _MassTwoLeptons_xh );
    }
  else
    {
      std::cerr << "[ERROR]: Unable to Create MassTwoLeptons Histogram" << std::endl;
    }
};

void BoxStructure::FillMr( float val = -999.0, float weight = 1.0 )
{
  if ( h_mr != NULL )
    {
      if ( _info ) std::cout <<"[INFO]: Filling Mr Histo" << std::endl;
      h_mr->Fill( val, weight );
    }
  else
    {
      std::cerr << "[ERROR]: Mr Histogram was NOT created" << std::endl;
    }
};

void BoxStructure::FillRsq( float val = -999.0, float weight = 1.0 )
{
  if ( h_rsq != NULL )
    {
      if ( _info ) std::cout <<"[INFO]: Filling Rsq Histo" << std::endl;
      h_rsq->Fill( val, weight );
    }
  else
    {
      std::cerr << "[ERROR]: Rsq Histogram was NOT created" << std::endl;
    }
};

void BoxStructure::FillNjet( float val = -999.0, float weight = 1.0 )
{
  if ( h_njet != NULL )
    {
      if ( _info ) std::cout <<"[INFO]: Filling Njet Histo" << std::endl;
      h_njet->Fill( val, weight );
    }
  else
    {
      std::cerr << "[ERROR]: Njet Histogram was NOT created" << std::endl;
    }
};

void BoxStructure::FillHT( float val = -999.0, float weight = 1.0 )
{
  if ( h_ht != NULL )
    {
      if ( _info ) std::cout <<"[INFO]: Filling HT Histo" << std::endl;
      h_ht->Fill( val, weight );
    }
  else
    {
      std::cerr << "[ERROR]: HT Histogram was NOT created" << std::endl;
    }
};

void BoxStructure::FillOneLepMT( float val = -999.0, float weight = 1.0 )
{
  if ( h_mt_1lep != NULL )
    {
      if ( _info ) std::cout <<"[INFO]: Filling MT1Lep Histo" << std::endl;
      h_mt_1lep->Fill( val, weight );
    }
  else
    {
      std::cerr << "[ERROR]: MT1Lep Histogram was NOT created" << std::endl;
    }
};

void BoxStructure::FillMassTwoLeptons( float val = -999.0, float weight = 1.0 )
{
  if ( h_mass_twoleptons != NULL )
    {
      if ( _info ) std::cout << "[INFO]: Filling MassTwoLeptons Histo" << std::endl;
      h_mass_twoleptons->Fill( val, weight );
    }
  else
    {
      std::cerr << "[ERROR]: MassTwoLeptons Histogram was NOT created" << std::endl;
    }
};


void BoxStructure::Sumw2()
{
  if( h_mr != NULL ) h_mr->Sumw2();
  if( h_rsq != NULL ) h_rsq->Sumw2();
  if( h_njet != NULL ) h_njet->Sumw2();
  if( h_ht != NULL ) h_ht->Sumw2();
  if( h_mt_1lep != NULL ) h_mt_1lep->Sumw2();
  if( h_mass_twoleptons != NULL ) h_mass_twoleptons->Sumw2();
};
/*
void BoxStructure::WriteMr( TFile* f )
{
  f->Write( )
};
*/
