#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TLegend.h"
#include "TVector3.h"
#include "TMath.h"

void SaveVariables_and_4vector() {
    TFile* datafiltered_Tfile = TFile::Open("datafiltered.root");
    TTree* datafiltered_Ttree = (TTree*)datafiltered_Tfile->Get("OutputTree");

    // Variables MC rebuilt
    Double_t piplus_PE, piplus_PX, piplus_PY, piplus_PZ, piplus_PT;

    Double_t piminus_PE, piminus_PX, piminus_PY, piminus_PZ, piminus_PT;

    Double_t Rebuilt_pi0_PX, Rebuilt_pi0_PY, Rebuilt_pi0_PZ, Rebuilt_pi0_PE, Rebuilt_pi0_PT;
 
    Double_t gamma0_PX, gamma0_PY, gamma0_PZ, gamma0_PE, gamma0_PT;

    Double_t gamma1_PX, gamma1_PY, gamma1_PZ, gamma1_PE, gamma1_PT;

    Double_t Kplus_PX, Kplus_PY, Kplus_PZ, Kplus_PE, Kplus_PT;

    Double_t Rebuilt_K_1_plus_PX, Rebuilt_K_1_plus_PY, Rebuilt_K_1_plus_PZ, Rebuilt_K_1_plus_PE, Rebuilt_K_1_plus_PT;

    Double_t B_PX, B_PY, B_PZ, B_PE, B_PT;

    Double_t gamma_PE, gamma_PX, gamma_PY, gamma_PZ, gamma_PT;

    // Variables MC true
    Double_t piplus_TRUEP_E, piplus_TRUEP_X, piplus_TRUEP_Y, piplus_TRUEP_Z, piplus_TRUEPT, piplus_TRUEORIGINVERTEX_X, piplus_TRUEORIGINVERTEX_Y, piplus_TRUEORIGINVERTEX_Z, piplus_TRUEENDVERTEX_X, piplus_TRUEENDVERTEX_Y, piplus_TRUEENDVERTEX_Z;

    Double_t piminus_TRUEP_E, piminus_TRUEP_X, piminus_TRUEP_Y, piminus_TRUEP_Z, piminus_TRUEPT, piminus_TRUEORIGINVERTEX_X, piminus_TRUEORIGINVERTEX_Y, piminus_TRUEORIGINVERTEX_Z, piminus_TRUEENDVERTEX_X, piminus_TRUEENDVERTEX_Y, piminus_TRUEENDVERTEX_Z;

    Double_t Tuple_pi0_TRUEP_X, Tuple_pi0_TRUEP_Y, Tuple_pi0_TRUEP_Z, Tuple_pi0_TRUEP_E, Tuple_pi0_TRUEPT, Tuple_pi0_TRUEORIGINVERTEX_X, Tuple_pi0_TRUEORIGINVERTEX_Y, Tuple_pi0_TRUEORIGINVERTEX_Z, Tuple_pi0_TRUEENDVERTEX_X, Tuple_pi0_TRUEENDVERTEX_Y, Tuple_pi0_TRUEENDVERTEX_Z;

    Double_t gamma0_TRUEP_X, gamma0_TRUEP_Y, gamma0_TRUEP_Z, gamma0_TRUEP_E, gamma0_TRUEPT, gamma0_TRUEORIGINVERTEX_X, gamma0_TRUEORIGINVERTEX_Y, gamma0_TRUEORIGINVERTEX_Z, gamma0_TRUEENDVERTEX_X, gamma0_TRUEENDVERTEX_Y, gamma0_TRUEENDVERTEX_Z;

    Double_t gamma1_TRUEP_X, gamma1_TRUEP_Y, gamma1_TRUEP_Z, gamma1_TRUEP_E, gamma1_TRUEPT, gamma1_TRUEORIGINVERTEX_X, gamma1_TRUEORIGINVERTEX_Y, gamma1_TRUEORIGINVERTEX_Z, gamma1_TRUEENDVERTEX_X, gamma1_TRUEENDVERTEX_Y, gamma1_TRUEENDVERTEX_Z;

    Double_t Kplus_TRUEP_X, Kplus_TRUEP_Y, Kplus_TRUEP_Z, Kplus_TRUEP_E, Kplus_TRUEPT, Kplus_TRUEORIGINVERTEX_X, Kplus_TRUEORIGINVERTEX_Y, Kplus_TRUEORIGINVERTEX_Z, Kplus_TRUEENDVERTEX_X, Kplus_TRUEENDVERTEX_Y, Kplus_TRUEENDVERTEX_Z;

    Double_t Tuple_K_1_plus_TRUEP_X, Tuple_K_1_plus_TRUEP_Y, Tuple_K_1_plus_TRUEP_Z, Tuple_K_1_plus_TRUEP_E, Tuple_K_1_plus_TRUEPT, Tuple_K_1_plus_TRUEORIGINVERTEX_X, Tuple_K_1_plus_TRUEORIGINVERTEX_Y, Tuple_K_1_plus_TRUEORIGINVERTEX_Z, Tuple_K_1_plus_TRUEENDVERTEX_X, Tuple_K_1_plus_TRUEENDVERTEX_Y, Tuple_K_1_plus_TRUEENDVERTEX_Z;

    Double_t Tuple_B_TRUEP_X, Tuple_B_TRUEP_Y, Tuple_B_TRUEP_Z, Tuple_B_TRUEP_E, Tuple_B_TRUEPT, Tuple_B_TRUEORIGINVERTEX_X, Tuple_B_TRUEORIGINVERTEX_Y, Tuple_B_TRUEORIGINVERTEX_Z, Tuple_B_TRUEENDVERTEX_X, Tuple_B_TRUEENDVERTEX_Y, Tuple_B_TRUEENDVERTEX_Z;

    Double_t gamma_TRUEP_E, gamma_TRUEP_X, gamma_TRUEP_Y, gamma_TRUEP_Z, gamma_TRUEPT, gamma_TRUEORIGINVERTEX_X, gamma_TRUEORIGINVERTEX_Y, gamma_TRUEORIGINVERTEX_Z, gamma_TRUEENDVERTEX_X, gamma_TRUEENDVERTEX_Y, gamma_TRUEENDVERTEX_Z;

    // Branch the input tree variables
    datafiltered_Ttree->SetBranchAddress("Tuple_B_TRUEP_E", &Tuple_B_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("Tuple_B_TRUEP_X", &Tuple_B_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("Tuple_B_TRUEP_Y", &Tuple_B_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("Tuple_B_TRUEP_Z", &Tuple_B_TRUEP_Z);

    datafiltered_Ttree->SetBranchAddress("piplus_TRUEP_E", &piplus_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("piplus_TRUEP_X", &piplus_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("piplus_TRUEP_Y", &piplus_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("piplus_TRUEP_Z", &piplus_TRUEP_Z);

    datafiltered_Ttree->SetBranchAddress("piminus_TRUEP_E", &piminus_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("piminus_TRUEP_X", &piminus_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("piminus_TRUEP_Y", &piminus_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("piminus_TRUEP_Z", &piminus_TRUEP_Z);

    datafiltered_Ttree->SetBranchAddress("Tuple_pi0_TRUEP_E", &Tuple_pi0_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("Tuple_pi0_TRUEP_X", &Tuple_pi0_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("Tuple_pi0_TRUEP_Y", &Tuple_pi0_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("Tuple_pi0_TRUEP_Z", &Tuple_pi0_TRUEP_Z);

    datafiltered_Ttree->SetBranchAddress("gamma0_TRUEP_E", &gamma0_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("gamma0_TRUEP_X", &gamma0_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("gamma0_TRUEP_Y", &gamma0_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("gamma0_TRUEP_Z", &gamma0_TRUEP_Z);

    datafiltered_Ttree->SetBranchAddress("gamma1_TRUEP_E", &gamma1_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("gamma1_TRUEP_X", &gamma1_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("gamma1_TRUEP_Y", &gamma1_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("gamma1_TRUEP_Z", &gamma1_TRUEP_Z);

    datafiltered_Ttree->SetBranchAddress("Kplus_TRUEP_E", &Kplus_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("Kplus_TRUEP_X", &Kplus_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("Kplus_TRUEP_Y", &Kplus_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("Kplus_TRUEP_Z", &Kplus_TRUEP_Z);

    datafiltered_Ttree->SetBranchAddress("Tuple_K_1_plus_TRUEP_E", &Tuple_K_1_plus_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("Tuple_K_1_plus_TRUEP_X", &Tuple_K_1_plus_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("Tuple_K_1_plus_TRUEP_Y", &Tuple_K_1_plus_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("Tuple_K_1_plus_TRUEP_Z", &Tuple_K_1_plus_TRUEP_Z);

    datafiltered_Ttree->SetBranchAddress("gamma_TRUEP_E", &gamma_TRUEP_E);
    datafiltered_Ttree->SetBranchAddress("gamma_TRUEP_X", &gamma_TRUEP_X);
    datafiltered_Ttree->SetBranchAddress("gamma_TRUEP_Y", &gamma_TRUEP_Y);
    datafiltered_Ttree->SetBranchAddress("gamma_TRUEP_Z", &gamma_TRUEP_Z);

    datafiltered_Ttree->SetBranchAddress("B_PE", &B_PE);
    datafiltered_Ttree->SetBranchAddress("B_PX", &B_PX);
    datafiltered_Ttree->SetBranchAddress("B_PY", &B_PY);
    datafiltered_Ttree->SetBranchAddress("B_PZ", &B_PZ);

    datafiltered_Ttree->SetBranchAddress("piplus_PE", &piplus_PE);
    datafiltered_Ttree->SetBranchAddress("piplus_PX", &piplus_PX);
    datafiltered_Ttree->SetBranchAddress("piplus_PY", &piplus_PY);
    datafiltered_Ttree->SetBranchAddress("piplus_PZ", &piplus_PZ);

    datafiltered_Ttree->SetBranchAddress("piminus_PE", &piminus_PE);
    datafiltered_Ttree->SetBranchAddress("piminus_PX", &piminus_PX);
    datafiltered_Ttree->SetBranchAddress("piminus_PY", &piminus_PY);
    datafiltered_Ttree->SetBranchAddress("piminus_PZ", &piminus_PZ);

    datafiltered_Ttree->SetBranchAddress("Rebuilt_pi0_PE", &Rebuilt_pi0_PE);
    datafiltered_Ttree->SetBranchAddress("Rebuilt_pi0_PX", &Rebuilt_pi0_PX);
    datafiltered_Ttree->SetBranchAddress("Rebuilt_pi0_PY", &Rebuilt_pi0_PY);
    datafiltered_Ttree->SetBranchAddress("Rebuilt_pi0_PZ", &Rebuilt_pi0_PZ);

    datafiltered_Ttree->SetBranchAddress("gamma0_PE", &gamma0_PE);
    datafiltered_Ttree->SetBranchAddress("gamma0_PX", &gamma0_PX);
    datafiltered_Ttree->SetBranchAddress("gamma0_PY", &gamma0_PY);
    datafiltered_Ttree->SetBranchAddress("gamma0_PZ", &gamma0_PZ);

    datafiltered_Ttree->SetBranchAddress("gamma1_PE", &gamma1_PE);
    datafiltered_Ttree->SetBranchAddress("gamma1_PX", &gamma1_PX);
    datafiltered_Ttree->SetBranchAddress("gamma1_PY", &gamma1_PY);
    datafiltered_Ttree->SetBranchAddress("gamma1_PZ", &gamma1_PZ);

    datafiltered_Ttree->SetBranchAddress("Kplus_PE", &Kplus_PE);
    datafiltered_Ttree->SetBranchAddress("Kplus_PX", &Kplus_PX);
    datafiltered_Ttree->SetBranchAddress("Kplus_PY", &Kplus_PY);
    datafiltered_Ttree->SetBranchAddress("Kplus_PZ", &Kplus_PZ);

    datafiltered_Ttree->SetBranchAddress("Rebuilt_K_1_plus_PE", &Rebuilt_K_1_plus_PE);
    datafiltered_Ttree->SetBranchAddress("Rebuilt_K_1_plus_PX", &Rebuilt_K_1_plus_PX);
    datafiltered_Ttree->SetBranchAddress("Rebuilt_K_1_plus_PY", &Rebuilt_K_1_plus_PY);
    datafiltered_Ttree->SetBranchAddress("Rebuilt_K_1_plus_PZ", &Rebuilt_K_1_plus_PZ);

    datafiltered_Ttree->SetBranchAddress("gamma_PE", &gamma_PE);
    datafiltered_Ttree->SetBranchAddress("gamma_PX", &gamma_PX);
    datafiltered_Ttree->SetBranchAddress("gamma_PY", &gamma_PY);
    datafiltered_Ttree->SetBranchAddress("gamma_PZ", &gamma_PZ);

    // ----------------------
    Double_t HelicityAngle;
    Double_t Diff_helicity;
    Double_t HelicityAngle_MC;

    //--------------- Avec les donnes rebuilt TRUE ---------------
    TH1D* hist_AngleCos = new TH1D("hist_AngleCos", "Helicity angle Cosine Distribution", 8, -1.00, 1.00);
    // Sumw2() active le stockage des erreurs    
    hist_AngleCos->Sumw2();

    hist_AngleCos->GetXaxis()->SetTitle("Angle distribution (cosine)");
    hist_AngleCos->GetXaxis()->CenterTitle(true);
    hist_AngleCos->GetYaxis()->SetTitle("Number of events");
    hist_AngleCos->GetYaxis()->CenterTitle(true);

    //--------------- Avec les donnes rebuilt MC ---------------
    TH1D* hist_AngleCos_MC = new TH1D("hist_AngleCos_MC", "Helicity angle Cosine Distribution MC", 8, -1.00, 1.00);
    // Sumw2() active le stockage des erreurs    
    hist_AngleCos_MC->Sumw2();
  
    // ---------- Variables calcul resolution helicity ----------
    TH1D* hist_reso = new TH1D("hist_reso", "Resolution on helicity angle", 100, -0.2, 0.2);
    Double_t sum_squared_diff = 0.0;  
    Double_t resolution;
    //------------------------------------------------------------

    // Loop over datafiltered_Ttree entries
    Long64_t nEntries = datafiltered_Ttree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        datafiltered_Ttree->GetEntry(i);

        // Reconstruire les 4-vecteurs des particules
        TLorentzVector gamma0, gamma1, vector_Tuple_pi0, gamma, vector_piplus, vector_piminus, vector_Kplus;
        gamma.SetPxPyPzE(gamma_TRUEP_X, gamma_TRUEP_Y, gamma_TRUEP_Z, gamma_TRUEP_E);
        gamma0.SetPxPyPzE(gamma0_TRUEP_X, gamma0_TRUEP_Y, gamma0_TRUEP_Z, gamma0_TRUEP_E);
        gamma1.SetPxPyPzE(gamma1_TRUEP_X, gamma1_TRUEP_Y, gamma1_TRUEP_Z, gamma1_TRUEP_E);
        vector_Tuple_pi0.SetPxPyPzE(Tuple_pi0_TRUEP_X, Tuple_pi0_TRUEP_Y, Tuple_pi0_TRUEP_Z, Tuple_pi0_TRUEP_E);// pi0 tel que genere dans le tuple            
        vector_piplus.SetPxPyPzE(piplus_TRUEP_X, piplus_TRUEP_Y, piplus_TRUEP_Z, piplus_TRUEP_E);
        vector_piminus.SetPxPyPzE(piminus_TRUEP_X, piminus_TRUEP_Y, piminus_TRUEP_Z, piminus_TRUEP_E);
        vector_Kplus.SetPxPyPzE(Kplus_TRUEP_X, Kplus_TRUEP_Y, Kplus_TRUEP_Z, Kplus_TRUEP_E);

        TLorentzVector vector_Rebuilt_pi0, vector_Rebuilt_omega, vector_Rebuilt_K_1_plus, vector_Tuple_K_1_plus, vector_Tuple_B, vector_Rebuilt_B;
        vector_Rebuilt_pi0.SetPxPyPzE(gamma0_TRUEP_X + gamma_TRUEP_X, gamma0_TRUEP_Y + gamma_TRUEP_Y, gamma0_TRUEP_Z + gamma_TRUEP_Z, gamma0_TRUEP_E + gamma_TRUEP_E);// pi0 tel qu'il se decay generalement
        vector_Rebuilt_omega.SetPxPyPzE(piplus_TRUEP_X + piminus_TRUEP_X + vector_Rebuilt_pi0.Px(), piplus_TRUEP_Y + piminus_TRUEP_Y + vector_Rebuilt_pi0.Py(), piplus_TRUEP_Z + piminus_TRUEP_Z + vector_Rebuilt_pi0.Pz(), piplus_TRUEP_E + piminus_TRUEP_E + vector_Rebuilt_pi0.E());
        vector_Rebuilt_K_1_plus.SetPxPyPzE(Kplus_TRUEP_X + vector_Rebuilt_omega.Px(), Kplus_TRUEP_Y + vector_Rebuilt_omega.Py(), Kplus_TRUEP_Z + vector_Rebuilt_omega.Pz(), Kplus_TRUEP_E + vector_Rebuilt_omega.E());
        vector_Tuple_K_1_plus.SetPxPyPzE(Tuple_K_1_plus_TRUEP_X, Tuple_K_1_plus_TRUEP_Y, Tuple_K_1_plus_TRUEP_Z, Tuple_K_1_plus_TRUEP_E); //generated      
        vector_Tuple_B.SetPxPyPzE(Tuple_B_TRUEP_X, Tuple_B_TRUEP_Y, Tuple_B_TRUEP_Z, Tuple_B_TRUEP_E);
        vector_Rebuilt_B.SetPxPyPzE(vector_Rebuilt_K_1_plus.Px() + gamma1_TRUEP_X, vector_Rebuilt_K_1_plus.Py() + gamma1_TRUEP_Y, vector_Rebuilt_K_1_plus.Pz() + gamma1_TRUEP_Z, vector_Rebuilt_K_1_plus.E() + gamma1_TRUEP_E);

        // BOOST vector_Kplus and vector_Rebuilt_omega to vector_Rebuilt_K_1_plus
        TVector3 Rebuilt_K_1_plus_BoostVector = -vector_Rebuilt_K_1_plus.BoostVector();
        TLorentzVector Kplus_new = vector_Kplus;// Kplus
        Kplus_new.Boost(Rebuilt_K_1_plus_BoostVector);
        TLorentzVector Rebuilt_omega_new = vector_Rebuilt_omega;// omega
        Rebuilt_omega_new.Boost(Rebuilt_K_1_plus_BoostVector);
        TLorentzVector B_new = vector_Rebuilt_B;// B reconstruit
        B_new.Boost(Rebuilt_K_1_plus_BoostVector);
        TLorentzVector pi0_new = vector_Rebuilt_pi0;// pi0 reconstruit
        pi0_new.Boost(Rebuilt_K_1_plus_BoostVector);
        TLorentzVector gamma1_new = gamma1;// gamma radiatif
        gamma1_new.Boost(Rebuilt_K_1_plus_BoostVector);
        

        // Angle d'helicite entre B et Kplus
        HelicityAngle = (B_new.Vect().Dot(Kplus_new.Vect()) / (B_new.Vect().Mag() * Kplus_new.Vect().Mag())); //Vec: vecteur spatial 3D et Mag: norme du vecteur 3D
        // Ci dessus, affichage en cosinus        
        //HelicityAngle = TMath::ACos(AngleCos); //affichage en rad
        hist_AngleCos->Fill(HelicityAngle);


        //--------------- Avec les donnes rebuilt MC ---------------

        // Reconstruire les 4-vecteurs des particules
        TLorentzVector gamma0_MC, gamma1_MC, vector_Tuple_pi0_MC, gamma_MC, vector_piplus_MC, vector_piminus_MC, vector_Kplus_MC;
        gamma_MC.SetPxPyPzE(gamma_PX, gamma_PY, gamma_PZ, gamma_PE);
        gamma0_MC.SetPxPyPzE(gamma0_PX, gamma0_PY, gamma0_PZ, gamma0_PE);
        gamma1_MC.SetPxPyPzE(gamma1_PX, gamma1_PY, gamma1_PZ, gamma1_PE);
        vector_Tuple_pi0_MC.SetPxPyPzE(Rebuilt_pi0_PX, Rebuilt_pi0_PY, Rebuilt_pi0_PZ, Rebuilt_pi0_PE);// pi0 tel que genere dans le tuple            
        vector_piplus_MC.SetPxPyPzE(piplus_PX, piplus_PY, piplus_PZ, piplus_PE);
        vector_piminus_MC.SetPxPyPzE(piminus_PX, piminus_PY, piminus_PZ, piminus_PE);
        vector_Kplus_MC.SetPxPyPzE(Kplus_PX, Kplus_PY, Kplus_PZ, Kplus_PE);

        TLorentzVector vector_Rebuilt_pi0_MC, vector_Rebuilt_omega_MC, vector_Rebuilt_K_1_plus_MC, vector_Tuple_K_1_plus_MC, vector_Tuple_B_MC, vector_Rebuilt_B_MC;
        vector_Rebuilt_pi0_MC.SetPxPyPzE(gamma0_PX + gamma_PX, gamma0_PY + gamma_PY, gamma0_PZ + gamma_PZ, gamma0_PE + gamma_PE);// pi0 tel qu'il se decay generalement
        vector_Rebuilt_omega_MC.SetPxPyPzE(piplus_PX + piminus_PX + vector_Rebuilt_pi0_MC.Px(), piplus_PY + piminus_PY + vector_Rebuilt_pi0_MC.Py(), piplus_PZ + piminus_PZ + vector_Rebuilt_pi0_MC.Pz(), piplus_PE + piminus_PE + vector_Rebuilt_pi0_MC.E());
        vector_Rebuilt_K_1_plus_MC.SetPxPyPzE(Kplus_PX + vector_Rebuilt_omega_MC.Px(), Kplus_PY + vector_Rebuilt_omega_MC.Py(), Kplus_PZ + vector_Rebuilt_omega_MC.Pz(), Kplus_PE + vector_Rebuilt_omega_MC.E());
        vector_Tuple_K_1_plus_MC.SetPxPyPzE(Rebuilt_K_1_plus_PX, Rebuilt_K_1_plus_PY, Rebuilt_K_1_plus_PZ, Rebuilt_K_1_plus_PE); //generated      
        vector_Tuple_B_MC.SetPxPyPzE(B_PX, B_PY, B_PZ, B_PE);
        vector_Rebuilt_B_MC.SetPxPyPzE(vector_Rebuilt_K_1_plus_MC.Px() + gamma1_PX, vector_Rebuilt_K_1_plus_MC.Py() + gamma1_PY, vector_Rebuilt_K_1_plus_MC.Pz() + gamma1_PZ, vector_Rebuilt_K_1_plus_MC.E() + gamma1_PE);

        // BOOST vector_Kplus and vector_Rebuilt_omega to vector_Rebuilt_K_1_plus
        TVector3 Rebuilt_K_1_plus_BoostVector_MC = -vector_Rebuilt_K_1_plus.BoostVector();
        TLorentzVector Kplus_new_MC = vector_Kplus_MC;// Kplus
        Kplus_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);
        TLorentzVector Rebuilt_omega_new_MC = vector_Rebuilt_omega_MC;// omega
        Rebuilt_omega_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);
        TLorentzVector B_new_MC = vector_Rebuilt_B_MC;// B reconstruit
        B_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);
        TLorentzVector pi0_new_MC = vector_Rebuilt_pi0_MC;// pi0 reconstruit
        pi0_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);
        TLorentzVector gamma1_new_MC = gamma1_MC;// gamma radiatif
        gamma1_new_MC.Boost(Rebuilt_K_1_plus_BoostVector_MC);      


        // Angle d'helicity entre B et Kplus
        HelicityAngle_MC = (B_new_MC.Vect().Dot(Kplus_new_MC.Vect()) / (B_new_MC.Vect().Mag() * Kplus_new_MC.Vect().Mag())); //Vec: vecteur spatial 3D et Mag: norme du vecteur 3D
        // Ci dessus, affichage en cosinus
        hist_AngleCos_MC->Fill(HelicityAngle_MC);

        // ----------- Resolution helicity -----------        
        // Difference d'angle
        Diff_helicity = HelicityAngle - HelicityAngle_MC;
        sum_squared_diff += Diff_helicity * Diff_helicity;

        hist_reso->Fill(Diff_helicity);
    }


    // ----------- Resolution helicity -----------
    // variance
    //Double_t variance = sum_squared_diff / (nEntries - 1);
    // ecart-type (résolution)
    //resolution = std::sqrt(variance);


    hist_reso->SetLineColor(kBlue);
    hist_reso->GetXaxis()->CenterTitle(true);
    hist_reso->GetXaxis()->SetTitle("Resolution on helicity angle, in cosine.");
    hist_reso->GetYaxis()->CenterTitle(true);
    hist_reso->GetYaxis()->SetTitle("Entries");
    TCanvas* Resolution = new TCanvas("Resolution", "Resolution on helicity angle", 800, 600);
    hist_reso->Draw();

    //Legende histo helicity
    TLegend* legend = new TLegend(0.5, 0.7, 0.7, 0.9);
    legend->AddEntry(hist_AngleCos, "Total helicity for matched data with errors", "lep");
    legend->AddEntry(hist_AngleCos_MC, "Total helicity for reconstructed data with errors", "lep");


    // Superposer les histogrammes dans un TCanvas
    TCanvas* Helicity_merged = new TCanvas("Helicity_merged", "Superposed Histograms of Helicity", 800, 600);
    
    hist_AngleCos->SetLineColor(kBlack);
    hist_AngleCos_MC->SetLineColor(kRed);
    hist_AngleCos->SetMinimum(0);
    hist_AngleCos->SetMaximum(300);
    hist_AngleCos->Draw();
    hist_AngleCos_MC->Draw("SAME");
    legend->Draw("SAME");
}

int Full_calc() {
    SaveVariables_and_4vector();
    return 0;
}