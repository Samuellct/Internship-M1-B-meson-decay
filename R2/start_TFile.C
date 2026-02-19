{
	TFile* myfile = new TFile("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagDown_mergeAll.root", "READ");
	TTree* mytree = (TTree*)myfile->Get("kpipipi0GTupleMC/DecayTree");
}