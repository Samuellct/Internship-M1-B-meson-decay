#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TLegend.h"
#include "TVector3.h"
#include "TMath.h"



// Données true identifiées avec un préfixe "_Tuple"
// Données reconstruites pas d'ajout ou (MC) a partir des boucles
// Données calculées dans ce code identifiées avec un préfixe "_Rebuilt"



void full_calc() {
    TFile* datafiltered_Tfile = TFile::Open("radiativeXpi0G_MC2017-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco17_S29r2_MagDown_mergeAll_ntp.root");
    TTree* datafiltered_Ttree = (TTree*)datafiltered_Tfile->Get("kpipipi0GTupleMC/DecayTree");

    // ----------------------- Variables MC rebuilt -----------------------
    Int_t piplus_ID;
    Double_t piplus_PE, piplus_PX, piplus_PY, piplus_PZ, piplus_PT;

    Int_t piminus_ID;
    Double_t piminus_PE, piminus_PX, piminus_PY, piminus_PZ, piminus_PT;

    Double_t pi0_PX, pi0_PY, pi0_PZ, pi0_PE, pi0_PT;
    Int_t pi0_ID;

    Int_t gamma0_ID;
    Double_t gamma0_PX, gamma0_PY, gamma0_PZ, gamma0_PE, gamma0_PT;

    Int_t gamma1_ID;
    Double_t gamma1_PX, gamma1_PY, gamma1_PZ, gamma1_PE, gamma1_PT;

    Int_t Kplus_ID;
    Double_t Kplus_PX, Kplus_PY, Kplus_PZ, Kplus_PE, Kplus_PT;

    Double_t K_1_plus_PX, K_1_plus_PY, K_1_plus_PZ, K_1_plus_PE, K_1_plus_PT;
    Int_t K_1_plus_ID;

    Double_t B_PX, B_PY, B_PZ, B_PE, B_PT;
    Int_t B_ID;

    Double_t gamma_PE, gamma_PX, gamma_PY, gamma_PZ, gamma_PT;
    Int_t gamma_ID;

    // -----------------------Variables MC true -----------------------
    Int_t piplus_TRUEID;
    Double_t piplus_TRUEP_E, piplus_TRUEP_X, piplus_TRUEP_Y, piplus_TRUEP_Z, piplus_TRUEPT, piplus_TRUEORIGINVERTEX_X, piplus_TRUEORIGINVERTEX_Y, piplus_TRUEORIGINVERTEX_Z, piplus_TRUEENDVERTEX_X, piplus_TRUEENDVERTEX_Y, piplus_TRUEENDVERTEX_Z;

    Int_t piminus_TRUEID;
    Double_t piminus_TRUEP_E, piminus_TRUEP_X, piminus_TRUEP_Y, piminus_TRUEP_Z, piminus_TRUEPT, piminus_TRUEORIGINVERTEX_X, piminus_TRUEORIGINVERTEX_Y, piminus_TRUEORIGINVERTEX_Z, piminus_TRUEENDVERTEX_X, piminus_TRUEENDVERTEX_Y, piminus_TRUEENDVERTEX_Z;

    Double_t Tuple_pi0_TRUEP_X, Tuple_pi0_TRUEP_Y, Tuple_pi0_TRUEP_Z, Tuple_pi0_TRUEP_E, Tuple_pi0_TRUEPT, Tuple_pi0_TRUEORIGINVERTEX_X, Tuple_pi0_TRUEORIGINVERTEX_Y, Tuple_pi0_TRUEORIGINVERTEX_Z, Tuple_pi0_TRUEENDVERTEX_X, Tuple_pi0_TRUEENDVERTEX_Y, Tuple_pi0_TRUEENDVERTEX_Z;
    Int_t Tuple_pi0_TRUEID;

    Int_t gamma0_TRUEID;
    Double_t gamma0_TRUEP_X, gamma0_TRUEP_Y, gamma0_TRUEP_Z, gamma0_TRUEP_E, gamma0_TRUEPT, gamma0_TRUEORIGINVERTEX_X, gamma0_TRUEORIGINVERTEX_Y, gamma0_TRUEORIGINVERTEX_Z, gamma0_TRUEENDVERTEX_X, gamma0_TRUEENDVERTEX_Y, gamma0_TRUEENDVERTEX_Z;

    Int_t gamma1_TRUEID;
    Double_t gamma1_TRUEP_X, gamma1_TRUEP_Y, gamma1_TRUEP_Z, gamma1_TRUEP_E, gamma1_TRUEPT, gamma1_TRUEORIGINVERTEX_X, gamma1_TRUEORIGINVERTEX_Y, gamma1_TRUEORIGINVERTEX_Z, gamma1_TRUEENDVERTEX_X, gamma1_TRUEENDVERTEX_Y, gamma1_TRUEENDVERTEX_Z;

    Int_t Kplus_TRUEID;
    Double_t Kplus_TRUEP_X, Kplus_TRUEP_Y, Kplus_TRUEP_Z, Kplus_TRUEP_E, Kplus_TRUEPT, Kplus_TRUEORIGINVERTEX_X, Kplus_TRUEORIGINVERTEX_Y, Kplus_TRUEORIGINVERTEX_Z, Kplus_TRUEENDVERTEX_X, Kplus_TRUEENDVERTEX_Y, Kplus_TRUEENDVERTEX_Z;

    Double_t Tuple_K_1_plus_TRUEP_X, Tuple_K_1_plus_TRUEP_Y, Tuple_K_1_plus_TRUEP_Z, Tuple_K_1_plus_TRUEP_E, Tuple_K_1_plus_TRUEPT, Tuple_K_1_plus_TRUEORIGINVERTEX_X, Tuple_K_1_plus_TRUEORIGINVERTEX_Y, Tuple_K_1_plus_TRUEORIGINVERTEX_Z, Tuple_K_1_plus_TRUEENDVERTEX_X, Tuple_K_1_plus_TRUEENDVERTEX_Y, Tuple_K_1_plus_TRUEENDVERTEX_Z;
    Int_t Tuple_K_1_plus_TRUEID;

    Double_t Tuple_B_TRUEP_X, Tuple_B_TRUEP_Y, Tuple_B_TRUEP_Z, Tuple_B_TRUEP_E, Tuple_B_TRUEPT, Tuple_B_TRUEORIGINVERTEX_X, Tuple_B_TRUEORIGINVERTEX_Y, Tuple_B_TRUEORIGINVERTEX_Z, Tuple_B_TRUEENDVERTEX_X, Tuple_B_TRUEENDVERTEX_Y, Tuple_B_TRUEENDVERTEX_Z;
    Int_t Tuple_B_TRUEID;

    Double_t gamma_TRUEP_E, gamma_TRUEP_X, gamma_TRUEP_Y, gamma_TRUEP_Z, gamma_TRUEPT, gamma_TRUEORIGINVERTEX_X, gamma_TRUEORIGINVERTEX_Y, gamma_TRUEORIGINVERTEX_Z, gamma_TRUEENDVERTEX_X, gamma_TRUEENDVERTEX_Y, gamma_TRUEENDVERTEX_Z;
    Int_t gamma_TRUEID;

    Int_t B_BKGCAT;
    // ----------------------- activer les branches utiles -----------------------
    datafiltered_Ttree->SetBranchStatus("*", 0);

    datafiltered_Ttree->SetBranchStatus("B_BKGCAT", 1);

    datafiltered_Ttree->SetBranchStatus("B_TRUEP_E", 1);
    datafiltered_Ttree->SetBranchStatus("B_TRUEP_X", 1);
    datafiltered_Ttree->SetBranchStatus("B_TRUEP_Y", 1);
    datafiltered_Ttree->SetBranchStatus("B_TRUEP_Z", 1);
    datafiltered_Ttree->SetBranchStatus("B_TRUEID", 1);        

    datafiltered_Ttree->SetBranchStatus("piplus_TRUEP_E", 1);
    datafiltered_Ttree->SetBranchStatus("piplus_TRUEP_X", 1);
    datafiltered_Ttree->SetBranchStatus("piplus_TRUEP_Y", 1);
    datafiltered_Ttree->SetBranchStatus("piplus_TRUEP_Z", 1);
    datafiltered_Ttree->SetBranchStatus("piplus_TRUEID", 1);

    datafiltered_Ttree->SetBranchStatus("piminus_TRUEP_E", 1);
    datafiltered_Ttree->SetBranchStatus("piminus_TRUEP_X", 1);
    datafiltered_Ttree->SetBranchStatus("piminus_TRUEP_Y", 1);
    datafiltered_Ttree->SetBranchStatus("piminus_TRUEP_Z", 1);
    datafiltered_Ttree->SetBranchStatus("piminus_TRUEID", 1);

    datafiltered_Ttree->SetBranchStatus("pi0_TRUEP_E", 1);
    datafiltered_Ttree->SetBranchStatus("pi0_TRUEP_X", 1);
    datafiltered_Ttree->SetBranchStatus("pi0_TRUEP_Y", 1);
    datafiltered_Ttree->SetBranchStatus("pi0_TRUEP_Z", 1);
    datafiltered_Ttree->SetBranchStatus("pi0_TRUEID", 1);

    datafiltered_Ttree->SetBranchStatus("gamma0_TRUEP_E", 1);
    datafiltered_Ttree->SetBranchStatus("gamma0_TRUEP_X", 1);
    datafiltered_Ttree->SetBranchStatus("gamma0_TRUEP_Y", 1);
    datafiltered_Ttree->SetBranchStatus("gamma0_TRUEP_Z", 1);
    datafiltered_Ttree->SetBranchStatus("gamma0_TRUEID", 1);

    datafiltered_Ttree->SetBranchStatus("gamma1_TRUEP_E", 1);
    datafiltered_Ttree->SetBranchStatus("gamma1_TRUEP_X", 1);
    datafiltered_Ttree->SetBranchStatus("gamma1_TRUEP_Y", 1);
    datafiltered_Ttree->SetBranchStatus("gamma1_TRUEP_Z", 1);
    datafiltered_Ttree->SetBranchStatus("gamma1_TRUEID", 1);

    datafiltered_Ttree->SetBranchStatus("Kplus_TRUEP_E", 1);
    datafiltered_Ttree->SetBranchStatus("Kplus_TRUEP_X", 1);
    datafiltered_Ttree->SetBranchStatus("Kplus_TRUEP_Y", 1);
    datafiltered_Ttree->SetBranchStatus("Kplus_TRUEP_Z", 1);
    datafiltered_Ttree->SetBranchStatus("Kplus_TRUEID", 1);

    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_TRUEP_E", 1);
    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_TRUEP_X", 1);
    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_TRUEP_Y", 1);
    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_TRUEP_Z", 1);
    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_TRUEID", 1);

    datafiltered_Ttree->SetBranchStatus("gamma_TRUEP_E", 1);
    datafiltered_Ttree->SetBranchStatus("gamma_TRUEP_X", 1);
    datafiltered_Ttree->SetBranchStatus("gamma_TRUEP_Y", 1);
    datafiltered_Ttree->SetBranchStatus("gamma_TRUEP_Z", 1);
    datafiltered_Ttree->SetBranchStatus("gamma_TRUEID", 1);

    datafiltered_Ttree->SetBranchStatus("B_PE", 1);
    datafiltered_Ttree->SetBranchStatus("B_PX", 1);
    datafiltered_Ttree->SetBranchStatus("B_PY", 1);
    datafiltered_Ttree->SetBranchStatus("B_PZ", 1);
    datafiltered_Ttree->SetBranchStatus("B_ID", 1);

    datafiltered_Ttree->SetBranchStatus("piplus_PE", 1);
    datafiltered_Ttree->SetBranchStatus("piplus_PX", 1);
    datafiltered_Ttree->SetBranchStatus("piplus_PY", 1);
    datafiltered_Ttree->SetBranchStatus("piplus_PZ", 1);
    datafiltered_Ttree->SetBranchStatus("piplus_ID", 1);

    datafiltered_Ttree->SetBranchStatus("piminus_PE", 1);
    datafiltered_Ttree->SetBranchStatus("piminus_PX", 1);
    datafiltered_Ttree->SetBranchStatus("piminus_PY", 1);
    datafiltered_Ttree->SetBranchStatus("piminus_PZ", 1);
    datafiltered_Ttree->SetBranchStatus("piminus_ID", 1);

    datafiltered_Ttree->SetBranchStatus("pi0_PE", 1);
    datafiltered_Ttree->SetBranchStatus("pi0_PX", 1);
    datafiltered_Ttree->SetBranchStatus("pi0_PY", 1);
    datafiltered_Ttree->SetBranchStatus("pi0_PZ", 1);
    datafiltered_Ttree->SetBranchStatus("pi0_ID", 1);

    datafiltered_Ttree->SetBranchStatus("gamma0_PE", 1);
    datafiltered_Ttree->SetBranchStatus("gamma0_PX", 1);
    datafiltered_Ttree->SetBranchStatus("gamma0_PY", 1);
    datafiltered_Ttree->SetBranchStatus("gamma0_PZ", 1);
    datafiltered_Ttree->SetBranchStatus("gamma0_ID", 1);

    datafiltered_Ttree->SetBranchStatus("gamma1_PE", 1);
    datafiltered_Ttree->SetBranchStatus("gamma1_PX", 1);
    datafiltered_Ttree->SetBranchStatus("gamma1_PY", 1);
    datafiltered_Ttree->SetBranchStatus("gamma1_PZ", 1);
    datafiltered_Ttree->SetBranchStatus("gamma1_ID", 1);

    datafiltered_Ttree->SetBranchStatus("Kplus_PE", 1);
    datafiltered_Ttree->SetBranchStatus("Kplus_PX", 1);
    datafiltered_Ttree->SetBranchStatus("Kplus_PY", 1);
    datafiltered_Ttree->SetBranchStatus("Kplus_PZ", 1);
    datafiltered_Ttree->SetBranchStatus("Kplus_ID", 1);

    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_PE", 1);
    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_PX", 1);
    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_PY", 1);
    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_PZ", 1);
    datafiltered_Ttree->SetBranchStatus("K_2_1770_plus_ID", 1);

    datafiltered_Ttree->SetBranchStatus("gamma_PE", 1);
    datafiltered_Ttree->SetBranchStatus("gamma_PX", 1);
    datafiltered_Ttree->SetBranchStatus("gamma_PY", 1);
    datafiltered_Ttree->SetBranchStatus("gamma_PZ", 1);
    datafiltered_Ttree->SetBranchStatus("gamma_ID", 1);

    // ----------------------- Branch the input tree variables -----------------------
    datafiltered_Ttree->SetBranchAddress("B_BKGCAT", &B_BKGCAT);
    
    datafiltered_Ttree->SetBranchAddress("B_TRUEP_E", &Tuple_B_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("B_TRUEP_X", &Tuple_B_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("B_TRUEP_Y", &Tuple_B_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("B_TRUEP_Z", &Tuple_B_TRUEP_Z);
    datafiltered_Ttree->SetBranchAddress("B_TRUEID", &Tuple_B_TRUEID);

    datafiltered_Ttree->SetBranchAddress("piplus_TRUEP_E", &piplus_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("piplus_TRUEP_X", &piplus_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("piplus_TRUEP_Y", &piplus_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("piplus_TRUEP_Z", &piplus_TRUEP_Z);
    datafiltered_Ttree->SetBranchAddress("piplus_TRUEID", &piplus_TRUEID);

    datafiltered_Ttree->SetBranchAddress("piminus_TRUEP_E", &piminus_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("piminus_TRUEP_X", &piminus_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("piminus_TRUEP_Y", &piminus_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("piminus_TRUEP_Z", &piminus_TRUEP_Z);
    datafiltered_Ttree->SetBranchAddress("piminus_TRUEID", &piminus_TRUEID);

    datafiltered_Ttree->SetBranchAddress("pi0_TRUEP_E", &Tuple_pi0_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("pi0_TRUEP_X", &Tuple_pi0_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("pi0_TRUEP_Y", &Tuple_pi0_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("pi0_TRUEP_Z", &Tuple_pi0_TRUEP_Z);
    datafiltered_Ttree->SetBranchAddress("pi0_TRUEID", &Tuple_pi0_TRUEID);

    datafiltered_Ttree->SetBranchAddress("gamma0_TRUEP_E", &gamma0_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("gamma0_TRUEP_X", &gamma0_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("gamma0_TRUEP_Y", &gamma0_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("gamma0_TRUEP_Z", &gamma0_TRUEP_Z);
    datafiltered_Ttree->SetBranchAddress("gamma0_TRUEID", &gamma0_TRUEID);

    datafiltered_Ttree->SetBranchAddress("gamma1_TRUEP_E", &gamma1_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("gamma1_TRUEP_X", &gamma1_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("gamma1_TRUEP_Y", &gamma1_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("gamma1_TRUEP_Z", &gamma1_TRUEP_Z);
    datafiltered_Ttree->SetBranchAddress("gamma1_TRUEID", &gamma1_TRUEID);

    datafiltered_Ttree->SetBranchAddress("Kplus_TRUEP_E", &Kplus_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("Kplus_TRUEP_X", &Kplus_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("Kplus_TRUEP_Y", &Kplus_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("Kplus_TRUEP_Z", &Kplus_TRUEP_Z);
    datafiltered_Ttree->SetBranchAddress("Kplus_TRUEID", &Kplus_TRUEID);

    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_TRUEP_E", &Tuple_K_1_plus_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_TRUEP_X", &Tuple_K_1_plus_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_TRUEP_Y", &Tuple_K_1_plus_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_TRUEP_Z", &Tuple_K_1_plus_TRUEP_Z);
    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_TRUEID", &Tuple_K_1_plus_TRUEID);

    datafiltered_Ttree->SetBranchAddress("gamma_TRUEP_E", &gamma_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("gamma_TRUEP_X", &gamma_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("gamma_TRUEP_Y", &gamma_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("gamma_TRUEP_Z", &gamma_TRUEP_Z);
    datafiltered_Ttree->SetBranchAddress("gamma_TRUEID", &gamma_TRUEID);

    datafiltered_Ttree->SetBranchAddress("B_PE", &B_PE);
    datafiltered_Ttree->SetBranchAddress("B_PX", &B_PX);
    datafiltered_Ttree->SetBranchAddress("B_PY", &B_PY);
    datafiltered_Ttree->SetBranchAddress("B_PZ", &B_PZ);
    datafiltered_Ttree->SetBranchAddress("B_ID", &B_ID);

    datafiltered_Ttree->SetBranchAddress("piplus_PE", &piplus_PE);
    datafiltered_Ttree->SetBranchAddress("piplus_PX", &piplus_PX);
    datafiltered_Ttree->SetBranchAddress("piplus_PY", &piplus_PY);
    datafiltered_Ttree->SetBranchAddress("piplus_PZ", &piplus_PZ);
    datafiltered_Ttree->SetBranchAddress("piplus_ID", &piplus_ID);

    datafiltered_Ttree->SetBranchAddress("piminus_PE", &piminus_PE);
    datafiltered_Ttree->SetBranchAddress("piminus_PX", &piminus_PX);
    datafiltered_Ttree->SetBranchAddress("piminus_PY", &piminus_PY);
    datafiltered_Ttree->SetBranchAddress("piminus_PZ", &piminus_PZ);
    datafiltered_Ttree->SetBranchAddress("piminus_ID", &piminus_ID);

    datafiltered_Ttree->SetBranchAddress("pi0_PE", &pi0_PE);
    datafiltered_Ttree->SetBranchAddress("pi0_PX", &pi0_PX);
    datafiltered_Ttree->SetBranchAddress("pi0_PY", &pi0_PY);
    datafiltered_Ttree->SetBranchAddress("pi0_PZ", &pi0_PZ);
    datafiltered_Ttree->SetBranchAddress("pi0_ID", &pi0_ID);

    datafiltered_Ttree->SetBranchAddress("gamma0_PE", &gamma0_PE);
    datafiltered_Ttree->SetBranchAddress("gamma0_PX", &gamma0_PX);
    datafiltered_Ttree->SetBranchAddress("gamma0_PY", &gamma0_PY);
    datafiltered_Ttree->SetBranchAddress("gamma0_PZ", &gamma0_PZ);
    datafiltered_Ttree->SetBranchAddress("gamma0_ID", &gamma0_ID);

    datafiltered_Ttree->SetBranchAddress("gamma1_PE", &gamma1_PE);
    datafiltered_Ttree->SetBranchAddress("gamma1_PX", &gamma1_PX);
    datafiltered_Ttree->SetBranchAddress("gamma1_PY", &gamma1_PY);
    datafiltered_Ttree->SetBranchAddress("gamma1_PZ", &gamma1_PZ);
    datafiltered_Ttree->SetBranchAddress("gamma1_ID", &gamma1_ID);

    datafiltered_Ttree->SetBranchAddress("Kplus_PE", &Kplus_PE);
    datafiltered_Ttree->SetBranchAddress("Kplus_PX", &Kplus_PX);
    datafiltered_Ttree->SetBranchAddress("Kplus_PY", &Kplus_PY);
    datafiltered_Ttree->SetBranchAddress("Kplus_PZ", &Kplus_PZ);
    datafiltered_Ttree->SetBranchAddress("Kplus_ID", &Kplus_ID);

    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_PE", &K_1_plus_PE);
    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_PX", &K_1_plus_PX);
    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_PY", &K_1_plus_PY);
    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_PZ", &K_1_plus_PZ);
    datafiltered_Ttree->SetBranchAddress("K_2_1770_plus_ID", &K_1_plus_ID);

    datafiltered_Ttree->SetBranchAddress("gamma_PE", &gamma_PE);
    datafiltered_Ttree->SetBranchAddress("gamma_PX", &gamma_PX);
    datafiltered_Ttree->SetBranchAddress("gamma_PY", &gamma_PY);
    datafiltered_Ttree->SetBranchAddress("gamma_PZ", &gamma_PZ);
    datafiltered_Ttree->SetBranchAddress("gamma_ID", &gamma_ID);


    // ----------------------- Update the outputFile + new TTree -----------------------
    TFile* outputFile = new TFile("datacut.root", "RECREATE");
    TTree* FullTree = new TTree("FullTree", "TTree with selected variables");

    // ----------------------- Add branches to FullTree -----------------------
    FullTree->Branch("B_TRUEP_E", &Tuple_B_TRUEP_E);
    FullTree->Branch("B_TRUEP_X", &Tuple_B_TRUEP_X);
    FullTree->Branch("B_TRUEP_Y", &Tuple_B_TRUEP_Y);
    FullTree->Branch("B_TRUEP_Z", &Tuple_B_TRUEP_Z);
    FullTree->Branch("B_TRUEID", &Tuple_B_TRUEID);
    FullTree->Branch("B_TRUEPT", &Tuple_B_TRUEPT);
    FullTree->Branch("B_TRUEORIGINVERTEX_X", &Tuple_B_TRUEORIGINVERTEX_X);
    FullTree->Branch("B_TRUEORIGINVERTEX_Y", &Tuple_B_TRUEORIGINVERTEX_Y);
    FullTree->Branch("B_TRUEORIGINVERTEX_Z", &Tuple_B_TRUEORIGINVERTEX_Z);
    FullTree->Branch("B_TRUEENDVERTEX_X", &Tuple_B_TRUEENDVERTEX_X);
    FullTree->Branch("B_TRUEENDVERTEX_Y", &Tuple_B_TRUEENDVERTEX_Y);
    FullTree->Branch("B_TRUEENDVERTEX_Z", &Tuple_B_TRUEENDVERTEX_Z);

    FullTree->Branch("pi0_TRUEP_E", &Tuple_pi0_TRUEP_E);
    FullTree->Branch("pi0_TRUEP_X", &Tuple_pi0_TRUEP_X);
    FullTree->Branch("pi0_TRUEP_Y", &Tuple_pi0_TRUEP_Y);
    FullTree->Branch("pi0_TRUEP_Z", &Tuple_pi0_TRUEP_Z);
    FullTree->Branch("pi0_TRUEID", &Tuple_pi0_TRUEID);
    FullTree->Branch("pi0_TRUEPT", &Tuple_pi0_TRUEPT);
    FullTree->Branch("pi0_TRUEORIGINVERTEX_X", &Tuple_pi0_TRUEORIGINVERTEX_X);
    FullTree->Branch("pi0_TRUEORIGINVERTEX_Y", &Tuple_pi0_TRUEORIGINVERTEX_Y);
    FullTree->Branch("pi0_TRUEORIGINVERTEX_Z", &Tuple_pi0_TRUEORIGINVERTEX_Z);
    FullTree->Branch("pi0_TRUEENDVERTEX_X", &Tuple_pi0_TRUEENDVERTEX_X);
    FullTree->Branch("pi0_TRUEENDVERTEX_Y", &Tuple_pi0_TRUEENDVERTEX_Y);
    FullTree->Branch("pi0_TRUEENDVERTEX_Z", &Tuple_pi0_TRUEENDVERTEX_Z);

    FullTree->Branch("K_2_1770_plus_TRUEP_E", &Tuple_K_1_plus_TRUEP_E);
    FullTree->Branch("K_2_1770_plus_TRUEP_X", &Tuple_K_1_plus_TRUEP_X);
    FullTree->Branch("K_2_1770_plus_TRUEP_Y", &Tuple_K_1_plus_TRUEP_Y);
    FullTree->Branch("K_2_1770_plus_TRUEP_Z", &Tuple_K_1_plus_TRUEP_Z);
    FullTree->Branch("K_2_1770_plus_TRUEID", &Tuple_K_1_plus_TRUEID);
    FullTree->Branch("K_2_1770_plus_TRUEPT", &Tuple_K_1_plus_TRUEPT);
    FullTree->Branch("K_2_1770_plus_TRUEORIGINVERTEX_X", &Tuple_K_1_plus_TRUEORIGINVERTEX_X);
    FullTree->Branch("K_2_1770_plus_TRUEORIGINVERTEX_Y", &Tuple_K_1_plus_TRUEORIGINVERTEX_Y);
    FullTree->Branch("K_2_1770_plus_TRUEORIGINVERTEX_Z", &Tuple_K_1_plus_TRUEORIGINVERTEX_Z);
    FullTree->Branch("K_2_1770_plus_TRUEENDVERTEX_X", &Tuple_K_1_plus_TRUEENDVERTEX_X);
    FullTree->Branch("K_2_1770_plus_TRUEENDVERTEX_Y", &Tuple_K_1_plus_TRUEENDVERTEX_Y);
    FullTree->Branch("K_2_1770_plus_TRUEENDVERTEX_Z", &Tuple_K_1_plus_TRUEENDVERTEX_Z);

    FullTree->Branch("piplus_TRUEP_E", &piplus_TRUEP_E);
    FullTree->Branch("piplus_TRUEP_X", &piplus_TRUEP_X);
    FullTree->Branch("piplus_TRUEP_Y", &piplus_TRUEP_Y);
    FullTree->Branch("piplus_TRUEP_Z", &piplus_TRUEP_Z);
    FullTree->Branch("piplus_TRUEID", &piplus_TRUEID);
    FullTree->Branch("piplus_TRUEPT", &piplus_TRUEPT);
    FullTree->Branch("piplus_TRUEORIGINVERTEX_X", &piplus_TRUEORIGINVERTEX_X);
    FullTree->Branch("piplus_TRUEORIGINVERTEX_Y", &piplus_TRUEORIGINVERTEX_Y);
    FullTree->Branch("piplus_TRUEORIGINVERTEX_Z", &piplus_TRUEORIGINVERTEX_Z);
    FullTree->Branch("piplus_TRUEENDVERTEX_X", &piplus_TRUEENDVERTEX_X);
    FullTree->Branch("piplus_TRUEENDVERTEX_Y", &piplus_TRUEENDVERTEX_Y);
    FullTree->Branch("piplus_TRUEENDVERTEX_Z", &piplus_TRUEENDVERTEX_Z);

    FullTree->Branch("piminus_TRUEP_E", &piminus_TRUEP_E);
    FullTree->Branch("piminus_TRUEP_X", &piminus_TRUEP_X);
    FullTree->Branch("piminus_TRUEP_Y", &piminus_TRUEP_Y);
    FullTree->Branch("piminus_TRUEP_Z", &piminus_TRUEP_Z);
    FullTree->Branch("piminus_TRUEID", &piminus_TRUEID);
    FullTree->Branch("piminus_TRUEPT", &piminus_TRUEPT);
    FullTree->Branch("piminus_TRUEORIGINVERTEX_X", &piminus_TRUEORIGINVERTEX_X);
    FullTree->Branch("piminus_TRUEORIGINVERTEX_Y", &piminus_TRUEORIGINVERTEX_Y);
    FullTree->Branch("piminus_TRUEORIGINVERTEX_Z", &piminus_TRUEORIGINVERTEX_Z);
    FullTree->Branch("piminus_TRUEENDVERTEX_X", &piminus_TRUEENDVERTEX_X);
    FullTree->Branch("piminus_TRUEENDVERTEX_Y", &piminus_TRUEENDVERTEX_Y);
    FullTree->Branch("piminus_TRUEENDVERTEX_Z", &piminus_TRUEENDVERTEX_Z);

    FullTree->Branch("gamma0_TRUEP_E", &gamma0_TRUEP_E);
    FullTree->Branch("gamma0_TRUEP_X", &gamma0_TRUEP_X);
    FullTree->Branch("gamma0_TRUEP_Y", &gamma0_TRUEP_Y);
    FullTree->Branch("gamma0_TRUEP_Z", &gamma0_TRUEP_Z);
    FullTree->Branch("gamma0_TRUEID", &gamma0_TRUEID);
    FullTree->Branch("gamma0_TRUEPT", &gamma0_TRUEPT);
    FullTree->Branch("gamma0_TRUEORIGINVERTEX_X", &gamma0_TRUEORIGINVERTEX_X);
    FullTree->Branch("gamma0_TRUEORIGINVERTEX_Y", &gamma0_TRUEORIGINVERTEX_Y);
    FullTree->Branch("gamma0_TRUEORIGINVERTEX_Z", &gamma0_TRUEORIGINVERTEX_Z);
    FullTree->Branch("gamma0_TRUEENDVERTEX_X", &gamma0_TRUEENDVERTEX_X);
    FullTree->Branch("gamma0_TRUEENDVERTEX_Y", &gamma0_TRUEENDVERTEX_Y);
    FullTree->Branch("gamma0_TRUEENDVERTEX_Z", &gamma0_TRUEENDVERTEX_Z);

    FullTree->Branch("gamma1_TRUEP_E", &gamma1_TRUEP_E);
    FullTree->Branch("gamma1_TRUEP_X", &gamma1_TRUEP_X);
    FullTree->Branch("gamma1_TRUEP_Y", &gamma1_TRUEP_Y);
    FullTree->Branch("gamma1_TRUEP_Z", &gamma1_TRUEP_Z);
    FullTree->Branch("gamma1_TRUEID", &gamma1_TRUEID);
    FullTree->Branch("gamma1_TRUEPT", &gamma1_TRUEPT);
    FullTree->Branch("gamma1_TRUEORIGINVERTEX_X", &gamma1_TRUEORIGINVERTEX_X);
    FullTree->Branch("gamma1_TRUEORIGINVERTEX_Y", &gamma1_TRUEORIGINVERTEX_Y);
    FullTree->Branch("gamma1_TRUEORIGINVERTEX_Z", &gamma1_TRUEORIGINVERTEX_Z);
    FullTree->Branch("gamma1_TRUEENDVERTEX_X", &gamma1_TRUEENDVERTEX_X);
    FullTree->Branch("gamma1_TRUEENDVERTEX_Y", &gamma1_TRUEENDVERTEX_Y);
    FullTree->Branch("gamma1_TRUEENDVERTEX_Z", &gamma1_TRUEENDVERTEX_Z);

    FullTree->Branch("Kplus_TRUEP_E", &Kplus_TRUEP_E);
    FullTree->Branch("Kplus_TRUEP_X", &Kplus_TRUEP_X);
    FullTree->Branch("Kplus_TRUEP_Y", &Kplus_TRUEP_Y);
    FullTree->Branch("Kplus_TRUEP_Z", &Kplus_TRUEP_Z);
    FullTree->Branch("Kplus_TRUEID", &Kplus_TRUEID);
    FullTree->Branch("Kplus_TRUEPT", &Kplus_TRUEPT);
    FullTree->Branch("Kplus_TRUEORIGINVERTEX_X", &Kplus_TRUEORIGINVERTEX_X);
    FullTree->Branch("Kplus_TRUEORIGINVERTEX_Y", &Kplus_TRUEORIGINVERTEX_Y);
    FullTree->Branch("Kplus_TRUEORIGINVERTEX_Z", &Kplus_TRUEORIGINVERTEX_Z);
    FullTree->Branch("Kplus_TRUEENDVERTEX_X", &Kplus_TRUEENDVERTEX_X);
    FullTree->Branch("Kplus_TRUEENDVERTEX_Y", &Kplus_TRUEENDVERTEX_Y);
    FullTree->Branch("Kplus_TRUEENDVERTEX_Z", &Kplus_TRUEENDVERTEX_Z);

    FullTree->Branch("gamma_TRUEP_E", &gamma_TRUEP_E);
    FullTree->Branch("gamma_TRUEP_X", &gamma_TRUEP_X);
    FullTree->Branch("gamma_TRUEP_Y", &gamma_TRUEP_Y);
    FullTree->Branch("gamma_TRUEP_Z", &gamma_TRUEP_Z);
    FullTree->Branch("gamma_TRUEPT", &gamma_TRUEPT);
    FullTree->Branch("gamma_TRUEORIGINVERTEX_X", &gamma_TRUEORIGINVERTEX_X);
    FullTree->Branch("gamma_TRUEORIGINVERTEX_Y", &gamma_TRUEORIGINVERTEX_Y);
    FullTree->Branch("gamma_TRUEORIGINVERTEX_Z", &gamma_TRUEORIGINVERTEX_Z);
    FullTree->Branch("gamma_TRUEENDVERTEX_X", &gamma_TRUEENDVERTEX_X);
    FullTree->Branch("gamma_TRUEENDVERTEX_Y", &gamma_TRUEENDVERTEX_Y);
    FullTree->Branch("gamma_TRUEENDVERTEX_Z", &gamma_TRUEENDVERTEX_Z);
    FullTree->Branch("gamma_TRUEID", &gamma_TRUEID);

    FullTree->Branch("B_PE", &B_PE);
    FullTree->Branch("B_PX", &B_PX);
    FullTree->Branch("B_PY", &B_PY);
    FullTree->Branch("B_PZ", &B_PZ);
    FullTree->Branch("B_ID", &B_ID);
    FullTree->Branch("B_PT", &B_PT);

    FullTree->Branch("piplus_PE", &piplus_PE);
    FullTree->Branch("piplus_PX", &piplus_PX);
    FullTree->Branch("piplus_PY", &piplus_PY);
    FullTree->Branch("piplus_PZ", &piplus_PZ);
    FullTree->Branch("piplus_ID", &piplus_ID);
    FullTree->Branch("piplus_PT", &piplus_PT);

    FullTree->Branch("piminus_PE", &piminus_PE);
    FullTree->Branch("piminus_PX", &piminus_PX);
    FullTree->Branch("piminus_PY", &piminus_PY);
    FullTree->Branch("piminus_PZ", &piminus_PZ);
    FullTree->Branch("piminus_ID", &piminus_ID);
    FullTree->Branch("piminus_PT", &piminus_PT);

    FullTree->Branch("pi0_PE", &pi0_PE);
    FullTree->Branch("pi0_PX", &pi0_PX);
    FullTree->Branch("pi0_PY", &pi0_PY);
    FullTree->Branch("pi0_PZ", &pi0_PZ);
    FullTree->Branch("pi0_ID", &pi0_ID);
    FullTree->Branch("pi0_PT", &pi0_PT);

    FullTree->Branch("gamma0_PE", &gamma0_PE);
    FullTree->Branch("gamma0_PX", &gamma0_PX);
    FullTree->Branch("gamma0_PY", &gamma0_PY);
    FullTree->Branch("gamma0_PZ", &gamma0_PZ);
    FullTree->Branch("gamma0_ID", &gamma0_ID);
    FullTree->Branch("gamma0_PT", &gamma0_PT);

    FullTree->Branch("gamma1_PE", &gamma1_PE);
    FullTree->Branch("gamma1_PX", &gamma1_PX);
    FullTree->Branch("gamma1_PY", &gamma1_PY);
    FullTree->Branch("gamma1_PZ", &gamma1_PZ);
    FullTree->Branch("gamma1_ID", &gamma1_ID);
    FullTree->Branch("gamma1_PT", &gamma1_PT);

    FullTree->Branch("Kplus_PE", &Kplus_PE);
    FullTree->Branch("Kplus_PX", &Kplus_PX);
    FullTree->Branch("Kplus_PY", &Kplus_PY);
    FullTree->Branch("Kplus_PZ", &Kplus_PZ);
    FullTree->Branch("Kplus_ID", &Kplus_ID);
    FullTree->Branch("Kplus_PT", &Kplus_PT);

    FullTree->Branch("K_2_1770_plus_PE", &K_1_plus_PE);
    FullTree->Branch("K_2_1770_plus_PX", &K_1_plus_PX);
    FullTree->Branch("K_2_1770_plus_PY", &K_1_plus_PY);
    FullTree->Branch("K_2_1770_plus_PZ", &K_1_plus_PZ);
    FullTree->Branch("K_2_1770_plus_ID", &K_1_plus_ID);
    FullTree->Branch("K_2_1770_plus_PT", &K_1_plus_PT);

    FullTree->Branch("gamma_PE", &gamma_PE);
    FullTree->Branch("gamma_PX", &gamma_PX);
    FullTree->Branch("gamma_PY", &gamma_PY);
    FullTree->Branch("gamma_PZ", &gamma_PZ);
    FullTree->Branch("gamma_PT", &gamma_PT);
    FullTree->Branch("gamma_ID", &gamma_ID);
    
    // ---------------------------------------------------------------------

    Double_t invmass_Rebuilt_pi0, invmass_Tuple_pi0, invmass_Rebuilt_K_1_plus, invmass_Tuple_K_1_plus, invmass_Tuple_B, invmass_Rebuilt_B;
    Double_t HelicityAngle, Tuple_HelicityAngle, HelicityAngle_Bplus, HelicityAngle_Bminus;
    Double_t Rebuilt_pi0_Px, Rebuilt_pi0_Py, Rebuilt_pi0_Pz, Rebuilt_pi0_E;
    Double_t Rebuilt_B_Px, Rebuilt_B_Py, Rebuilt_B_Pz, Rebuilt_B_E;
    Double_t Rebuilt_K_1_plus_Px, Rebuilt_K_1_plus_Py, Rebuilt_K_1_plus_Pz, Rebuilt_K_1_plus_E;
    Double_t Rebuilt_omega_Px, Rebuilt_omega_Py, Rebuilt_omega_Pz, Rebuilt_omega_E;
    Double_t invmass_Rebuilt_B_boost; Double_t invmass_Rebuilt_pi0_boost;
    Double_t Boost_Rebuilt_B_Px, Boost_Rebuilt_B_Py, Boost_Rebuilt_B_Pz, Boost_Rebuilt_B_E;
    Double_t Boost_gamma1_Px, Boost_gamma1_Py, Boost_gamma1_Pz, Boost_gamma1_E;
    Double_t Boost_Kplus_Px, Boost_Kplus_Py, Boost_Kplus_Pz, Boost_Kplus_E;
    Double_t Boost_Rebuilt_omega_Px, Boost_Rebuilt_omega_Py, Boost_Rebuilt_omega_Pz, Boost_Rebuilt_omega_E;
    Double_t vector_pi0piminus_mag2; Double_t vector_pi0piplus_mag2;

    FullTree->Branch("HelicityAngle", &HelicityAngle);
    FullTree->Branch("HelicityAngle_Bplus", &HelicityAngle_Bplus);
    FullTree->Branch("HelicityAngle_Bminus", &HelicityAngle_Bminus);

    FullTree->Branch("Rebuilt_pi0_Px", &Rebuilt_pi0_Px);
    FullTree->Branch("Rebuilt_pi0_Py", &Rebuilt_pi0_Py);
    FullTree->Branch("Rebuilt_pi0_Pz", &Rebuilt_pi0_Pz);
    FullTree->Branch("Rebuilt_pi0_E", &Rebuilt_pi0_E);

    FullTree->Branch("Rebuilt_B_Px", &Rebuilt_B_Px);
    FullTree->Branch("Rebuilt_B_Py", &Rebuilt_B_Py);
    FullTree->Branch("Rebuilt_B_Pz", &Rebuilt_B_Pz);
    FullTree->Branch("Rebuilt_B_E", &Rebuilt_B_E);

    FullTree->Branch("Rebuilt_K_1_plus_Px", &Rebuilt_K_1_plus_Px);
    FullTree->Branch("Rebuilt_K_1_plus_Py", &Rebuilt_K_1_plus_Py);
    FullTree->Branch("Rebuilt_K_1_plus_Pz", &Rebuilt_K_1_plus_Pz);
    FullTree->Branch("Rebuilt_K_1_plus_E", &Rebuilt_K_1_plus_E);

    FullTree->Branch("Rebuilt_omega_Px", &Rebuilt_omega_Px);
    FullTree->Branch("Rebuilt_omega_Py", &Rebuilt_omega_Py);
    FullTree->Branch("Rebuilt_omega_Pz", &Rebuilt_omega_Pz);
    FullTree->Branch("Rebuilt_omega_E", &Rebuilt_omega_E);

    FullTree->Branch("Boost_Rebuilt_B_Px", &Boost_Rebuilt_B_Px);
    FullTree->Branch("Boost_Rebuilt_B_Py", &Boost_Rebuilt_B_Py);
    FullTree->Branch("Boost_Rebuilt_B_Pz", &Boost_Rebuilt_B_Pz);
    FullTree->Branch("Boost_Rebuilt_B_E", &Boost_Rebuilt_B_E);

    FullTree->Branch("Boost_gamma1_Px", &Boost_gamma1_Px);
    FullTree->Branch("Boost_gamma1_Py", &Boost_gamma1_Py);
    FullTree->Branch("Boost_gamma1_Pz", &Boost_gamma1_Pz);
    FullTree->Branch("Boost_gamma1_E", &Boost_gamma1_E);

    FullTree->Branch("Boost_Kplus_Px", &Boost_Kplus_Px);
    FullTree->Branch("Boost_Kplus_Py", &Boost_Kplus_Py);
    FullTree->Branch("Boost_Kplus_Pz", &Boost_Kplus_Pz);
    FullTree->Branch("Boost_Kplus_E", &Boost_Kplus_E);

    FullTree->Branch("Boost_Rebuilt_omega_Px", &Boost_Rebuilt_omega_Px);
    FullTree->Branch("Boost_Rebuilt_omega_Py", &Boost_Rebuilt_omega_Py);
    FullTree->Branch("Boost_Rebuilt_omega_Pz", &Boost_Rebuilt_omega_Pz);
    FullTree->Branch("Boost_Rebuilt_omega_E", &Boost_Rebuilt_omega_E);

    FullTree->Branch("invmass_Rebuilt_pi0", &invmass_Rebuilt_pi0);
    FullTree->Branch("invmass_Tuple_pi0", &invmass_Tuple_pi0);
    FullTree->Branch("invmass_Rebuilt_pi0_boost", &invmass_Rebuilt_pi0_boost);
    FullTree->Branch("invmass_Rebuilt_K_1_plus", &invmass_Rebuilt_K_1_plus);
    FullTree->Branch("invmass_Tuple_K_1_plus", &invmass_Tuple_K_1_plus);
    FullTree->Branch("invmass_Tuple_B", &invmass_Tuple_B);
    FullTree->Branch("invmass_Rebuilt_B", &invmass_Rebuilt_B);
    FullTree->Branch("invmass_Rebuilt_B_boost", &invmass_Rebuilt_B_boost);

    FullTree->Branch("vector_pi0piminus_mag2", &vector_pi0piminus_mag2);
    FullTree->Branch("vector_pi0piplus_mag2", &vector_pi0piplus_mag2);

    // ----------------------------------------------
    Double_t Diff_helicity;
    // ----------------------------------------------

    // ----------------------- Avec les donnees de reconstruction basiques -----------------------
    Double_t invmass_Rebuilt_MC_pi0, invmass_Tuple_MC_pi0, invmass_Rebuilt_MC_K_1_plus, invmass_Tuple_MC_K_1_plus, invmass_Tuple_MC_B, invmass_Rebuilt_MC_B;
    Double_t HelicityAngle_MC, Tuple_MC_HelicityAngle, HelicityAngle_Bplus_MC, HelicityAngle_Bminus_MC;

    Double_t Rebuilt_MC_pi0_Px, Rebuilt_MC_pi0_Py, Rebuilt_MC_pi0_Pz, Rebuilt_MC_pi0_E;
    Double_t Rebuilt_MC_B_Px, Rebuilt_MC_B_Py, Rebuilt_MC_B_Pz, Rebuilt_MC_B_E;
    Double_t Rebuilt_MC_K_1_plus_Px, Rebuilt_MC_K_1_plus_Py, Rebuilt_MC_K_1_plus_Pz, Rebuilt_MC_K_1_plus_E;
    Double_t Rebuilt_MC_omega_Px, Rebuilt_MC_omega_Py, Rebuilt_MC_omega_Pz, Rebuilt_MC_omega_E;
    Double_t invmass_Rebuilt_MC_B_boost; Double_t invmass_Rebuilt_MC_pi0_boost;

    Double_t Boost_Rebuilt_MC_B_Px, Boost_Rebuilt_MC_B_Py, Boost_Rebuilt_MC_B_Pz, Boost_Rebuilt_MC_B_E;
    Double_t Boost_MC_gamma1_Px, Boost_MC_gamma1_Py, Boost_MC_gamma1_Pz, Boost_MC_gamma1_E;
    Double_t Boost_MC_Kplus_Px, Boost_MC_Kplus_Py, Boost_MC_Kplus_Pz, Boost_MC_Kplus_E;
    Double_t Boost_Rebuilt_MC_omega_Px, Boost_Rebuilt_MC_omega_Py, Boost_Rebuilt_MC_omega_Pz, Boost_Rebuilt_MC_omega_E;
    Double_t vector_pi0piminus_MC_mag2; Double_t vector_pi0piplus_MC_mag2;

    FullTree->Branch("HelicityAngle_MC", &HelicityAngle_MC);
    FullTree->Branch("HelicityAngle_Bplus_MC", &HelicityAngle_Bplus_MC);
    FullTree->Branch("HelicityAngle_Bminus_MC", &HelicityAngle_Bminus_MC);

    FullTree->Branch("Rebuilt_MC_pi0_Px", &Rebuilt_MC_pi0_Px);
    FullTree->Branch("Rebuilt_MC_pi0_Py", &Rebuilt_MC_pi0_Py);
    FullTree->Branch("Rebuilt_MC_pi0_Pz", &Rebuilt_MC_pi0_Pz);
    FullTree->Branch("Rebuilt_MC_pi0_E", &Rebuilt_MC_pi0_E);

    FullTree->Branch("Rebuilt_MC_B_Px", &Rebuilt_MC_B_Px);
    FullTree->Branch("Rebuilt_MC_B_Py", &Rebuilt_MC_B_Py);
    FullTree->Branch("Rebuilt_MC_B_Pz", &Rebuilt_MC_B_Pz);
    FullTree->Branch("Rebuilt_MC_B_E", &Rebuilt_MC_B_E);

    FullTree->Branch("Rebuilt_MC_K_1_plus_Px", &Rebuilt_MC_K_1_plus_Px);
    FullTree->Branch("Rebuilt_MC_K_1_plus_Py", &Rebuilt_MC_K_1_plus_Py);
    FullTree->Branch("Rebuilt_MC_K_1_plus_Pz", &Rebuilt_MC_K_1_plus_Pz);
    FullTree->Branch("Rebuilt_MC_K_1_plus_E", &Rebuilt_MC_K_1_plus_E);

    FullTree->Branch("Rebuilt_MC_omega_Px", &Rebuilt_MC_omega_Px);
    FullTree->Branch("Rebuilt_MC_omega_Py", &Rebuilt_MC_omega_Py);
    FullTree->Branch("Rebuilt_MC_omega_Pz", &Rebuilt_MC_omega_Pz);
    FullTree->Branch("Rebuilt_MC_omega_E", &Rebuilt_MC_omega_E);

    FullTree->Branch("Boost_Rebuilt_MC_B_Px", &Boost_Rebuilt_MC_B_Px);
    FullTree->Branch("Boost_Rebuilt_MC_B_Py", &Boost_Rebuilt_MC_B_Py);
    FullTree->Branch("Boost_Rebuilt_MC_B_Pz", &Boost_Rebuilt_MC_B_Pz);
    FullTree->Branch("Boost_Rebuilt_MC_B_E", &Boost_Rebuilt_MC_B_E);

    FullTree->Branch("Boost_MC_gamma1_Px", &Boost_MC_gamma1_Px);
    FullTree->Branch("Boost_MC_gamma1_Py", &Boost_MC_gamma1_Py);
    FullTree->Branch("Boost_MC_gamma1_Pz", &Boost_MC_gamma1_Pz);
    FullTree->Branch("Boost_MC_gamma1_E", &Boost_MC_gamma1_E);

    FullTree->Branch("Boost_MC_Kplus_Px", &Boost_MC_Kplus_Px);
    FullTree->Branch("Boost_MC_Kplus_Py", &Boost_MC_Kplus_Py);
    FullTree->Branch("Boost_MC_Kplus_Pz", &Boost_MC_Kplus_Pz);
    FullTree->Branch("Boost_MC_Kplus_E", &Boost_MC_Kplus_E);

    FullTree->Branch("Boost_Rebuilt_MC_omega_Px", &Boost_Rebuilt_MC_omega_Px);
    FullTree->Branch("Boost_Rebuilt_MC_omega_Py", &Boost_Rebuilt_MC_omega_Py);
    FullTree->Branch("Boost_Rebuilt_MC_omega_Pz", &Boost_Rebuilt_MC_omega_Pz);
    FullTree->Branch("Boost_Rebuilt_MC_omega_E", &Boost_Rebuilt_MC_omega_E);

    FullTree->Branch("invmass_Rebuilt_MC_pi0", &invmass_Rebuilt_MC_pi0);
    FullTree->Branch("invmass_Tuple_MC_pi0", &invmass_Tuple_MC_pi0);
    FullTree->Branch("invmass_Rebuilt_MC_pi0_boost", &invmass_Rebuilt_MC_pi0_boost);
    FullTree->Branch("invmass_Rebuilt_MC_K_1_plus", &invmass_Rebuilt_MC_K_1_plus);
    FullTree->Branch("invmass_Tuple_MC_K_1_plus", &invmass_Tuple_MC_K_1_plus);
    FullTree->Branch("invmass_Tuple_MC_B", &invmass_Tuple_MC_B);
    FullTree->Branch("invmass_Rebuilt_MC_B", &invmass_Rebuilt_MC_B);
    FullTree->Branch("invmass_Rebuilt_MC_B_boost", &invmass_Rebuilt_MC_B_boost);

    FullTree->Branch("vector_pi0piminus_MC_mag2", &vector_pi0piminus_MC_mag2);
    FullTree->Branch("vector_pi0piplus_MC_mag2", &vector_pi0piplus_MC_mag2);

    FullTree->Branch("Diff_helicity", &Diff_helicity);

    TH1D* hist_CosTheta_B_Gamma1 = new TH1D("hist_CosTheta_B_Gamma1", "Cosine of Angle Between B and Gamma1", 100, -10000.0, 10000.0);
    TH1D* hist_CosTheta_Kplus_Omega = new TH1D("hist_CosTheta_Kplus_Omega", "Cosine of Angle Between Kplus and Omega", 100, -10000.0, 10000.0);


    // ----------------------- Avec les donnes rebuilt TRUE -----------------------
    // 3 histos pour plot helicity
    TH1D* hist_AngleCos = new TH1D("hist_AngleCos", "Angle Cosine Distribution", 8, -1.00, 1.00);
    TH1D* hist_B_ID_Positive = new TH1D("hist_B_ID_Positive", "B_ID > 0 Distribution", 8, -1.00, 1.00);
    TH1D* hist_B_ID_Negative = new TH1D("hist_B_ID_Negative", "B_ID < 0 Distribution", 8, -1.00, 1.00);

    // Sumw2() active le stockage des erreurs    
    hist_AngleCos->Sumw2();
    hist_B_ID_Positive->Sumw2();
    hist_B_ID_Negative->Sumw2();

    TH2D* dalitzPlot = new TH2D("dalitzPlot", "Dalitz Plot;M^2(pim, pi0) [MeV^2];M^2(pip, pi0) [MeV^2]", 100, 0, 450000, 100, 0, 600000);

    // Counters for equal and non-equal events
    int equalEvents[3] = { 0 }; int nonEqualEvents[3] = { 0 };
    int oppositeMomentaEvents1 = 0; int nonOppositeMomentaEvents1 = 0;
    int oppositeMomentaEvents2 = 0; int nonOppositeMomentaEvents2 = 0;

    // ----------------------- Avec les donnes rebuilt MC -----------------------
    // 3 histos pour plot helicity
    TH1D* hist_AngleCos_MC = new TH1D("hist_AngleCos_MC", "Angle Cosine Distribution MC", 8, -1.00, 1.00);
    TH1D* hist_B_ID_Positive_MC = new TH1D("hist_B_ID_Positive_MC", "B_ID > 0 Distribution", 8, -1.00, 1.00);
    TH1D* hist_B_ID_Negative_MC = new TH1D("hist_B_ID_Negative_MC", "B_ID < 0 Distribution", 8, -1.00, 1.00);
    TH2D* hist_diff_helicity = new TH2D("hist_diff_helicity", "hist_diff_helicity", 16, -1, 1, 16, -1, 1);

    // Sumw2() active le stockage des erreurs    
    hist_AngleCos_MC->Sumw2();
    hist_B_ID_Positive_MC->Sumw2();
    hist_B_ID_Negative_MC->Sumw2();

    TH2D* dalitzPlot_MC = new TH2D("dalitzPlot_MC", "Dalitz Plot;M^2(pim, pi0) [MeV^2];M^2(pip, pi0) [MeV^2]", 100, 0, 450000, 100, 0, 600000);

    // Counters for equal and non-equal events
    int equalEvents_MC[3] = { 0 }; int nonEqualEvents_MC[3] = { 0 };
    int oppositeMomentaEvents1_MC = 0; int nonOppositeMomentaEvents1_MC = 0;
    int oppositeMomentaEvents2_MC = 0; int nonOppositeMomentaEvents2_MC = 0;

    // ----------------------- Loop -----------------------
    Long64_t nEntries = datafiltered_Ttree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        datafiltered_Ttree->GetEntry(i);
		if (B_BKGCAT == 10) {
            // ----------------------- Reconstruire les 4-vecteurs des particules -----------------------
            TLorentzVector gamma0, gamma1, vector_Tuple_pi0, gamma, vector_piplus, vector_piminus, vector_Kplus;
            gamma.SetPxPyPzE(gamma_TRUEP_X, gamma_TRUEP_Y, gamma_TRUEP_Z, gamma_TRUEP_E);
            gamma0.SetPxPyPzE(gamma0_TRUEP_X, gamma0_TRUEP_Y, gamma0_TRUEP_Z, gamma0_TRUEP_E);
            gamma1.SetPxPyPzE(gamma1_TRUEP_X, gamma1_TRUEP_Y, gamma1_TRUEP_Z, gamma1_TRUEP_E);
            vector_Tuple_pi0.SetPxPyPzE(Tuple_pi0_TRUEP_X, Tuple_pi0_TRUEP_Y, Tuple_pi0_TRUEP_Z, Tuple_pi0_TRUEP_E);// pi0 tel que genere dans le tuple            
            vector_piplus.SetPxPyPzE(piplus_TRUEP_X, piplus_TRUEP_Y, piplus_TRUEP_Z, piplus_TRUEP_E);
            vector_piminus.SetPxPyPzE(piminus_TRUEP_X, piminus_TRUEP_Y, piminus_TRUEP_Z, piminus_TRUEP_E);
            vector_Kplus.SetPxPyPzE(Kplus_TRUEP_X, Kplus_TRUEP_Y, Kplus_TRUEP_Z, Kplus_TRUEP_E);

            TLorentzVector vector_Rebuilt_pi0, vector_Rebuilt_omega, vector_Rebuilt_K_1_plus, vector_Tuple_K_1_plus, vector_Tuple_B, vector_Rebuilt_B;
            vector_Rebuilt_pi0.SetPxPyPzE(gamma0_TRUEP_X + gamma_TRUEP_X, gamma0_TRUEP_Y + gamma_TRUEP_Y, gamma0_TRUEP_Z + gamma_TRUEP_Z, gamma0_TRUEP_E + gamma_TRUEP_E);// pi0 tel qu'il se decay generalement
            vector_Rebuilt_omega.SetPxPyPzE(piplus_TRUEP_X + piminus_TRUEP_X + vector_Rebuilt_pi0.Px(), piplus_TRUEP_Y + piminus_TRUEP_Y + vector_Rebuilt_pi0.Py(), piplus_TRUEP_Z + piminus_TRUEP_Z + vector_Rebuilt_pi0.Pz(), piplus_TRUEP_E + piminus_TRUEP_E + vector_Rebuilt_pi0.E());
            vector_Rebuilt_K_1_plus.SetPxPyPzE(Kplus_TRUEP_X + vector_Rebuilt_omega.Px(), Kplus_TRUEP_Y + vector_Rebuilt_omega.Py(), Kplus_TRUEP_Z + vector_Rebuilt_omega.Pz(), Kplus_TRUEP_E + vector_Rebuilt_omega.E());
            vector_Tuple_K_1_plus.SetPxPyPzE(Tuple_K_1_plus_TRUEP_X, Tuple_K_1_plus_TRUEP_Y, Tuple_K_1_plus_TRUEP_Z, Tuple_K_1_plus_TRUEP_E); //generated      
            vector_Tuple_B.SetPxPyPzE(Tuple_B_TRUEP_X, Tuple_B_TRUEP_Y, Tuple_B_TRUEP_Z, Tuple_B_TRUEP_E);
            vector_Rebuilt_B.SetPxPyPzE(vector_Rebuilt_K_1_plus.Px() + gamma1_TRUEP_X, vector_Rebuilt_K_1_plus.Py() + gamma1_TRUEP_Y, vector_Rebuilt_K_1_plus.Pz() + gamma1_TRUEP_Z, vector_Rebuilt_K_1_plus.E() + gamma1_TRUEP_E);

            // ----------------------- BOOST vector_Kplus and vector_Rebuilt_omega to vector_Rebuilt_K_1_plus -----------------------
            TVector3 Rebuilt_K_1_plus_BoostVector = -vector_Rebuilt_K_1_plus.BoostVector();
            TLorentzVector Kplus_new = vector_Kplus;// Kplus
            Kplus_new.Boost(Rebuilt_K_1_plus_BoostVector);
            TLorentzVector Rebuilt_omega_new = vector_Rebuilt_omega;// omega
            Rebuilt_omega_new.Boost(Rebuilt_K_1_plus_BoostVector);
            TLorentzVector B_new = vector_Rebuilt_B;// B reconstruit
            B_new.Boost(Rebuilt_K_1_plus_BoostVector);
            TLorentzVector pi0_new = vector_Rebuilt_pi0;// pi0 reconstruit
            pi0_new.Boost(Rebuilt_K_1_plus_BoostVector);
            TLorentzVector gamma1_new = gamma1;// gamma radiatif
            gamma1_new.Boost(Rebuilt_K_1_plus_BoostVector);
            // Check if the momenta of vector_Kplus and vector_Rebuilt_omega are opposite
            if (B_new.Vect().Dot(gamma1_new.Vect()) < 0) { oppositeMomentaEvents2++; }
            else { nonOppositeMomentaEvents2++; }
            if ((Kplus_new.Vect().Dot(Rebuilt_omega_new.Vect())) < 0) { oppositeMomentaEvents1++; }
            else { nonOppositeMomentaEvents1++; }

            // Compare les 4-vecteurs et incremente les compteurs
            bool comparisons[3] = {
                ((vector_Tuple_K_1_plus - vector_Rebuilt_K_1_plus).Mag() < 0.05 * (vector_Rebuilt_K_1_plus).Mag()),
                ((vector_Tuple_pi0 - vector_Rebuilt_pi0).Mag() < 0.05 * (vector_Rebuilt_pi0).Mag()),
                ((vector_Rebuilt_omega - (vector_piplus + vector_piminus + vector_Rebuilt_pi0)).Mag() < 0.05 * (vector_piplus + vector_piminus + vector_Rebuilt_pi0).Mag())
            };

            for (int i = 0; i < 3; ++i) {
                if (comparisons[i]) { equalEvents[i]++; }
                else { nonEqualEvents[i]++; }
            }

            // ----------------------- Invariant mass -----------------------
            invmass_Rebuilt_pi0 = vector_Rebuilt_pi0.M();
            invmass_Tuple_pi0 = vector_Tuple_pi0.M();
            // Les K
            invmass_Rebuilt_K_1_plus = vector_Rebuilt_K_1_plus.M();
            invmass_Tuple_K_1_plus = vector_Tuple_K_1_plus.M();
            // Les B
            invmass_Tuple_B = vector_Tuple_B.M();
            invmass_Rebuilt_B = vector_Rebuilt_B.M();
            //Particules boostees
            invmass_Rebuilt_B_boost = B_new.M();
            //
            invmass_Rebuilt_pi0_boost = pi0_new.M();

            // ----------------------- Angle d'helicite entre B et Kplus -----------------------
            HelicityAngle = (B_new.Vect().Dot(Kplus_new.Vect()) / (B_new.Vect().Mag() * Kplus_new.Vect().Mag())); //Vec: vecteur spatial 3D et Mag: norme du vecteur 3D
            // Ci dessus, affichage en cosinus        
            //HelicityAngle = TMath::ACos(AngleCos); //affichage en rad
            hist_AngleCos->Fill(HelicityAngle);

            // Appliquer la condition B_ID > 0
            if (Tuple_B_TRUEID > 0) {
                // Remplir les histogrammes pour AngleCos avec B_ID > 0
                HelicityAngle_Bplus = HelicityAngle;
                hist_B_ID_Positive->Fill(HelicityAngle);
            }
            // Appliquer la condition B_ID < 0
            else if (Tuple_B_TRUEID < 0) {
                // Remplir les histogrammes pour AngleCos avec B_ID < 0
                HelicityAngle_Bminus = HelicityAngle;
                hist_B_ID_Negative->Fill(HelicityAngle);
            }

            // ----------------------- Calculs Dalitz plot du omega -----------------------
            TLorentzVector vector_pi0piplus = vector_Rebuilt_pi0 + vector_piplus;
            TLorentzVector vector_pi0piminus = vector_Rebuilt_pi0 + vector_piminus;
            // Remplir l'histogramme
            vector_pi0piminus_mag2 = vector_pi0piminus.M2();
            vector_pi0piplus_mag2 = vector_pi0piplus.M2();
            dalitzPlot->Fill(vector_pi0piminus_mag2, vector_pi0piplus_mag2);


            // ----------------------- Fill 4vector branches -----------------------
            Rebuilt_pi0_Px = vector_Rebuilt_pi0.Px();
            Rebuilt_pi0_Py = vector_Rebuilt_pi0.Py();
            Rebuilt_pi0_Pz = vector_Rebuilt_pi0.Pz();
            Rebuilt_pi0_E = vector_Rebuilt_pi0.E();

            Rebuilt_B_Px = vector_Rebuilt_B.Px();
            Rebuilt_B_Py = vector_Rebuilt_B.Py();
            Rebuilt_B_Pz = vector_Rebuilt_B.Pz();
            Rebuilt_B_E = vector_Rebuilt_B.E();

            Rebuilt_K_1_plus_Px = vector_Rebuilt_K_1_plus.Px();
            Rebuilt_K_1_plus_Py = vector_Rebuilt_K_1_plus.Py();
            Rebuilt_K_1_plus_Pz = vector_Rebuilt_K_1_plus.Pz();
            Rebuilt_K_1_plus_E = vector_Rebuilt_K_1_plus.E();

            Rebuilt_omega_Px = vector_Rebuilt_omega.Px();
            Rebuilt_omega_Py = vector_Rebuilt_omega.Py();
            Rebuilt_omega_Pz = vector_Rebuilt_omega.Pz();
            Rebuilt_omega_E = vector_Rebuilt_omega.E();

            Boost_Rebuilt_B_Px = B_new.Px();
            Boost_Rebuilt_B_Py = B_new.Py();
            Boost_Rebuilt_B_Pz = B_new.Pz();
            Boost_Rebuilt_B_E = B_new.E();

            Boost_gamma1_Px = gamma1_new.Px();
            Boost_gamma1_Py = gamma1_new.Py();
            Boost_gamma1_Pz = gamma1_new.Pz();
            Boost_gamma1_E = gamma1_new.E();

            Boost_Kplus_Px = Kplus_new.Px();
            Boost_Kplus_Py = Kplus_new.Py();
            Boost_Kplus_Pz = Kplus_new.Pz();
            Boost_Kplus_E = Kplus_new.E();

            Boost_Rebuilt_omega_Px = Rebuilt_omega_new.Px();
            Boost_Rebuilt_omega_Py = Rebuilt_omega_new.Py();
            Boost_Rebuilt_omega_Pz = Rebuilt_omega_new.Pz();
            Boost_Rebuilt_omega_E = Rebuilt_omega_new.E();

            Double_t cosTheta_B_Gamma1 = B_new.Vect().Dot(gamma1_new.Vect()) / (B_new.Vect().Mag() * gamma1_new.Vect().Mag());
            Double_t cosTheta_Kplus_Omega = Kplus_new.Vect().Dot(Rebuilt_omega_new.Vect()) / (Kplus_new.Vect().Mag() * Rebuilt_omega_new.Vect().Mag());

            hist_CosTheta_B_Gamma1->Fill(cosTheta_B_Gamma1);
            hist_CosTheta_Kplus_Omega->Fill(cosTheta_Kplus_Omega);

            // ####################### Avec les donnes rebuilt MC #######################

            // ----------------------- Reconstruire les 4-vecteurs des particules -----------------------
            TLorentzVector gamma0_MC, gamma1_MC, vector_Tuple_pi0_MC, gamma_MC, vector_piplus_MC, vector_piminus_MC, vector_Kplus_MC;
            gamma_MC.SetPxPyPzE(gamma_PX, gamma_PY, gamma_PZ, gamma_PE);
            gamma0_MC.SetPxPyPzE(gamma0_PX, gamma0_PY, gamma0_PZ, gamma0_PE);
            gamma1_MC.SetPxPyPzE(gamma1_PX, gamma1_PY, gamma1_PZ, gamma1_PE);
            vector_Tuple_pi0_MC.SetPxPyPzE(pi0_PX, pi0_PY, pi0_PZ, pi0_PE);// pi0 tel que genere dans le tuple            
            vector_piplus_MC.SetPxPyPzE(piplus_PX, piplus_PY, piplus_PZ, piplus_PE);
            vector_piminus_MC.SetPxPyPzE(piminus_PX, piminus_PY, piminus_PZ, piminus_PE);
            vector_Kplus_MC.SetPxPyPzE(Kplus_PX, Kplus_PY, Kplus_PZ, Kplus_PE);

            TLorentzVector vector_Rebuilt_pi0_MC, vector_Rebuilt_omega_MC, vector_Rebuilt_K_1_plus_MC, vector_Tuple_K_1_plus_MC, vector_Tuple_B_MC, vector_Rebuilt_B_MC;
            vector_Rebuilt_pi0_MC.SetPxPyPzE(gamma0_PX + gamma_PX, gamma0_PY + gamma_PY, gamma0_PZ + gamma_PZ, gamma0_PE + gamma_PE);// pi0 tel qu'il se decay generalement
            vector_Rebuilt_omega_MC.SetPxPyPzE(piplus_PX + piminus_PX + vector_Rebuilt_pi0_MC.Px(), piplus_PY + piminus_PY + vector_Rebuilt_pi0_MC.Py(), piplus_PZ + piminus_PZ + vector_Rebuilt_pi0_MC.Pz(), piplus_PE + piminus_PE + vector_Rebuilt_pi0_MC.E());
            vector_Rebuilt_K_1_plus_MC.SetPxPyPzE(Kplus_PX + vector_Rebuilt_omega_MC.Px(), Kplus_PY + vector_Rebuilt_omega_MC.Py(), Kplus_PZ + vector_Rebuilt_omega_MC.Pz(), Kplus_PE + vector_Rebuilt_omega_MC.E());
            vector_Tuple_K_1_plus_MC.SetPxPyPzE(K_1_plus_PX, K_1_plus_PY, K_1_plus_PZ, K_1_plus_PE); //generated      
            vector_Tuple_B_MC.SetPxPyPzE(B_PX, B_PY, B_PZ, B_PE);
            vector_Rebuilt_B_MC.SetPxPyPzE(vector_Rebuilt_K_1_plus_MC.Px() + gamma1_PX, vector_Rebuilt_K_1_plus_MC.Py() + gamma1_PY, vector_Rebuilt_K_1_plus_MC.Pz() + gamma1_PZ, vector_Rebuilt_K_1_plus_MC.E() + gamma1_PE);

            // ----------------------- BOOST vector_Kplus and vector_Rebuilt_omega to vector_Rebuilt_K_1_plus -----------------------
            TVector3 Rebuilt_K_1_plus_BoostVector_MC = -vector_Rebuilt_K_1_plus.BoostVector();
            TLorentzVector Kplus_new_MC = vector_Kplus_MC;// Kplus
            Kplus_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);
            TLorentzVector Rebuilt_omega_new_MC = vector_Rebuilt_omega_MC;// omega
            Rebuilt_omega_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);
            TLorentzVector B_new_MC = vector_Rebuilt_B_MC;// B reconstruit
            B_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);
            TLorentzVector pi0_new_MC = vector_Rebuilt_pi0_MC;// pi0 reconstruit
            pi0_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);
            TLorentzVector gamma1_new_MC = gamma1_MC;// gamma radiatif
            gamma1_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);
            // Check if the momenta of vector_Kplus and vector_Rebuilt_omega are opposite
            if (B_new_MC.Vect().Dot(gamma1_new_MC.Vect()) < 0) { oppositeMomentaEvents2_MC++; }
            else { nonOppositeMomentaEvents2_MC++; }
            if ((Kplus_new_MC.Vect().Dot(Rebuilt_omega_new_MC.Vect())) < 0) { oppositeMomentaEvents1_MC++; }
            else { nonOppositeMomentaEvents1_MC++; }

            // Compare les 4-vecteurs et incremente les compteurs
            bool comparisons_MC[3] = {
                ((vector_Tuple_K_1_plus_MC - vector_Rebuilt_K_1_plus_MC).Mag() < 0.05 * (vector_Rebuilt_K_1_plus_MC).Mag()),
                ((vector_Tuple_pi0_MC - vector_Rebuilt_pi0_MC).Mag() < 0.05 * (vector_Rebuilt_pi0_MC).Mag()),
                ((vector_Rebuilt_omega_MC - (vector_piplus_MC + vector_piminus_MC + vector_Rebuilt_pi0_MC)).Mag() < 0.05 * (vector_piplus_MC + vector_piminus_MC + vector_Rebuilt_pi0_MC).Mag())
            };

            for (int i = 0; i < 3; ++i) {
                if (comparisons_MC[i]) { equalEvents_MC[i]++; }
                else { nonEqualEvents_MC[i]++; }
            }

            // ----------------------- Invariant mass -----------------------
            invmass_Rebuilt_MC_pi0 = vector_Rebuilt_pi0_MC.M();
            invmass_Tuple_MC_pi0 = vector_Tuple_pi0_MC.M();
            // Les K
            invmass_Rebuilt_MC_K_1_plus = vector_Rebuilt_K_1_plus_MC.M();
            invmass_Tuple_MC_K_1_plus = vector_Tuple_K_1_plus_MC.M();
            // Les B
            invmass_Tuple_MC_B = vector_Tuple_B_MC.M();
            invmass_Rebuilt_MC_B = vector_Rebuilt_B_MC.M();
            //Particules boostees
            invmass_Rebuilt_MC_B_boost = B_new_MC.M();
            invmass_Rebuilt_MC_pi0_boost = pi0_new_MC.M();

            // ----------------------- Angle d'helicity entre B et Kplus -----------------------
            HelicityAngle_MC = (B_new_MC.Vect().Dot(Kplus_new_MC.Vect()) / (B_new_MC.Vect().Mag() * Kplus_new_MC.Vect().Mag())); //Vec: vecteur spatial 3D et Mag: norme du vecteur 3D
            // Ci dessus, affichage en cosinus
            hist_AngleCos_MC->Fill(HelicityAngle_MC);

            // Appliquer la condition B_ID > 0
            if (B_ID > 0) {
                // Remplir les histogrammes pour AngleCos avec B_ID > 0
                HelicityAngle_Bplus_MC = HelicityAngle_MC;
                hist_B_ID_Positive_MC->Fill(HelicityAngle_MC);
            }
            // Appliquer la condition B_ID < 0
            else if (B_ID < 0) {
                // Remplir les histogrammes pour AngleCos avec B_ID < 0
                HelicityAngle_Bminus_MC = HelicityAngle_MC;
                hist_B_ID_Negative_MC->Fill(HelicityAngle_MC);
            }

            // ----------------------- Calculs Dalitz plot du omega -----------------------
            TLorentzVector vector_pi0piplus_MC = vector_Rebuilt_pi0_MC + vector_piplus_MC;
            TLorentzVector vector_pi0piminus_MC = vector_Rebuilt_pi0_MC + vector_piminus_MC;
            // Remplir l'histogramme
            vector_pi0piminus_MC_mag2 = vector_pi0piminus_MC.M2();
            vector_pi0piplus_MC_mag2 = vector_pi0piplus_MC.M2();
            dalitzPlot_MC->Fill(vector_pi0piminus_MC_mag2, vector_pi0piplus_MC_mag2);

            // ----------------------- Resolution helicity -----------------------        
            // Difference d'angle
            Diff_helicity = HelicityAngle - HelicityAngle_MC;
            hist_diff_helicity->Fill(HelicityAngle, HelicityAngle_MC);

            // ----------------------- Fill 4vector branches -----------------------
            Rebuilt_MC_pi0_Px = vector_Rebuilt_pi0_MC.Px();
            Rebuilt_MC_pi0_Py = vector_Rebuilt_pi0_MC.Py();
            Rebuilt_MC_pi0_Pz = vector_Rebuilt_pi0_MC.Pz();
            Rebuilt_MC_pi0_E = vector_Rebuilt_pi0_MC.E();

            Rebuilt_MC_B_Px = vector_Rebuilt_B_MC.Px();
            Rebuilt_MC_B_Py = vector_Rebuilt_B_MC.Py();
            Rebuilt_MC_B_Pz = vector_Rebuilt_B_MC.Pz();
            Rebuilt_MC_B_E = vector_Rebuilt_B_MC.E();

            Rebuilt_MC_K_1_plus_Px = vector_Rebuilt_K_1_plus_MC.Px();
            Rebuilt_MC_K_1_plus_Py = vector_Rebuilt_K_1_plus_MC.Py();
            Rebuilt_MC_K_1_plus_Pz = vector_Rebuilt_K_1_plus_MC.Pz();
            Rebuilt_MC_K_1_plus_E = vector_Rebuilt_K_1_plus_MC.E();

            Rebuilt_MC_omega_Px = vector_Rebuilt_omega_MC.Px();
            Rebuilt_MC_omega_Py = vector_Rebuilt_omega_MC.Py();
            Rebuilt_MC_omega_Pz = vector_Rebuilt_omega_MC.Pz();
            Rebuilt_MC_omega_E = vector_Rebuilt_omega_MC.E();

            Boost_Rebuilt_MC_B_Px = B_new_MC.Px();
            Boost_Rebuilt_MC_B_Py = B_new_MC.Py();
            Boost_Rebuilt_MC_B_Pz = B_new_MC.Pz();
            Boost_Rebuilt_MC_B_E = B_new_MC.E();

            Boost_MC_gamma1_Px = gamma1_new_MC.Px();
            Boost_MC_gamma1_Py = gamma1_new_MC.Py();
            Boost_MC_gamma1_Pz = gamma1_new_MC.Pz();
            Boost_MC_gamma1_E = gamma1_new_MC.E();

            Boost_MC_Kplus_Px = Kplus_new_MC.Px();
            Boost_MC_Kplus_Py = Kplus_new_MC.Py();
            Boost_MC_Kplus_Pz = Kplus_new_MC.Pz();
            Boost_MC_Kplus_E = Kplus_new_MC.E();

            Boost_Rebuilt_MC_omega_Px = Rebuilt_omega_new_MC.Px();
            Boost_Rebuilt_MC_omega_Py = Rebuilt_omega_new_MC.Py();
            Boost_Rebuilt_MC_omega_Pz = Rebuilt_omega_new_MC.Pz();
            Boost_Rebuilt_MC_omega_E = Rebuilt_omega_new_MC.E();

            FullTree->Fill();
        }    
    }

    TCanvas* canvas_B_Gamma1 = new TCanvas("canvas_B_Gamma1", "Cosine of Angle Between B and Gamma1", 800, 600);
    hist_CosTheta_B_Gamma1->Draw();
    //canvas_B_Gamma1->Write();  // Sauvegarde dans le fichier de sortie

    TCanvas* canvas_Kplus_Omega = new TCanvas("canvas_Kplus_Omega", "Cosine of Angle Between Kplus and Omega", 800, 600);
    hist_CosTheta_Kplus_Omega->Draw();
    //canvas_Kplus_Omega->Write();  // Sauvegarde dans le fichier de sortie


    // ----------------------- Legende histo helicity -----------------------
    TLegend* legend = new TLegend(0.5, 0.7, 0.7, 0.9);
    legend->AddEntry(hist_AngleCos, "Total helicity ", "lep");
    legend->AddEntry(hist_B_ID_Positive, "Helicity for B_ID > 0", "lep");
    legend->AddEntry(hist_B_ID_Negative, "Helicity for B_ID < 0", "lep");

    legend->AddEntry(hist_AngleCos_MC, "Total helicity ", "lep");
    legend->AddEntry(hist_B_ID_Positive_MC, "Helicity for B_ID > 0", "lep");
    legend->AddEntry(hist_B_ID_Negative_MC, "Helicity for B_ID < 0", "lep");

    // ----------------------- Superposer les histogrammes dans un TCanvas -----------------------
    TCanvas* Helicity_merged = new TCanvas("Helicity_merged", "Superposed Histograms of Helicity", 800, 600);
    hist_AngleCos->SetLineColor(kBlack);
    hist_B_ID_Positive->SetLineColor(kRed);
    hist_B_ID_Negative->SetLineColor(kBlue);
    hist_AngleCos->SetMinimum(0);
    hist_AngleCos->SetMaximum(300);
    hist_B_ID_Positive->SetMinimum(0);
    hist_B_ID_Negative->SetMinimum(0);
    hist_AngleCos->Draw();
    hist_B_ID_Positive->Draw("SAME");
    hist_B_ID_Negative->Draw("SAME");
    legend->Draw("SAME");
    Helicity_merged->Write();

    TCanvas* Helicity_merged_MC = new TCanvas("Helicity_merged_MC", "Superposed Histograms of Helicity", 800, 600);
    hist_AngleCos_MC->SetLineColor(kBlack);
    hist_B_ID_Positive_MC->SetLineColor(kRed);
    hist_B_ID_Negative_MC->SetLineColor(kBlue);
    hist_AngleCos_MC->SetMinimum(0);
    hist_AngleCos_MC->SetMaximum(300);
    hist_B_ID_Positive_MC->SetMinimum(0);
    hist_B_ID_Negative_MC->SetMinimum(0);
    hist_AngleCos_MC->Draw();
    hist_B_ID_Positive_MC->Draw("SAME");
    hist_B_ID_Negative_MC->Draw("SAME");
    legend->Draw("SAME");
    Helicity_merged_MC->Write();

    // ----------------------- Print resultats comparaison for TRUE data -----------------------
    const char* eventNames[3] = { "K", "pi", "omega" };
    for (int i = 0; i < 3; ++i) {
        std::cout << "Events (true) with equal 4-vectors for " << eventNames[i] << ": " << equalEvents[i] << ", non-equal (true): " << nonEqualEvents[i] << std::endl;
    }

    // Nb d'events avec impulsions opposees ou non
    std::cout << "Nombre d'events (true) with opposite momenta for K+ and w: " << oppositeMomentaEvents1_MC << ", Non-opposite: " << nonOppositeMomentaEvents1_MC << std::endl;
    std::cout << "Nombre d'events (true) with opposite momenta for B and gamma: " << oppositeMomentaEvents2_MC << ", Non-opposite: " << nonOppositeMomentaEvents2_MC << std::endl;


    // ####################### Avec les donnees MC #######################
    
	// ----------------------- Print resultats comparaison -----------------------
    const char* eventNames_MC[3] = { "K", "pi", "omega" };
    for (int i = 0; i < 3; ++i) {
        std::cout << "Events (MC) with equal 4-vectors for " << eventNames_MC[i] << ": " << equalEvents_MC[i] << ", non-equal (MC): " << nonEqualEvents_MC[i] << std::endl;
    }
    // Nb d'events avec impulsions opposees ou non
    std::cout << "Nombre d'events (MC) with opposite momenta for K+ and w: " << oppositeMomentaEvents1_MC << ", Non-opposite: " << nonOppositeMomentaEvents1_MC << std::endl;
    std::cout << "Nombre d'events (MC) with opposite momenta for B and gamma: " << oppositeMomentaEvents2_MC << ", Non-opposite: " << nonOppositeMomentaEvents2_MC << std::endl;


    // ----------------------- Write the output tree to the output file -----------------------
    outputFile->Write();
    outputFile->Close();
    delete Helicity_merged;
    delete Helicity_merged_MC;   
	delete canvas_B_Gamma1;
	delete canvas_Kplus_Omega;
}

int main2() {
    full_calc();
    return 0;
}