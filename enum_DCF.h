/*
 * enum_DCF.h
 *
 *  Created on: Feb 14, 2018
 *      Author: danish3216
 */

#ifndef ENUM_DCF_H_
#define ENUM_DCF_H_

typedef enum {

	DCF_6220_RecordTyp_1_4,
	DCF_6220_MsgTypId_5_8,
	DCF_6220_PAN_9_28,
	DCF_6220_ProcessCd_29_34,
	DCF_6220_TransAmt_35_46,
	DCF_6220_SettlAmt_47_58,
	DCF_6220_cardHdrbillAmt_59_70,
	DCF_6220_TransDateTime_71_80,
	DCF_6220_STAN_81_86,
	DCF_6220_LocTransDate_87_90,
	DCF_6220_LocTranstime_91_96,
	DCF_6220_ExpDate_97_100,
	DCF_6220_SettlDate_101_104,
	DCF_6220_MerchantTyp_105_108,
	DCF_6220_POS_EntryMode_109_111,
	DCF_6220_POS_CondCD_112_113,
	DCF_6220_RRNum_114_125,
	DCF_6220_AuthIdRsp_126_131,
	DCF_6220_ResCD_132_133,
	DCF_6220_TerminalID_134_141,
	DCF_6220_CAIC_142_156,
	DCF_6220_ECSLI_157_159,
	DCF_6220_AVS_Resp_160_160,
	DCF_6220_CVV2_CVC2_ResultCd_161_161,
	DCF_6220_Visa_E_Comm_Tid_162_162,
	DCF_6220_Tras_CurrCd_163_165,
	DCF_6220_Settl_CurrCd_166_168,
	DCF_6220_CardhdBill_CurrCd_169_171,
	DCF_6220_Adv_RsnCd_172_174,
	DCF_6220_RFU_175_175,
	DCF_6220_POS_Cardhdr_Pindicator_176_176,
	DCF_6220_POS_Trns_Sindicator_177_177,
	DCF_6220_CH_ActTermLvl_Indicator_178_178,
	DCF_6220_NwRefNum_179_187,
	DCF_6220_O_STAN_188_193,
	DCF_6220_O_Date_194_197,
	DCF_6220_Acqsp_PvtData_198_246,
	DCF_6220_Pnt_Ser_DataCd_247_256,

	DCF_6221_RecordTyp_1_4,
	DCF_6221_MrchNm_5_26,
	DCF_6221_Mrch_streetAdr_27_71,
	DCF_6221_Mrch_city_72_84,
	DCF_6221_Mrch_state_85_87,
	DCF_6221_Mrch_POS_CntryCd_88_90,
	DCF_6221_Mrch_POS_ZipCd_91_100,
	DCF_6221_Finc_Nw_Cd_101_103,
	DCF_6221_Tran_catg_Cd_104_104,
	DCF_6221_Mrch_Advcd_105_106,
	DCF_6221_MSCSI_107_107,
	DCF_6221_MSCEI_108_108,
	DCF_6221_Wallt_Pgmdata_109_111,
	DCF_6221_RFU_112_256,

	DCF_6222_RecordTyp_1_4,
	DCF_6222_BanknetNwCd_5_7,
	DCF_6222_BanknetRefNum_8_13,
	DCF_6222_BanknetDate_14_17,
	DCF_6222_MCEAI_18_18,
	DCF_6222_PmntTrnsTypIndicator_19_21,
	DCF_6222_MC_TIP_SIPI_22_22,
	DCF_6222_MC_PromoCd_23_28,
	DCF_6222_ServiceCd_29_31,
	DCF_6222_RFU_32_256,

	DCF_6223_RecordTyp_1_4,
	DCF_6223_VISA_CAVV_ResCd_5_5,
	DCF_6223_VISA_CardLvl_Res_6_7,
	DCF_6223_US_Diff_BilIndc_8_8,
	DCF_6223_VIS_US_Exst_DebtIndc_9_9,
	DCF_6223_VISA_Relt_Prticpnt_Indc_10_10,
	DCF_6223_VISA_ACI_Indc_11_11,
	DCF_6223_VISA_Trans_Id_12_26,
	DCF_6223_VISA_ValidCd_27_30,
	DCF_6223_VISA_CommCard_InquryResp_31_31,
	DCF_6223_VISA_Mrkt_Sp_DataIdt_32_32,
	DCF_6223_PPI_33_33,
	DCF_6223_MVV_34_43,
	DCF_6223_Reserve_44_256,
	
	DCF_6224_NA_1_256,			//Fields not specified  for 6224
	DCF_6225_NA_1_256,			//Fields not specified  for 6225
	
	DCF_6226_RecordTyp_1_4,
	DCF_6226_ECPI_5_5,
	DCF_6226_CAVV_6_9,
	DCF_6226_NRID_10_24,
	DCF_6226_CDIC_25_25,
	DCF_6226_RFU_26_256,
	
	DCF_6227_NA_1_256,			//Fields not specified  for 6224

	DCF_6228_MSO_ID_1_44,			//Fields not specified  for 6225
	DCF_6228_MERCH_ID_45_59

}DCF_FIELDS;


//DCF Header fields
typedef enum {

	DCF_HDR_acRecType_1_4,
	DCF_HDR_acFileName_5_36,
	DCF_HDR_acPtdfTermRouteNo_37_42,
	DCF_HDR_acBeginTranDate_43_48,
	DCF_HDR_acMsgType_49_51
	
}DCF_HDR_FIELDS;


//DCF Trailer fields
typedef enum {

	DCF_TRL_M_RecordTyp_1_4,
	DCF_TRL_M_FileNm_5_36,
	DCF_TRL_M_AcqICA_37_42,
	DCF_TRL_M_SettlDate_43_48,
	DCF_TRL_M_NumFincTrans_49_56,
	DCF_TRL_M_R_T_Num_57_67,
	DCF_TRL_M_PrcId_68_78,
	DCF_TRL_M_Reserved_79_256
}DCF_TRL_FIELDS;



#endif /* INCLUDE_ENUM_DCF_H_ */
