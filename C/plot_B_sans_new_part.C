#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TChain.h>
#include <iostream>



Double_t piminus_ProbNNpi, piminus_ProbNNk, piminus_ProbNNp, piminus_IPCHI2_OWNPV, piminus_PT;
Bool_t piminus_isMuon;
Double_t Kplus_ProbNNpi, Kplus_ProbNNk, Kplus_ProbNNp, Kplus_IPCHI2_OWNPV, Kplus_PT;
Bool_t Kplus_isMuon;
Double_t piplus_ProbNNpi, piplus_ProbNNk, piplus_ProbNNp, piplus_IPCHI2_OWNPV, piplus_PT;
Bool_t piplus_isMuon;
Double_t B_FDCHI2_OWNPV, B_FD_OWNPV, B_ENDVERTEX_CHI2, B_DIRA_OWNPV, B_PT;
Double_t pi0_PT;
Double_t gamma_CL, gamma_PP_IsPhoton, gamma_PP_IsNotE, gamma_PT;
Double_t gamma0_CL, gamma0_PP_IsPhoton, gamma0_PP_IsNotE, gamma0_PT;
Double_t gamma1_CL, gamma1_PP_IsPhoton, gamma1_PP_IsNotE, gamma1_PT;
Double_t B_M, B_M01234, B_M1234, B_M012345;
Bool_t B_L0PhotonDecision_TOS, B_L0ElectronDecision_TOS, B_Hlt1TrackAllL0Decision_TOS, B_Hlt1TrackPhotonDecision_TOS, B_Hlt2RadiativeTopoTrackDecision_TOS, B_Hlt2RadiativeTopoPhotonDecision_TOS, B_Hlt2RadiativeTopoTrackTOSDecision_TOS, B_Hlt2RadiativeTopoPhotonL0Decision_TOS;
Int_t B_BKGCAT;
Double_t B_M0234, B_M02;
//
Double_t piminus_ProbNNpi_data, piminus_ProbNNk_data, piminus_ProbNNp_data, piminus_IPCHI2_OWNPV_data, piminus_PT_data;
Bool_t piminus_isMuon_data;
Double_t Kplus_ProbNNpi_data, Kplus_ProbNNk_data, Kplus_ProbNNp_data, Kplus_IPCHI2_OWNPV_data, Kplus_PT_data;
Bool_t Kplus_isMuon_data;
Double_t piplus_ProbNNpi_data, piplus_ProbNNk_data, piplus_ProbNNp_data, piplus_IPCHI2_OWNPV_data, piplus_PT_data;
Bool_t piplus_isMuon_data;
Double_t B_FDCHI2_OWNPV_data, B_FD_OWNPV_data, B_ENDVERTEX_CHI2_data, B_DIRA_OWNPV_data, B_PT_data;
Double_t pi0_PT_data;
Double_t gamma_CL_data, gamma_PP_IsPhoton_data, gamma_PP_IsNotE_data, gamma_PT_data;
Double_t gamma0_CL_data, gamma0_PP_IsPhoton_data, gamma0_PP_IsNotE_data, gamma0_PT_data;
Double_t gamma1_CL_data, gamma1_PP_IsPhoton_data, gamma1_PP_IsNotE_data, gamma1_PT_data;
Double_t B_M_data, B_M01234_data, B_M1234_data, B_M012345_data;
Bool_t B_L0PhotonDecision_TOS_data, B_L0ElectronDecision_TOS_data, B_Hlt1TrackAllL0Decision_TOS_data, B_Hlt1TrackPhotonDecision_TOS_data, B_Hlt2RadiativeTopoTrackDecision_TOS_data, B_Hlt2RadiativeTopoPhotonDecision_TOS_data, B_Hlt2RadiativeTopoTrackTOSDecision_TOS_data, B_Hlt2RadiativeTopoPhotonL0Decision_TOS_data;
Double_t B_M0234_data, B_M02_data;

// ###############################################################

