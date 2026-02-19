#define myclass_treeMC_kpipipi0G_cxx
#include "myclass_treeMC_kpipipi0G.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void myclass_treeMC_kpipipi0G::Loop() {
    //   In a ROOT session, you can do:
    //      root> .L myclass_treeMC_kpipipi0G.C
    //      root> myclass_treeMC_kpipipi0G t
    //      root> t.GetEntry(12); // Fill t data members with entry number 12
    //      root> t.Show();       // Show values of entry 12
    //      root> t.Show(16);     // Read and show values of entry 16
    //      root> t.Loop();       // Loop on all entries
    //

    //     This is the loop skeleton where:
    //    jentry is the global entry number in the chain
    //    ientry is the entry number in the current Tree
    //  Note that the argument to GetEntry must be:
    //    jentry for TChain::GetEntry
    //    ientry for TTree::GetEntry and TBranch::GetEntry
    //
    //       To read only selected branches, Insert statements like:
    // METHOD1:
    //    fChain->SetBranchStatus("*",0);  // disable all branches
    //    fChain->SetBranchStatus("branchname",1);  // activate branchname
    // METHOD2: replace line
    //    fChain->GetEntry(jentry);       //read all branches
    //by  b_branchname->GetEntry(ientry); //read only this branch
    if (fChain == 0) return;

    fChain->SetBranchStatus("*", 0);  // disable all branches
    fChain->SetBranchStatus("B_M", 1);  // activate branchname
    fChain->SetBranchStatus("B_BKGCAT", 1);
    fChain->SetBranchStatus("B_M34", 1);
    fChain->SetBranchStatus("B_M1234", 1);
    fChain->SetBranchStatus("B_M01234", 1);

    Long64_t nentries = fChain->GetEntriesFast();

    // -------------------- Creation canvas et histo --------------------
    TCanvas* plot_invmass = new TCanvas("plot_invmass", "masse invariante de pi0, omega, K1plus et B", 1200, 700); 
    plot_invmass->Divide(2, 2);  
	
    TH1D *mB_all = new TH1D("mB_all", "Distribution de la masse du m#acute{e}son B", 100, 4200, 6700);
	TH1D *mB_cut = new TH1D("mB", "mB for quasi-signal entries", 100, 4200, 6700);
	
	TH1D* mpi0_all = new TH1D("mpi0_all", "Distribution de la masse du m#acute{e}son pi0", 100, 100, 170);
	TH1D* mpi0_cut = new TH1D("mpi0", "pi0 mass for quasi-signal", 100, 100, 170);
	
    TH1D* momega_all = new TH1D("momega_all", "Distribution de la masse du m#acute{e}son omega", 100, 400, 4500);
	TH1D* momega_cut = new TH1D("momega", "omega mass for quasi-signal", 100, 400, 4500);
	
    TH1D* mK1plus_all = new TH1D("mK1plus_all", "Distribution de la masse du m#acute{e}son K1plus", 100, 900, 6000); 
	TH1D* mK1plus_cut = new TH1D("mK1plus", "K1plus mass for quasi-signal", 100, 900, 6000);
	
	// -------------------- Nom des axes --------------------
    TH1D* histograms[] = { mB_all, mpi0_all, momega_all,mK1plus_all };
    const char* titles[] = { "Particle mass (MeV)", "Nombre de candidats" };

    for (TH1D* hist : histograms) {
        hist->GetXaxis()->SetTitle(titles[0]);
        hist->GetXaxis()->CenterTitle(true);
        hist->GetYaxis()->SetTitle(titles[1]);
        hist->GetYaxis()->CenterTitle(true);
    }

    for (Int_t jentry = 0; jentry < nentries;jentry++) {
        GetEntry(jentry);		
		mB_all->Fill(B_M);
		mpi0_all->Fill(B_M34);
		momega_all->Fill(B_M1234);
		mK1plus_all->Fill(B_M01234);        
        if (B_BKGCAT == 10) {
            mB_cut->Fill(B_M);
            mpi0_cut->Fill(B_M34);
            momega_cut->Fill(B_M1234);
            mK1plus_cut->Fill(B_M01234);
        }			
    }

    // -------------------- Legende --------------------
    TLegend* leg1 = new TLegend(0.15,0.8,0.43,0.90);
    mB_all->SetLineColor(1);
    mB_cut->SetLineColor(2);
	leg1->SetTextSize(0.04);
    leg1->AddEntry(mB_all, "candidats reconstruits"); 
    leg1->AddEntry(mB_cut, "candidats match#acute{e}s");
	//
	TLegend* leg2 = new TLegend(0.15,0.8,0.43,0.90);
    mpi0_all->SetLineColor(1);
    mpi0_cut->SetLineColor(2);
    leg2->SetTextSize(0.04);
    leg2->AddEntry(mpi0_all, "candidats reconstruits"); 
    leg2->AddEntry(mpi0_cut, "candidats match#acute{e}s");
	//
	TLegend* leg3 = new TLegend(0.60,0.5,0.88,0.6);
    momega_all->SetLineColor(1);
    momega_cut->SetLineColor(2);
    leg3->SetTextSize(0.04);
    leg3->AddEntry(momega_all, "candidats reconstruits"); 
    leg3->AddEntry(momega_cut, "candidats match#acute{e}s");
	//
	TLegend* leg4 = new TLegend(0.60,0.5,0.88,0.6);
    mK1plus_all->SetLineColor(1);
    mK1plus_cut->SetLineColor(2);
    leg4->SetTextSize(0.04);
    leg4->AddEntry(mK1plus_all, "candidats reconstruits"); 
    leg4->AddEntry(mK1plus_cut, "candidats match#acute{e}s");
 
    // -------------------- Fill canvas --------------------
    plot_invmass->cd(1);
	mB_all->Draw();
	mB_cut->Draw("Same");
	leg1->Draw("Same");
	
	plot_invmass->cd(2);
	mpi0_all->Draw();
	mpi0_cut->Draw("Same");
	leg2->Draw("Same");
	
	plot_invmass->cd(3);
	momega_all->Draw();
	momega_cut->Draw("Same");
	leg3->Draw("Same");
	
	plot_invmass->cd(4);
	mK1plus_all->Draw();
	mK1plus_cut->Draw("Same");
	leg4->Draw("Same");  
	
	// -------------------- Save in pdf --------------------
    plot_invmass->Print("Particle_mass.pdf");
}

