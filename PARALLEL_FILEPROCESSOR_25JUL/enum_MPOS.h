#ifndef ENUM_TT_FIELDS_H_
#define ENUM_TT_FIELDS_H_


//enum value corresponds to index number in data buffer
//Denotes TT fields positions and names in a positions based record
enum MPOS_TT_FIELDS{
		acMeId_0_1_15,
		TT_1_16_16,
		acTId_2_17_24,
		TT_3_25_25,
		acBrnCo_4_26_30,
		TT_5_31_31,
		acCardNo_6_32_50,
		TT_7_51_51,
		dTxnAmt_8_52_64,
		TT_9_65_65,
		acMCC_10_66_69,
		cV_11_70_70,
		TT_12_71_71,
		TT_13_72_72,
		acAuth_14_73_78,
		TT_15_79_79,
		acCurr_16_80_82,
		TT_17_83_83,
		iBth_18_84_88,
		TT_19_89_89,
		acSettleDate_20_90_98,
		TT_21_99_99,
		acTxnDate_22_100_108,
		TT_23_109_109,
		AcTxnTime_24_110_113,
		cTxnType_25_114_114,
		TT_26_115_115,
		TT_27_116_116,
		acRRNNo_28_117_122,
		TT_29_123_128,
		cFVTType_30_129_129,
		TT_31_130_130,
		TT_32_131_131,
		acProcDate_33_132_140,
		TT_34_141_141,
		acExp_35_142_145,
		TT_36_146_146,
		dVisaComm_37_147_159,
		TT_38_160_160,
		dMastComm_39_161_173,
		TT_40_174_174,
		acCit_41_175_177,
		cLastEMVStat_42_178_178,
		TT_43_179_179,
		cEMVFlag_44_180_180,
		TT_45_181_181,
		TT_46_182_182,
		acTranType_47_183_184,
		TT_48_185_185,
		acAppPANSqqNum_49_186_187,
		TT_50_188_188,
		acTranDate_51_189_194,
		TT_52_195_195,
		acEMVTermCap_53_196_203,
		TT_54_204_204,
		acTermCntryCode_55_205_207,
		TT_56_208_208,
		acTermSerlNum_57_209_216,
		TT_58_217_217,
		acUnpredictNum_59_218_225,
		TT_60_226_226,
		acATC_61_227_230,
		TT_62_231_231,
		acAIP_63_232_235,
		TT_64_236_236,
		acARQC_65_237_252,
		TT_66_253_253,
		acIssAppData_67_254_317,
		TT_68_318_318,
		acTVR_69_319_328,
		TT_70_329_329,
		dAmtAuth_71_330_341,
		TT_72_342_342,
		acIssScrptData_73_343_598,
		TT_74_599_599,
		acIssScriptResultData_75_600_679,
		TT_76_680_680,
		acCryptoInfoData_77_681_682,
		TT_78_683_683,
		acTranCrncyCde_79_684_686,
		TT_80_687_687,
		dAmtOther_81_688_699,
		TT_82_700_700,
		acCVMRslts_83_701_706,
		cTermEntryCap_84_707_707,
		TT_85_708_708,
		cDataSuspect_86_709_709,
		TT_87_710_711,
		dCashAtPOSAmt_88_712_724,
		TT_89_725_725,
		acCashAtPOSType_90_726_729,
		TT_91_730_730,
		acMsgType_92_731_734
};


//Denotes Header fields positions & names in MPOS header line
enum MPOS_HDR{
	MPOS_HDR_0,
	MPOS_HDR_1,
	MPOS_HDR_2
};



//Denotes trailer fields positions & names in MPOS trailer line
enum MPOS_TRL{
	MPOS_TRL_0,
	MPOS_TRL_1,
	MPOS_TRL_2

};

#endif

