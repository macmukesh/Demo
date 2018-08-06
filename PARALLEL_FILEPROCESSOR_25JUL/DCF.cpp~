#include "DCF.h"

DCF::DCF()
{
	
}

DCF::~DCF()
{


}

void DCF::ValidateInputRawData(const char * acInpData,size_t inpsz)
{
	if(!inpsz%168)
	{
		// length validation failed
	}
}

void DCF::IdentifyParserCd(const char * rawdata,size_t rawsz,PARSERCD & parsercd)
{

	if( *(rawdata+2) == '0' && *(rawdata+3) == '0' ){			

		parsercd	=	HDR;

	}else if(*(rawdata+2) == '4' && *(rawdata+3) == '0'){

		parsercd	=	TRL;

	}else if(*(rawdata+2) == '2' && *(rawdata+3) == '0'){

		//Check for ACQ Txn..rectyp must be (0-4)6220 and (132-133)respcd=00 and (176-176)(postxnind=0) or (if postxnind=4 and msgtyp=0120||0121||0420)
		if(!strncmp(rawdata+131, "00", 2)){

			if( (*(rawdata+176) == '0') || ( (*(rawdata+176) == '4') && (!strncmp(rawdata+4, "0120", 4)
							|| !strncmp(rawdata+4, "0420", 4) || !strncmp(rawdata+4, "0121", 4) || !strncmp(rawdata+4, "0100", 4)   )))
				parsercd	=	DATA1;					
		} 
	}

}
/*
1: Input Value as frm file
2: COLID mapped with element
3: out area to store decoded value
*/
void DCF::TransformCol(const char * acTempData,const StructTTUB::TTCOL & enTTCol,char * out)
{

	switch(enTTCol)
	{
		case StructTTUB::CODE4:
					if(!strcmp(acTempData, "003000"))
					{
						strcpy(out, "10");		//$ 25 March acTxnCode->acCODE4
					}
					else if(!strcmp(acTempData, "203000"))
					{
						strcpy(out, "14");		//$ 25 March acTxnCode->acCODE4
					}
					break;
		case StructTTUB::IATAINVOICENO:
					if(!strcmp(acTempData, " "))
					{
						strcpy(out, "1");
					}
					if((strncmp(acTempData, "          ", 10) == 0) || (strcmp(acTempData, "") == 0))
						strcpy(out, "1");
					else if(strncmp(acTempData, "0000      ", 10) == 0)
					{
						strncpy(out, "0000", 4);
						out[4]='\0';
					}
					else
						strcpy(out,acTempData);

					break;
		case StructTTUB::AUTHCODE:
					if(strcmp(acTempData, "") != 0)
					{
						ObjUtility.fnLeftTrim(const_cast <char *>(acTempData));
						ObjUtility.fnRTrim(const_cast <char *>(acTempData));
					}
						ObjUtility.fnLeftPad(const_cast <char *>(acTempData), 6, '0');
						strcpy(out, acTempData);
					break;
		
		}
}

