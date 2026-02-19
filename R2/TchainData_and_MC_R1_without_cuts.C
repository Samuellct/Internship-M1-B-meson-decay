#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TChain.h>
#include <iostream>
#include <TLatex.h>

Double_t piminus_ProbNNpi, piminus_ProbNNk, piminus_ProbNNp, piminus_IPCHI2_OWNPV, piminus_PT;
Bool_t piminus_isMuon;
Double_t Kplus_ProbNNpi, Kplus_ProbNNk, Kplus_ProbNNp, Kplus_IPCHI2_OWNPV, Kplus_PT;
Bool_t Kplus_isMuon; 
Double_t piplus_ProbNNpi, piplus_ProbNNk, piplus_ProbNNp, piplus_IPCHI2_OWNPV, piplus_PT;
Bool_t piplus_isMuon; 
Double_t B_FDCHI2_OWNPV, B_FD_OWNPV, B_ENDVERTEX_CHI2, B_DIRA_OWNPV, B_PT;
Double_t pi0_PT;
Double_t gamma_CL, gamma_PP_IsPhoton, gamma_PP_IsNotE, gamma_PP_IsNotH, gamma_PT;
Double_t gamma0_CL, gamma0_PP_IsPhoton, gamma0_PP_IsNotE, gamma0_PP_IsNotH, gamma0_PT;
Double_t gamma1_CL, gamma1_PP_IsPhoton, gamma1_PP_IsNotE, gamma1_PP_IsNotH, gamma1_PT;
Double_t B_M, B_M01234, B_M1234, B_M012345;
Bool_t B_L0PhotonDecision_TOS, B_L0ElectronDecision_TOS, B_Hlt1TrackAllL0Decision_TOS, B_Hlt1TrackPhotonDecision_TOS, B_Hlt2RadiativeTopoTrackDecision_TOS, B_Hlt2RadiativeTopoPhotonDecision_TOS, B_Hlt2RadiativeTopoTrackTOSDecision_TOS, B_Hlt2RadiativeTopoPhotonL0Decision_TOS;
Int_t B_BKGCAT;
//
Double_t piminus_ProbNNpi_data, piminus_ProbNNk_data, piminus_ProbNNp_data, piminus_IPCHI2_OWNPV_data, piminus_PT_data;
Bool_t piminus_isMuon_data;
Double_t Kplus_ProbNNpi_data, Kplus_ProbNNk_data, Kplus_ProbNNp_data, Kplus_IPCHI2_OWNPV_data, Kplus_PT_data;
Bool_t Kplus_isMuon_data; 
Double_t piplus_ProbNNpi_data, piplus_ProbNNk_data, piplus_ProbNNp_data, piplus_IPCHI2_OWNPV_data, piplus_PT_data;
Bool_t piplus_isMuon_data; 
Double_t B_FDCHI2_OWNPV_data, B_FD_OWNPV_data, B_ENDVERTEX_CHI2_data, B_DIRA_OWNPV_data, B_PT_data;
Double_t pi0_PT_data;
Double_t gamma_CL_data, gamma_PP_IsPhoton_data, gamma_PP_IsNotE_data, gamma_PP_IsNotH_data, gamma_PT_data;
Double_t gamma0_CL_data, gamma0_PP_IsPhoton_data, gamma0_PP_IsNotE_data, gamma0_PP_IsNotH_data, gamma0_PT_data;
Double_t gamma1_CL_data, gamma1_PP_IsPhoton_data, gamma1_PP_IsNotE_data, gamma1_PP_IsNotH_data, gamma1_PT_data;
Double_t B_M_data, B_M01234_data, B_M1234_data, B_M012345_data;
Bool_t B_L0PhotonDecision_TOS_data, B_L0ElectronDecision_TOS_data, B_Hlt1TrackAllL0Decision_TOS_data, B_Hlt1TrackPhotonDecision_TOS_data, B_Hlt2RadiativeTopoTrackDecision_TOS_data, B_Hlt2RadiativeTopoPhotonDecision_TOS_data, B_Hlt2RadiativeTopoTrackTOSDecision_TOS_data, B_Hlt2RadiativeTopoPhotonL0Decision_TOS_data;

// ###############################################################

