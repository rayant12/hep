//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Mar 13 11:13:44 2018 by ROOT version 6.06/08
// from TTree EventTree/Tutorial tree
// found on file: eventdata.root
//////////////////////////////////////////////////////////

#ifndef myClass_h
#define myClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <iostream>

using namespace std;

// Header file for the classes stored in the TTree if any.

class myClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
//   const Int_t 1200 = 1200;

   // Declaration of leaf types
 //EventData       *event;
   Int_t           fParticles_;
   Double_t        fParticles_fPosX[1200];   //[fParticles_]
   Double_t        fParticles_fPosY[1200];   //[fParticles_]
   Double_t        fParticles_fPosZ[1200];   //[fParticles_]
   Double_t        fParticles_fMomentum[1200];   //[fParticles_]
   Double_t        fParticles_fMomentumPhi[1200];   //[fParticles_]
   Double_t        fParticles_fMomentumEta[1200];   //[fParticles_]
   Long64_t        fParticles_fTags[1200][128];   //[fParticles_]
   Int_t           fEventSize;

   // List of branches
   TBranch        *b_event_fParticles_;   //!
   TBranch        *b_fParticles_fPosX;   //!
   TBranch        *b_fParticles_fPosY;   //!
   TBranch        *b_fParticles_fPosZ;   //!
   TBranch        *b_fParticles_fMomentum;   //!
   TBranch        *b_fParticles_fMomentumPhi;   //!
   TBranch        *b_fParticles_fMomentumEta;   //!
   TBranch        *b_fParticles_fTags;   //!
   TBranch        *b_event_fEventSize;   //!

   myClass(TTree *tree=0);
   virtual ~myClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef myClass_cxx
myClass::myClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("eventdata.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("eventdata.root");
      }
      f->GetObject("EventTree",tree);

   }
   Init(tree);
}

myClass::~myClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t myClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t myClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void myClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fParticles", &fParticles_, &b_event_fParticles_);
   fChain->SetBranchAddress("fParticles.fPosX", fParticles_fPosX, &b_fParticles_fPosX);
   fChain->SetBranchAddress("fParticles.fPosY", fParticles_fPosY, &b_fParticles_fPosY);
   fChain->SetBranchAddress("fParticles.fPosZ", fParticles_fPosZ, &b_fParticles_fPosZ);
   fChain->SetBranchAddress("fParticles.fMomentum", fParticles_fMomentum, &b_fParticles_fMomentum);
   fChain->SetBranchAddress("fParticles.fMomentumPhi", fParticles_fMomentumPhi, &b_fParticles_fMomentumPhi);
   fChain->SetBranchAddress("fParticles.fMomentumEta", fParticles_fMomentumEta, &b_fParticles_fMomentumEta);
   fChain->SetBranchAddress("fParticles.fTags[128]", fParticles_fTags, &b_fParticles_fTags);
   fChain->SetBranchAddress("fEventSize", &fEventSize, &b_event_fEventSize);
   Notify();
}

Bool_t myClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void myClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t myClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef myClass_cxx