void DCF::SetHdrFormat(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{
	DCF_HDR_FIELDS objHdr=(DCF_HDR_FIELDS)iElemNo;

	switch(objHdr)
	{
		case DCF_HDR_acRecType_1_4:
			iNoOfBytes=4;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_HDR_acRecType_1_4";
			break;
		case DCF_HDR_acFileName_5_36:
			iNoOfBytes=32;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_HDR_acFileName_5_36";
			break;
		case DCF_HDR_acPtdfTermRouteNo_37_42:
			iNoOfBytes=6;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_HDR_acPtdfTermRouteNo_37_42";
			break;
		case DCF_HDR_acBeginTranDate_43_48:
			iNoOfBytes=6;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_HDR_acBeginTranDate_43_48";
			break;
		case DCF_HDR_acMsgType_49_51:
			iNoOfBytes=3;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_HDR_acMsgType_49_51";
			break;			
	}
}
void DCF::SetTrlFormat(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{
	DCF_TRL_FIELDS objTrl=(DCF_TRL_FIELDS)iElemNo;
	switch(objTrl)
	{
		case DCF_TRL_M_RecordTyp_1_4 :
			iNoOfBytes=4;															
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_TRL_M_RecordTyp_1_4";
			break;
		case DCF_TRL_M_FileNm_5_36 :
			iNoOfBytes=32;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_TRL_M_FileNm_5_36";
			break;
		case DCF_TRL_M_AcqICA_37_42 :
			iNoOfBytes=6;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_TRL_M_AcqICA_37_42";
			break;
		case DCF_TRL_M_SettlDate_43_48 :
			iNoOfBytes=6;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_TRL_M_SettlDate_43_48";
			break;
		case DCF_TRL_M_NumFincTrans_49_56 :
			iNoOfBytes=8;
			enFmAttr=NUMERIC;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_TRL_M_NumFincTrans_49_56";
			break;
		case DCF_TRL_M_R_T_Num_57_67 :
			iNoOfBytes=11;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_TRL_M_R_T_Num_57_67";
			break;
		case DCF_TRL_M_PrcId_68_78 :
			iNoOfBytes=11;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_TRL_M_PrcId_68_78";
			break;
		case DCF_TRL_M_Reserved_79_256 :
			iNoOfBytes=178;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_TRL_M_Reserved_79_256";
			break;
	}
}
void DCF::SetD1Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{
	DCF_FIELDS objHdr=(DCF_FIELDS)iElemNo;

	switch(objHdr)
	{
		case  DCF_6220_RecordTyp_1_4 :
			iNoOfBytes=4;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_RecordTyp_1_4";
			break;
		// CVDFLD insted of CODE3	
		case  DCF_6220_MsgTypId_5_8 :
			iNoOfBytes=4;
			enFmAttr=NUMERIC_LEADING_ZEROES;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_MsgTypId_5_8";
			break;
		case  DCF_6220_PAN_9_28 :
			iNoOfBytes=20;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::CARDNO;
			strElemNm="DCF_6220_PAN_9_28";
			break;	
		case  DCF_6220_ProcessCd_29_34 :
			iNoOfBytes=6;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::CODE4;
			strElemNm="DCF_6220_ProcessCd_29_34";
			break;
		case  DCF_6220_TransAmt_35_46 :
			iNoOfBytes=12;
			enFmAttr=NUMERIC;
			enTTField=StructTTUB::RAWAMOUNT1;
			strElemNm="DCF_6220_TransAmt_35_46";
			break;
		case  DCF_6220_SettlAmt_47_58 :
			iNoOfBytes=12;
			enFmAttr=NUMERIC;
			enTTField=StructTTUB::RAWAMOUNT2;
			strElemNm="DCF_6220_SettlAmt_47_58";
			break;
		case  DCF_6220_cardHdrbillAmt_59_70 :
			iNoOfBytes=12;
			enFmAttr=NUMERIC;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_cardHdrbillAmt_59_70";
			break;
		case  DCF_6220_TransDateTime_71_80 :
			iNoOfBytes=10;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_TransDateTime_71_80";
			break;
		case  DCF_6220_STAN_81_86 :
			iNoOfBytes=6;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::SRLSEQNO1;
			strElemNm="DCF_6220_STAN_81_86";
			break;
		case  DCF_6220_LocTransDate_87_90 :
			iNoOfBytes=4;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::TRANSDT;
			strElemNm="DCF_6220_LocTransDate_87_90";
			break;
		case  DCF_6220_LocTranstime_91_96 :
			iNoOfBytes=6;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_LocTranstime_91_96";
			break;
		case  DCF_6220_ExpDate_97_100 :
			iNoOfBytes=4;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_ExpDate_97_100";
			break;
		case  DCF_6220_SettlDate_101_104 :
			iNoOfBytes=4;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_SettlDate_101_104";
			break;
		case  DCF_6220_MerchantTyp_105_108 :
			iNoOfBytes=4;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::MCCCODE;
			strElemNm="DCF_6220_MerchantTyp_105_108";
			break;
		case  DCF_6220_POS_EntryMode_109_111 :
			iNoOfBytes=3;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::PANENTRYMODE;
			strElemNm="DCF_6220_POS_EntryMode_109_111";
			break;
		case  DCF_6220_POS_CondCD_112_113 :
			iNoOfBytes=2;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_POS_CondCD_112_113";
			break;
		case  DCF_6220_RRNum_114_125 :
			iNoOfBytes=12;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::IATAINVOICENO;
			strElemNm="DCF_6220_RRNum_114_125";
			break;
		case  DCF_6220_AuthIdRsp_126_131 :
			iNoOfBytes=6;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::AUTHCODE;
			strElemNm="DCF_6220_AuthIdRsp_126_131";
			break;
		case  DCF_6220_ResCD_132_133 :
			iNoOfBytes=2;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::RESPCODE;
			strElemNm="DCF_6220_ResCD_132_133";
			break;
		case  DCF_6220_TerminalID_134_141 :
			iNoOfBytes=8;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_TerminalID_134_141";
			break;
		case  DCF_6220_CAIC_142_156 :
			iNoOfBytes=15;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::TID;
			strElemNm="DCF_6220_CAIC_142_156";
			break;
		case  DCF_6220_ECSLI_157_159 :
			iNoOfBytes=3;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::NOOFCHRGBK;
			strElemNm="DCF_6220_ECSLI_157_159";
			break;
		case  DCF_6220_AVS_Resp_160_160 :
			iNoOfBytes=1;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_AVS_Resp_160_160";
			break;
		case  DCF_6220_CVV2_CVC2_ResultCd_161_161 :
			iNoOfBytes=1;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_CVV2_CVC2_ResultCd_161_161";
			break;
		case  DCF_6220_Visa_E_Comm_Tid_162_162 :
			iNoOfBytes=1;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_Visa_E_Comm_Tid_162_162";
			break;
		case  DCF_6220_Tras_CurrCd_163_165 :
			iNoOfBytes=3;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::HCURRCODE;
			strElemNm="DCF_6220_Tras_CurrCd_163_165";
			break;
		case  DCF_6220_Settl_CurrCd_166_168 :
			iNoOfBytes=3;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_Settl_CurrCd_166_168";
			break;
		case  DCF_6220_CardhdBill_CurrCd_169_171 :
			iNoOfBytes=3;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::AUTHCURRCODE;
			strElemNm="DCF_6220_CardhdBill_CurrCd_169_171";
			break;
		case  DCF_6220_Adv_RsnCd_172_174 :
			iNoOfBytes=3;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_Adv_RsnCd_172_174";
			break;
		case  DCF_6220_RFU_175_175 :
			iNoOfBytes=1;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_RFU_175_175";
			break;
		case  DCF_6220_POS_Cardhdr_Pindicator_176_176 :
			iNoOfBytes=1;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_POS_Cardhdr_Pindicator_176_176";
			break;
		case  DCF_6220_POS_Trns_Sindicator_177_177 :
			iNoOfBytes=1;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_POS_Trns_Sindicator_177_177";
			break;
		case  DCF_6220_CH_ActTermLvl_Indicator_178_178 :
			iNoOfBytes=1;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_CH_ActTermLvl_Indicator_178_178";
			break;
		case  DCF_6220_NwRefNum_179_187 :
			iNoOfBytes=9;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_NwRefNum_179_187";
			break;
		case  DCF_6220_O_STAN_188_193 :
			iNoOfBytes=6;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::ORIGSEQNO1;
			strElemNm="DCF_6220_O_STAN_188_193";
			break;
		case  DCF_6220_O_Date_194_197 :
			iNoOfBytes=4;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_O_Date_194_197";
			break;
		case  DCF_6220_Acqsp_PvtData_198_246 :
			iNoOfBytes=49;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_Acqsp_PvtData_198_246";
			break;
		case  DCF_6220_Pnt_Ser_DataCd_247_256 :
			iNoOfBytes=10;
			enFmAttr=NO_CHECK;
			enTTField=StructTTUB::FORMATTYPE;
			strElemNm="DCF_6220_Pnt_Ser_DataCd_247_256";
			break;	
	}
}
void DCF::SetD2Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{

}
void DCF::SetD3Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{

}
void DCF::SetD4Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{

}
void DCF::SetD5Format(const unsigned int iElemNo,unsigned int & iNoOfBytes,FMTATTR & enFmAttr,StructTTUB::TTCOL & enTTField,string & strElemNm)
{

}
