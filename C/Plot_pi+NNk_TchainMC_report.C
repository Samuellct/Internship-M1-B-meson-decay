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
                  
    // 
    tree->SetBranchAddress("piplus_ProbNNk", &piplus_ProbNNk);
    tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT);
    tree->SetBranchAddress("B_FD_OWNPV", &B_FD_OWNPV);
    tree->SetBranchAddress("gamma0_CL", &gamma0_CL);

    // Create canvas
    TCanvas *plot_canvas = new TCanvas("plot_canvas", "plot_canvas", 800, 600);

    TH1D* hist_signal = new TH1D("hist_total", "piplus_ProbNNk distribution for MC TChain", 100, -0.1, 1.1);
    TH1D* hist_bkg = new TH1D("hist_filtre_bkg", "piplus_ProbNNk distribution for BKG=10", 100, -0.1, 1.1);
   
    hist_signal->GetXaxis()->SetTitle("piplus_ProbNNk distribution");
    hist_signal->GetXaxis()->CenterTitle(true);
    hist_signal->GetYaxis()->SetTitle("Number of events (Log scale)");
    hist_signal->GetYaxis()->CenterTitle(true);

    // Loop
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);
        if (B_BKGCAT == 10) {
            hist_signal->Fill(piplus_ProbNNk);
        } else if (B_BKGCAT != 10) {
            hist_bkg->Fill(piplus_ProbNNk);
        }
    }

    // Legend
    TLegend *legend = new TLegend(0.25,0.9,0.45,0.8);
    legend->AddEntry(hist_signal, "Signal events", "l");
    legend->AddEntry(hist_bkg, "Background events", "l"); 

    plot_canvas->cd();
    gPad->SetLogy(1);
    //hist_signal[i]->SetMinimum(1e-4);
    //hist_signal[i]->SetMaximum(1e0);
    hist_signal->SetLineColor(kRed);
    hist_signal->DrawNormalized();
    hist_bkg->SetLineColor(kBlue);
    hist_bkg->DrawNormalized("same");
    legend->Draw("same");
}

// ###############################################################

Int_t main() {
    plotVariables2();
    return 0;
}
