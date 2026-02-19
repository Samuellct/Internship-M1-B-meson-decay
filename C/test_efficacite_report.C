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
Double_t gamma_CL, gamma_PP_IsPhoton, gamma_PP_IsNotE, gamma_PP_IsNotH, gamma_PT;
Double_t gamma0_CL, gamma0_PP_IsPhoton, gamma0_PP_IsNotE, gamma0_PP_IsNotH, gamma0_PT;
Double_t gamma1_CL, gamma1_PP_IsPhoton, gamma1_PP_IsNotE, gamma1_PP_IsNotH, gamma1_PT;
Double_t B_M, B_M01234, B_M1234, B_M012345;
Bool_t B_L0PhotonDecision_TOS, B_L0ElectronDecision_TOS, B_Hlt1TrackAllL0Decision_TOS, B_Hlt1TrackPhotonDecision_TOS, B_Hlt2RadiativeTopoTrackDecision_TOS, B_Hlt2RadiativeTopoPhotonDecision_TOS, B_Hlt2RadiativeTopoTrackTOSDecision_TOS, B_Hlt2RadiativeTopoPhotonL0Decision_TOS;
Int_t B_BKGCAT;

// ##############################################################

void calculateEfficiencies() {
    TChain *tree = new TChain("kpipipi0GTupleMC/DecayTree");    
    tree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagDown_mergeAll.root");
    tree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagUp_mergeAll.root");
    tree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagDown_mergeAll_ntp.root");
    tree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagUp_mergeAll_ntp.root");
    // Branches
    tree->SetBranchStatus("*", 0);
    tree->SetBranchStatus("piminus_ProbNNpi", 1);  tree->SetBranchStatus("piplus_ProbNNpi", 1);      tree->SetBranchStatus("gamma_CL", 1);           tree->SetBranchStatus("gamma0_CL", 1);              tree->SetBranchStatus("gamma1_CL", 1);                                                                                                                                                                                                                                                                                                                              
    tree->SetBranchStatus("piminus_ProbNNk", 1);   tree->SetBranchStatus("Kplus_ProbNNk", 1);   tree->SetBranchStatus("piplus_ProbNNk", 1);        tree->SetBranchStatus("gamma_PP_IsPhoton", 1);      tree->SetBranchStatus("gamma0_PP_IsPhoton", 1);               
    tree->SetBranchStatus("piminus_ProbNNp", 1);
    tree->SetBranchStatus("Kplus_ProbNNpi", 1);
    tree->SetBranchStatus("Kplus_ProbNNp", 1);
    tree->SetBranchStatus("piplus_ProbNNp", 1);
    tree->SetBranchStatus("gamma1_PP_IsPhoton", 1);                                                                                                                                                                                                                                                                                                                             
                     
    tree->SetBranchStatus("B_BKGCAT", 1); 
    
    tree->SetBranchStatus("B_M", 1);
    tree->SetBranchStatus("B_M01234", 1);
    tree->SetBranchStatus("B_M1234", 1);    
    tree->SetBranchStatus("B_L0PhotonDecision_TOS", 1);
    tree->SetBranchStatus("B_L0ElectronDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt1TrackAllL0Decision_TOS", 1);
    tree->SetBranchStatus("B_Hlt1TrackPhotonDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoTrackDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoPhotonDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoTrackTOSDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoPhotonL0Decision_TOS", 1);
    //    
    tree->SetBranchAddress("piminus_ProbNNpi", &piminus_ProbNNpi);                 tree->SetBranchAddress("Kplus_ProbNNpi", &Kplus_ProbNNpi);                 tree->SetBranchAddress("piplus_ProbNNpi", &piplus_ProbNNpi);                              tree->SetBranchAddress("gamma_CL", &gamma_CL);                           tree->SetBranchAddress("gamma0_CL", &gamma0_CL);                           tree->SetBranchAddress("gamma1_CL", &gamma1_CL);                                                                                                                                                                                                                                                                                                                              
    tree->SetBranchAddress("piminus_ProbNNk", &piminus_ProbNNk);                   tree->SetBranchAddress("Kplus_ProbNNk", &Kplus_ProbNNk);                   tree->SetBranchAddress("piplus_ProbNNk", &piplus_ProbNNk);                                       tree->SetBranchAddress("gamma_PP_IsPhoton", &gamma_PP_IsPhoton);         tree->SetBranchAddress("gamma0_PP_IsPhoton", &gamma0_PP_IsPhoton);         tree->SetBranchAddress("gamma1_PP_IsPhoton", &gamma1_PP_IsPhoton);
    tree->SetBranchAddress("piminus_ProbNNp", &piminus_ProbNNp);                   tree->SetBranchAddress("Kplus_ProbNNp", &Kplus_ProbNNp);                   tree->SetBranchAddress("piplus_ProbNNp", &piplus_ProbNNp);                                                                                                                                                                                                                                                                                                                                  
    
    
    tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT); 


    tree->SetBranchAddress("B_M01234", &B_M01234);
    tree->SetBranchAddress("B_M1234", &B_M1234);
    tree->SetBranchAddress("B_M", &B_M);
    tree->SetBranchAddress("B_L0PhotonDecision_TOS", &B_L0PhotonDecision_TOS);
    tree->SetBranchAddress("B_L0ElectronDecision_TOS", &B_L0ElectronDecision_TOS);
    tree->SetBranchAddress("B_Hlt1TrackAllL0Decision_TOS", &B_Hlt1TrackAllL0Decision_TOS);
    tree->SetBranchAddress("B_Hlt1TrackPhotonDecision_TOS", &B_Hlt1TrackPhotonDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoTrackDecision_TOS", &B_Hlt2RadiativeTopoTrackDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoPhotonDecision_TOS", &B_Hlt2RadiativeTopoPhotonDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoTrackTOSDecision_TOS", &B_Hlt2RadiativeTopoTrackTOSDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoPhotonL0Decision_TOS", &B_Hlt2RadiativeTopoPhotonL0Decision_TOS);
    
    //------------------------------------------------------------
    Int_t signal_total = 0, background_total = 0, signal_pass[5] = {0}, background_pass[5] = {0};

    for (Long64_t i = 0, nEntries = tree->GetEntries(); i < nEntries; ++i) {
        tree->GetEntry(i);
        if (B_BKGCAT == 10) {
            ++signal_total;
            signal_pass[0] += (piminus_ProbNNpi > 0.2 && piminus_ProbNNk < 0.8 && piminus_ProbNNp < 0.8 && piplus_ProbNNpi > 0.2 && piplus_ProbNNk < 0.8 && piplus_ProbNNp < 0.8 && Kplus_ProbNNpi < 0.8 && Kplus_ProbNNk > 0.2 && Kplus_ProbNNp < 0.8);
            signal_pass[1] += (gamma_CL > 0.2 && gamma_PP_IsPhoton > 0.5 && gamma0_CL > 0.2 && gamma0_PP_IsPhoton > 0.5 && gamma1_CL > 0.2 && gamma1_PP_IsPhoton > 0.5);
            signal_pass[2] += (B_M01234<3000 && B_M1234<1500 && B_M<7000 && B_M>4500);
            signal_pass[3] += ((B_L0PhotonDecision_TOS==1 || B_L0ElectronDecision_TOS==1) && (B_Hlt1TrackAllL0Decision_TOS==1 || B_Hlt1TrackPhotonDecision_TOS==1) && (B_Hlt2RadiativeTopoTrackDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonDecision_TOS == 1 || B_Hlt2RadiativeTopoTrackTOSDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonL0Decision_TOS == 1));
            signal_pass[4] += ((piminus_ProbNNpi > 0.2 && piminus_ProbNNk < 0.8 && piminus_ProbNNp < 0.8 && piplus_ProbNNpi > 0.2 && piplus_ProbNNk < 0.8 && piplus_ProbNNp < 0.8 && Kplus_ProbNNpi < 0.8 && Kplus_ProbNNk > 0.2 && Kplus_ProbNNp < 0.8) && (gamma_CL > 0.2 && gamma_PP_IsPhoton > 0.5 && gamma0_CL > 0.2 && gamma0_PP_IsPhoton > 0.5 && gamma1_CL > 0.2 && gamma1_PP_IsPhoton > 0.5) && (B_M01234 < 3000 && B_M1234 < 1500 && B_M < 7000 && B_M>4500) && ((B_L0PhotonDecision_TOS==1 || B_L0ElectronDecision_TOS==1) && (B_Hlt1TrackAllL0Decision_TOS==1 || B_Hlt1TrackPhotonDecision_TOS==1) && (B_Hlt2RadiativeTopoTrackDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonDecision_TOS == 1 || B_Hlt2RadiativeTopoTrackTOSDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonL0Decision_TOS == 1)));
            
        } else if (B_BKGCAT != 10) {
            ++background_total;
            background_pass[0] += (piminus_ProbNNpi > 0.2 && piminus_ProbNNk < 0.8 && piminus_ProbNNp < 0.8 && piplus_ProbNNpi > 0.2 && piplus_ProbNNk < 0.8 && piplus_ProbNNp < 0.8 && Kplus_ProbNNpi < 0.8 && Kplus_ProbNNk > 0.2 && Kplus_ProbNNp < 0.8);
            background_pass[1] += (gamma_CL > 0.2 && gamma_PP_IsPhoton > 0.5 && gamma0_CL > 0.2 && gamma0_PP_IsPhoton > 0.5 && gamma1_CL > 0.2 && gamma1_PP_IsPhoton > 0.5);
            background_pass[2] += (B_M01234 < 3000 && B_M1234 < 1500 && B_M < 7000 && B_M>4500);
            background_pass[3] += ((B_L0PhotonDecision_TOS==1 || B_L0ElectronDecision_TOS==1) && (B_Hlt1TrackAllL0Decision_TOS==1 || B_Hlt1TrackPhotonDecision_TOS==1) && (B_Hlt2RadiativeTopoTrackDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonDecision_TOS == 1 || B_Hlt2RadiativeTopoTrackTOSDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonL0Decision_TOS == 1));
            background_pass[4] += ((piminus_ProbNNpi > 0.2 && piminus_ProbNNk < 0.8 && piminus_ProbNNp < 0.8 && piplus_ProbNNpi > 0.2 && piplus_ProbNNk < 0.8 && piplus_ProbNNp < 0.8 && Kplus_ProbNNpi < 0.8 && Kplus_ProbNNk > 0.2 && Kplus_ProbNNp < 0.8) && (gamma_CL > 0.2 && gamma_PP_IsPhoton > 0.5 && gamma0_CL > 0.2 && gamma0_PP_IsPhoton > 0.5 && gamma1_CL > 0.2 && gamma1_PP_IsPhoton > 0.5) && (B_M01234 < 3000 && B_M1234 < 1500 && B_M < 7000 && B_M>4500) && ((B_L0PhotonDecision_TOS==1 || B_L0ElectronDecision_TOS==1) && (B_Hlt1TrackAllL0Decision_TOS==1 || B_Hlt1TrackPhotonDecision_TOS==1) && (B_Hlt2RadiativeTopoTrackDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonDecision_TOS == 1 || B_Hlt2RadiativeTopoTrackTOSDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonL0Decision_TOS == 1)));
           
        }
    }

   /* for (Int_t j = 0; j < 5; ++j) {
        Double_t efficiency_signal = (signal_pass[j] / static_cast<Double_t>(signal_total)) * 100.0;
        Double_t efficiency_background = (background_pass[j] / static_cast<Double_t>(background_total)) * 100.0;
        std::cout << "Efficiency_" << (j == 0 ? "charged" : j == 1 ? "neutral" : j == 2 ? "masse" : j == 3 ? "trigger" : "all")
             << "_signal: " << efficiency_signal << "%" << std::endl;
        std::cout << "Efficiency_" << (j == 0 ? "charged" : j == 1 ? "neutral" : j == 2 ? "masse" : j == 3 ? "trigger" : "all")
             << "_background: " << efficiency_background << "%" << std::endl;
        
        std::cout << "background_total" << background_total << std::endl;
    }*/

    // Noms des efficacités pour faciliter l'accès et améliorer la lisibilité
    const char* efficiencyNames[] = {"chargedPID", "neutralPID", "masse", "trigger", "all"};

    TCanvas* textCanvas = new TCanvas("textCanvas", "Efficiency Results", 800, 600);
    textCanvas->cd();
    TLatex latex;
    latex.SetTextAlign(13);  // Align left, center vertically
    latex.SetTextSize(0.020);
    double lineSpacing = 0.04; // Adjust line spacing
    int line = 0;

    for (Int_t j = 0; j < 5; ++j) {
        Double_t efficiency_MC = (signal_pass[j] / static_cast<Double_t>(signal_total)) * 100.0;
        Double_t efficiency_bkg = (background_pass[j] / static_cast<Double_t>(background_total)) * 100.0;
        latex.DrawLatex(0.1, 0.9 - line * lineSpacing, 
            Form("Efficiency %s: MC = %.2f%% (%d/%d), bkg = %.2f%% (%d/%d)", 
                efficiencyNames[j], efficiency_MC, signal_pass[j], signal_total, 
                efficiency_bkg, background_pass[j], background_total));
		
		line++;
    }






}

// ###############################################################

Int_t main() {  
    calculateEfficiencies();
    return 0;
}
