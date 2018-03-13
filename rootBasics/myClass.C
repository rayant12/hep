#define myClass_cxx
#include "myClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>

void myClass::Loop()
{
//   In a ROOT session, you can do:
//      root> .L myClass.C
//      root> myClass t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      cout << "number of particles = " << fParticles_ << endl;

      for(int ip=0; ip<fParticles_;ip++){
	
	Double_t eta = fParticles_fMomentumEta[ip];
	Double_t theta = TMath::ATan(TMath::Exp(-eta))*2.0;
	
	Double_t pz = fParticles_fMomentum[ip]*TMath::Cos(theta);
	Double_t pt = fParticles_fMomentum[ip]*TMath::Sin(theta);
	Double_t px = pt*TMath::Cos(fParticles_fMomentumPhi[ip]);
	Double_t py = pt*TMath::Sin(fParticles_fMomentumPhi[ip]);

	
	cout << "(px, py, pz) = (" << px << ", " << py << ", " << pz << ") " << endl;

      } // end of loop over number of particles

   }
}
