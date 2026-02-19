#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TChain.h>
#include <iostream>


Double_t B_M;
Int_t B_BKGCAT;

// ###############################################################

void plotVariables2() {
	TFile* inputFile = TFile::Open("radiativeXpi0G_MC2017-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco17_S29r2_MagDown_mergeAll_ntp.root");
    TTree* tree = (TTree*)inputFile->Get("kpipipi0GTupleMC/DecayTree");

    // Branches
    tree->SetBranchStatus("*", 0);
    tree->SetBranchStatus("B_BKGCAT", 1);
    tree->SetBranchStatus("B_M", 1);
    //
    tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT);
    tree->SetBranchAddress("B_M", &B_M);

    // Create canvas
    TCanvas *plot_canvas = new TCanvas("plot_canvas", "plot_canvas", 800, 600);
    
    TH1D* hist_mB_sig = new TH1D("hist_mB_sig", "B invariant mass distribution for MC TChain", 100, 4000, 7500);
    TH1D* hist_mB_bkg = new TH1D("hist_mB_bkg", "B invariant mass distribution for BKG", 100, 4000, 7500);
   
   
   TH1D* histograms[] = {hist_mB_sig};
    const char* titles[] = { "Particle mass (MeV)", "Number of events (Log scale)" };

    for (TH1D* hist : histograms) {
        hist->GetXaxis()->SetTitle(titles[0]);
        hist->GetXaxis()->CenterTitle(true);
        hist->GetYaxis()->SetTitle(titles[1]);
        hist->GetYaxis()->CenterTitle(true);
    }


    // Loop
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);
        if (B_BKGCAT == 10) {
            hist_mB_sig->Fill(B_M);
            
        } else if (B_BKGCAT != 10) {
            hist_mB_bkg->Fill(B_M);
            
        }
    }


    // Legend
    TLegend *legend1 = new TLegend(0.25,0.9,0.45,0.8);  
    legend1->AddEntry(hist_mB_sig, "Signal (candidats matchés)", "l");
    legend1->AddEntry(hist_mB_bkg, "Bruit de fond (candidats non matchés)", "l"); 
 

    plot_canvas->cd();
    //gPad->SetLogy(1);
    hist_mB_sig->SetMinimum(0);
    hist_mB_sig->SetMaximum(400);
    hist_mB_sig->SetLineColor(kRed);
    hist_mB_sig->Draw();
    hist_mB_bkg->SetLineColor(kBlue);
    hist_mB_bkg->Draw("same");
    legend1->Draw("same");    

}

// ###############################################################

Int_t main() {
    plotVariables2();
    return 0;
}