Double_t getHistValue(Int_t index) {
    switch (index) {
        case 0: return piminus_ProbNNpi;
        case 1: return piminus_ProbNNk;
        case 2: return piminus_ProbNNp;
        case 3: return piminus_IPCHI2_OWNPV;
        case 4: return piminus_PT;
        case 5: return piminus_isMuon;		
        case 6: return Kplus_ProbNNpi;
        case 7: return Kplus_ProbNNk;
        case 8: return Kplus_ProbNNp;
        case 9: return Kplus_IPCHI2_OWNPV;
        case 10: return Kplus_PT;
		case 11: return Kplus_isMuon;		
        case 12: return piplus_ProbNNpi;
        case 13: return piplus_ProbNNk;
        case 14: return piplus_ProbNNp;
        case 15: return piplus_IPCHI2_OWNPV;
        case 16: return piplus_PT;		
        case 17: return piplus_isMuon;		
        case 18: return B_FDCHI2_OWNPV;
        case 19: return B_FD_OWNPV;
        case 20: return B_ENDVERTEX_CHI2;
        case 21: return B_DIRA_OWNPV;
        case 22: return B_PT;		
        case 23: return pi0_PT;		
        case 24: return gamma_CL;
        case 25: return gamma_PP_IsPhoton;
        case 26: return gamma_PP_IsNotE;
        case 27: return gamma_PP_IsNotH;
        case 28: return gamma_PT;		
        case 29: return gamma0_CL;
        case 30: return gamma0_PP_IsPhoton;
        case 31: return gamma0_PP_IsNotE;
        case 32: return gamma0_PP_IsNotH;
        case 33: return gamma0_PT;		
        case 34: return gamma1_CL;
        case 35: return gamma1_PP_IsPhoton;
        case 36: return gamma1_PP_IsNotE;
        case 37: return gamma1_PP_IsNotH;
        case 38: return gamma1_PT;
        default: return 0;
    }
}

Double_t getHistValue_data(Int_t index_data) {
    switch (index_data) {
        case 0: return piminus_ProbNNpi_data;
        case 1: return piminus_ProbNNk_data;
        case 2: return piminus_ProbNNp_data;
        case 3: return piminus_IPCHI2_OWNPV_data;
        case 4: return piminus_PT_data;
        case 5: return piminus_isMuon_data;		
        case 6: return Kplus_ProbNNpi_data;
        case 7: return Kplus_ProbNNk_data;
        case 8: return Kplus_ProbNNp_data;
        case 9: return Kplus_IPCHI2_OWNPV_data;
        case 10: return Kplus_PT_data;
        case 11: return Kplus_isMuon_data;		
        case 12: return piplus_ProbNNpi_data;
        case 13: return piplus_ProbNNk_data;
        case 14: return piplus_ProbNNp_data;
        case 15: return piplus_IPCHI2_OWNPV_data;
        case 16: return piplus_PT_data;		
        case 17: return piplus_isMuon_data;		
        case 18: return B_FDCHI2_OWNPV_data;
        case 19: return B_FD_OWNPV_data;
        case 20: return B_ENDVERTEX_CHI2_data;
        case 21: return B_DIRA_OWNPV_data;
        case 22: return B_PT_data;		
        case 23: return pi0_PT_data;		
        case 24: return gamma_CL_data;
        case 25: return gamma_PP_IsPhoton_data;
        case 26: return gamma_PP_IsNotE_data;
        case 27: return gamma_PP_IsNotH_data;
        case 28: return gamma_PT_data;		
        case 29: return gamma0_CL_data;
        case 30: return gamma0_PP_IsPhoton_data;
        case 31: return gamma0_PP_IsNotE_data;
        case 32: return gamma0_PP_IsNotH_data;
        case 33: return gamma0_PT_data;		
        case 34: return gamma1_CL_data;
        case 35: return gamma1_PP_IsPhoton_data;
        case 36: return gamma1_PP_IsNotE_data;
        case 37: return gamma1_PP_IsNotH_data;
        case 38: return gamma1_PT_data;
        default: return 0;
    }
}

// ###############################################################

