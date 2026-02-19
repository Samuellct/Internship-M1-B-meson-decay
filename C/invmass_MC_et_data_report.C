#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TChain.h>
#include <iostream>


Double_t B_M1234;
Double_t B_M1234_data;
Int_t B_BKGCAT;

// ###############################################################

void plotVariables2() {
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
    tree->SetBranchStatus("B_BKGCAT", 1);
    tree->SetBranchStatus("B_M1234", 1);                  
    //
    tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT);
    tree->SetBranchAddress("B_M1234", &B_M1234);
    // ########################################################
    // ------------------------- DATA -------------------------
    // ########################################################
    TFile* datafiltered_Tfile = TFile::Open("DATAkpipipi0G_SELkpipipi0G_MagUp-2011-S21r1p2.root");
    TTree* tree_data = (TTree*)datafiltered_Tfile->Get("DecayTree");

    // Branches
    tree_data->SetBranchStatus("*", 0);
    tree_data->SetBranchStatus("B_M1234", 1);                  
    // 
    tree_data->SetBranchAddress("B_M1234", &B_M1234_data);



    // Create canvas
    TCanvas *plot_canvas = new TCanvas("plot_canvas", "plot_canvas", 800, 600);  
    
    TH1D* hist_mw_MC = new TH1D("hist_mw_MC", "", 100, 0, 6000);
    TH1D* hist_mw_data = new TH1D("hist_mw_data", "", 100, 0, 6000);
   
   TH1D* histograms[] = { hist_mw_MC};
   const char* titles[] = { "Particle mass (MeV)", "Number of events" };

    for (TH1D* hist : histograms) {
        hist->GetXaxis()->SetTitle(titles[0]);
        hist->GetXaxis()->CenterTitle(true);
        hist->GetYaxis()->SetTitle(titles[1]);
        hist->GetYaxis()->CenterTitle(true);
    }

    // Loop MC
    Long64_t nEntries1 = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries1; ++i) {
        tree->GetEntry(i);
        if (B_BKGCAT == 10) {
            hist_mw_MC->Fill(B_M1234);
        } 
    }

    // Loop data
    Long64_t nEntries2 = tree_data->GetEntries();
    for (Long64_t i = 0; i < nEntries2; ++i) {
        tree_data->GetEntry(i);
        hist_mw_data->Fill(B_M1234_data);
    }

    // Legend
    TLegend *legend1 = new TLegend(0.25,0.9,0.45,0.8);  
    legend1->SetTextSize(0.04);
    legend1->AddEntry(hist_mw_MC, "MC events", "l");
    legend1->AddEntry(hist_mw_data, "Data events", "l"); 

    plot_canvas->cd();
    gPad->SetLogy(1);
    hist_mw_data->SetMinimum(1e-4);
    hist_mw_data->SetMaximum(1);
    hist_mw_MC->SetLineColor(kRed);
    hist_mw_MC->DrawNormalized();
    hist_mw_data->SetLineColor(kBlue);
    hist_mw_data->DrawNormalized("same");
    legend1->Draw("same");    


}

// ###############################################################

Int_t main() {
    plotVariables2();
    return 0;
}
