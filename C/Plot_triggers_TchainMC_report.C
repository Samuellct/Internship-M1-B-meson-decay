#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TChain.h>
#include <iostream>


Double_t B_M;
Bool_t B_L0PhotonDecision_TOS, B_L0ElectronDecision_TOS, B_Hlt1TrackAllL0Decision_TOS, B_Hlt1TrackPhotonDecision_TOS, B_Hlt2RadiativeTopoTrackDecision_TOS, B_Hlt2RadiativeTopoPhotonDecision_TOS, B_Hlt2RadiativeTopoTrackTOSDecision_TOS, B_Hlt2RadiativeTopoPhotonL0Decision_TOS;
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
    tree->SetBranchStatus("B_L0PhotonDecision_TOS", 1);
    tree->SetBranchStatus("B_L0ElectronDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt1TrackAllL0Decision_TOS", 1);
    tree->SetBranchStatus("B_Hlt1TrackPhotonDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoTrackDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoPhotonDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoTrackTOSDecision_TOS", 1);
    tree->SetBranchStatus("B_Hlt2RadiativeTopoPhotonL0Decision_TOS", 1);
                  
    //
    tree->SetBranchAddress("B_BKGCAT", &B_BKGCAT);
    tree->SetBranchAddress("B_M", &B_M);
    tree->SetBranchAddress("B_L0PhotonDecision_TOS", &B_L0PhotonDecision_TOS);
    tree->SetBranchAddress("B_L0ElectronDecision_TOS", &B_L0ElectronDecision_TOS);
    tree->SetBranchAddress("B_Hlt1TrackAllL0Decision_TOS", &B_Hlt1TrackAllL0Decision_TOS);
    tree->SetBranchAddress("B_Hlt1TrackPhotonDecision_TOS", &B_Hlt1TrackPhotonDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoTrackDecision_TOS", &B_Hlt2RadiativeTopoTrackDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoPhotonDecision_TOS", &B_Hlt2RadiativeTopoPhotonDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoTrackTOSDecision_TOS", &B_Hlt2RadiativeTopoTrackTOSDecision_TOS);
    tree->SetBranchAddress("B_Hlt2RadiativeTopoPhotonL0Decision_TOS", &B_Hlt2RadiativeTopoPhotonL0Decision_TOS);

    // Create canvas
    TCanvas *plot_canvas = new TCanvas("plot_canvas", "plot_canvas", 800, 600);
    plot_canvas->Divide(2,2);

    TH1D* hist_mB_ref = new TH1D("hist_mB_ref", "", 100, 4000, 7000);
    TH1D* hist_mB_L0 = new TH1D("hist_mB_L0", "", 100, 4000, 7000);
    TH1D* hist_mB_T1 = new TH1D("hist_mB_T1", "", 100, 4000, 7000);
    TH1D* hist_mB_T2 = new TH1D("hist_mB_T2", "", 100, 4000, 7000);


    TH1D* hist_mB_ref_bkg = new TH1D("hist_mB_ref_bkg", "B invariant mass distribution for BKG", 100, 4000, 7000);
    TH1D* hist_mB_L0_bkg = new TH1D("hist_mB_L0_bkg", "K1 invariant mass distribution for BKG", 100, 4000, 7000);
    TH1D* hist_mB_T1_bkg = new TH1D("hist_mB_T1_bkg", "omega invariant mass distribution for BKG", 100, 4000, 7000);
    TH1D* hist_mB_T2_bkg = new TH1D("hist_mB_T2_bkg", "omega invariant mass distribution for BKG", 100, 4000, 7000);

   TH1D* histograms[] = { hist_mB_ref, hist_mB_L0, hist_mB_T1, hist_mB_T2};
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
        bool L0_trigger = (B_L0PhotonDecision_TOS==1 || B_L0ElectronDecision_TOS==1);
        bool HLT1 = (B_Hlt1TrackAllL0Decision_TOS==1 || B_Hlt1TrackPhotonDecision_TOS==1);
        bool HLT2 = (B_Hlt2RadiativeTopoTrackDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonDecision_TOS == 1 || B_Hlt2RadiativeTopoTrackTOSDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonL0Decision_TOS == 1);
        
        if (B_BKGCAT == 10) {
            hist_mB_ref->Fill(B_M);
            if (L0_trigger) {
                hist_mB_L0->Fill(B_M);
                if (HLT1) {
                    hist_mB_T1->Fill(B_M);
                    if (HLT2) {
                        hist_mB_T2->Fill(B_M);
                    }
                }
            }
        }
        else if (B_BKGCAT != 10) {
            hist_mB_ref_bkg->Fill(B_M);
            if (L0_trigger) {
                hist_mB_L0_bkg->Fill(B_M);
                if (HLT1) {
                    hist_mB_T1_bkg->Fill(B_M);
                    if (HLT2) {
                        hist_mB_T2_bkg->Fill(B_M);
                    }
                }
            }
        }
    }



    // Legend
    TLegend *legend1 = new TLegend(0.25,0.9,0.45,0.8);  
    legend1->SetTextSize(0.04);
    legend1->AddEntry(hist_mB_ref , "Signal events", "l");
    legend1->AddEntry(hist_mB_ref_bkg, "Background events", "l"); 

    TLegend *legend2 = new TLegend(0.25,0.9,0.45,0.8);
    legend2->SetTextSize(0.04);
    legend2->AddEntry(hist_mB_L0, "Signal events", "l");
    legend2->AddEntry(hist_mB_L0_bkg, "Background events", "l"); 
    
    TLegend *legend3 = new TLegend(0.25,0.9,0.45,0.8);
    legend3->SetTextSize(0.04);
    legend3->AddEntry(hist_mB_T1 , "Signal events", "l");
    legend3->AddEntry(hist_mB_T1_bkg , "Background events", "l");      

    TLegend *legend4 = new TLegend(0.25,0.9,0.45,0.8);
    legend4->SetTextSize(0.04);
    legend4->AddEntry(hist_mB_T2, "Signal events", "l");
    legend4->AddEntry(hist_mB_T2_bkg , "Background events", "l");  
     

    plot_canvas->cd(1);
    //gPad->SetLogy(1);
    hist_mB_ref->SetLineColor(kRed);
    hist_mB_ref->DrawNormalized();
    hist_mB_ref_bkg->SetLineColor(kBlue);
    hist_mB_ref_bkg->DrawNormalized("same");
    legend1->Draw("same");    

    plot_canvas->cd(2);
    //gPad->SetLogy(1);
    //hist_signal[i]->SetMinimum(1e-4);
    //hist_signal[i]->SetMaximum(1e0);
    hist_mB_L0->SetLineColor(kRed);
    hist_mB_L0->DrawNormalized();
    hist_mB_L0_bkg->SetLineColor(kBlue);
    hist_mB_L0_bkg->DrawNormalized("same");
    legend2->Draw("same"); 

    plot_canvas->cd(3);
    //gPad->SetLogy(1);
    hist_mB_T1->SetLineColor(kRed);
    hist_mB_T1->DrawNormalized();
    hist_mB_T1_bkg->SetLineColor(kBlue);
    hist_mB_T1_bkg->DrawNormalized("same");
    legend3->Draw("same");

    plot_canvas->cd(4);
    //gPad->SetLogy(1);
    hist_mB_T2->SetLineColor(kRed);
    hist_mB_T2->DrawNormalized();
    hist_mB_T2_bkg->SetLineColor(kBlue);
    hist_mB_T2_bkg->DrawNormalized("same");
    legend4->Draw("same");
}

// ###############################################################

Int_t main() {
    plotVariables2();
    return 0;
}
