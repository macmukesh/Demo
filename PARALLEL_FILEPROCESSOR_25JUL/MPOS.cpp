#include "MPOS.h"

MPOS::MPOS()
{
	
}

MPOS::~MPOS()
{


}

void MPOS::ValidateInputRawData(const char * acInpData,size_t inpsz)
{
	if(!inpsz%736)
	{
		// length validation failed
	}
}

void MPOS::IdentifyParserCd(const char * rawdata,size_t rawsz,PARSERCD & parsercd)
{	
		if (!strncmp(rawdata, "START", 5)) {
			parsercd= HDR;
		} else if (!strncmp(rawdata, "END", 3)) {
			parsercd= TRL;
		} else {
			parsercd= DATA1;	
		}
}
/*
1: Input Value as frm file
2: COLID mapped with element
3: out area to store decoded value
*/
void MPOS::TransformCol(const char * acTempData,const StructTTUB::TTCOL & enTTCol,char * out)
{

	switch(enTTCol)
	{
		case StructTTUB::CODE2:
					if(acTempData[0] == 'P')
						//out = 'P';
						strcpy(out, "p");			//POS
					else
						strcpy(out, "M");
					
					break;
		case StructTTUB::CODE4:
					if(acTempData[0] == '0')
							strcpy(out, "10");		//ONLINE
					else if(acTempData[0] == '6')
							strcpy(out, "10");		//OFFLINE
					else if(acTempData[0] == '9')
							strcpy(out, "14");		//REFUND
					break;
		case StructTTUB::CODE5:
					if(acTempData[0] == 'V')
								{
										strcpy(out, "I");	// mark invalid or void txn
										//++iNonACQRecCount; //TODO to added to discarded count
								}	
					break;
		
		}
}