void plotVariables2(const char* outputFileName) {
    // ########################################################
    // --------------------- MONTE CARLO ----------------------
    // ########################################################
    TChain *tree = new TChain("kpipipi0GTupleMC/DecayTree");    
	tree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagDown_mergeAll.root");
    tree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagUp_mergeAll.root");
    tree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagDown_mergeAll_ntp.root");
    tree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagUp_mergeAll_ntp.root");
    // Branches
    tree->SetBranchStatus("*", 0);
    tree->SetBranchStatus("piminus_ProbNNpi", 1);             tree->SetBranchStatus("Kplus_ProbNNpi", 1);                   tree->SetBranchStatus("piplus_ProbNNpi", 1);                   tree->SetBranchStatus("B_FDCHI2_OWNPV", 1);                 tree->SetBranchStatus("gamma_CL", 1);                        tree->SetBranchStatus("gamma0_CL", 1);                        tree->SetBranchStatus("gamma1_CL", 1);                                                                                                                                                                                                                                                                                                                              
    tree->SetBranchStatus("piminus_ProbNNk", 1);              tree->SetBranchStatus("Kplus_ProbNNk", 1);                    tree->SetBranchStatus("piplus_ProbNNk", 1);                    tree->SetBranchStatus("B_FD_OWNPV", 1);                     tree->SetBranchStatus("gamma_PP_IsPhoton", 1);               tree->SetBranchStatus("gamma0_PP_IsPhoton", 1);               tree->SetBranchStatus("gamma1_PP_IsPhoton", 1);
    tree->SetBranchStatus("piminus_ProbNNp", 1);              tree->SetBranchStatus("Kplus_ProbNNp", 1);                    tree->SetBranchStatus("piplus_ProbNNp", 1);                    tree->SetBranchStatus("B_ENDVERTEX_CHI2", 1);               tree->SetBranchStatus("gamma_PP_IsNotE", 1);                 tree->SetBranchStatus("gamma0_PP_IsNotE", 1);                 tree->SetBranchStatus("gamma1_PP_IsNotE", 1);                                                                                                                                                                                                                                                                                                        
    tree->SetBranchStatus("piminus_IPCHI2_OWNPV", 1);         tree->SetBranchStatus("Kplus_IPCHI2_OWNPV", 1);               tree->SetBranchStatus("piplus_IPCHI2_OWNPV", 1);               tree->SetBranchStatus("B_DIRA_OWNPV", 1);                   tree->SetBranchStatus("gamma_PP_IsNotH", 1);                 tree->SetBranchStatus("gamma0_PP_IsNotH", 1);                 tree->SetBranchStatus("gamma1_PP_IsNotH", 1);  
    tree->SetBranchStatus("piminus_PT", 1);                   tree->SetBranchStatus("Kplus_PT", 1);                         tree->SetBranchStatus("piplus_PT", 1);                         tree->SetBranchStatus("B_PT", 1);                           tree->SetBranchStatus("gamma_PT", 1);                        tree->SetBranchStatus("gamma0_PT", 1);                        tree->SetBranchStatus("gamma1_PT", 1);                                                                                                                                                                                                                                                    
    tree->SetBranchStatus("piminus_isMuon", 1);               tree->SetBranchStatus("piplus_isMuon", 1);                   tree->SetBranchStatus("Kplus_isMuon", 1);                                                                                       
    tree->SetBranchStatus("pi0_PT", 1);                       tree->SetBranchStatus("B_BKGCAT", 1); 
    
    tree->SetBranchStatus("B_M", 1);
    tree->SetBranchStatus("B_M01234", 1);
    tree->SetBranchStatus("B_M1234", 1);
    tree->SetBranchStatus("B_M012345", 1);
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
    tree->SetBranchAddress("piminus_IPCHI2_OWNPV", &piminus_IPCHI2_OWNPV);         tree->SetBranchAddress("Kplus_IPCHI2_OWNPV", &Kplus_IPCHI2_OWNPV);         tree->SetBranchAddress("piplus_IPCHI2_OWNPV", &piplus_IPCHI2_OWNPV);         tree->SetBranchAddress("B_DIRA_OWNPV", &B_DIRA_OWNPV);                 tree->SetBranchAddress("gamma_PP_IsNotH", &gamma_PP_IsNotH);             tree->SetBranchAddress("gamma0_PP_IsNotH", &gamma0_PP_IsNotH);             tree->SetBranchAddress("gamma1_PP_IsNotH", &gamma1_PP_IsNotH);  
    tree->SetBranchAddress("piminus_PT", &piminus_PT);                             tree->SetBranchAddress("Kplus_PT", &Kplus_PT);                             tree->SetBranchAddress("piplus_PT", &piplus_PT);                             tree->SetBranchAddress("B_PT", &B_PT);                                 tree->SetBranchAddress("gamma_PT", &gamma_PT);                           tree->SetBranchAddress("gamma0_PT", &gamma0_PT);                           tree->SetBranchAddress("gamma1_PT", &gamma1_PT);                                                                                                                                                                                                                                                    
    tree->SetBranchAddress("piminus_isMuon", &piminus_isMuon);                     tree->SetBranchAddress("piplus_isMuon", &piplus_isMuon);                   tree->SetBranchAddress("Kplus_isMuon", &Kplus_isMuon);                                                                                       
    tree->SetBranchAddress("pi0_PT", &pi0_PT);        tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT); 

    tree->SetBranchAddress("B_M", &B_M);
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
    TChain *tree_data = new TChain("DecayTree");    
    //tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagDown-2011-S21r1p2_red.root");
    tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagUp-2011-S21r1p2_red.root");
    tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagDown-2012-S21r0p2_red.root");
    tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagUp-2012-S21r0p2_red.root");
    
    // Branches
    tree_data->SetBranchStatus("*", 0);
    tree_data->SetBranchStatus("piminus_ProbNNpi", 1);             tree_data->SetBranchStatus("Kplus_ProbNNpi", 1);                   tree_data->SetBranchStatus("piplus_ProbNNpi", 1);                   tree_data->SetBranchStatus("B_FDCHI2_OWNPV", 1);                 tree_data->SetBranchStatus("gamma_CL", 1);                        tree_data->SetBranchStatus("gamma0_CL", 1);                        tree_data->SetBranchStatus("gamma1_CL", 1);                                                                                                                                                                                                                                                                                                                              
    tree_data->SetBranchStatus("piminus_ProbNNk", 1);              tree_data->SetBranchStatus("Kplus_ProbNNk", 1);                    tree_data->SetBranchStatus("piplus_ProbNNk", 1);                    tree_data->SetBranchStatus("B_FD_OWNPV", 1);                     tree_data->SetBranchStatus("gamma_PP_IsPhoton", 1);               tree_data->SetBranchStatus("gamma0_PP_IsPhoton", 1);               tree_data->SetBranchStatus("gamma1_PP_IsPhoton", 1);               tree_data->SetBranchStatus("B_M01234", 1);
    tree_data->SetBranchStatus("piminus_ProbNNp", 1);              tree_data->SetBranchStatus("Kplus_ProbNNp", 1);                    tree_data->SetBranchStatus("piplus_ProbNNp", 1);                    tree_data->SetBranchStatus("B_ENDVERTEX_CHI2", 1);               tree_data->SetBranchStatus("gamma_PP_IsNotE", 1);                 tree_data->SetBranchStatus("gamma0_PP_IsNotE", 1);                 tree_data->SetBranchStatus("gamma1_PP_IsNotE", 1);                 tree_data->SetBranchStatus("B_M1234", 1);                                                                                                                                                                                                                                                                                       
    tree_data->SetBranchStatus("piminus_IPCHI2_OWNPV", 1);         tree_data->SetBranchStatus("Kplus_IPCHI2_OWNPV", 1);               tree_data->SetBranchStatus("piplus_IPCHI2_OWNPV", 1);               tree_data->SetBranchStatus("B_DIRA_OWNPV", 1);                   tree_data->SetBranchStatus("gamma_PP_IsNotH", 1);                 tree_data->SetBranchStatus("gamma0_PP_IsNotH", 1);                 tree_data->SetBranchStatus("gamma1_PP_IsNotH", 1);                 tree_data->SetBranchStatus("B_M012345", 1);     
    tree_data->SetBranchStatus("piminus_PT", 1);                   tree_data->SetBranchStatus("Kplus_PT", 1);                         tree_data->SetBranchStatus("piplus_PT", 1);                         tree_data->SetBranchStatus("B_PT", 1);                           tree_data->SetBranchStatus("gamma_PT", 1);                        tree_data->SetBranchStatus("gamma0_PT", 1);                        tree_data->SetBranchStatus("gamma1_PT", 1);                                                                                                                                                                                                                                                    
    tree_data->SetBranchStatus("piminus_isMuon", 1);               tree_data->SetBranchStatus("piplus_isMuon", 1);                   tree_data->SetBranchStatus("Kplus_isMuon", 1);                                                                                       
    tree_data->SetBranchStatus("pi0_PT", 1);

    tree_data->SetBranchStatus("B_M", 1);
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
    tree_data->SetBranchAddress("piminus_IPCHI2_OWNPV", &piminus_IPCHI2_OWNPV_data);         tree_data->SetBranchAddress("Kplus_IPCHI2_OWNPV", &Kplus_IPCHI2_OWNPV_data);         tree_data->SetBranchAddress("piplus_IPCHI2_OWNPV", &piplus_IPCHI2_OWNPV_data);         tree_data->SetBranchAddress("B_DIRA_OWNPV", &B_DIRA_OWNPV_data);                 tree_data->SetBranchAddress("gamma_PP_IsNotH", &gamma_PP_IsNotH_data);             tree_data->SetBranchAddress("gamma0_PP_IsNotH", &gamma0_PP_IsNotH_data);             tree_data->SetBranchAddress("gamma1_PP_IsNotH", &gamma1_PP_IsNotH_data);             tree_data->SetBranchAddress("B_M012345", &B_M012345_data);   
    tree_data->SetBranchAddress("piminus_PT", &piminus_PT_data);                             tree_data->SetBranchAddress("Kplus_PT", &Kplus_PT_data);                             tree_data->SetBranchAddress("piplus_PT", &piplus_PT_data);                             tree_data->SetBranchAddress("B_PT", &B_PT_data);                                 tree_data->SetBranchAddress("gamma_PT", &gamma_PT_data);                           tree_data->SetBranchAddress("gamma0_PT", &gamma0_PT_data);                           tree_data->SetBranchAddress("gamma1_PT", &gamma1_PT_data);                                                                                                                                                                                                                                                   
    tree_data->SetBranchAddress("piminus_isMuon", &piminus_isMuon_data);                     tree_data->SetBranchAddress("piplus_isMuon", &piplus_isMuon_data);                   tree_data->SetBranchAddress("Kplus_isMuon", &Kplus_isMuon_data);                                                                                       
    tree_data->SetBranchAddress("pi0_PT", &pi0_PT_data);     

    tree_data->SetBranchAddress("B_M", &B_M_data);
    tree_data->SetBranchAddress("B_L0PhotonDecision_TOS", &B_L0PhotonDecision_TOS_data);
    tree_data->SetBranchAddress("B_L0ElectronDecision_TOS", &B_L0ElectronDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt1TrackAllL0Decision_TOS", &B_Hlt1TrackAllL0Decision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt1TrackPhotonDecision_TOS", &B_Hlt1TrackPhotonDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt2RadiativeTopoTrackDecision_TOS", &B_Hlt2RadiativeTopoTrackDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt2RadiativeTopoPhotonDecision_TOS", &B_Hlt2RadiativeTopoPhotonDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt2RadiativeTopoTrackTOSDecision_TOS", &B_Hlt2RadiativeTopoTrackTOSDecision_TOS_data);
    tree_data->SetBranchAddress("B_Hlt2RadiativeTopoPhotonL0Decision_TOS", &B_Hlt2RadiativeTopoPhotonL0Decision_TOS_data);

    // ---------------------- CANVAS ----------------------
    TCanvas *piminus_var = new TCanvas("piminus_var", "piminus_var Plots", 1200, 800);
    piminus_var->Divide(3, 2);
    TCanvas *piplus_var = new TCanvas("piplus_var", "piplus_var Plots", 800, 600);
    piplus_var->Divide(3, 2);
    TCanvas *Kplus_var = new TCanvas("Kplus_var", "Kplus_var Plots", 800, 600);
    Kplus_var->Divide(3, 2);
    TCanvas *B_var = new TCanvas("B_var", "B_var Plots", 800, 600);
    B_var->Divide(3, 2);
    TCanvas *pi0_var = new TCanvas("pi0_var", "pi0_var Plots", 800, 600);
    pi0_var->Divide(3, 2);
    TCanvas *gamma_var = new TCanvas("gamma_var", "gamma_var Plots", 800, 600);
    gamma_var->Divide(3, 2);
    TCanvas *gamma0_var = new TCanvas("gamma0_var", "gamma0_var Plots", 800, 600);
    gamma0_var->Divide(3, 2);
    TCanvas *gamma1_var = new TCanvas("gamma1_var", "gamma1_var Plots", 800, 600);
    gamma1_var->Divide(3, 2);
    TCanvas *mass_inv = new TCanvas("mass_inv", "Mass Invariants", 800, 600);
    mass_inv->Divide(3, 1);
    TCanvas *triggers = new TCanvas("triggers", "Trigger Conditions", 800, 600); 
    triggers->Divide(2, 2);

    // ---------------------- Variables pr les boucles ----------------------
    const Int_t numHist = 39; // Nombre total d'histogrammes    
    const char* histNames1[numHist] = {"ProbNNpi", "ProbNNk", "ProbNNp", "IPCHI2_OWNPV", "PT", "isMuon", "ProbNNpi", "ProbNNk", "ProbNNp", "IPCHI2_OWNPV", "PT", "isMuon", "ProbNNpi", "ProbNNk", "ProbNNp", "IPCHI2_OWNPV", "PT", "isMuon", "FDCHI2_OWNPV", "FD_OWNPV", "ENDVERTEX_CHI2", "DIRA_OWNPV", "PT", "PT", "CL", "IsPhoton", "IsNotE", "IsNotH", "PT", "CL", "PP_IsPhoton", "PP_IsNotE", "PP_IsNotH", "PT", "CL", "IsPhoton", "IsNotE", "IsNotH", "PT"};
    const char* histNames2[numHist] = {"ProbNNpi_data", "ProbNNk_data", "ProbNNp_data", "IPCHI2_OWNPV_data", "PT_data", "isMuon_data", "ProbNNpi_data", "ProbNNk_data", "ProbNNp_data", "IPCHI2_OWNPV_data", "PT_data", "isMuon_data", "ProbNNpi_data", "ProbNNk_data", "ProbNNp_data", "IPCHI2_OWNPV_data", "PT_data", "isMuon_data", "FDCHI2_OWNPV_data", "FD_OWNPV_data", "ENDVERTEX_CHI2_data", "DIRA_OWNPV_data", "PT_data", "PT_data", "CL_data", "PP_IsPhoton_data", "PP_IsNotE_data", "PP_IsNotH_data", "PT_data", "CL_data", "PP_IsPhoton_data", "PP_IsNotE_data", "PP_IsNotH_data", "PT_data", "CL_data", "PP_IsPhoton_data", "PP_IsNotE_data", "PP_IsNotH_data", "PT_data"};           
    const char* histTitles[numHist] = {";piminus_ProbNNpi", ";piminus_ProbNNk", ";piminus_ProbNNp", ";piminus_IPCHI2_OWNPV", ";piminus_PT", ";piminus_isMuon", ";Kplus_ProbNNpi", ";Kplus_ProbNNk", ";Kplus_ProbNNp", ";Kplus_IPCHI2_OWNPV", ";Kplus_PT", ";Kplus_isMuon", ";piplus_ProbNNpi", ";piplus_ProbNNk", ";piplus_ProbNNp", ";piplus_IPCHI2_OWNPV", ";piplus_PT", ";piplus_isMuon", ";B_FDCHI2_OWNPV", ";B_FD_OWNPV", ";B_ENDVERTEX_CHI2", ";B_DIRA_OWNPV", ";B_PT", ";pi0_PT", ";gamma_CL", ";gamma_PP_IsPhoton", ";gamma_PP_IsNotE", ";gamma_PP_IsNotH", ";gamma_PT", ";gamma0_CL", ";gamma0_PP_IsPhoton", ";gamma0_PP_IsNotE", ";gamma0_PP_IsNotH", ";gamma0_PT", ";gamma1_CL", ";gamma1_PP_IsPhoton", ";gamma1_PP_IsNotE", ";gamma1_PP_IsNotH", ";gamma1_PT"};
    const Int_t numBins[numHist] = {100, 100, 100, 100, 100, 2, 100, 100, 100, 100, 100, 2, 100, 100, 100, 100, 100, 2, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    const Double_t histRanges[numHist][2] = { {-0.1, 1.1}, {-0.1, 1.1}, {-0.1, 1.1}, {-100, 43000}, {-100, 10000}, {0, 2}, {-0.1, 1.1}, {-0.1, 1.1}, {-0.1, 1.1}, {-1000, 35000}, {-1000, 22000}, {0, 2}, {-0.1, 1.1}, {-0.1, 1.1}, {-0.1, 1.1}, {-1000, 25000}, {-100, 15000}, {0, 2}, {-5000, 140000}, {-5, 150}, {-5, 30}, {0.92, 1.02}, {-10, 40000}, {-10, 7500}, {-0.1, 1.1}, {-0.4, 1.4}, {0, 1.1}, {-0.1, 1.1}, {-100, 6000}, {-0.1, 1.1}, {-0.2, 1.3}, {-0.1, 1.1}, {-0.1, 1.1}, {-100, 6000}, {-0.1, 1.1}, {-0.5, 1.4}, {0, 1.1}, {-0.1, 1.1}, {-10, 25000}};
 
    // ---------------------- HISTOGRAMS ----------------------
    TH1D* hist_sig[numHist];
    TH1D* hist_data[numHist];
    for (Int_t i = 0; i < numHist; ++i) {
        hist_sig[i] = new TH1D(Form("hist_%s_sig", histNames1[i]), histTitles[i], numBins[i], histRanges[i][0], histRanges[i][1]);
        hist_data[i] = new TH1D(Form("hist_%s_data", histNames2[i]), histTitles[i], numBins[i], histRanges[i][0], histRanges[i][1]);
    }

    TH1D* hist_mass_inv_k1plus_sig = new TH1D("hist_mass_inv_k1plus", "mass inv de K1plus", 100, 0, 4000);
    TH1D* hist_mass_inv_B_sig = new TH1D("hist_mass_inv_B", "mass inv de B", 100, 4000, 8000);
    TH1D* hist_mass_inv_omega_sig = new TH1D("hist_mass_inv_omega", "mass inv de omega", 100, -500, 3000);
    
    TH1D* hist_mass_inv_k1plus_data = new TH1D("hist_mass_inv_k1plus", "mass inv de K1plus", 100, 0, 4000);
    TH1D* hist_mass_inv_B_data= new TH1D("hist_mass_inv_B", "mass inv de B", 100, 4000, 8000);
    TH1D* hist_mass_inv_omega_data = new TH1D("hist_mass_inv_omega", "mass inv de omega", 100, -500, 3000);

    TH1D* hist_sans_trigger = new TH1D("hist_sans_trigger", "B_M without trigger", 100, 3000, 8000);
    TH1D* hist_sans_trigger_data = new TH1D("hist_sans_trigger_data", "B_M without trigger data", 100, 3000, 8000);
    TH1D* hist_trigger_L0 = new TH1D("hist_trigger_L0", "trigger L0", 100, 3000, 8000);
    TH1D* hist_trigger_L0_data = new TH1D("hist_trigger_L0_data", "trigger L0 data", 100, 3000, 8000);    
    TH1D* hist_trigger_L0_and_T1 = new TH1D("hist_trigger_L0_and_T1", "trigger L0 and HLT1", 100, 3000, 8000);
    TH1D* hist_trigger_L0_and_T1_data = new TH1D("hist_trigger_L0_and_T1_data", "trigger L0 and HLT1 data", 100, 3000, 8000);
    TH1D* hist_trigger_all = new TH1D("hist_trigger_all", "trigger L0, HLT1 and HLT2", 100, 3000, 8000);
    TH1D* hist_trigger_all_data = new TH1D("hist_trigger_all_data", "trigger L0, HLT1 and HLT2 data", 100, 3000, 8000);

    // ---------------------- LOOP MC ----------------------
    Long64_t nentries1 = tree->GetEntries();
    for (Long64_t i = 0; i < nentries1; ++i) {
        tree->GetEntry(i);
        if (B_BKGCAT == 10) {
            for (int j = 0; j < numHist; ++j) {            
                hist_sig[j]->Fill(getHistValue(j));
            }
            hist_mass_inv_k1plus_sig->Fill(B_M01234);
            hist_mass_inv_B_sig->Fill(B_M012345);
            //hist_mass_inv_B_sig->Fill(B_M);
            hist_mass_inv_omega_sig->Fill(B_M1234);
            hist_sans_trigger->Fill(B_M);
            hist_trigger_L0->Fill(B_M);
            hist_trigger_L0_and_T1->Fill(B_M);
            hist_trigger_all->Fill(B_M);            
        }
    }

	// ---------------------- LOOP DATA ----------------------
    Long64_t nentries2 = tree_data->GetEntries();
    for (Long64_t i = 0; i < nentries2; i++) {
        tree_data->GetEntry(i);
        for (int j = 0; j < numHist; ++j) {
            hist_data[j]->Fill(getHistValue_data(j));
        }
        hist_mass_inv_k1plus_data->Fill(B_M01234_data);
        hist_mass_inv_B_data->Fill(B_M012345_data);
        //hist_mass_inv_B_data->Fill(B_M_data);
        hist_mass_inv_omega_data->Fill(B_M1234_data);
        hist_sans_trigger_data->Fill(B_M_data);
        hist_trigger_L0_data->Fill(B_M_data);
        hist_trigger_L0_and_T1_data->Fill(B_M_data);
        hist_trigger_all_data->Fill(B_M_data);
    } 

    // ---------------------- LEGEND ----------------------
    TLegend *legend = new TLegend(0.25,0.9,0.45,0.8);
    legend->AddEntry(hist_sig[0], "MC", "l");
    legend->AddEntry(hist_data[0], "Data", "l"); 

    // ---------------------- FILL CANVAS ----------------------
    for (Int_t i = 0; i < numHist; ++i) {
        hist_sig[i]->SetLineColor(kRed);
        hist_data[i]->SetLineColor(kBlue);
        gStyle->SetOptStat(111111);
        if (i < 6) {
            piminus_var->cd(i+1);
            if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4) {// Display log scale
                gPad->SetLogy();
                hist_data[i]->SetMinimum(1e-4);
                hist_data[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();         
            hist_data[i]->DrawNormalized("same");        
        } else if (i < 12) {
            Kplus_var->cd(i-5);
            if (i == 6 || i == 7 || i == 8 || i == 9 || i == 10) {
                gPad->SetLogy();
                hist_data[i]->SetMinimum(1e-4);
                hist_data[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();         
            hist_data[i]->DrawNormalized("same");
        } else if (i < 18) {
            piplus_var->cd(i-11);
            if (i == 12 || i == 13 || i == 14 || i == 15 || i == 16){
                gPad->SetLogy();
                hist_data[i]->SetMinimum(1e-4);
                hist_data[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();         
            hist_data[i]->DrawNormalized("same");
        } else if (i < 23) {
            B_var->cd(i-17);
            if (i == 18 || i == 19 || i == 20 || i == 21 || i == 22){
                gPad->SetLogy();
                hist_data[i]->SetMinimum(1e-4);
                hist_data[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();         
            hist_data[i]->DrawNormalized("same");
        } else if (i < 24) {
            pi0_var->cd(i-22);
            if (i == 23){
                gPad->SetLogy();
                hist_data[i]->SetMinimum(1e-4);
                hist_data[i]->SetMaximum(1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();
            hist_data[i]->DrawNormalized("same");
        } else if (i < 29) {
            gamma_var->cd(i-23);
            if (i == 24 || i == 25 || i == 26 || i == 27 || i == 28){
                gPad->SetLogy();
                hist_data[i]->SetMinimum(1e-4);
                hist_data[i]->SetMaximum(1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();
            hist_data[i]->DrawNormalized("same");
        } else if (i < 34) {
            gamma0_var->cd(i-28);
            if (i == 29 || i == 30 || i == 31 || i == 32 || i == 33){
                gPad->SetLogy();
                hist_data[i]->SetMinimum(1e-4);
                hist_data[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();
            hist_data[i]->DrawNormalized("same");
        } else {
            gamma1_var->cd(i-33);            
            if (i == 34 || i == 35 || i == 36 || i == 37 || i == 38){
                gPad->SetLogy();
                hist_data[i]->SetMinimum(1e-4);
                hist_data[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();
            hist_data[i]->DrawNormalized("same");
        }  
        legend->Draw();       
    } 

    // ---------------------- Plot masse invariante et triggers ----------------------
    
    mass_inv->cd(1);
	gPad->SetLogy(1);
    hist_mass_inv_k1plus_sig->SetLineColor(kRed);
    hist_mass_inv_k1plus_data->SetLineColor(kBlue);
    hist_mass_inv_k1plus_sig->DrawNormalized();
    hist_mass_inv_k1plus_data->DrawNormalized("same");
    mass_inv->cd(2);
	gPad->SetLogy(1);
    hist_mass_inv_B_sig->SetLineColor(kRed);
    hist_mass_inv_B_data->SetLineColor(kBlue);   
    hist_mass_inv_B_sig->DrawNormalized();
    hist_mass_inv_B_data->DrawNormalized("same");    
    mass_inv->cd(3);
	gPad->SetLogy(1);
    hist_mass_inv_omega_sig->SetLineColor(kRed);
    hist_mass_inv_omega_data->SetLineColor(kBlue);  
    hist_mass_inv_omega_sig->DrawNormalized();
    hist_mass_inv_omega_data->DrawNormalized("same");    
    //
    triggers->cd(1);
	gPad->SetLogy(1);
    hist_sans_trigger->SetLineColor(kRed);
    hist_sans_trigger_data->SetLineColor(kBlue);
    hist_sans_trigger->DrawNormalized();
    hist_sans_trigger_data->DrawNormalized("same"); 
    triggers->cd(2);
	gPad->SetLogy(1);
    hist_trigger_L0->SetLineColor(kRed);
    hist_trigger_L0_data->SetLineColor(kBlue);
    hist_trigger_L0->DrawNormalized();
    hist_trigger_L0_data->DrawNormalized("same"); 
    triggers->cd(3);
	gPad->SetLogy(1);
    hist_trigger_L0_and_T1->SetLineColor(kRed);
    hist_trigger_L0_and_T1_data->SetLineColor(kBlue);
    hist_trigger_L0_and_T1->DrawNormalized();
    hist_trigger_L0_and_T1_data->DrawNormalized("same"); 
    triggers->cd(4);
	gPad->SetLogy(1);
    hist_trigger_all->SetLineColor(kRed);
    hist_trigger_all_data->SetLineColor(kBlue);
    hist_trigger_all->DrawNormalized();
    hist_trigger_all_data->DrawNormalized("same"); 
    
	// ---------------------- Add text in the middle of each canvas ----------------------
	const char* particleNames[] = {"piminus", "piplus", "Kplus", "B", "pi0", "gamma", "gamma0", "gamma1", "mass_inv", "triggers"};
	for (Int_t i = 0; i < 10; ++i) {
		if (i == 8) continue;  // Skip adding text for i == 8

		TCanvas *canvas = nullptr;
		if (i == 0) canvas = piminus_var;
		else if (i == 1) canvas = piplus_var;
		else if (i == 2) canvas = Kplus_var;
		else if (i == 3) canvas = B_var;
		else if (i == 4) canvas = pi0_var;
		else if (i == 5) canvas = gamma_var;
		else if (i == 6) canvas = gamma0_var;
		else if (i == 7) canvas = gamma1_var;
		else if (i == 9) canvas = triggers;

		canvas->cd();
		if (canvas) {  // Check if canvas is not nullptr before drawing
			TText *text = new TText(0.5, 0.5, Form(particleNames[i]));
			text->SetTextAlign(22);
			text->SetTextSize(0.03);
			text->SetTextColor(kBlack);
			text->Draw();
		}
	}

    // ---------------------- Print to pdf ----------------------
    piminus_var->Print(Form("%s[", outputFileName)); // Open PDF file
    piminus_var->Print(outputFileName);
    piplus_var->Print(outputFileName);
    Kplus_var->Print(outputFileName);
    B_var->Print(outputFileName);
    pi0_var->Print(outputFileName);
    gamma_var->Print(outputFileName);
    gamma0_var->Print(outputFileName);
    gamma1_var->Print(outputFileName);
    mass_inv->Print(outputFileName);
    triggers->Print(outputFileName);
    piminus_var->Print(Form("%s]", outputFileName)); // Close PDF file

    delete piminus_var;
    delete piplus_var;
    delete Kplus_var;
    delete B_var;
    delete pi0_var;
    delete gamma_var;
    delete gamma0_var;
    delete gamma1_var;
    delete mass_inv;
    delete triggers;   
}

// ###############################################################

int main() {
    const char* outputFileName = "Run1_Tchain_data_and_MC_sanscuts.pdf";
    plotVariables2(outputFileName);
    return 0;
}
