// ######################################################################
// ## Codes utilisés dans le cadre de l'étude du canal B+ -> K1+ gamma ##
// ######################################################################


//	/!\ Les codes doivent se trouver dans le même dossier que les sources de donnée /!\


//	/!\ Les commandes suivantes sont à executer dans le terminal ROOT /!\

/*
// ######################################################################
1 - Macro pour accéder au Tchain Monte Carlo du Run 1: 

.L start_MCR1.C

==> On accède aux variables avec: mytree->Draw("NOM_DE_LA_VARIABLE")

// ######################################################################
2 - Macro pour accéder au Tchain DATA du Run 1: 

.L start_dataR1.C

==> On accède aux variables avec: mytree->Draw("NOM_DE_LA_VARIABLE")

// ######################################################################
3 - Macro générée par MakeClass et utilisée pour voir l'impact de BKG==10: (Données utilisées : TFile 2017 MagDown)

.L myclass_treeMC_kpipipi0G.C

Ensuite: myclass_treeMC_kpipipi0G t

Ensuite: t.Loop();

==> Plots enregistrés dans le PDF "Particle_mass.pdf"

// ######################################################################
4- Macro pour accéder à un TFile en particulier:

//	/!\ ouvrir le script dans un éditeur et spécifier le TFile et le chemin du TTree /!\

.L start_TFile.C

==> On accède aux variables avec: mytree->Draw("NOM_DE_LA_VARIABLE")

// ######################################################################
5- Full_calc: Calcule et enregistre dans un TFile les composantes des 4-vecteurs, l'angle d'helicité et sa résolution (Data utilisée : TFile 2017 MagDown)

.L Full_calc.C

Ensuite: main2()

==> TFile produit: "datacut.root"

// ######################################################################
6- TchainData_and_MC_R1_without_cuts: Génère un fichier PDF présentant les variables observées pour la préselection avec les données MC + de l'expérience


.L TchainData_and_MC_R1_without_cuts.C

Ensuite: main3()

==> Plots enregistrés dans le PDF "Run1_Tchain_data_and_MC_sanscuts.pdf"

// ######################################################################
7- TchainData_and_MC_R1_cuts: Comme le code n°7 mais avec des coupures appliquées sur les variables PID, masses invariantes et triggers. Les efficacités par catégorie sont également calculées.


.L TchainData_and_MC_R1_cuts.C

Ensuite: main4()

==> Plots et efficacités enregistrés dans le PDF "Run1_Tchain_data_and_MC_allcuts.pdf"

// ######################################################################
8- run2_TchainMC_without_cut: Génère un fichier PDF présentant les variables observées pour la préselection avec le Run 2

.L run2_TchainMC_without_cut.C

Ensuite: main4()

==> Plots enregistrés dans le PDF "Run2_Tchain_MC_sanscuts.pdf"

// ######################################################################
9- run2_TchainMC_cuts: Génère un fichier PDF présentant les variables du Run 2 et les coupures associées

.L run2_TchainMC_cuts.C

Ensuite: main5()

==> Plots enregistrés dans le PDF "Run2_Tchain_MC_cuts.pdf"

*/

















