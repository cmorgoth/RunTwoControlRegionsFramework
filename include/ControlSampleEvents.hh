#ifndef ControlSampleEvents_HH
#define ControlSampleEvents_HH

//C++ INCLUDES
#include <cmath>
#include "assert.h"
#include <Rtypes.h>
#include <fstream>
#include <string>
#include <iostream>
//ROOT INCLUDES
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TError.h"
#include "TLorentzVector.h"

class ControlSampleEvents {
  
public:
  
  /// bit map
  /// DON'T CHANGE ORDER
  
  //*******************************************
  //=== Process IDs  ====
  //*******************************************
  enum BkgProcessId { kData = 0,
		      kQCD = 1,
		      kWJets = 2,
		      kZJets = 3,
		      kTTJets = 4,
		      kSingleT = 5,
		      kVV = 6,
		      kHiggs = 7,
		      kSUSY = 99,
		      kUnknown = 999
  };
  
  /// variables
  Float_t                 weight;
  UInt_t                  run;
  UInt_t                  lumi;
  UInt_t                  event;
  UInt_t                  processID;
  UInt_t                  NPU_0;
  UInt_t                  NPU_Minus1;
  UInt_t                  NPU_Plus1;
  TLorentzVector          genlep1;
  TLorentzVector          genlep2;
  Int_t                   genlep1Type;
  Int_t                   genlep2Type;
  TLorentzVector          lep1;
  TLorentzVector          lep2;
  Int_t                   lep1Type;
  Int_t                   lep2Type;
  Int_t                   lep1MatchedGenLepIndex;
  Int_t                   lep2MatchedGenLepIndex;
  Bool_t                  lep1PassVeto;
  Bool_t                  lep1PassLoose;
  Bool_t                  lep1PassTight;
  Bool_t                  lep2PassVeto;
  Bool_t                  lep2PassLoose;
  Bool_t                  lep2PassTight;
  TLorentzVector          bjet1;
  TLorentzVector          bjet2;
  Bool_t                  bjet1PassLoose;
  Bool_t                  bjet1PassMedium;
  Bool_t                  bjet1PassTight;
  Bool_t                  bjet2PassLoose;
  Bool_t                  bjet2PassMedium;
  Bool_t                  bjet2PassTight;
  TLorentzVector          jet1;
  TLorentzVector          jet2;      
  Bool_t                  jet1PassCSVLoose;
  Bool_t                  jet1PassCSVMedium;
  Bool_t                  jet1PassCSVTight;
  Bool_t                  jet2PassCSVLoose;
  Bool_t                  jet2PassCSVMedium;
  Bool_t                  jet2PassCSVTight;
  Float_t                 MR;
  Float_t                 Rsq;
  Float_t                 MR_LeadLeptonsAsMET;
  Float_t                 Rsq_LeadLeptonsAsMET;
  Float_t                 MR_LeptonsAsMET;
  Float_t                 Rsq_LeptonsAsMET;
  Float_t                 MET;
  Float_t                 MET_LeadLeptonsAsMET;
  Float_t                 MET_LeptonsAsMET;
  Float_t                 minDPhi;
  Float_t                 minDPhiN;
  Float_t                 minDPhiFolded;
  Float_t                 minDPhiNFolded;
  Float_t                 dPhiHemHem;
  Float_t                 dPhiHemHem_LeptonsAsMET;
  Float_t                 dPhiHemHem_LeadLeptonsAsMET;
  UInt_t                  NJets40;
  UInt_t                  NJets80;
  UInt_t                  NBJetsLoose;
  UInt_t                  NBJetsMedium;
  UInt_t                  NBJetsTight;
  Float_t                 HT;
  Float_t                 lep1MT;
  Float_t                 xs_w;
  Float_t                 xs_w_kf;
  
  
public:
  /// this is the main element
  TChain *tree_;
  TFile *f_;
  
