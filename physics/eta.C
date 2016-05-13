#include <TH1.h>
#include <TRandom3.h>
#include <TMath.h>
#include <TFile.h>
void eta()
{
  TH1F* h_eta = new TH1F("h_eta","",100,-10,10);
  TH1F* h_theta = new TH1F("h_theta","",100,0,TMath::Pi());
  
  const int neve=10000;
  TRandom3* myrndm = new TRandom3();
  for(unsigned int i=0; i<neve; i++){
    float theta = myrndm->Rndm()*TMath::Pi();
    h_theta->Fill(theta);

    float eta = -TMath::Log(TMath::Tan(0.5*theta));

    h_eta->Fill(eta);
  }

  h_theta->Draw();
  h_eta->Draw();

  TFile* outFile = new TFile("eta_theta.root","recreate");
  
  h_theta->Write();
  h_eta->Write();

  outFile->Close();


}
