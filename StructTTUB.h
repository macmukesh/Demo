#ifndef _TTUB_H_
#define _TTUB_H_

typedef struct
{
	
char	acFormatType[2+1];
char	acFileNumber[3+1];
char	cDC;
char   	acProcDate[6+1];
char	acMEId[15+1];
char	acTID[8+1];
char	acBatchNo[5+1];
char  	acBatchDate[6+1];
char	acTransDate[6+1];
char	acCardNo[19+1];
char	acAuthCode[6+1];
char	acIATAInvoiceNo[15+1];
char	acSrlSeqNo1[12+1];
char	acSrlSeqNo2[12+1];
char	acTxnStepFlg[2+1];
char	cNetwork;
char	cCODE2;
char	acCODE3[3+1];
char	acCODE4[2+1];
char	cCODE5;
char	acCHCurrCode[3+1];
char	acBinCode[6+1];
char	acBinGroup[3+1];
char	cEcomFlag;
int		iDefferedDays ; 
char	cCDCode;
double	dRawAmount1; 
double	dRawAmount2; 
double	dDCCLocalAmt; 
char	acBank2[2+1];
char	acOGFileNo[3+1];
char	cBSA; 
char	acRRN[12+1];
char 	acAcqId[11+1];
char	cProductCode;
double	dDcclocalAmt1;
char	acAction[3+1];
char	acNwRegionIssuer[2+1];
char	acArn[23+1];
char	acIntchgratedesg[29+1];
char	acPanEntryMode[3+1];
char	acPoicurrcode[3+1];
char	acPoicurrexp[2+1];
char	acMerchverival[12+1];
char	acAuthCurrCode[3+1];
char	acRespCode[2+1];
char	acMEState[3+1];
char	acChgDtTime[14+1];
char	acLniSsr[4+1];
char	acTranId[15+1];
char	acTraceId[16+1];
char	acTravelAgencyCode[8+1];
char	acPOSAgentName[25+1];
char	acSubMEName[22+1];
char	acSubMECity[13+1];
char	acSubMEState[3+1];
char	acSubMECountryCode[3+1];
char	cOriginator1 ;
char	acFiller3[3+1];
char	acFiller1[15+1];
char	cCardProgram;
char	acMccCode[4+1];
char	acMccGroup[3+1];
char	acOrigBatchDate[6+1];
char	acOrigProcDate[6+1];
char	acOrigSeqNo1[12+1];
char	acOrigTid[8+1];
char	cEMCode;
char	acRecapNo[3+1];
char	cDSFEXP;
char	cSSFEXP;
char	acSTCurrCode[3+1];
float	dSTSmsPortionInChcy;
char 	acServcd[3+1];
char    acTxnlcId[15+1];
char 	acMeName[50+1];
char 	acChrgbkreason[2+1];
char 	acNumofchrgbk[3+1];
char 	acPosDataCode[10+1];
char 	acB5IssathdtRespCde[4+1]; 
char	cB4TermEntryCap;
char 	acB2TranType[2+1];
char 	acB2TranDate[6+1];
char 	acB3EmvTermCap[8+1];
char	acB2TranEntryCde[3+1];
char 	acB3TermSrlNum[8+1];
char 	acB2UnpredictNum[8+1];
char 	acB2Atc[4+1];
char 	acB2A1p[4+1];
char 	acB2Arqc[16+1];
char 	acB2IssAppData[70+1];
char 	acB2Tvr[10+1];
float	dB2AmtAuth;
char 	acB6IssScrData[80+1];
char 	acB2CryptoInfoData[2+1];
char 	acB2TermCrncyCde[3+1];
float	dB2AmtOther;
char 	acB3CvmRslts[6+1];
char 	acB3EmvTermType[2+1];
char 	acB3Name[32+1];
char 	acB3ApplVerNum[4+1];
char 	acB5IssathdtAddData[16+1];
char	acMECity[13+1];
char	acMECountry[3+1];
char	acMEZip[10+1];
char	cMOTOIND;
char	acProcessingCode[6+1];
char	acPOSDataCode[12+1];
char	acTranLCycleID[16+1];
char	cCrdHolderPresInd;
		

enum TTCOL
	{
			FORMATTYPE,
	FILENO,
	DC,
	PROCDT,
	MEID,
	TID,
	BATCHNO,
	BATCHDT,
	TRANSDT,
	CARDNO,
	AUTHCODE,
	IATAINVOICENO,
	SRLSEQNO1,
	SRLSEQNO2,
	TXNSTEPFLG,
	NETWORK,
	CODE2,
	CODE3,
	CODE4,
	CODE5,
	HCURRCODE,
	BINCODE,
	BINGROUP,
	ECOMFLAG,
	IDEFFEREDDAYS,
	CODE,
	RAWAMOUNT1,
	RAWAMOUNT2,
	DCCLOCALAMT,
	BANK2,
	OGFILENO,
	BSA,
	RRN,
	ACQID,
	PRODUCTCODE,
	DCCLOCALAMT1,
	ACTION,
	NWREGIONISSUER,
	ARN1,
	INTCHGRATEDESG,
	PANENTRYMODE,
	POICURRCODE,
	POICURREXP,
	MERCHVERIVAL,
	AUTHCURRCODE,
	RESPCODE,
	MESTATE,
	HGDTTIME,
	LNISSR,
	TRANID,
	TRACEID,
	TRAVELAGENCYCODE,
	POSAGENTNAME5,
	SUBMENAME2,
	SUBMECITY,
	SUBMESTATE,
	SUBMECOUNTRYCODE,
	ORIGINATOR1,
	ACFILLER3,
	CARDKIND,
	CARDPROGRAM,
	MCCCODE,
	MCCGROUP,
	ORIGBATCHDT,
	ORIGPROCDT,
	ORIGSEQNO1,
	ORIGTID,
	EMCODE,
	RECAPNO,
	DSFEXP,
	SSFEXP,
	STCURRCODE,
	STSMSPORTIONINCHCY,
	SERVCD,
	TXNLCID,
	MENAME0,
	HRGBKREASON,
	NOOFCHRGBK,
	POSDATACODE1,
	B5ISSATHDTRESPCDE,
	B4TERMENTRYCAP,
	B2TRANTYPE,
	B2TRANDT,
	B3EMVTERMCAP,
	B2TRANENTRYCDE,
	B3TERMSRLNO,
	B2UNPREDICTNO,
	B2ATC,
	B2A1P,
	B2ARQC,
	B2ISSAPPDATA0,
	B2TVR,
	B2AMTAUTH,
	B6ISSSCRDATA0,
	B2CRYPTOINFODATA,
	B2TERMCRNCYCDE,
	B2AMTOTHER,
	B3CVMRSLTS,
	B3EMVTERMTYPE,
	B3NAME2,
	B3APPLVERNO,
	B5ISSATHDTADDDATA,
	MECITY,
	MECOUNTRY,
	MEZIP,
	MOTOIND,
	PROCESSINGCODE,
	POSDATACODE,
	TRANLCYCLEID,
	CRDHOLDERPRESIND
	
	};



}StructTTUB;
#endif

