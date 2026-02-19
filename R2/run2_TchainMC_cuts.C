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
Int_t B_BKGCAT;


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

// ###############################################################

void plotVariables4(const char* outputFileName) {
    // ########################################################
    // --------------------- MONTE CARLO ----------------------
    // ########################################################	
    TChain *tree = new TChain("kpipipi0GTupleMC/DecayTree");   
    tree->Add("radiativeXpi0G_MC2016-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco16_S28r2_MagDown_mergeAll_ntp.root");
    tree->Add("radiativeXpi0G_MC2016-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco16_S28r2_MagUp_mergeAll_ntp.root");
    tree->Add("radiativeXpi0G_MC2017-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco17_S29r2_MagDown_mergeAll_ntp.root");
    tree->Add("radiativeXpi0G_MC2017-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco17_S29r2_MagUp_mergeAll_ntp.root");
    tree->Add("radiativeXpi0G_MC2018-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco18_S34_MagDown_mergeAll_ntp.root");
    tree->Add("radiativeXpi0G_MC2018-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco18_S34_MagUp_mergeAll_ntp.root");

    
    // Branches
    tree->SetBranchStatus("*", 0);
    tree->SetBranchStatus("piminus_ProbNNpi", 1);             tree->SetBranchStatus("Kplus_ProbNNpi", 1);                   tree->SetBranchStatus("piplus_ProbNNpi", 1);                   tree->SetBranchStatus("B_FDCHI2_OWNPV", 1);                 tree->SetBranchStatus("gamma_CL", 1);                        tree->SetBranchStatus("gamma0_CL", 1);                        tree->SetBranchStatus("gamma1_CL", 1);                                                                                                                                                                                                                                                                                                                              
    tree->SetBranchStatus("piminus_ProbNNk", 1);              tree->SetBranchStatus("Kplus_ProbNNk", 1);                    tree->SetBranchStatus("piplus_ProbNNk", 1);                    tree->SetBranchStatus("B_FD_OWNPV", 1);                     tree->SetBranchStatus("gamma_PP_IsPhoton", 1);               tree->SetBranchStatus("gamma0_PP_IsPhoton", 1);               tree->SetBranchStatus("gamma1_PP_IsPhoton", 1);
    tree->SetBranchStatus("piminus_ProbNNp", 1);              tree->SetBranchStatus("Kplus_ProbNNp", 1);                    tree->SetBranchStatus("piplus_ProbNNp", 1);                    tree->SetBranchStatus("B_ENDVERTEX_CHI2", 1);               tree->SetBranchStatus("gamma_PP_IsNotE", 1);                 tree->SetBranchStatus("gamma0_PP_IsNotE", 1);                 tree->SetBranchStatus("gamma1_PP_IsNotE", 1);                                                                                                                                                                                                                                                                                                        
    tree->SetBranchStatus("piminus_IPCHI2_OWNPV", 1);         tree->SetBranchStatus("Kplus_IPCHI2_OWNPV", 1);               tree->SetBranchStatus("piplus_IPCHI2_OWNPV", 1);               tree->SetBranchStatus("B_DIRA_OWNPV", 1);                   tree->SetBranchStatus("gamma_PP_IsNotH", 1);                 tree->SetBranchStatus("gamma0_PP_IsNotH", 1);                 tree->SetBranchStatus("gamma1_PP_IsNotH", 1);  
    tree->SetBranchStatus("piminus_PT", 1);                   tree->SetBranchStatus("Kplus_PT", 1);                         tree->SetBranchStatus("piplus_PT", 1);                         tree->SetBranchStatus("B_PT", 1);                           tree->SetBranchStatus("gamma_PT", 1);                        tree->SetBranchStatus("gamma0_PT", 1);                        tree->SetBranchStatus("gamma1_PT", 1);                                                                                                                                                                                                                                                    
    tree->SetBranchStatus("piminus_isMuon", 1);               tree->SetBranchStatus("piplus_isMuon", 1);                   tree->SetBranchStatus("Kplus_isMuon", 1);                                                                                       
    tree->SetBranchStatus("pi0_PT", 1);                       tree->SetBranchStatus("B_BKGCAT", 1); 
    //    
    tree->SetBranchAddress("piminus_ProbNNpi", &piminus_ProbNNpi);                 tree->SetBranchAddress("Kplus_ProbNNpi", &Kplus_ProbNNpi);                 tree->SetBranchAddress("piplus_ProbNNpi", &piplus_ProbNNpi);                 tree->SetBranchAddress("B_FDCHI2_OWNPV", &B_FDCHI2_OWNPV);             tree->SetBranchAddress("gamma_CL", &gamma_CL);                           tree->SetBranchAddress("gamma0_CL", &gamma0_CL);                           tree->SetBranchAddress("gamma1_CL", &gamma1_CL);                                                                                                                                                                                                                                                                                                                              
    tree->SetBranchAddress("piminus_ProbNNk", &piminus_ProbNNk);                   tree->SetBranchAddress("Kplus_ProbNNk", &Kplus_ProbNNk);                   tree->SetBranchAddress("piplus_ProbNNk", &piplus_ProbNNk);                   tree->SetBranchAddress("B_FD_OWNPV", &B_FD_OWNPV);                     tree->SetBranchAddress("gamma_PP_IsPhoton", &gamma_PP_IsPhoton);         tree->SetBranchAddress("gamma0_PP_IsPhoton", &gamma0_PP_IsPhoton);         tree->SetBranchAddress("gamma1_PP_IsPhoton", &gamma1_PP_IsPhoton);
    tree->SetBranchAddress("piminus_ProbNNp", &piminus_ProbNNp);                   tree->SetBranchAddress("Kplus_ProbNNp", &Kplus_ProbNNp);                   tree->SetBranchAddress("piplus_ProbNNp", &piplus_ProbNNp);                   tree->SetBranchAddress("B_ENDVERTEX_CHI2", &B_ENDVERTEX_CHI2);         tree->SetBranchAddress("gamma_PP_IsNotE", &gamma_PP_IsNotE);             tree->SetBranchAddress("gamma0_PP_IsNotE", &gamma0_PP_IsNotE);             tree->SetBranchAddress("gamma1_PP_IsNotE", &gamma1_PP_IsNotE);                                                                                                                                                                                                                                                                                                        
    tree->SetBranchAddress("piminus_IPCHI2_OWNPV", &piminus_IPCHI2_OWNPV);         tree->SetBranchAddress("Kplus_IPCHI2_OWNPV", &Kplus_IPCHI2_OWNPV);         tree->SetBranchAddress("piplus_IPCHI2_OWNPV", &piplus_IPCHI2_OWNPV);         tree->SetBranchAddress("B_DIRA_OWNPV", &B_DIRA_OWNPV);                 tree->SetBranchAddress("gamma_PP_IsNotH", &gamma_PP_IsNotH);             tree->SetBranchAddress("gamma0_PP_IsNotH", &gamma0_PP_IsNotH);             tree->SetBranchAddress("gamma1_PP_IsNotH", &gamma1_PP_IsNotH);  
    tree->SetBranchAddress("piminus_PT", &piminus_PT);                             tree->SetBranchAddress("Kplus_PT", &Kplus_PT);                             tree->SetBranchAddress("piplus_PT", &piplus_PT);                             tree->SetBranchAddress("B_PT", &B_PT);                                 tree->SetBranchAddress("gamma_PT", &gamma_PT);                           tree->SetBranchAddress("gamma0_PT", &gamma0_PT);                           tree->SetBranchAddress("gamma1_PT", &gamma1_PT);                                                                                                                                                                                                                                                    
    tree->SetBranchAddress("piminus_isMuon", &piminus_isMuon);                     tree->SetBranchAddress("piplus_isMuon", &piplus_isMuon);                   tree->SetBranchAddress("Kplus_isMuon", &Kplus_isMuon);                                                                                       
    tree->SetBranchAddress("pi0_PT", &pi0_PT);        tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT); 

    // --------------------- canvas ---------------------
    TCanvas *piminus_var = new TCanvas("piminus_var", "piminus_var Plots", 800, 600);
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

    // Variables pr les boucles
    const Int_t numHist = 39; // Nombre total d'histogrammes
    const char* histNames[numHist] = {"ProbNNpi", "ProbNNk", "ProbNNp", "IPCHI2_OWNPV", "PT", "isMuon", "ProbNNpi", "ProbNNk", "ProbNNp", "IPCHI2_OWNPV", "PT", "isMuon", "ProbNNpi", "ProbNNk", "ProbNNp", "IPCHI2_OWNPV", "PT", "isMuon", "FDCHI2_OWNPV", "FD_OWNPV", "ENDVERTEX_CHI2", "DIRA_OWNPV", "PT", "PT", "CL", "IsPhoton", "IsNotE", "IsNotH", "PT", "CL", "PP_IsPhoton", "PP_IsNotE", "PP_IsNotH", "PT", "CL", "IsPhoton", "IsNotE", "IsNotH", "PT"};
    const char* histTitles[numHist] = {";piminus_ProbNNpi", ";piminus_ProbNNk", ";piminus_ProbNNp", ";piminus_IPCHI2_OWNPV", ";piminus_PT", ";piminus_isMuon", ";Kplus_ProbNNpi", ";Kplus_ProbNNk", ";Kplus_ProbNNp", ";Kplus_IPCHI2_OWNPV", ";Kplus_PT", ";Kplus_isMuon", ";piplus_ProbNNpi", ";piplus_ProbNNk", ";piplus_ProbNNp", ";piplus_IPCHI2_OWNPV", ";piplus_PT", ";piplus_isMuon", ";B_FDCHI2_OWNPV", ";B_FD_OWNPV", ";B_ENDVERTEX_CHI2", ";B_DIRA_OWNPV", ";B_PT", ";pi0_PT", ";gamma_CL", ";gamma_PP_IsPhoton", ";gamma_PP_IsNotE", ";gamma_PP_IsNotH", ";gamma_PT", ";gamma0_CL", ";gamma0_PP_IsPhoton", ";gamma0_PP_IsNotE", ";gamma0_PP_IsNotH", ";gamma0_PT", ";gamma1_CL", ";gamma1_PP_IsPhoton", ";gamma1_PP_IsNotE", ";gamma1_PP_IsNotH", ";gamma1_PT"};
    const Int_t numBins[numHist] = {100, 100, 100, 100, 100, 2, 100, 100, 100, 100, 100, 2, 100, 100, 100, 100, 100, 2, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    const Double_t histRanges[numHist][2] = { {-0.1, 1.1}, {-0.1, 1.1}, {-0.1, 1.1}, {-100, 43000}, {-100, 15000}, {0, 2}, {-0.1, 1.1}, {-0.1, 1.1}, {-0.1, 1.1}, {-100, 40000}, {-100, 25000}, {0, 2}, {-0.1, 1.1}, {-0.1, 1.1}, {-0.1, 1.1}, {-100, 40000}, {-100, 45000}, {0, 2}, {-1000, 180000}, {-5, 220}, {-5, 30}, {0.95, 1.01}, {-10, 55000}, {-10, 12000}, {-0.1, 1.1}, {-0.4, 1.4}, {0, 1.1}, {-0.1, 1.1}, {-10, 15000}, {-0.1, 1.1}, {-0.2, 1.3}, {-0.2, 1.1}, {-0.1, 1.1}, {-10, 10000}, {-0.1, 1.1}, {-0.5, 1.4}, {0, 1.1}, {-0.1, 1.1}, {-10, 30000}};


    // --------------------- Histograms ---------------------
    TH1D* hist_sig[numHist];
    TH1D* hist_bkg[numHist];
    for (Int_t i = 0; i < numHist; ++i) {
        hist_sig[i] = new TH1D(Form("hist_%s_sig", histNames[i]), histTitles[i], numBins[i], histRanges[i][0], histRanges[i][1]);
        hist_bkg[i] = new TH1D(Form("hist_%s_bkg", histNames[i]), histTitles[i], numBins[i], histRanges[i][0], histRanges[i][1]);
    }

    // --------------------- Loop MC et cuts ---------------------
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);
        if (piminus_ProbNNpi > 0.2 && piminus_ProbNNk < 0.8 && piminus_ProbNNp<0.8 && piplus_ProbNNpi>0.2 && piplus_ProbNNk<0.8 && piplus_ProbNNp<0.8 && Kplus_ProbNNpi<0.8 && Kplus_ProbNNk>0.2 && Kplus_ProbNNp<0.8 && gamma_CL>0.2 && gamma_PP_IsPhoton>0.5 && gamma0_CL>0.2 && gamma0_PP_IsPhoton>0.5 && gamma1_CL>0.2 && gamma1_PP_IsPhoton>0.5 ) {
            for (int j = 0; j < numHist; ++j) {
                if (B_BKGCAT == 10) {
                    hist_sig[j]->Fill(getHistValue(j));
                } else if (B_BKGCAT != 10) {
                    hist_bkg[j]->Fill(getHistValue(j));
                }
            }
        }
    }

    // --------------------- Legend ---------------------
    TLegend *legend = new TLegend(0.25,0.9,0.45,0.8);
    legend->AddEntry(hist_sig[0], "Signal", "l");
    legend->AddEntry(hist_bkg[0], "Background", "l"); 

    // --------------------- Fill canvas ---------------------
    for (Int_t i = 0; i < numHist; ++i) {
        hist_sig[i]->SetLineColor(kRed);
        hist_bkg[i]->SetLineColor(kBlue);
        gStyle->SetOptStat(111111);
        if (i < 6) {
            piminus_var->cd(i+1);
            if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4) {// Display log scale
                gPad->SetLogy();
                hist_bkg[i]->SetMinimum(1e-4);
                hist_bkg[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();         
            hist_bkg[i]->DrawNormalized("same");        
        } else if (i < 12) {
            Kplus_var->cd(i-5);
            if (i == 6 || i == 7 || i == 8 || i == 9 || i == 10) {
                gPad->SetLogy();
                hist_bkg[i]->SetMinimum(1e-4);
                hist_bkg[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();         
            hist_bkg[i]->DrawNormalized("same");
        } else if (i < 18) {
            piplus_var->cd(i-11);
            if (i == 12 || i == 13 || i == 14 || i == 15 || i == 16){
                gPad->SetLogy();
                hist_bkg[i]->SetMinimum(1e-4);
                hist_bkg[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();         
            hist_bkg[i]->DrawNormalized("same");
        } else if (i < 23) {
            B_var->cd(i-17);
            if (i == 18 || i == 19 || i == 20 || i == 21){
                gPad->SetLogy();
                hist_bkg[i]->SetMinimum(1e-4);
                hist_bkg[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();         
            hist_bkg[i]->DrawNormalized("same");
        } else if (i < 24) {
            pi0_var->cd(i-22);
            if (i == 23){
                gPad->SetLogy();
                hist_bkg[i]->SetMinimum(1e-4);
                hist_bkg[i]->SetMaximum(1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();
            hist_bkg[i]->DrawNormalized("same");
        } else if (i < 29) {
            gamma_var->cd(i-23);
            if (i == 24 || i == 25 || i == 27){
                gPad->SetLogy();
                hist_bkg[i]->SetMinimum(1e-4);
                hist_bkg[i]->SetMaximum(1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();
            hist_bkg[i]->DrawNormalized("same");
        } else if (i < 34) {
            gamma0_var->cd(i-28);
            if (i == 29 || i == 30 || i == 32){
                gPad->SetLogy();
                hist_bkg[i]->SetMinimum(1e-4);
                hist_bkg[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();
            hist_bkg[i]->DrawNormalized("same");
        } else {
            gamma1_var->cd(i-33);            
            if (i == 34 || i == 35 || i == 37){
                gPad->SetLogy();
                hist_bkg[i]->SetMinimum(1e-4);
                hist_bkg[i]->SetMaximum(1e1);
            } else {
                gPad->SetLogy(false);
            }
            hist_sig[i]->DrawNormalized();
            hist_bkg[i]->DrawNormalized("same");
        }  
        legend->Draw();       
    }    

    // --------------------- Add text in the middle of each canvas ---------------------
    const char* particleNames[] = {"piminus", "piplus", "Kplus", "B", "pi0", "gamma", "gamma0", "gamma1"};
    for (Int_t i = 0; i < 8; ++i) {
        TCanvas *canvas = nullptr;
        if (i == 0) canvas = piminus_var;
        else if (i == 1) canvas = piplus_var;
        else if (i == 2) canvas = Kplus_var;
        else if (i == 3) canvas = B_var;
        else if (i == 4) canvas = pi0_var;
        else if (i == 5) canvas = gamma_var;
        else if (i == 6) canvas = gamma0_var;
        else if (i == 7) canvas = gamma1_var;
        canvas->cd();
        TText *text = new TText(0.5, 0.5, Form(particleNames[i]));
        text->SetTextAlign(22);
        text->SetTextSize(0.03);
        text->SetTextColor(kBlack);
        text->Draw();
    }

    // --------------------- Print to pdf ---------------------
    piminus_var->Print(Form("%s[", outputFileName)); // Open PDF file
    piminus_var->Print(outputFileName); // Print into PDF
    piplus_var->Print(outputFileName);
    Kplus_var->Print(outputFileName);
    B_var->Print(outputFileName);
    pi0_var->Print(outputFileName);
    gamma_var->Print(outputFileName);
    gamma0_var->Print(outputFileName);
    gamma1_var->Print(outputFileName);
    piminus_var->Print(Form("%s]", outputFileName)); // Close PDF file

    delete piminus_var;
    delete piplus_var;
    delete Kplus_var;
    delete B_var;
    delete pi0_var;
    delete gamma_var;
    delete gamma0_var;
    delete gamma1_var;
   
}

// ###############################################################

Int_t main6() {
    const char* outputFileName = "Run2_Tchain_MC_cuts.pdf";
    plotVariables4(outputFileName);
    return 0;
}