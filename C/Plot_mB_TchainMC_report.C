#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TChain.h>
#include <iostream>


Double_t piplus_ProbNNk;
Double_t B_FD_OWNPV;
Double_t gamma0_CL;
Int_t B_BKGCAT;
Double_t B_M;

// ###############################################################

void plotVariables2() {
    TChain *tree = new TChain("kpipipi0GTupleMC/DecayTree");    
    tree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagDown_mergeAll.root");
    tree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagUp_mergeAll.root");
    tree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagDown_mergeAll_ntp.root");
    tree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagUp_mergeAll_ntp.root");
    // Branches
    tree->SetBranchStatus("*", 0);
    tree->SetBranchStatus("piplus_ProbNNk", 1);
    tree->SetBranchStatus("B_BKGCAT", 1);
    tree->SetBranchStatus("B_FD_OWNPV", 1);
    tree->SetBranchStatus("gamma0_CL", 1);
    tree->SetBranchStatus("B_M", 1);
                  
    // 
    tree->SetBranchAddress("piplus_ProbNNk", &piplus_ProbNNk);
    tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT);
    tree->SetBranchAddress("B_FD_OWNPV", &B_FD_OWNPV);
    tree->SetBranchAddress("gamma0_CL", &gamma0_CL);
    tree->SetBranchAddress("B_M", &B_M);

    // Create canvas
    TCanvas *plot_canvas = new TCanvas("plot_canvas", "piminus_var Plots", 800, 600);

    TH1D* hist_total = new TH1D("hist_total", "B meson mass distribution for MC TChain", 100, 4000, 7000.0);
    TH1D* hist_filtre_bkg = new TH1D("hist_filtre_bkg", "B meson mass distribution for BKG=10", 100, 4000.0, 7000.0);
   
    hist_total->GetXaxis()->SetTitle("Invariant mass distribution (MeV)");
    hist_total->GetXaxis()->CenterTitle(true);
    hist_total->GetYaxis()->SetTitle("Number of events");
    hist_total->GetYaxis()->CenterTitle(true);

    // Loop
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);
        hist_total->Fill(B_M);
        if (B_BKGCAT == 10) {
            hist_filtre_bkg->Fill(B_M);
        }
    }

    // Legend
    TLegend *legend = new TLegend(0.25,0.9,0.45,0.8);
    legend->AddEntry(hist_total, "All events", "l");
    legend->AddEntry(hist_filtre_bkg, "Quasi-signal data", "l"); 

    plot_canvas->cd();
    //gPad->SetLogy(1);
    hist_total->SetLineColor(kBlack);
    hist_total->Draw();
    hist_filtre_bkg->SetLineColor(kRed);
    hist_filtre_bkg->Draw("same");
    legend->Draw("same");
}

// ###############################################################

Int_t main() {
    plotVariables2();
    return 0;
}
