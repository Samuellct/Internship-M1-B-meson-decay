#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TVector3.h"
#include "TMath.h"

void ReconstructParticles1() {
    // Ouvrir le fichier ROOT
    TFile* file = TFile::Open("datacut.root");
    TTree* tree = (TTree*)file->Get("OutputTree");

    // Variables pour stocker les composantes des 4-vecteurs pour chaque particule
    Double_t B_TRUEP_E, B_TRUEP_X, B_TRUEP_Y, B_TRUEP_Z;
    Double_t pi0_TRUEP_X, pi0_TRUEP_Y, pi0_TRUEP_Z, pi0_TRUEP_E;
    Double_t gamma0_TRUEP_X, gamma0_TRUEP_Y, gamma0_TRUEP_Z, gamma0_TRUEP_E;
    Double_t gamma1_TRUEP_X, gamma1_TRUEP_Y, gamma1_TRUEP_Z, gamma1_TRUEP_E;
    Double_t gamma_TRUEP_E, gamma_TRUEP_X, gamma_TRUEP_Y, gamma_TRUEP_Z;
    Double_t piplus_TRUEP_E, piplus_TRUEP_X, piplus_TRUEP_Y, piplus_TRUEP_Z;
    Double_t piminus_TRUEP_E, piminus_TRUEP_X, piminus_TRUEP_Y, piminus_TRUEP_Z;
    Double_t Kplus_TRUEP_X, Kplus_TRUEP_Y, Kplus_TRUEP_Z, Kplus_TRUEP_E;
    Double_t K_2_1770_plus_TRUEP_X, K_2_1770_plus_TRUEP_Y, K_2_1770_plus_TRUEP_Z, K_2_1770_plus_TRUEP_E;
    Double_t K_1_1270_plus_TRUEP_X, K_1_1270_plus_TRUEP_Y, K_1_1270_plus_TRUEP_Z, K_1_1270_plus_TRUEP_E;

    // Lier les variables aux branches de l'arbre
    tree->SetBranchAddress("B_TRUEP_E", &B_TRUEP_E);
    tree->SetBranchAddress("B_TRUEP_X", &B_TRUEP_X);
    tree->SetBranchAddress("B_TRUEP_Y", &B_TRUEP_Y);
    tree->SetBranchAddress("B_TRUEP_Z", &B_TRUEP_Z);

    tree->SetBranchAddress("piplus_TRUEP_E", &piplus_TRUEP_E);
    tree->SetBranchAddress("piplus_TRUEP_X", &piplus_TRUEP_X);
    tree->SetBranchAddress("piplus_TRUEP_Y", &piplus_TRUEP_Y);
    tree->SetBranchAddress("piplus_TRUEP_Z", &piplus_TRUEP_Z);

    tree->SetBranchAddress("piminus_TRUEP_E", &piminus_TRUEP_E);
    tree->SetBranchAddress("piminus_TRUEP_X", &piminus_TRUEP_X);
    tree->SetBranchAddress("piminus_TRUEP_Y", &piminus_TRUEP_Y);
    tree->SetBranchAddress("piminus_TRUEP_Z", &piminus_TRUEP_Z);

    tree->SetBranchAddress("pi0_TRUEP_E", &pi0_TRUEP_E);
    tree->SetBranchAddress("pi0_TRUEP_X", &pi0_TRUEP_X);
    tree->SetBranchAddress("pi0_TRUEP_Y", &pi0_TRUEP_Y);
    tree->SetBranchAddress("pi0_TRUEP_Z", &pi0_TRUEP_Z);

    tree->SetBranchAddress("gamma0_TRUEP_E", &gamma0_TRUEP_E);
    tree->SetBranchAddress("gamma0_TRUEP_X", &gamma0_TRUEP_X);
    tree->SetBranchAddress("gamma0_TRUEP_Y", &gamma0_TRUEP_Y);
    tree->SetBranchAddress("gamma0_TRUEP_Z", &gamma0_TRUEP_Z);

    tree->SetBranchAddress("gamma1_TRUEP_E", &gamma1_TRUEP_E);
    tree->SetBranchAddress("gamma1_TRUEP_X", &gamma1_TRUEP_X);
    tree->SetBranchAddress("gamma1_TRUEP_Y", &gamma1_TRUEP_Y);
    tree->SetBranchAddress("gamma1_TRUEP_Z", &gamma1_TRUEP_Z);

    tree->SetBranchAddress("Kplus_TRUEP_E", &Kplus_TRUEP_E);
    tree->SetBranchAddress("Kplus_TRUEP_X", &Kplus_TRUEP_X);
    tree->SetBranchAddress("Kplus_TRUEP_Y", &Kplus_TRUEP_Y);
    tree->SetBranchAddress("Kplus_TRUEP_Z", &Kplus_TRUEP_Z);

    tree->SetBranchAddress("K_2_1770_plus_TRUEP_E", &K_2_1770_plus_TRUEP_E);
    tree->SetBranchAddress("K_2_1770_plus_TRUEP_X", &K_2_1770_plus_TRUEP_X);
    tree->SetBranchAddress("K_2_1770_plus_TRUEP_Y", &K_2_1770_plus_TRUEP_Y);
    tree->SetBranchAddress("K_2_1770_plus_TRUEP_Z", &K_2_1770_plus_TRUEP_Z);

    tree->SetBranchAddress("K_1_1270_plus_TRUEP_E", &K_1_1270_plus_TRUEP_E);
    tree->SetBranchAddress("K_1_1270_plus_TRUEP_X", &K_1_1270_plus_TRUEP_X);
    tree->SetBranchAddress("K_1_1270_plus_TRUEP_Y", &K_1_1270_plus_TRUEP_Y);
    tree->SetBranchAddress("K_1_1270_plus_TRUEP_Z", &K_1_1270_plus_TRUEP_Z);

    tree->SetBranchAddress("gamma_TRUEP_E", &gamma_TRUEP_E);
    tree->SetBranchAddress("gamma_TRUEP_X", &gamma_TRUEP_X);
    tree->SetBranchAddress("gamma_TRUEP_Y", &gamma_TRUEP_Y);
    tree->SetBranchAddress("gamma_TRUEP_Z", &gamma_TRUEP_Z);

    // Histogrammes pour les masses invariantes
    TH1D* hPi0Mass = new TH1D("hPi0Mass", "Masse invariante de pi0;Masse invariante;events", 100, 100, 200);
    TH1D* hpi0_GeneratedMass = new TH1D("hpi0_GeneratedMass", "Masse invariante de pi0 (gen);Masse invariante;events", 100, 100, 200);
    
    TH1D* hk1plus = new TH1D("hk1plus", "Masse invariante de K", 100, 1000, 3000);
    TH1D* hk2plus = new TH1D("hk2plus", "Masse invariante de K", 100, 1000, 3000);

    TH1D* hB_Gen = new TH1D("hB_Gen", "Masse invariante de B genere", 100, 5100, 5400);
    TH1D* hB_rec = new TH1D("hB_rec", "Masse invariante de B reconstruit", 100, 5100, 5400);
    
    TH1D* hAngle = new TH1D("hAngle", "Angle Distribution;Angle;Events", 100, 0, TMath::Pi());

    // Counters for equal and non-equal events
    int equalEvents1 = 0; int equalEvents2 = 0; int equalEvents3 = 0;
    int nonEqualEvents1 = 0; int nonEqualEvents2 = 0; int nonEqualEvents3 = 0;
    int oppositeMomentaEvents = 0;
    int nonOppositeMomentaEvents = 0;


    // Boucle sur les entrees de l'arbre
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t iEntry = 0; iEntry < nEntries; ++iEntry) {
        tree->GetEntry(iEntry);

        // Reconstruire les 4-vecteurs des particules
        TLorentzVector gamma0, gamma1, pi0_Generated, gamma, piplus, piminus, Kplus;
        gamma.SetPxPyPzE(gamma_TRUEP_X, gamma_TRUEP_Y, gamma_TRUEP_Z, gamma_TRUEP_E);
        gamma0.SetPxPyPzE(gamma0_TRUEP_X, gamma0_TRUEP_Y, gamma0_TRUEP_Z, gamma0_TRUEP_E);
        gamma1.SetPxPyPzE(gamma1_TRUEP_X, gamma1_TRUEP_Y, gamma1_TRUEP_Z, gamma1_TRUEP_E);
        pi0_Generated.SetPxPyPzE(pi0_TRUEP_X, pi0_TRUEP_Y, pi0_TRUEP_Z, pi0_TRUEP_E);// pi0 tel que généré dans le tuple            
        piplus.SetPxPyPzE(piplus_TRUEP_X, piplus_TRUEP_Y, piplus_TRUEP_Z, piplus_TRUEP_E);
        piminus.SetPxPyPzE(piminus_TRUEP_X, piminus_TRUEP_Y, piminus_TRUEP_Z, piminus_TRUEP_E);
        Kplus.SetPxPyPzE(Kplus_TRUEP_X, Kplus_TRUEP_Y, Kplus_TRUEP_Z, Kplus_TRUEP_E);


        TLorentzVector pi0_reconstructed, omega_reconstructed, K_1_1270_plus_reconstructed, K_1_1270_plus_Generated, K_2_1770_plus, B_Generated, B_reconstructed;
        pi0_reconstructed.SetPxPyPzE(gamma0_TRUEP_X + gamma_TRUEP_X, gamma0_TRUEP_Y + gamma_TRUEP_Y, gamma0_TRUEP_Z + gamma_TRUEP_Z, gamma0_TRUEP_E + gamma_TRUEP_E);// pi0 tel qu'il se decay generalement
        omega_reconstructed.SetPxPyPzE(piplus_TRUEP_X + piminus_TRUEP_X + pi0_reconstructed.Px(), piplus_TRUEP_Y + piminus_TRUEP_Y + pi0_reconstructed.Py(), piplus_TRUEP_Z + piminus_TRUEP_Z + pi0_reconstructed.Pz(), piplus_TRUEP_E + piminus_TRUEP_E + pi0_reconstructed.E());
        
        K_1_1270_plus_reconstructed.SetPxPyPzE(Kplus_TRUEP_X + omega_reconstructed.Px(), Kplus_TRUEP_Y + omega_reconstructed.Py(), Kplus_TRUEP_Z + omega_reconstructed.Pz(), Kplus_TRUEP_E + omega_reconstructed.E());
        
        K_1_1270_plus_Generated.SetPxPyPzE(Kplus_TRUEP_X + piplus_TRUEP_X + piminus_TRUEP_X, Kplus_TRUEP_Y + piplus_TRUEP_Y + piminus_TRUEP_Y, Kplus_TRUEP_Z + piplus_TRUEP_Z + piminus_TRUEP_Z, Kplus_TRUEP_E + piplus_TRUEP_E + piminus_TRUEP_E);
        K_2_1770_plus.SetPxPyPzE(K_2_1770_plus_TRUEP_X, K_2_1770_plus_TRUEP_Y, K_2_1770_plus_TRUEP_Z, K_2_1770_plus_TRUEP_E); //generated      
        B_Generated.SetPxPyPzE(B_TRUEP_X, B_TRUEP_Y, B_TRUEP_Z, B_TRUEP_E);        
        B_reconstructed.SetPxPyPzE(K_1_1270_plus_reconstructed.Px() + gamma1_TRUEP_X, K_1_1270_plus_reconstructed.Py() + gamma1_TRUEP_Y, K_1_1270_plus_reconstructed.Pz() + gamma1_TRUEP_Z, K_1_1270_plus_reconstructed.E() + gamma1_TRUEP_E);

        // Boost Kplus and omega_reconstructed to K_1_1270_plus_reconstructed
        TVector3 K_1_1270_plus_reconstructed_BoostVector = K_1_1270_plus_reconstructed.BoostVector();
        TLorentzVector Kplus_new = Kplus;
        Kplus_new.Boost(-K_1_1270_plus_reconstructed_BoostVector);

        TLorentzVector omega_reconstructed_new = omega_reconstructed;
        omega_reconstructed_new.Boost(-K_1_1270_plus_reconstructed_BoostVector);

        // Check if the momenta of Kplus and omega_reconstructed are opposite
        bool momenta = (Kplus_new.Vect().Dot(omega_reconstructed_new.Vect()) < 0);

        // Increment counters based on momenta comparison
        if (momenta) { oppositeMomentaEvents++; }
        else { nonOppositeMomentaEvents++; }

        // Compare the 4-vectors
        bool Kversus = (K_1_1270_plus_reconstructed == K_2_1770_plus);
        bool pi0versus = (pi0_Generated == pi0_reconstructed);
        bool omegaversus = (omega_reconstructed == piplus + piminus + pi0_reconstructed);

        // Increment counters based on comparison results
        if (Kversus) { equalEvents1++; }
        else { nonEqualEvents1++; }
        if (pi0versus) { equalEvents2++; }
        else { nonEqualEvents2++; }
        if (omegaversus) { equalEvents3++; }
        else { nonEqualEvents3++; }

        // Calculer la masse invariante des pi0
        hPi0Mass->Fill(pi0_reconstructed.M());
        hpi0_GeneratedMass->Fill(pi0_Generated.M());
        // Les K
        hk1plus->Fill(K_1_1270_plus_reconstructed.M());
        hk2plus->Fill(K_2_1770_plus.M());
        // Les B
        hB_Gen->Fill(B_Generated.M());
        hB_rec->Fill(B_reconstructed.M());


        // Angle between B and k+ in the rest frame of K_1_1270_plus_reconstructed
        Double_t Bangle = B_reconstructed.Vect().Angle(Kplus_new.Vect());
        Double_t BangleRAD = Bangle * TMath::DegToRad(); //Conversion radian
        hAngle->Fill(BangleRAD);

    }

    // Display the message with counts of equal and non-equal events
    std::cout << "Events with equal 4-vectors for K: " << equalEvents1
        << ", non-equal: " << nonEqualEvents1 << std::endl;
    std::cout << "Events with equal 4-vectors for pi: " << equalEvents2
        << ", non-equal: " << nonEqualEvents2 << std::endl;
    std::cout << "Events with equal 4-vectors for omega: " << equalEvents3
        << ", non-equal: " << nonEqualEvents3 << std::endl;

    // Affichage du nombre d'événements avec des moments opposés ou non
    std::cout << "Nombre d'events with opposite momenta for K+ and w: " << oppositeMomentaEvents
        << ", Non-opposite: " << nonOppositeMomentaEvents << std::endl;

    // Tracer les histogrammes sur un graphique
    TCanvas* c = new TCanvas("c", "Masse Invariante", 800, 600);
    c->Divide(2, 2);
    hPi0Mass->SetLineColor(kBlue), hk1plus->SetLineColor(kBlue), hB_rec->SetLineColor(kBlue);
    hpi0_GeneratedMass->SetLineColor(kRed), hk2plus->SetLineColor(kRed), hB_Gen->SetLineColor(kRed);
    c->cd(1);
    hPi0Mass->Draw();
    hpi0_GeneratedMass->Draw("same");

    c->cd(2);
    hk1plus->Draw();
    hk2plus->Draw("same");

    c->cd(3);
    hB_Gen->Draw();
    hB_rec->Draw("same");

    c->cd(4);
    hAngle->Draw();

    // Ajouter une legende
    TLegend* legend = new TLegend(0.65, 0.5, 0.88, 0.7);
    legend->AddEntry(hPi0Mass, "pi0 -> #gamma#gamma", "l"), legend->AddEntry(hk1plus, "K1plus", "l");
    legend->AddEntry(hpi0_GeneratedMass, "pi0 from tuple", "l"), legend->AddEntry(hk2plus, "K2plus", "l");
    legend->Draw();

    // Afficher le graphique
    c->Draw();




}


int quadri2() {
    ReconstructParticles1();
    return 0;
}
