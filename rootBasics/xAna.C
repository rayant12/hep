// example code to fill histograms using the variables in a TTree


#include <vector>
#include <iostream>
#include <TH1D.h>
#include <TFile.h>
#include "untuplizer.h"
#include <TCanvas.h>

using namespace std;
void xAna(std::string inputFile){

  //get TTree from file ...
  TreeReader data(inputFile.data(),"tree");

  const int nbins=200;
  const float xmin=-4;
  const float xmax= 4;
  const float binwidth = (xmax-xmin)/(float)nbins;

  TH1F* h_eta=new TH1F("h_eta","",nbins,xmin,xmax);
  h_eta->SetXTitle("#eta");
  h_eta->SetYTitle(Form("Number of events per %.2f",binwidth));

  //Event loop
  for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){

    if (jEntry % 50000 == 0)
      fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());

    data.GetEntry(jEntry);

    float thiseta = data.GetFloat("eta");

    h_eta->Fill(thiseta);

  } // end of loop over entries

  // now we can perform the fit
  TCanvas* c1 = new TCanvas("c1");
  h_eta->Fit("gaus");
  c1->Print("etafit.pdf");
    
}