void MPOS::SetHdrFormat(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{
	MPOS_HDR objHdr=(MPOS_HDR)iElemNo;

	switch(objHdr)
	{
			case MPOS_HDR_0 :
				iNoOfBytes=5;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="MPOS_HDR_0";
				break;
			case MPOS_HDR_1 :
				iNoOfBytes=2;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="MPOS_HDR_1";
				break;
			case MPOS_HDR_2 :
				iNoOfBytes=9;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="MPOS_HDR_2";
				break;
	}
}
void MPOS::SetTrlFormat(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{
	MPOS_TRL objTrl=(MPOS_TRL)iElemNo;
	switch(objTrl)
	{
		case MPOS_TRL_0 :
				iNoOfBytes=3;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="MPOS_TRL_0";
				break;
				
	case MPOS_TRL_1 :
				iNoOfBytes=4;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="MPOS_TRL_1";
				break;
	case MPOS_TRL_2	:	
				iNoOfBytes=9;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="MPOS_TRL_2";
				break;	
	}
}
void MPOS::SetD1Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{
	MPOS_TT_FIELDS objHdr=(MPOS_TT_FIELDS)iElemNo;

	switch(objHdr)
	{
		case acMeId_0_1_15 :
				iNoOfBytes=15;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::MEID;
				strElemNm="acMeId_0_1_15";
				break;
		case TT_1_16_16 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_1_16_16";
				break;
		case acTId_2_17_24 :
				iNoOfBytes=8;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::TID;
				strElemNm="acTId_2_17_24";
				break;
		case TT_3_25_25 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_3_25_25";
				break;
		case acBrnCo_4_26_30 :
				iNoOfBytes=5;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="acBrnCo_4_26_30";
				break;
		case TT_5_31_31 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_5_31_31";
				break;
		case acCardNo_6_32_50 :
				iNoOfBytes=19;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::CARDNO;
				strElemNm="acCardNo_6_32_50";
				break;
		case TT_7_51_51 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_7_51_51";
				break;
		case dTxnAmt_8_52_64 :
				iNoOfBytes=13;
				enFmAttr=NO_CHECK;	
				enTTField=StructTTUB::RAWAMOUNT1;
				strElemNm="dTxnAmt_8_52_64";
				break;
		case TT_9_65_65 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_9_65_65";
				break;
		case acMCC_10_66_69 :
				iNoOfBytes=4;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::MCCCODE;
				strElemNm="acMCC_10_66_69";
				break;
		case cV_11_70_70 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::CODE5;
				strElemNm="cV_11_70_70";
				break;
		case TT_12_71_71 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_12_71_71";
				break;
		case TT_13_72_72 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_13_72_72";
				break;
		case acAuth_14_73_78 :
				iNoOfBytes=6;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::AUTHCODE;
				strElemNm="acAuth_14_73_78";
				break;
		case TT_15_79_79 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_15_79_79";
				break;
		case acCurr_16_80_82 :
				iNoOfBytes=3;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::HCURRCODE;
				strElemNm="acCurr_16_80_82";
				break;
		case TT_17_83_83 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_17_83_83";
				break;
		case iBth_18_84_88 :
				iNoOfBytes=5;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::BATCHNO;
				strElemNm="iBth_18_84_88";
				break;
		case TT_19_89_89 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_19_89_89";
				break;
		case acSettleDate_20_90_98 :
				iNoOfBytes=9;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::BATCHDT;
				strElemNm="acSettleDate_20_90_98";
				break;
		case TT_21_99_99 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_21_99_99";
				break;
		case acTxnDate_22_100_108 :
				iNoOfBytes=9;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::TRANSDT;
				strElemNm="acTxnDate_22_100_108";
				break;
		case TT_23_109_109 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_23_109_109";
				break;
		case cTxnType_25_114_114 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::CODE4;
				strElemNm="cTxnType_25_114_114";
				break;
		case TT_26_115_115 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_26_115_115";
				break;
		case TT_27_116_116 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_27_116_116";
				break;
		case acRRNNo_28_117_122 :
				iNoOfBytes=6;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::RRN;
				strElemNm="acRRNNo_28_117_122";
				break;
		case TT_29_123_128 :
				iNoOfBytes=6;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_29_123_128";
				break;
		case TT_31_130_130 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_31_130_130";
				break;
		case TT_32_131_131 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_32_131_131";
				break;
		case TT_34_141_141 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_34_141_141";
				break;
		case TT_36_146_146 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_36_146_146";
				break;
		case TT_38_160_160 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_38_160_160";
				break;
		case TT_40_174_174 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_40_174_174";
				break;
		case TT_43_179_179 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_43_179_179";
				break;
		case TT_45_181_181 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_45_181_181";
				break;
		case TT_46_182_182 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_46_182_182";
				break;
		case acTranType_47_183_184 :
				iNoOfBytes=2;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2TRANTYPE;
				strElemNm="acTranType_47_183_184";
				break;
		case TT_48_185_185 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_48_185_185";
				break;
		case TT_50_188_188 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_50_188_188";
				break;
		case acTranDate_51_189_194 :
				iNoOfBytes=6;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2TRANDT;
				strElemNm="acTranDate_51_189_194";
				break;
		case TT_52_195_195 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_52_195_195";
				break;
		case acEMVTermCap_53_196_203 :
				iNoOfBytes=8;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B3EMVTERMCAP;
				strElemNm="acEMVTermCap_53_196_203";
				break;
		case TT_54_204_204 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_54_204_204";
				break;
		case acTermCntryCode_55_205_207 :
				iNoOfBytes=3;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2TRANENTRYCDE;
				strElemNm="acTermCntryCode_55_205_207";
				break;
		case TT_56_208_208 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_56_208_208";
				break;
		case acTermSerlNum_57_209_216 :
				iNoOfBytes=8;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B3TERMSRLNO;
				strElemNm="acTermSerlNum_57_209_216";
				break;
		case TT_58_217_217 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_58_217_217";
				break;
		case acUnpredictNum_59_218_225 :
				iNoOfBytes=8;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2UNPREDICTNO;
				strElemNm="acUnpredictNum_59_218_225";
				break;
		case TT_60_226_226 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_60_226_226";
				break;
		case acATC_61_227_230 :
				iNoOfBytes=4;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2ATC;
				strElemNm="acATC_61_227_230";
				break;
		case TT_62_231_231 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_62_231_231";
				break;
		case acAIP_63_232_235 :
				iNoOfBytes=4;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2A1P;
				strElemNm="acAIP_63_232_235";
				break;
		case TT_64_236_236 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_64_236_236";
				break;
		case acARQC_65_237_252 :
				iNoOfBytes=16;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2ARQC;
				strElemNm="acARQC_65_237_252";
				break;
		case TT_66_253_253 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_66_253_253";
				break;
		case acIssAppData_67_254_317 :
				iNoOfBytes=64;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2ISSAPPDATA0;
				strElemNm="acIssAppData_67_254_317";
				break;
		case TT_68_318_318 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_68_318_318";
				break;
		case acTVR_69_319_328 :
				iNoOfBytes=10;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2TVR;
				strElemNm="acTVR_69_319_328";
				break;
		case TT_70_329_329 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_70_329_329";
				break;
		case dAmtAuth_71_330_341 :
				iNoOfBytes=12;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2AMTAUTH;
				strElemNm="dAmtAuth_71_330_341";
				break;
		case TT_72_342_342 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_72_342_342";
				break;
		case acIssScrptData_73_343_598 :
				iNoOfBytes=256;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B6ISSSCRDATA0;
				strElemNm="acIssScrptData_73_343_598";
				break;
		case TT_74_599_599 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_74_599_599";
				break;
		case acIssScriptResultData_75_600_679 :
				iNoOfBytes=80;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B6ISSSCRDATA0;
				strElemNm="acIssScriptResultData_75_600_679";
				break;
		case TT_76_680_680 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_76_680_680";
				break;
		case acCryptoInfoData_77_681_682 :
				iNoOfBytes=2;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2CRYPTOINFODATA;
				strElemNm="acCryptoInfoData_77_681_682";
				break;
		case TT_78_683_683 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_78_683_683";
				break;
		case acTranCrncyCde_79_684_686 :
				iNoOfBytes=3;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2TERMCRNCYCDE;
				strElemNm="acTranCrncyCde_79_684_686";
				break;
		case TT_80_687_687 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_80_687_687";
				break;
		case dAmtOther_81_688_699 :
				iNoOfBytes=12;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B2AMTOTHER;
				strElemNm="dAmtOther_81_688_699";
				break;
		case TT_82_700_700 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_82_700_700";
				break;
		case acCVMRslts_83_701_706 :
				iNoOfBytes=6;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B3CVMRSLTS;
				strElemNm="acCVMRslts_83_701_706";
				break;
		case cTermEntryCap_84_707_707 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::B4TERMENTRYCAP;
				strElemNm="cTermEntryCap_84_707_707";
				break;
		case TT_85_708_708 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_85_708_708";
				break;
		case cDataSuspect_86_709_709 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="cDataSuspect_86_709_709";
				break;
		case TT_87_710_711 :
				iNoOfBytes=2;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_87_710_711";
				break;
		case dCashAtPOSAmt_88_712_724 :
				iNoOfBytes=13;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="dCashAtPOSAmt_88_712_724";
				break;
		case TT_89_725_725 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_89_725_725";
				break;
		case acCashAtPOSType_90_726_729 :
				iNoOfBytes=4;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::CODE2;
				strElemNm="acCashAtPOSType_90_726_729";
				break;
		case TT_91_730_730 :
				iNoOfBytes=1;
				enFmAttr=NO_CHECK;
				enTTField=StructTTUB::FORMATTYPE;
				strElemNm="TT_91_730_730";
				break;
	}
}
void MPOS::SetD2Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{

}
void MPOS::SetD3Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{

}
void MPOS::SetD4Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{

}
void MPOS::SetD5Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{

}
