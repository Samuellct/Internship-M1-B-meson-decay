#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TChain.h>
#include <iostream>


Double_t B_M;
Double_t B_M01234;
Double_t B_M1234;
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
    tree->SetBranchStatus("B_BKGCAT", 1);
    tree->SetBranchStatus("B_M", 1);
    tree->SetBranchStatus("B_M01234", 1);
    tree->SetBranchStatus("B_M1234", 1);
                  
    //
    tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT);
    tree->SetBranchAddress("B_M", &B_M);
    tree->SetBranchAddress("B_M01234", &B_M01234);
    tree->SetBranchAddress("B_M1234", &B_M1234);

    // Create canvas
    TCanvas *plot_canvas = new TCanvas("plot_canvas", "plot_canvas", 1000, 700);
    plot_canvas->Divide(2,1);

    //TH1D* hist_mB_sig = new TH1D("hist_mB_sig", "B invariant mass distribution for MC TChain", 100, 4000, 7500);
    TH1D* hist_mK1_sig = new TH1D("hist_mK1_sig", "K1 invariant mass distribution for MC TChain", 100, 500, 6000);
    TH1D* hist_momega_sig = new TH1D("hist_momega_sig", "omega invariant mass distribution for MC TChain", 100, 0, 4500);
    
    //TH1D* hist_mB_bkg = new TH1D("hist_mB_bkg", "B invariant mass distribution for BKG", 100, 4000, 7500);
    TH1D* hist_mK1_bkg = new TH1D("hist_mK1_bkg", "K1 invariant mass distribution for BKG", 100, 500, 6000);
    TH1D* hist_momega_bkg = new TH1D("hist_momega_bkg", "omega invariant mass distribution for BKG", 100, 0, 4500);
   
   TH1D* histograms[] = { hist_mK1_sig, hist_momega_sig};
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
            //hist_mB_sig->Fill(B_M);
            hist_mK1_sig->Fill(B_M01234);
            hist_momega_sig->Fill(B_M1234);
        } else if (B_BKGCAT != 10) {
            //hist_mB_bkg->Fill(B_M);
            hist_mK1_bkg->Fill(B_M01234);
            hist_momega_bkg->Fill(B_M1234);
        }
    }

    // Legend
    //TLegend *legend1 = new TLegend(0.25,0.9,0.45,0.8);  
    //legend1->AddEntry(hist_mB_sig, "Signal events", "l");
    //legend1->AddEntry(hist_mB_bkg, "Background events", "l"); 

    TLegend *legend2 = new TLegend(0.25,0.9,0.45,0.8);
    legend2->SetTextSize(0.03);
    legend2->AddEntry(hist_mK1_sig, "Signal events", "l");
    legend2->AddEntry(hist_mK1_bkg, "Background events", "l"); 
    
    TLegend *legend3 = new TLegend(0.25,0.9,0.45,0.8);
    legend3->SetTextSize(0.03);
    legend3->AddEntry(hist_momega_sig, "Signal events", "l");
    legend3->AddEntry(hist_momega_bkg, "Background events", "l");        

     


    plot_canvas->cd(1);
    gPad->SetLogy(1);
    hist_mK1_sig->SetLineColor(kRed);
    hist_mK1_sig->DrawNormalized();
    hist_mK1_bkg->SetLineColor(kBlue);
    hist_mK1_bkg->DrawNormalized("same");
    legend2->Draw("same");    

    /*plot_canvas->cd(2);
    gPad->SetLogy(1);
    //hist_signal[i]->SetMinimum(1e-4);
    //hist_signal[i]->SetMaximum(1e0);
    hist_mB_sig->SetLineColor(kRed);
    hist_mB_sig->DrawNormalized();
    hist_mB_bkg->SetLineColor(kBlue);
    hist_mB_bkg->DrawNormalized("same");
    legend1->Draw("same");  */  

    plot_canvas->cd(2);
    gPad->SetLogy(1);
    hist_momega_sig->SetLineColor(kRed);
    hist_momega_sig->DrawNormalized();
    hist_momega_bkg->SetLineColor(kBlue);
    hist_momega_bkg->DrawNormalized("same");
    legend3->Draw("same");
}

// ###############################################################

Int_t main() {
    plotVariables2();
    return 0;
}
