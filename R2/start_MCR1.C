{
    TChain *mytree = new TChain("kpipipi0GTupleMC/DecayTree");    
    mytree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagDown_mergeAll.root");
    mytree->Add("radiativeXpi0G_MC2011-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21r1_MagUp_mergeAll.root");
    mytree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagDown_mergeAll_ntp.root");
    mytree->Add("radiativeXpi0G_MC2012-Bu2K1gamma_omegaK_pipipi0-12103600-Py8Sim09mReco14c_S21_MagUp_mergeAll_ntp.root");
	
	massCuts = TCut("B_M01234 < 1500 && B_M1234 > 600 && B_M1234 < 900 && B_M > 4500 && B_M < 7000");	
	L0TOS   = TCut("(B_L0PhotonDecision_TOS || B_L0ElectronDecision_TOS)");
	HLT1TOS = TCut("(B_Hlt1TrackAllL0Decision_TOS || B_Hlt1TrackPhotonDecision_TOS)"); // RUN1 NAMING
	HLT2TOS = TCut("B_Hlt2RadiativeTopoTrackDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonDecision_TOS == 1 ||B_Hlt2RadiativeTopoTrackTOSDecision_TOS == 1 || B_Hlt2RadiativeTopoPhotonL0Decision_TOS == 1");
 
	ChargedPIDcut = TCut("piminus_ProbNNpi > 0.2 && piminus_ProbNNk < 0.8 && piminus_ProbNNp < 0.8 && piplus_ProbNNpi > 0.2 && piplus_ProbNNk < 0.8 && piplus_ProbNNp < 0.8 && Kplus_ProbNNpi < 0.8 && Kplus_ProbNNk > 0.2 && Kplus_ProbNNp < 0.8");
	NeutralPIDcut = TCut("gamma_CL > 0.2 && gamma_PP_IsPhoton > 0.5 && gamma0_CL > 0.2 && gamma0_PP_IsPhoton > 0.5 && gamma1_CL > 0.2 && gamma1_PP_IsPhoton > 0.5");
	
	
	Basecut = TCut(massCuts + L0TOS + HLT1TOS + HLT2TOS + ChargedPIDcut + NeutralPIDcut);
	newparts = TCut("(B_M0234 < 1750 || B_M0234>1970) && (B_M02 < 840 || B_M02>1920 || (B_M02 > 970 && B_M02 < 1800))");

	All = TCut(massCuts + newparts + L0TOS + HLT1TOS + HLT2TOS + ChargedPIDcut + NeutralPIDcut);
	
}




 