  /// hold the names of variables to facilitate things (filled during Init)
  std::vector<std::string> variables_;
  
  /// default constructor  
  ControlSampleEvents()  {
    genlep1Ptr  = &genlep1;
    genlep2Ptr  = &genlep2;
    lep1Ptr     = &lep1;
    lep2Ptr     = &lep2;
    bjet1Ptr    = &bjet1;
    bjet2Ptr    = &bjet2;       
    jet1Ptr     = &jet1;
    jet2Ptr     = &jet2;       
  };
  
  /// default destructor
  ~ControlSampleEvents(){ 
    if (f_) f_->Close();  
  };
  
  /// initialize varibles and fill list of available variables
  void InitVariables() {
    weight               = 0.0;
    run                  = 0.0;
    lumi                 = 0.0;
    event                = 0.0;
    processID            = ControlSampleEvents::kUnknown;
    NPU_0                = 0.0;
    NPU_Minus1           = 0.0;
    NPU_Plus1            = 0.0;
    genlep1              = TLorentzVector();
    genlep2              = TLorentzVector();
    genlep1Type          = 0.0;
    genlep2Type          = 0.0;
    lep1                 = TLorentzVector();
    lep2                 = TLorentzVector();
    lep1Type             = 0.0;
    lep2Type             = 0.0;
    lep1MatchedGenLepIndex = -1;
    lep2MatchedGenLepIndex = -1;
    lep1PassVeto         = 0.0;
    lep1PassLoose        = 0.0;
    lep1PassTight        = 0.0;
    lep2PassVeto         = 0.0;
    lep2PassLoose        = 0.0;
    lep2PassTight        = 0.0;
    bjet1                = TLorentzVector();
    bjet2                = TLorentzVector();
    bjet1PassLoose       = 0.0;
    bjet1PassMedium      = 0.0;
    bjet1PassTight       = 0.0;
    bjet2PassLoose       = 0.0;
    bjet2PassMedium      = 0.0;
    bjet2PassTight       = 0.0;
    jet1                 = TLorentzVector();
    jet2                 = TLorentzVector();
    jet1PassCSVLoose     = 0.0;
    jet1PassCSVMedium    = 0.0;
    jet1PassCSVTight     = 0.0;
    jet2PassCSVLoose     = 0.0;
    jet2PassCSVMedium    = 0.0;
    jet2PassCSVTight     = 0.0;
    MR                   = 0.0;
    Rsq                  = 0.0;
    MR_LeadLeptonsAsMET        = 0.0;
    Rsq_LeadLeptonsAsMET       = 0.0;
    MR_LeptonsAsMET         = 0.0;
    Rsq_LeptonsAsMET        = 0.0;
    MET                  = 0.0;
    MET_LeadLeptonsAsMET       = 0.0;
    MET_LeptonsAsMET        = 0.0;
    minDPhi              = 0.0;
    minDPhiN             = 0.0;
    dPhiHemHem           = -1.0;
    dPhiHemHem_LeptonsAsMET          = -1.0;
    dPhiHemHem_LeadLeptonsAsMET           = -1.0;
    NJets40              = 0.0;
    NJets80              = 0.0;
    NBJetsLoose          = 0.0;
    NBJetsMedium         = 0.0;
    NBJetsTight          = 0.0;
    HT                   = 0.0;      
    lep1MT               = 0.0;  
    xs_w                 = 0.0;
    xs_w_kf              = 0.0;
  }
  
  /// load a ControlSampleEvents
  
  /*
  void LoadTree(const char* file){
    f_ = TFile::Open(file);
    assert(f_);
    tree_ = dynamic_cast<TTree*>(f_->Get("ControlSampleEvent"));
    InitTree();
    assert(tree_);
  }
  */
  
