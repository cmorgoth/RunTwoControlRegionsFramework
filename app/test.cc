//C++ INCLUDE
#include <iostream>
#include <vector>
#include <map>
//ROOT INCLUDE

//LOCAL INCLUDE
#include "ControlSampleEvents.hh"
#include "BoxStructure.hh"
#include "BkgData.hh"

int main( )
{

  ControlSampleEvents* CSE = new ControlSampleEvents( );
  BoxStructure* BS = new BoxStructure( );
  BkgData* BD = new BkgData( );
  //BS->SetDebugLevel( true );
  //BS->SetInfoLevel( true );
  float Mr_bin[] = {1,2,3,4,5,6,7,8,9,10,11};
  //BS->SetMrBinning( 10, 200.0, 2500.0 );
  BS->SetMrBinning( 10, Mr_bin); 
  BS->CreateMr( );
  BS->CreateRsq( );
  BS->CreateNjet( );
  BS->CreateHT( );
  BS->CreateOneLepMT( );
  BS->SetMassTwoLeptonsBinning( 50, 70.0, 110.0 );
  BS->CreateMassTwoLeptons( );
  BS->FillMassTwoLeptons( 90.0, 1.0 );
  BS->~BoxStructure( );
  return 0;
}