void plotVariables2() {
    // ########################################################
    // --------------------- MONTE CARLO ----------------------
    // ########################################################
    TChain* tree = new TChain("kpipipi0GTupleMC/DecayTree");
    tree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagDown_mergeAll.root");
    tree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagUp_mergeAll.root");
    tree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagDown_mergeAll_ntp.root");
    tree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagUp_mergeAll_ntp.root");
    // Branches
    tree->SetBranchStatus("*", 0);
    tree->SetBranchStatus("piminus_ProbNNpi", 1);             tree->SetBranchStatus("Kplus_ProbNNpi", 1);                   tree->SetBranchStatus("piplus_ProbNNpi", 1);                   tree->SetBranchStatus("B_FDCHI2_OWNPV", 1);                 tree->SetBranchStatus("gamma_CL", 1);                        tree->SetBranchStatus("gamma0_CL", 1);                        tree->SetBranchStatus("gamma1_CL", 1);
    tree->SetBranchStatus("piminus_ProbNNk", 1);              tree->SetBranchStatus("Kplus_ProbNNk", 1);                    tree->SetBranchStatus("piplus_ProbNNk", 1);                    tree->SetBranchStatus("B_FD_OWNPV", 1);                     tree->SetBranchStatus("gamma_PP_IsPhoton", 1);               tree->SetBranchStatus("gamma0_PP_IsPhoton", 1);               tree->SetBranchStatus("gamma1_PP_IsPhoton", 1);
    tree->SetBranchStatus("piminus_ProbNNp", 1);              tree->SetBranchStatus("Kplus_ProbNNp", 1);                    tree->SetBranchStatus("piplus_ProbNNp", 1);                    tree->SetBranchStatus("B_ENDVERTEX_CHI2", 1);               tree->SetBranchStatus("gamma_PP_IsNotE", 1);                 tree->SetBranchStatus("gamma0_PP_IsNotE", 1);                 tree->SetBranchStatus("gamma1_PP_IsNotE", 1);
    tree->SetBranchStatus("piminus_IPCHI2_OWNPV", 1);         tree->SetBranchStatus("Kplus_IPCHI2_OWNPV", 1);               tree->SetBranchStatus("piplus_IPCHI2_OWNPV", 1);               tree->SetBranchStatus("B_DIRA_OWNPV", 1);
    tree->SetBranchStatus("piminus_PT", 1);                   tree->SetBranchStatus("Kplus_PT", 1);                         tree->SetBranchStatus("piplus_PT", 1);                         tree->SetBranchStatus("B_PT", 1);                           tree->SetBranchStatus("gamma_PT", 1);                        tree->SetBranchStatus("gamma0_PT", 1);                        tree->SetBranchStatus("gamma1_PT", 1);
    tree->SetBranchStatus("piminus_isMuon", 1);               tree->SetBranchStatus("piplus_isMuon", 1);                   tree->SetBranchStatus("Kplus_isMuon", 1);
    tree->SetBranchStatus("pi0_PT", 1);                       tree->SetBranchStatus("B_BKGCAT", 1);

    tree->SetBranchStatus("B_M", 1);
    tree->SetBranchStatus("B_M01234", 1);
    tree->SetBranchStatus("B_M1234", 1);
    tree->SetBranchStatus("B_M012345", 1);
    tree->SetBranchStatus("B_M0234", 1);
    tree->SetBranchStatus("B_M02", 1);
    tree->SetBranchStatus("B_L0PhotonDecision_TOS", 1);
    tree->SetBranchStatus("B_L0ElectronDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt1TrackAllL0Decision_TOS", 1);
    tree->SetBranchStatus("B_Hlt1TrackPhotonDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoTrackDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoPhotonDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoTrackTOSDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoPhotonL0Decision_TOS", 1);
    //    
    tree->SetBranchAddress("piminus_ProbNNpi", &piminus_ProbNNpi);                 tree->SetBranchAddress("Kplus_ProbNNpi", &Kplus_ProbNNpi);                 tree->SetBranchAddress("piplus_ProbNNpi", &piplus_ProbNNpi);                 tree->SetBranchAddress("B_FDCHI2_OWNPV", &B_FDCHI2_OWNPV);             tree->SetBranchAddress("gamma_CL", &gamma_CL);                           tree->SetBranchAddress("gamma0_CL", &gamma0_CL);                           tree->SetBranchAddress("gamma1_CL", &gamma1_CL);
    tree->SetBranchAddress("piminus_ProbNNk", &piminus_ProbNNk);                   tree->SetBranchAddress("Kplus_ProbNNk", &Kplus_ProbNNk);                   tree->SetBranchAddress("piplus_ProbNNk", &piplus_ProbNNk);                   tree->SetBranchAddress("B_FD_OWNPV", &B_FD_OWNPV);                     tree->SetBranchAddress("gamma_PP_IsPhoton", &gamma_PP_IsPhoton);         tree->SetBranchAddress("gamma0_PP_IsPhoton", &gamma0_PP_IsPhoton);         tree->SetBranchAddress("gamma1_PP_IsPhoton", &gamma1_PP_IsPhoton);
    tree->SetBranchAddress("piminus_ProbNNp", &piminus_ProbNNp);                   tree->SetBranchAddress("Kplus_ProbNNp", &Kplus_ProbNNp);                   tree->SetBranchAddress("piplus_ProbNNp", &piplus_ProbNNp);                   tree->SetBranchAddress("B_ENDVERTEX_CHI2", &B_ENDVERTEX_CHI2);         tree->SetBranchAddress("gamma_PP_IsNotE", &gamma_PP_IsNotE);             tree->SetBranchAddress("gamma0_PP_IsNotE", &gamma0_PP_IsNotE);             tree->SetBranchAddress("gamma1_PP_IsNotE", &gamma1_PP_IsNotE);
    tree->SetBranchAddress("piminus_IPCHI2_OWNPV", &piminus_IPCHI2_OWNPV);         tree->SetBranchAddress("Kplus_IPCHI2_OWNPV", &Kplus_IPCHI2_OWNPV);         tree->SetBranchAddress("piplus_IPCHI2_OWNPV", &piplus_IPCHI2_OWNPV);         tree->SetBranchAddress("B_DIRA_OWNPV", &B_DIRA_OWNPV);
    tree->SetBranchAddress("piminus_PT", &piminus_PT);                             tree->SetBranchAddress("Kplus_PT", &Kplus_PT);                             tree->SetBranchAddress("piplus_PT", &piplus_PT);                             tree->SetBranchAddress("B_PT", &B_PT);                                 tree->SetBranchAddress("gamma_PT", &gamma_PT);                           tree->SetBranchAddress("gamma0_PT", &gamma0_PT);                           tree->SetBranchAddress("gamma1_PT", &gamma1_PT);
    tree->SetBranchAddress("piminus_isMuon", &piminus_isMuon);                     tree->SetBranchAddress("piplus_isMuon", &piplus_isMuon);                   tree->SetBranchAddress("Kplus_isMuon", &Kplus_isMuon);
    tree->SetBranchAddress("pi0_PT", &pi0_PT);        tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT);

    tree->SetBranchAddress("B_M", &B_M);
    tree->SetBranchAddress("B_M0234", &B_M0234);
    tree->SetBranchAddress("B_M02", &B_M02);
    tree->SetBranchAddress("B_M01234", &B_M01234);
    tree->SetBranchAddress("B_M1234", &B_M1234);
    tree->SetBranchAddress("B_M012345", &B_M012345);
    tree->SetBranchAddress("B_L0PhotonDecision_TOS", &B_L0PhotonDecision_TOS);
    tree->SetBranchAddress("B_L0ElectronDecision_TOS", &B_L0ElectronDecision_TOS);
    tree->SetBranchAddress("B_Hlt1TrackAllL0Decision_TOS", &B_Hlt1TrackAllL0Decision_TOS);
    tree->SetBranchAddress("B_Hlt1TrackPhotonDecision_TOS", &B_Hlt1TrackPhotonDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoTrackDecision_TOS", &B_Hlt2RadiativeTopoTrackDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoPhotonDecision_TOS", &B_Hlt2RadiativeTopoPhotonDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoTrackTOSDecision_TOS", &B_Hlt2RadiativeTopoTrackTOSDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoPhotonL0Decision_TOS", &B_Hlt2RadiativeTopoPhotonL0Decision_TOS);

    // ########################################################
    // ------------------------- DATA -------------------------
    // ########################################################
    TChain* tree_data = new TChain("DecayTree");
    //tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagDown-2011-S21r1p2_red.root");
    tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagUp-2011-S21r1p2_red.root");
    tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagDown-2012-S21r0p2_red.root");
    tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagUp-2012-S21r0p2_red.root");

    // ---------------------- BRANCHES ----------------------
    tree_data->SetBranchStatus("*", 0);
    tree_data->SetBranchStatus("piminus_ProbNNpi", 1);             tree_data->SetBranchStatus("Kplus_ProbNNpi", 1);                   tree_data->SetBranchStatus("piplus_ProbNNpi", 1);                   tree_data->SetBranchStatus("B_FDCHI2_OWNPV", 1);                 tree_data->SetBranchStatus("gamma_CL", 1);                        tree_data->SetBranchStatus("gamma0_CL", 1);                        tree_data->SetBranchStatus("gamma1_CL", 1);
    tree_data->SetBranchStatus("piminus_ProbNNk", 1);              tree_data->SetBranchStatus("Kplus_ProbNNk", 1);                    tree_data->SetBranchStatus("piplus_ProbNNk", 1);                    tree_data->SetBranchStatus("B_FD_OWNPV", 1);                     tree_data->SetBranchStatus("gamma_PP_IsPhoton", 1);               tree_data->SetBranchStatus("gamma0_PP_IsPhoton", 1);               tree_data->SetBranchStatus("gamma1_PP_IsPhoton", 1);               tree_data->SetBranchStatus("B_M01234", 1);
    tree_data->SetBranchStatus("piminus_ProbNNp", 1);              tree_data->SetBranchStatus("Kplus_ProbNNp", 1);                    tree_data->SetBranchStatus("piplus_ProbNNp", 1);                    tree_data->SetBranchStatus("B_ENDVERTEX_CHI2", 1);               tree_data->SetBranchStatus("gamma_PP_IsNotE", 1);                 tree_data->SetBranchStatus("gamma0_PP_IsNotE", 1);                 tree_data->SetBranchStatus("gamma1_PP_IsNotE", 1);                 tree_data->SetBranchStatus("B_M1234", 1);
    tree_data->SetBranchStatus("piminus_IPCHI2_OWNPV", 1);         tree_data->SetBranchStatus("Kplus_IPCHI2_OWNPV", 1);               tree_data->SetBranchStatus("piplus_IPCHI2_OWNPV", 1);               tree_data->SetBranchStatus("B_DIRA_OWNPV", 1);                             tree_data->SetBranchStatus("B_M012345", 1);
    tree_data->SetBranchStatus("piminus_PT", 1);                   tree_data->SetBranchStatus("Kplus_PT", 1);                         tree_data->SetBranchStatus("piplus_PT", 1);                         tree_data->SetBranchStatus("B_PT", 1);                           tree_data->SetBranchStatus("gamma_PT", 1);                        tree_data->SetBranchStatus("gamma0_PT", 1);                        tree_data->SetBranchStatus("gamma1_PT", 1);
    tree_data->SetBranchStatus("piminus_isMuon", 1);               tree_data->SetBranchStatus("piplus_isMuon", 1);                   tree_data->SetBranchStatus("Kplus_isMuon", 1);
    tree_data->SetBranchStatus("pi0_PT", 1);

    tree_data->SetBranchStatus("B_M", 1);
    tree_data->SetBranchStatus("B_M0234", 1);
    tree_data->SetBranchStatus("B_M02", 1);
    tree_data->SetBranchStatus("B_L0PhotonDecision_TOS", 1);
    tree_data->SetBranchStatus("B_L0ElectronDecision_TOS", 1);
    tree_data->SetBranchStatus("B_Hlt1TrackAllL0Decision_TOS", 1);
    tree_data->SetBranchStatus("B_Hlt1TrackPhotonDecision_TOS", 1);
    tree_data->SetBranchStatus("B_Hlt2RadiativeTopoTrackDecision_TOS", 1);
    tree_data->SetBranchStatus("B_Hlt2RadiativeTopoPhotonDecision_TOS", 1);
    tree_data->SetBranchStatus("B_Hlt2RadiativeTopoTrackTOSDecision_TOS", 1);
    tree_data->SetBranchStatus("B_Hlt2RadiativeTopoPhotonL0Decision_TOS", 1);
    //    
    tree_data->SetBranchAddress("piminus_ProbNNpi", &piminus_ProbNNpi_data);                 tree_data->SetBranchAddress("Kplus_ProbNNpi", &Kplus_ProbNNpi_data);                 tree_data->SetBranchAddress("piplus_ProbNNpi", &piplus_ProbNNpi_data);                 tree_data->SetBranchAddress("B_FDCHI2_OWNPV", &B_FDCHI2_OWNPV_data);             tree_data->SetBranchAddress("gamma_CL", &gamma_CL_data);                           tree_data->SetBranchAddress("gamma0_CL", &gamma0_CL_data);                           tree_data->SetBranchAddress("gamma1_CL", &gamma1_CL_data);
    tree_data->SetBranchAddress("piminus_ProbNNk", &piminus_ProbNNk_data);                   tree_data->SetBranchAddress("Kplus_ProbNNk", &Kplus_ProbNNk_data);                   tree_data->SetBranchAddress("piplus_ProbNNk", &piplus_ProbNNk_data);                   tree_data->SetBranchAddress("B_FD_OWNPV", &B_FD_OWNPV_data);                     tree_data->SetBranchAddress("gamma_PP_IsPhoton", &gamma_PP_IsPhoton_data);         tree_data->SetBranchAddress("gamma0_PP_IsPhoton", &gamma0_PP_IsPhoton_data);         tree_data->SetBranchAddress("gamma1_PP_IsPhoton", &gamma1_PP_IsPhoton_data);         tree_data->SetBranchAddress("B_M01234", &B_M01234_data);
    tree_data->SetBranchAddress("piminus_ProbNNp", &piminus_ProbNNp_data);                   tree_data->SetBranchAddress("Kplus_ProbNNp", &Kplus_ProbNNp_data);                   tree_data->SetBranchAddress("piplus_ProbNNp", &piplus_ProbNNp_data);                   tree_data->SetBranchAddress("B_ENDVERTEX_CHI2", &B_ENDVERTEX_CHI2_data);         tree_data->SetBranchAddress("gamma_PP_IsNotE", &gamma_PP_IsNotE_data);             tree_data->SetBranchAddress("gamma0_PP_IsNotE", &gamma0_PP_IsNotE_data);             tree_data->SetBranchAddress("gamma1_PP_IsNotE", &gamma1_PP_IsNotE_data);             tree_data->SetBranchAddress("B_M1234", &B_M1234_data);
    tree_data->SetBranchAddress("piminus_IPCHI2_OWNPV", &piminus_IPCHI2_OWNPV_data);         tree_data->SetBranchAddress("Kplus_IPCHI2_OWNPV", &Kplus_IPCHI2_OWNPV_data);         tree_data->SetBranchAddress("piplus_IPCHI2_OWNPV", &piplus_IPCHI2_OWNPV_data);         tree_data->SetBranchAddress("B_DIRA_OWNPV", &B_DIRA_OWNPV_data);                   tree_data->SetBranchAddress("B_M012345", &B_M012345_data);
    tree_data->SetBranchAddress("piminus_PT", &piminus_PT_data);                             tree_data->SetBranchAddress("Kplus_PT", &Kplus_PT_data);                             tree_data->SetBranchAddress("piplus_PT", &piplus_PT_data);                             tree_data->SetBranchAddress("B_PT", &B_PT_data);                                 tree_data->SetBranchAddress("gamma_PT", &gamma_PT_data);                           tree_data->SetBranchAddress("gamma0_PT", &gamma0_PT_data);                           tree_data->SetBranchAddress("gamma1_PT", &gamma1_PT_data);
    tree_data->SetBranchAddress("piminus_isMuon", &piminus_isMuon_data);                     tree_data->SetBranchAddress("piplus_isMuon", &piplus_isMuon_data);                   tree_data->SetBranchAddress("Kplus_isMuon", &Kplus_isMuon_data);
    tree_data->SetBranchAddress("pi0_PT", &pi0_PT_data);

    tree_data->SetBranchAddress("B_M", &B_M_data);
    tree_data->SetBranchAddress("B_M0234", &B_M0234_data);
    tree_data->SetBranchAddress("B_M02", &B_M02_data);
    tree_data->SetBranchAddress("B_L0PhotonDecision_TOS", &B_L0PhotonDecision_TOS_data);
    tree_data->SetBranchAddress("B_L0ElectronDecision_TOS", &B_L0ElectronDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt1TrackAllL0Decision_TOS", &B_Hlt1TrackAllL0Decision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt1TrackPhotonDecision_TOS", &B_Hlt1TrackPhotonDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt2RadiativeTopoTrackDecision_TOS", &B_Hlt2RadiativeTopoTrackDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt2RadiativeTopoPhotonDecision_TOS", &B_Hlt2RadiativeTopoPhotonDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt2RadiativeTopoTrackTOSDecision_TOS", &B_Hlt2RadiativeTopoTrackTOSDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt2RadiativeTopoPhotonL0Decision_TOS", &B_Hlt2RadiativeTopoPhotonL0Decision_TOS_data);


    // --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Create canvas
    TCanvas* plot_canvas = new TCanvas("plot_canvas", "plot_canvas", 900, 600);

    TH1D* hist_mB_MC = new TH1D("hist_mB_MC", "", 100, 4000, 7000);
    TH1D* hist_mB_data = new TH1D("hist_mB_data", "", 100, 4000, 7000);

    TH1D* histograms[] = { hist_mB_MC, hist_mB_data };
    const char* titles[] = { "Particle mass (MeV)", "Number of events (Log scale)" };

    for (TH1D* hist : histograms) {
        hist->GetXaxis()->SetTitle(titles[0]);
        hist->GetXaxis()->CenterTitle(true);
        hist->GetYaxis()->SetTitle(titles[1]);
        hist->GetYaxis()->CenterTitle(true);
    }

    Long64_t nentries1 = tree->GetEntries();    
    for (Long64_t i = 0; i < nentries1; ++i) {
        tree->GetEntry(i);
        if (B_BKGCAT == 10) {
            // CUTS ON TRIGGER
            bool L0_trigger = (B_L0PhotonDecision_TOS == 1 || B_L0ElectronDecision_TOS == 1);
            bool HLT1 = (B_Hlt1TrackAllL0Decision_TOS == 1 || B_Hlt1TrackPhotonDecision_TOS == 1);
            bool HLT2 = (B_Hlt2RadiativeTopoTrackDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonDecision_TOS == 1 || B_Hlt2RadiativeTopoTrackTOSDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonL0Decision_TOS == 1);
            // CUTS ON INVMASS
            bool massCuts = B_M01234 < 1500 && B_M1234 > 600 && B_M1234 < 900 && B_M > 4500 && B_M < 7000;
            bool special = (B_M0234 < 1750 || B_M0234>1970) && (B_M02 < 840 || B_M02>1920 || (B_M02 > 970 && B_M02 < 1800));
            // OTHER CUTS
            bool ChargedPIDcut = piminus_ProbNNpi > 0.2 && piminus_ProbNNk < 0.8 && piminus_ProbNNp < 0.8 && piplus_ProbNNpi > 0.2 && piplus_ProbNNk < 0.8 && piplus_ProbNNp < 0.8 && Kplus_ProbNNpi < 0.8 && Kplus_ProbNNk > 0.2 && Kplus_ProbNNp < 0.8;
            bool NeutralPIDcut = gamma_CL > 0.2 && gamma_PP_IsPhoton > 0.5 && gamma0_CL > 0.2 && gamma0_PP_IsPhoton > 0.5 && gamma1_CL > 0.2 && gamma1_PP_IsPhoton > 0.5;
            // FILL HISTOGRAMS
            if (massCuts && L0_trigger && HLT1 && HLT2 && ChargedPIDcut && NeutralPIDcut) {
                hist_mB_MC->Fill(B_M);
            }
        }
    }

   /* // ---------------------- LOOP DATA ----------------------
    Long64_t nentries2 = tree_data->GetEntries();   
    for (Long64_t i = 0; i < nentries2; ++i) {
        tree_data->GetEntry(i);
        // CUTS ON TRIGGER
        bool L0_data = (B_L0PhotonDecision_TOS_data == 1 || B_L0ElectronDecision_TOS_data == 1);
        bool HLT1_data = (B_Hlt1TrackAllL0Decision_TOS_data == 1 || B_Hlt1TrackPhotonDecision_TOS_data == 1);
        bool HLT2_data = (B_Hlt2RadiativeTopoTrackDecision_TOS_data == 1 || B_Hlt2RadiativeTopoPhotonDecision_TOS_data == 1 || B_Hlt2RadiativeTopoTrackTOSDecision_TOS_data == 1 || B_Hlt2RadiativeTopoPhotonL0Decision_TOS_data == 1);
        // CUTS ON INVMASS
        bool massCuts_data = B_M01234_data < 1500 && B_M1234_data > 600 && B_M1234_data < 900 && B_M012345_data > 4500 && B_M012345_data < 7000;
        bool special_data = (B_M0234_data < 1750 || B_M0234_data >1970) && (B_M02_data < 840 || B_M02_data >1920 || (B_M02_data > 970 && B_M02_data < 1800));
        // OTHER CUTS
        bool ChargedPIDcut_data = piminus_ProbNNpi_data > 0.2 && piminus_ProbNNk_data < 0.8 && piminus_ProbNNp_data < 0.8 && piplus_ProbNNpi_data > 0.2 && piplus_ProbNNk_data < 0.8 && piplus_ProbNNp_data < 0.8 && Kplus_ProbNNpi_data < 0.8 && Kplus_ProbNNk_data > 0.2 && Kplus_ProbNNp_data < 0.8;
        bool NeutralPIDcut_data = gamma_CL_data > 0.2 && gamma_PP_IsPhoton_data > 0.5 && gamma0_CL_data > 0.2 && gamma0_PP_IsPhoton_data > 0.5 && gamma1_CL_data > 0.2 && gamma1_PP_IsPhoton_data > 0.5;
        // FILL HISTOGRAMS
        if (massCuts_data && special_data && L0_data && HLT1_data && HLT2_data && ChargedPIDcut_data && NeutralPIDcut_data) {
            hist_mB_data->Fill(B_M_data);
        }
    }*/


    // Legend
    TLegend* legend1 = new TLegend(0.25, 0.9, 0.45, 0.8);
    legend1->SetTextSize(0.04);
    legend1->AddEntry(hist_mB_MC, "MC events", "l");
    legend1->AddEntry(hist_mB_MC, "Data events", "l");

    plot_canvas->cd();
    //gPad->SetLogy(1);
    hist_mB_MC->SetLineColor(kRed);
    hist_mB_MC->Draw();
    hist_mB_MC->SetLineColor(kBlue);
    hist_mB_MC->Draw("same");
    legend1->Draw("same");  

}

// ###############################################################

Int_t main() {
    plotVariables2();
    return 0;
}