  void LoadChain(const char* file){
    tree_ = new TChain("ControlSampleEvent");
    //chaining TFiles
    std::ifstream chainFile ( file );
    TString tfName;//TFileName
    std::string tf_name;
    if ( chainFile.is_open() )
      {
	while ( chainFile.good() )
	  {
	    chainFile >> tf_name;
	    tfName = tf_name.c_str();
	    if ( tf_name.find("#") != std::string::npos )
	      {
		std::cout << "[INFO]: Skipping File: " << tfName << std::endl;
	      }
	    else
	      {
		tree_->Add( tfName );
		std::cout << "[INFO]: Adding File: " << tfName << std::endl; 
	      }
	  }
      }
    else{
      std::cerr << "Unable to open file: "  << file << std::endl;
    }
    
    InitTree();
    //InitTreeSmall();
    assert(tree_);
  }
  
  /// create a ControlSampleEvents
  void CreateTree(){
    //tree_ = new TTree("ControlSampleEvent","ControlSampleEvent");
    f_ = 0;
    
    //book the branches
    tree_->Branch("weight",&weight,"weight/F");
    tree_->Branch("run",&run,"run/i");
    tree_->Branch("lumi",&lumi,"lumi/i");
    tree_->Branch("event",&event,"event/i");
    tree_->Branch("processID",&processID,"processID/i");
    tree_->Branch("NPU_0",&NPU_0,"NPU_0/i");
    tree_->Branch("NPU_Minus1",&NPU_Minus1,"NPU_Minus1/i");
    tree_->Branch("NPU_Plus1",&NPU_Plus1,"NPU_Plus1/i");
    tree_->Branch("genlep1Type",&genlep1Type,"genlep1Type/I");
    tree_->Branch("genlep2Type",&genlep2Type,"genlep2Type/I");
    tree_->Branch("lep1Type",&lep1Type,"lep1Type/I");
    tree_->Branch("lep2Type",&lep2Type,"lep2Type/I");
    tree_->Branch("lep1MatchedGenLepIndex",&lep1MatchedGenLepIndex,"lep1MatchedGenLepIndex/I");
    tree_->Branch("lep2MatchedGenLepIndex",&lep2MatchedGenLepIndex,"lep2MatchedGenLepIndex/I");
    tree_->Branch("lep1PassVeto",&lep1PassVeto,"lep1PassVeto/O");
    tree_->Branch("lep1PassLoose",&lep1PassLoose,"lep1PassLoose/O");
    tree_->Branch("lep1PassTight",&lep1PassTight,"lep1PassTight/O");
    tree_->Branch("lep2PassVeto",&lep2PassVeto,"lep2PassVeto/O");
    tree_->Branch("lep2PassLoose",&lep2PassLoose,"lep2PassLoose/O");
    tree_->Branch("lep2PassTight",&lep2PassTight,"lep2PassTight/O");
    tree_->Branch("bjet1PassLoose",&bjet1PassLoose,"bjet1PassLoose/O");
    tree_->Branch("bjet1PassMedium",&bjet1PassMedium,"bjet1PassMedium/O");
    tree_->Branch("bjet1PassTight",&bjet1PassTight,"bjet1PassTight/O");
    tree_->Branch("bjet2PassLoose",&bjet2PassLoose,"bjet2PassLoose/O");
    tree_->Branch("bjet2PassMedium",&bjet2PassMedium,"bjet2PassMedium/O");
    tree_->Branch("bjet2PassTight",&bjet2PassTight,"bjet2PassTight/O");
    tree_->Branch("jet1PassCSVLoose",&jet1PassCSVLoose,"jet1PassCSVLoose/O");
    tree_->Branch("jet1PassCSVMedium",&jet1PassCSVMedium,"jet1PassCSVMedium/O");
    tree_->Branch("jet1PassCSVTight",&jet1PassCSVTight,"jet1PassCSVTight/O");
    tree_->Branch("jet2PassCSVLoose",&jet2PassCSVLoose,"jet2PassCSVLoose/O");
    tree_->Branch("jet2PassCSVMedium",&jet2PassCSVMedium,"jet2PassCSVMedium/O");
    tree_->Branch("jet2PassCSVTight",&jet2PassCSVTight,"jet2PassCSVTight/O");
    tree_->Branch("MR",&MR,"MR/F");
    tree_->Branch("Rsq",&Rsq,"Rsq/F");
    tree_->Branch("MR_LeadLeptonsAsMET",&MR_LeadLeptonsAsMET,"MR_LeadLeptonsAsMET/F");
    tree_->Branch("Rsq_LeadLeptonsAsMET",&Rsq_LeadLeptonsAsMET,"Rsq_LeadLeptonsAsMET/F");
    tree_->Branch("MR_LeptonsAsMET",&MR_LeptonsAsMET,"MR_LeptonsAsMET/F");
    tree_->Branch("Rsq_LeptonsAsMET",&Rsq_LeptonsAsMET,"Rsq_LeptonsAsMET/F");
    tree_->Branch("MET",&MET,"MET/F");
    tree_->Branch("MET_LeadLeptonsAsMET",&MET_LeadLeptonsAsMET,"MET_LeadLeptonsAsMET/F");
    tree_->Branch("MET_LeptonsAsMET",&MET_LeptonsAsMET,"MET_LeptonsAsMET/F");
    tree_->Branch("minDPhi",&minDPhi,"minDPhi/F");
    tree_->Branch("minDPhiN",&minDPhiN,"minDPhiN/F");
    tree_->Branch("dPhiHemHem",&dPhiHemHem,"dPhiHemHem/F");
    tree_->Branch("dPhiHemHem_LeptonsAsMET",&dPhiHemHem_LeptonsAsMET,"dPhiHemHem_LeptonsAsMET/F");
    tree_->Branch("dPhiHemHem_LeadLeptonsAsMET",&dPhiHemHem_LeadLeptonsAsMET,"dPhiHemHem_LeadLeptonsAsMET/F");
    tree_->Branch("NJets40",&NJets40,"NJets40/i");
    tree_->Branch("NJets80",&NJets80,"NJets80/i");
    tree_->Branch("NBJetsLoose",&NBJetsLoose,"NBJetsLoose/i");
    tree_->Branch("NBJetsMedium",&NBJetsMedium,"NBJetsMedium/i");
    tree_->Branch("NBJetsTight",&NBJetsTight,"NBJetsTight/i");
    tree_->Branch("HT",&HT,"HT/F");
    tree_->Branch("lep1MT",&lep1MT,"lep1MT/F");
    tree_->Branch("genlep1", "TLorentzVector", &genlep1Ptr);
    tree_->Branch("genlep2", "TLorentzVector", &genlep2Ptr);
    tree_->Branch("lep1",    "TLorentzVector", &lep1Ptr);
    tree_->Branch("lep2",    "TLorentzVector", &lep2Ptr);
    tree_->Branch("bjet1",   "TLorentzVector", &bjet1Ptr);
    tree_->Branch("bjet2",   "TLorentzVector", &bjet2Ptr);
    tree_->Branch("jet1",    "TLorentzVector", &jet1Ptr);
    tree_->Branch("jet2",    "TLorentzVector", &jet2Ptr);
  } 
  
