#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TChain.h>
#include <iostream>


Double_t B_M02;
Double_t B_M1234;
Double_t B_M0234;
Double_t B_M02_data;
Double_t B_M1234_data;
Double_t B_M0234_data;

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
    tree->SetBranchStatus("B_M0234", 1); 
    tree->SetBranchStatus("B_M02", 1);                 
    //
    tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT);
    tree->SetBranchAddress("B_M1234", &B_M1234);
    tree->SetBranchAddress("B_M0234", &B_M0234);
    tree->SetBranchAddress("B_M02", &B_M02);
    // ########################################################
    // ------------------------- DATA -------------------------
    // ########################################################
    TChain *tree_data = new TChain("DecayTree");
    tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagUp-2011-S21r1p2_red.root");
    tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagDown-2012-S21r0p2_red.root");
    tree_data->Add("DATAkpipipi0G_SELkpipipi0G_MagUp-2012-S21r0p2_red.root");
    // Branches
    tree_data->SetBranchStatus("*", 0);
    tree_data->SetBranchStatus("B_M1234", 1);
    tree_data->SetBranchStatus("B_M0234", 1);
    tree_data->SetBranchStatus("B_M02", 1);                   
    // 
    tree_data->SetBranchAddress("B_M1234", &B_M1234_data);
    tree_data->SetBranchAddress("B_M0234", &B_M0234_data);
    tree_data->SetBranchAddress("B_M02", &B_M02_data);

    // Create canvas
    TCanvas *plot_canvas = new TCanvas("plot_canvas", "plot_canvas", 1000, 600);  
    plot_canvas->Divide(3,1);
    
    //TH1D* hist_m02_MC = new TH1D("hist_m02_MC", "", 100, 0, 3000);
    TH1D* hist_m02_data = new TH1D("hist_m02_data", "", 100, 0, 3000);

    //TH1D* hist_momega_MC = new TH1D("hist_momega_MC", "", 100, 450, 600);
    TH1D* hist_momega_data = new TH1D("hist_momega_data", "", 100, 450, 600);

    //TH1D* hist_m0234_MC = new TH1D("hist_m0234_MC", "", 100, 0, 3500);
    TH1D* hist_m0234_data = new TH1D("hist_m0234_data", "", 100, 0, 3500);
   
   TH1D* histograms[] = { hist_m02_data, hist_momega_data, hist_m0234_data };
    const char* titles[] = { "Particle mass (MeV)", "Number of events" };

    for (TH1D* hist : histograms) {
        hist->GetXaxis()->SetTitle(titles[0]);
        hist->GetXaxis()->CenterTitle(true);
        hist->GetYaxis()->SetTitle(titles[1]);
        hist->GetYaxis()->CenterTitle(true);
    }

   /* // Loop MC
    Long64_t nEntries1 = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries1; ++i) {
        tree->GetEntry(i);        
        if (B_BKGCAT == 10) {
            if (B_M1234 > 720 && B_M1234 < 845) {
                hist_m02_MC->Fill(B_M02);
                hist_momega_MC->Fill(B_M1234);
                hist_m0234_MC->Fill(B_M0234);
            }
        } 
    }*/

    // Loop data
    Long64_t nEntries2 = tree_data->GetEntries();
    for (Long64_t i = 0; i < nEntries2; ++i) {
        tree_data->GetEntry(i);        
        hist_m02_data->Fill(B_M02_data);
        hist_momega_data->Fill(B_M1234_data);
        hist_m0234_data->Fill(B_M0234_data);
    }
    /*
    // Legend
    TLegend *legend1 = new TLegend(0.25,0.9,0.55,0.8);  
    legend1->SetTextSize(0.04);
    //legend1->AddEntry(hist_m02_MC, "MC events", "l");
    legend1->AddEntry(hist_m02_data, "Data events", "l");

    TLegend *legend2 = new TLegend(0.25,0.9, 0.55,0.8);
    legend2->SetTextSize(0.04);
    //legend2->AddEntry(hist_momega_MC, "MC events", "l");
    legend2->AddEntry(hist_momega_data, "Data events", "l");

    TLegend *legend3 = new TLegend(0.25,0.9, 0.55,0.8);
    legend3->SetTextSize(0.04);
    //legend3->AddEntry(hist_m0234_MC, "MC events", "l");
    legend3->AddEntry(hist_m0234_data, "Data events", "l");
    */
    plot_canvas->cd(1);
    //gPad->SetLogy(1);
    //hist_m02_MC->SetLineColor(kRed);
    //hist_m02_MC->DrawNormalized();
    //hist_m02_data->SetLineColor(kBlue);
    hist_m02_data->Draw();
    //legend1->Draw("same");

    plot_canvas->cd(2);
    //gPad->SetLogy(1);
    //hist_momega_MC->SetLineColor(kRed);
    //hist_momega_MC->DrawNormalized();
    //hist_momega_data->SetLineColor(kBlue);
    hist_momega_data->Draw();
    //legend2->Draw("same");   

    plot_canvas->cd(3);
    //gPad->SetLogy(1);
    //hist_m0234_data->SetMinimum(1e-3);
    //hist_m0234_data->SetMaximum(1e-1);
    //hist_m0234_MC->SetLineColor(kRed);
    //hist_m0234_MC->DrawNormalized();
    //hist_m0234_data->SetLineColor(kBlue);
    hist_m0234_data->Draw();
    //legend3->Draw("same");   

}

// ###############################################################

Int_t main() {
    plotVariables2();
    return 0;
}