  void InitTreeSmall()
  {
    assert(tree_);
    // don't forget to set pointers to zero before you set address
    // or you will fully appreciate that "ROOT sucks" :)             
    InitVariables();
    //Set branch address                                               
    Int_t currentState = gErrorIgnoreLevel;
    
    tree_->SetBranchStatus("*", 0);
    tree_->SetBranchStatus("lep1Type", 1);
    tree_->SetBranchStatus("lep1PassLoose", 1);
    tree_->SetBranchStatus("lep2Type", 1);
    tree_->SetBranchStatus("lep2PassLoose", 1);
    tree_->SetBranchStatus("NBJetsLoose", 1);
    tree_->SetBranchStatus("NBJetsMedium", 1);
    tree_->SetBranchStatus("MR", 1);
    tree_->SetBranchStatus("Rsq", 1);
    tree_->SetBranchStatus("lep1MT", 1);
    tree_->SetBranchStatus("HT", 1);
    tree_->SetBranchStatus("MET", 1);
    tree_->SetBranchStatus("xs_w", 1);
    tree_->SetBranchStatus("xs_w_kf", 1);
    tree_->SetBranchStatus("lep1", 1);
    tree_->SetBranchStatus("lep2", 1);
    //tree_->SetBranchStatus("", 1);
    //tree_->SetBranchStatus("", 1);

    tree_->SetBranchAddress("lep1Type",&lep1Type);
    tree_->SetBranchAddress("lep2Type",&lep2Type);
    tree_->SetBranchAddress("lep1PassLoose",&lep1PassLoose);
    tree_->SetBranchAddress("lep2PassLoose",&lep2PassLoose);
    tree_->SetBranchAddress("MR",&MR);
    tree_->SetBranchAddress("Rsq",&Rsq);
    tree_->SetBranchAddress("NBJetsLoose",&NBJetsLoose);
    tree_->SetBranchAddress("NBJetsMedium",&NBJetsMedium);
    tree_->SetBranchAddress("HT",&HT);
    tree_->SetBranchAddress("MET",&MET);
    tree_->SetBranchAddress("lep1MT",&lep1MT);
    tree_->SetBranchAddress("lep1",&lep1Ptr);
    tree_->SetBranchAddress("lep2",&lep2Ptr);
    tree_->SetBranchAddress("xs_w", &xs_w);
    tree_->SetBranchAddress("xs_w_kf", &xs_w_kf);

    gErrorIgnoreLevel = currentState;
    
  }
  
  // initialze a ControlSampleEvents
  void InitTree(){
    assert(tree_);
    // don't forget to set pointers to zero before you set address
    // or you will fully appreciate that "ROOT sucks" :)
    InitVariables();
    //Set branch address
    Int_t currentState = gErrorIgnoreLevel;
    
    tree_->SetBranchAddress("weight",&weight);
    tree_->SetBranchAddress("run",&run);
    tree_->SetBranchAddress("lumi",&lumi);
    tree_->SetBranchAddress("event",&event);
    tree_->SetBranchAddress("processID",&processID);
    tree_->SetBranchAddress("NPU_0",&NPU_0);
    tree_->SetBranchAddress("NPU_Minus1",&NPU_Minus1);
    tree_->SetBranchAddress("NPU_Plus1",&NPU_Plus1);
    tree_->SetBranchAddress("genlep1Type",&genlep1Type);
    tree_->SetBranchAddress("genlep2Type",&genlep2Type);
    tree_->SetBranchAddress("lep1Type",&lep1Type);
    tree_->SetBranchAddress("lep2Type",&lep2Type);
    tree_->SetBranchAddress("lep1MatchedGenLepIndex",&lep1MatchedGenLepIndex);
    tree_->SetBranchAddress("lep2MatchedGenLepIndex",&lep2MatchedGenLepIndex);
    tree_->SetBranchAddress("lep1PassVeto",&lep1PassVeto);
    tree_->SetBranchAddress("lep1PassLoose",&lep1PassLoose);
    tree_->SetBranchAddress("lep1PassTight",&lep1PassTight);
    tree_->SetBranchAddress("lep2PassVeto",&lep2PassVeto);
    tree_->SetBranchAddress("lep2PassLoose",&lep2PassLoose);
    tree_->SetBranchAddress("lep2PassTight",&lep2PassTight);
    tree_->SetBranchAddress("bjet1PassLoose",&bjet1PassLoose);
    tree_->SetBranchAddress("bjet1PassMedium",&bjet1PassMedium);
    tree_->SetBranchAddress("bjet1PassTight",&bjet1PassTight);
    tree_->SetBranchAddress("bjet2PassLoose",&bjet2PassLoose);
    tree_->SetBranchAddress("bjet2PassMedium",&bjet2PassMedium);
    tree_->SetBranchAddress("bjet2PassTight",&bjet2PassTight);
    tree_->SetBranchAddress("jet1PassCSVLoose",&jet1PassCSVLoose);
    tree_->SetBranchAddress("jet1PassCSVMedium",&jet1PassCSVMedium);
    tree_->SetBranchAddress("jet1PassCSVTight",&jet1PassCSVTight);
    tree_->SetBranchAddress("jet2PassCSVLoose",&jet2PassCSVLoose);
    tree_->SetBranchAddress("jet2PassCSVMedium",&jet2PassCSVMedium);
    tree_->SetBranchAddress("jet2PassCSVTight",&jet2PassCSVTight);
    tree_->SetBranchAddress("MR",&MR);
    tree_->SetBranchAddress("Rsq",&Rsq);
    tree_->SetBranchAddress("MR_LeadLeptonsAsMET",&MR_LeadLeptonsAsMET);
    tree_->SetBranchAddress("Rsq_LeadLeptonsAsMET",&Rsq_LeadLeptonsAsMET);
    tree_->SetBranchAddress("MR_LeptonsAsMET",&MR_LeptonsAsMET);
    tree_->SetBranchAddress("Rsq_LeptonsAsMET",&Rsq_LeptonsAsMET);
    tree_->SetBranchAddress("MET",&MET);
    tree_->SetBranchAddress("MET_LeadLeptonsAsMET",&MET_LeadLeptonsAsMET);
    tree_->SetBranchAddress("MET_LeptonsAsMET",&MET_LeptonsAsMET);
    tree_->SetBranchAddress("minDPhi",&minDPhi);
    tree_->SetBranchAddress("minDPhiN",&minDPhiN);
    tree_->SetBranchAddress("dPhiHemHem",&dPhiHemHem);
    tree_->SetBranchAddress("dPhiHemHem_LeptonsAsMET",&dPhiHemHem_LeptonsAsMET);
    tree_->SetBranchAddress("dPhiHemHem_LeadLeptonsAsMET",&dPhiHemHem_LeadLeptonsAsMET);
    tree_->SetBranchAddress("NJets40",&NJets40);
    tree_->SetBranchAddress("NJets80",&NJets80);
    tree_->SetBranchAddress("NBJetsLoose",&NBJetsLoose);
    tree_->SetBranchAddress("NBJetsMedium",&NBJetsMedium);
    tree_->SetBranchAddress("NBJetsTight",&NBJetsTight);
    tree_->SetBranchAddress("HT",&HT);
    tree_->SetBranchAddress("lep1MT",&lep1MT);	
    tree_->SetBranchAddress("genlep1",&genlep1Ptr);
    tree_->SetBranchAddress("genlep2",&genlep2Ptr);
    tree_->SetBranchAddress("lep1",&lep1Ptr);
    tree_->SetBranchAddress("lep2",&lep2Ptr);
    tree_->SetBranchAddress("bjet1",&bjet1Ptr);
    tree_->SetBranchAddress("bjet2",&bjet2Ptr);
    tree_->SetBranchAddress("jet1",&jet1Ptr);
    tree_->SetBranchAddress("jet2",&jet2Ptr);
    tree_->SetBranchAddress("xs_w", &xs_w);
    tree_->SetBranchAddress("xs_w_kf", &xs_w_kf);
    
    gErrorIgnoreLevel = currentState;
  }
  
private:
  TLorentzVector* genlep1Ptr;
  TLorentzVector* genlep2Ptr;
  TLorentzVector* lep1Ptr;
  TLorentzVector* lep2Ptr;
  TLorentzVector* bjet1Ptr;
  TLorentzVector* bjet2Ptr;
  TLorentzVector* jet1Ptr;
  TLorentzVector* jet2Ptr;
      
}; 


#endif

