#ifndef TTMODEL_H
#define TTMODEL_H

#include "enum_DataType.h"
#include "StructTTUB.h"
#include "Utility.h"
#include <sys/time.h>

struct Model
{
	private:
		StructTTUB objTT;
		DATATYP enDT;
		float fTmp;
		double dTmp ;
		int iTmp ;
		char * out;
		double *dout;
		int * iout;
		short int * siout;
		long int * liout;
		float *fout;
		size_t colmaxsz;
		const char * Tmpvalue;
		char day[2];
		int imonth;
		int iyear;
		int iday;
		char year [5];
	public:

		// fetch data from ref tank
		void EnrichData()
		{
			/*
			strncpy(ObjOsrt.acMeiCode, ptrTerminal[pos].acMe, 6);
			ObjOsrt.cEcom = ptrTerminal[pos].cInternetFlg;
			ObjOsrt.cMeMccFlag = ptrTerminal[pos].cMeMccFlag;
			*/
		}

		void UpdateColData()
		{		
			/*
				if(!strcmp(objTT.acC0cvdfld, "0100"))
				strcpy(objTT.acCODE3, "210");
				if(!strcmp(objTT.acC0cvdfld, "0120"))
				strcpy(objTT.acCODE3, "210");
				if(!strcmp(objTT.acC0cvdfld, "0420"))
				strcpy(objTT.acCODE3, "420");	//acMsgNum to 
			*/	
				/*
				//From terminal tab
				if((strncmp(objTT.acCHCurrCode, "356", 3) != 0) && (ObjOsrt.cMeMccFlag == '3'))
					objTT.cCDCode = '3';	// DCC
				else if((strncmp(objTT.acCHCurrCode, "356", 3) != 0) && (ObjOsrt.cMeMccFlag == '2') )
					objTT.cCDCode = '2';	// CCC (MCC)
				else
					objTT.cCDCode = '1';	// INR
				
				//From terminal tab
				if(ObjOsrt.cEcom == 'Y')
					strcpy(objTT.acTxnStepFlg, "52");
				else
					strcpy(objTT.acTxnStepFlg, "51");

				objTT.cEcomFlag = ObjOsrt.cEcom;
				
				//From terminal tab
				strncpy(ObjTTUB.acMEId, ObjOsrt.acMeiCode, 6);
				*/
	
				// wrtie code to update code to arrive at some common fields
		}

		bool isleapyear(unsigned short year){
			return (!(year%4) && (year%100) || !(year%400));
		}

		//1 valid, 0 invalid
		bool IsDateValid(unsigned short year,unsigned short month,unsigned short day){
			unsigned short monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};
			if (!year || !month || !day || month>12)
				return 0;
			if (isleapyear(year) && month==2)
				monthlen[1]++;
			if (day>monthlen[month-1])
				return 0;
			return 1;
		}

		std::string GetEnumDataTypeName(const int ino)
		{
			DATATYP enDT=(DATATYP)ino;
			switch(enDT)
			{
				case VARCHAR1:
					return std::string("VARCHAR");
				case CHAR1:
					return std::string("CHAR");
				case FLOAT1:
					return std::string("FLOAT");
				case DOUBLE1:
					return std::string("DOUBLE");
				case INTEGER:
					return std::string("INTEGER");
				case LONG:
					return std::string("LONG");
				case DATE:
					return std::string("DATE");
				default:
					return std::string("DEFAULT");
			}
		}

	void PrintTTObj(ofstream & TxnFp)
	{

	TxnFp<<"DATA|"<<objTT.acFormatType<<"|"<<objTT.acFileNumber<<"|"<<objTT.cDC<<"|"<<objTT.acProcDate<<"|"<<objTT.acMEId<<"|"<<objTT.acTID<<"|"<<objTT.acBatchNo<<"|"<<objTT.acBatchDate<<"|"<<objTT.acTransDate<<"|"<<objTT.acCardNo<<"|"<<objTT.acAuthCode<<"|"<<objTT.acIATAInvoiceNo<<"|"<<objTT.acSrlSeqNo1<<"|"<<objTT.acSrlSeqNo2<<"|"<<objTT.acTxnStepFlg<<"|"<<objTT.cNetwork<<"|"<<objTT.cCODE2<<"|"<<objTT.acCODE3<<"|"<<objTT.acCODE4<<"|"<<objTT.cCODE5<<"|"<<objTT.acCHCurrCode<<"|"<<objTT.acBinCode<<"|"<<objTT.acBinGroup<<"|"<<objTT.cEcomFlag<<"|"<<objTT.iDefferedDays  <<"|"<<objTT.cCDCode<<"|"<<objTT.dRawAmount1 <<"|"<<objTT.dRawAmount2 <<"|"<<objTT.dDCCLocalAmt <<"|"<<objTT.acBank2<<"|"<<objTT.acOGFileNo<<"|"<<objTT.cBSA <<"|"<<objTT.acRRN<<"|"<<objTT.acAcqId<<"|"<<objTT.cProductCode<<"|"<<objTT.dDcclocalAmt1<<"|"<<objTT.acAction<<"|"<<objTT.acNwRegionIssuer<<"|"<<objTT.acArn<<"|"<<objTT.acIntchgratedesg<<"|"<<objTT.acPanEntryMode<<"|"<<objTT.acPoicurrcode<<"|"<<objTT.acPoicurrexp<<"|"<<objTT.acMerchverival<<"|"<<objTT.acAuthCurrCode<<"|"<<objTT.acRespCode<<"|"<<objTT.acMEState<<"|"<<objTT.acChgDtTime<<"|"<<objTT.acLniSsr<<"|"<<objTT.acTranId<<"|"<<objTT.acTraceId<<"|"<<objTT.acTravelAgencyCode<<"|"<<objTT.acPOSAgentName<<"|"<<objTT.acSubMEName<<"|"<<objTT.acSubMECity<<"|"<<objTT.acSubMEState<<"|"<<objTT.acSubMECountryCode<<"|"<<objTT.cOriginator1 <<"|"<<objTT.acFiller3<<"|"<<objTT.acFiller1<<"|"<<objTT.cCardProgram<<"|"<<objTT.acMccCode<<"|"<<objTT.acMccGroup<<"|"<<objTT.acOrigBatchDate<<"|"<<objTT.acOrigProcDate<<"|"<<objTT.acOrigSeqNo1<<"|"<<objTT.acOrigTid<<"|"<<objTT.cEMCode<<"|"<<objTT.acRecapNo<<"|"<<objTT.cDSFEXP<<"|"<<objTT.cSSFEXP<<"|"<<objTT.acSTCurrCode<<"|"<<objTT.dSTSmsPortionInChcy<<"|"<<objTT.acServcd<<"|"<<objTT.  acTxnlcId<<"|"<<objTT.acMeName<<"|"<<objTT.acChrgbkreason<<"|"<<objTT.acNumofchrgbk<<"|"<<objTT.acPosDataCode<<"|"<<objTT.acB5IssathdtRespCde<<"|"<<objTT.acB2TranType<<"|"<<objTT.acB2TranDate<<"|"<<objTT.acB3EmvTermCap<<"|"<<objTT.acB2TranEntryCde<<"|"<<objTT.acB3TermSrlNum<<"|"<<objTT.acB2UnpredictNum<<"|"<<objTT.acB2Atc<<"|"<<objTT.acB2A1p<<"|"<<objTT.acB2Arqc<<"|"<<objTT.acB2IssAppData<<"|"<<objTT.acB2Tvr<<"|"<<objTT.dB2AmtAuth<<"|"<<objTT.acB6IssScrData<<"|"<<objTT.acB2CryptoInfoData<<"|"<<objTT.acB2TermCrncyCde<<"|"<<objTT.dB2AmtOther<<"|"<<objTT.acB3CvmRslts<<"|"<<objTT.acB3EmvTermType<<"|"<<objTT.acB3Name<<"|"<<objTT.acB3ApplVerNum<<"|"<<objTT.acB5IssathdtAddData<<"|"<<objTT.acMECity<<"|"<<objTT.acMECountry<<"|"<<objTT.acMEZip<<"|"<<objTT.cMOTOIND<<"|"<<objTT.acProcessingCode<<"|"<<objTT.acPOSDataCode<<"|"<<objTT.acTranLCycleID<<"|"<<objTT.cCrdHolderPresInd <<"|"<<endl;
	
	}


		int SetData(StructTTUB::TTCOL enColId,const char * value,const unsigned int valSz,int & iErrOutVal)
		{
			enDT=VARCHAR1 ;
			cout<<enColId<<" : "<<value<<endl;
			switch(enColId)
			{
		case StructTTUB::FORMATTYPE: 
		out = objTT.acFormatType;		
		colmaxsz=sizeof(objTT.acFormatType);			
		enDT=VARCHAR1 ;
		break;

		case StructTTUB::FILENO: 
		out = objTT.acFileNumber;		
		colmaxsz=sizeof(objTT.acFileNumber);		
		enDT=VARCHAR1 ;
		break;

		case StructTTUB::DC: 
		out = &objTT.cDC;		
		colmaxsz=sizeof(objTT.cDC);		
		enDT=CHAR1;
		break;

		case StructTTUB::PROCDT: 
		out = objTT.acProcDate;		
		colmaxsz=sizeof(objTT.acProcDate);		
		enDT=DATE;
		break;

		case StructTTUB::MEID: 
		out = objTT.acMEId;		
		colmaxsz=sizeof(objTT.acMEId);		
		enDT=VARCHAR1 ;
		break;

		case StructTTUB::TID: 
		out = objTT.acTID;		
		colmaxsz=sizeof(objTT.acTID);		
		enDT=VARCHAR1 ;
		break;

		case StructTTUB::BATCHNO: 
		out = objTT.acBatchNo;		
		colmaxsz=sizeof(objTT.acBatchNo);		
		enDT=VARCHAR1 ;
		break;

		case StructTTUB::BATCHDT: 
		out = objTT.acBatchDate;		
		colmaxsz=sizeof(objTT.acBatchDate);		
		enDT=DATE;
		break;

		case StructTTUB::TRANSDT: 
		out = objTT.acTransDate;		
		colmaxsz=sizeof(objTT.acTransDate);	
		enDT=DATE;	
		break;

		case StructTTUB::CARDNO: 
		out = objTT.acCardNo;		
		colmaxsz=sizeof(objTT.acCardNo);		
		enDT=VARCHAR1; 
		break;

		case StructTTUB::AUTHCODE: 
		out = objTT.acAuthCode;		
		colmaxsz=sizeof(objTT.acAuthCode);		
		enDT=VARCHAR1; 
		break;

		case StructTTUB::IATAINVOICENO: 
		out = objTT.acIATAInvoiceNo;		
		colmaxsz=sizeof(objTT.acIATAInvoiceNo);		
		enDT=VARCHAR1; 
		break;

		case StructTTUB::SRLSEQNO1: 
		out = objTT.acSrlSeqNo1;		
		colmaxsz=sizeof(objTT.acSrlSeqNo1);		
		enDT=VARCHAR1; 
		break;

		case StructTTUB::SRLSEQNO2: 
		out = objTT.acSrlSeqNo2;		
		colmaxsz=sizeof(objTT.acSrlSeqNo2);		
		enDT=VARCHAR1; 
		break;

		case StructTTUB::TXNSTEPFLG: 
		out = objTT.acTxnStepFlg;		
		colmaxsz=sizeof(objTT.acTxnStepFlg);		
		enDT=VARCHAR1; 
		break;

		case StructTTUB::NETWORK: 
		out = &objTT.cNetwork;		
		colmaxsz=sizeof(objTT.cNetwork);
		enDT=CHAR1;		
		break;


		case StructTTUB::CODE2: 
		out = &objTT.cCODE2;		
		colmaxsz=sizeof(objTT.cCODE2);
		enDT=CHAR1;		
		break;

		case StructTTUB::CODE3: 
		out = objTT.acCODE3;		
		colmaxsz=sizeof(objTT.acCODE3);		
		enDT=VARCHAR1; 
		break;

		case StructTTUB::CODE4: 
		out = objTT.acCODE4;		
		colmaxsz=sizeof(objTT.acCODE4);		
		enDT=VARCHAR1; 
		break;

		case StructTTUB::CODE5: 
		out = &objTT.cCODE5;		
		colmaxsz=sizeof(objTT.cCODE5);
		enDT=CHAR1;		
		break;
					

		case StructTTUB::HCURRCODE : 
		out = objTT.acCHCurrCode;		
		colmaxsz=sizeof(objTT.acCHCurrCode);		
		enDT=VARCHAR1; 
		break;

		case StructTTUB::BINCODE: 
		out = objTT.acBinCode;		
		colmaxsz=sizeof(objTT.acBinCode);		
		enDT=VARCHAR1; 
		break;


		case StructTTUB::BINGROUP: 
		out = objTT.acBinGroup;		
		colmaxsz=sizeof(objTT.acBinGroup);		
		enDT=VARCHAR1; 
		break;
					

		case StructTTUB::ECOMFLAG : 
		out = &objTT.cEcomFlag;		
		colmaxsz=sizeof(objTT.cEcomFlag);
		enDT=CHAR1;		
		break;
					

		case StructTTUB::IDEFFEREDDAYS: 
		iout = &objTT.iDefferedDays;		
		colmaxsz=sizeof(objTT.iDefferedDays);
		enDT=INTEGER;		
		break;


		case StructTTUB::CODE: 
		out = &objTT.cCDCode;		
		colmaxsz=sizeof(objTT.cCDCode);
		enDT=CHAR1;		
		break;

		case StructTTUB::RAWAMOUNT1: 
		dout = &objTT.dRawAmount1;		
		colmaxsz=sizeof(objTT.dRawAmount1);	
		enDT=DOUBLE1;	
		break;

		case StructTTUB::RAWAMOUNT2: 
		dout = &objTT.dRawAmount2;		
		colmaxsz=sizeof(objTT.dRawAmount2);
		enDT=DOUBLE1;		
		break;

		case StructTTUB::DCCLOCALAMT: 
		dout = &objTT.dDCCLocalAmt;		
		colmaxsz=sizeof(objTT.dDCCLocalAmt);
		enDT=DOUBLE1;		
		break;

		case StructTTUB::BANK2: 
		out = objTT.acBank2;		
		colmaxsz=sizeof(objTT.acBank2);		
		break;
					
		case StructTTUB::OGFILENO: 
		out = objTT.acOGFileNo;		
		colmaxsz=sizeof(objTT.acOGFileNo);		
		break;
					
		case StructTTUB::BSA: 
		out = &objTT.cBSA;		
		colmaxsz=sizeof(objTT.cBSA);
		enDT=CHAR1;		
		break;
					
		case StructTTUB::RRN: 
		out = objTT.acRRN;		
		colmaxsz=sizeof(objTT.acRRN);		
		break;
					
		case StructTTUB::ACQID: 
		out = objTT.acAcqId;		
		colmaxsz=sizeof(objTT.acAcqId);		
		break;
					
		case StructTTUB::PRODUCTCODE: 
		out = &objTT.cProductCode;		
		colmaxsz=sizeof(objTT.cProductCode);
		enDT=CHAR1;		
		break;
					
		case StructTTUB::DCCLOCALAMT1: 
		dout = &objTT.dDcclocalAmt1;	
		colmaxsz=sizeof(objTT.dDcclocalAmt1);	
		enDT=DOUBLE1;
		break;
					
		case StructTTUB::ACTION : 
		out = objTT.acAction;		
		colmaxsz=sizeof(objTT.acAction);		
		break;

		case StructTTUB::NWREGIONISSUER: 
		out = objTT.acNwRegionIssuer;		
		colmaxsz=sizeof(objTT.acNwRegionIssuer);		
		break;
					
		case StructTTUB::ARN1: 
		out = objTT.acArn;		
		colmaxsz=sizeof(objTT.acArn);		
		break;
					
		case StructTTUB::INTCHGRATEDESG: 
		out = objTT.acIntchgratedesg;		
		colmaxsz=sizeof(objTT.acIntchgratedesg);		
		break;
										
		case StructTTUB::PANENTRYMODE: 
		out = objTT.acPanEntryMode;		
		colmaxsz=sizeof(objTT.acPanEntryMode);		
		break;

		case StructTTUB::POICURRCODE: 
		out = objTT.acPoicurrcode;		
		colmaxsz=sizeof(objTT.acPoicurrcode);		
		break;

		case StructTTUB::POICURREXP: 
		out = objTT.acPoicurrexp;		
		colmaxsz=sizeof(objTT.acPoicurrexp);		
		break;
					

		case StructTTUB::MERCHVERIVAL: 
		out = objTT.acMerchverival;		
		colmaxsz=sizeof(objTT.acMerchverival);		
		break;
					
		case StructTTUB::AUTHCURRCODE: 
		out = objTT.acAuthCurrCode;		
		colmaxsz=sizeof(objTT.acAuthCurrCode);		
		break;
					
		case StructTTUB::RESPCODE: 
		out = objTT.acRespCode;		
		colmaxsz=sizeof(objTT.acRespCode);		
		break;
					
		case StructTTUB::MESTATE: 
		out = objTT.acMEState;		
		colmaxsz=sizeof(objTT.acMEState);		
		break;
					
		case StructTTUB::HGDTTIME: 
		out = objTT.acChgDtTime;		
		colmaxsz=sizeof(objTT.acChgDtTime);		
		break;
					
		case StructTTUB::LNISSR: 
		out = objTT.acLniSsr;		
		colmaxsz=sizeof(objTT.acLniSsr);		
		break;

		case StructTTUB::TRANID: 
		out = objTT.acTranId;		
		colmaxsz=sizeof(objTT.acTranId);		
		break;

		case StructTTUB::TRACEID: 
		out = objTT.acTraceId;		
		colmaxsz=sizeof(objTT.acTraceId);		
		break;
					
		case StructTTUB::TRAVELAGENCYCODE : 
		out = objTT.acTravelAgencyCode;		
		colmaxsz=sizeof(objTT.acTravelAgencyCode);		
		break;
					

		case StructTTUB::POSAGENTNAME5: 
		out = objTT.acPOSAgentName;		
		colmaxsz=sizeof(objTT.acPOSAgentName);		
		break;
					

		case StructTTUB::SUBMENAME2: 
		out = objTT.acSubMEName;		
		colmaxsz=sizeof(objTT.acSubMEName);		
		break;
										

		case StructTTUB::SUBMECITY: 
		out = objTT.acSubMECity;		
		colmaxsz=sizeof(objTT.acSubMECity);		
		break;

		case StructTTUB::SUBMESTATE: 
		out = objTT.acSubMEState;		
		colmaxsz=sizeof(objTT.acSubMEState);		
		break;

		case StructTTUB::SUBMECOUNTRYCODE: 
		out = objTT.acSubMECountryCode;		
		colmaxsz=sizeof(objTT.acSubMECountryCode);		
		break;
																									

		case StructTTUB::ORIGINATOR1: 
		out = &objTT.cOriginator1;		
		colmaxsz=sizeof(objTT.cOriginator1);
		enDT=CHAR1;		
		break;
					

		case StructTTUB::ACFILLER3: 
		out = objTT.acFiller3;		
		colmaxsz=sizeof(objTT.acFiller3);		
		break;
					


		case StructTTUB::CARDKIND: 
		out = objTT.acFiller1;		
		colmaxsz=sizeof(objTT.acFiller1);
		enDT=CHAR1;		
		break;
							


		case StructTTUB::CARDPROGRAM: 
		out = &objTT.cCardProgram;		
		colmaxsz=sizeof(objTT.cCardProgram);
		enDT=CHAR1;		
		break;




		case StructTTUB::MCCCODE: 
		out = objTT.acMccCode;		
		colmaxsz=sizeof(objTT.acMccCode);		
		break;

		case StructTTUB::MCCGROUP	: 
		out = objTT.acMccGroup;		
		colmaxsz=sizeof(objTT.acMccGroup);		
		break;
					

		case StructTTUB::ORIGBATCHDT: 
		out = objTT.acOrigBatchDate;		
		colmaxsz=sizeof(objTT.acOrigBatchDate);		
		break;
					


		case StructTTUB::ORIGPROCDT: 
		out = objTT.acOrigProcDate;		
		colmaxsz=sizeof(objTT.acOrigProcDate);		
		break;
					


		case StructTTUB::ORIGSEQNO1: 
		out = objTT.acOrigSeqNo1;		
		colmaxsz=sizeof(objTT.acOrigSeqNo1);		
		break;
					

		case StructTTUB::ORIGTID: 
		out = objTT.acOrigTid;		
		colmaxsz=sizeof(objTT.acOrigTid);		
		break;
					

		case StructTTUB::EMCODE: 
		out = &objTT.cEMCode;		
		colmaxsz=sizeof(objTT.cEMCode);
		enDT=CHAR1;		
		break;


		case StructTTUB::RECAPNO: 
		out = objTT.acRecapNo;		
		colmaxsz=sizeof(objTT.acRecapNo);		
		break;


		case StructTTUB::DSFEXP: 
		out = &objTT.cDSFEXP;		
		colmaxsz=sizeof(objTT.cDSFEXP);
		enDT=CHAR1;		
		break;
		
		case StructTTUB::B4TERMENTRYCAP:
		out = &objTT.cB4TermEntryCap;
		colmaxsz=sizeof(objTT.cB4TermEntryCap);
		enDT=CHAR1;
		break;

		case StructTTUB::SSFEXP: 
		out = &objTT.cSSFEXP;		
		colmaxsz=sizeof(objTT.cSSFEXP);
		enDT=CHAR1;		
		break;


		case StructTTUB::STCURRCODE: 
		out = objTT.acSTCurrCode;		
		colmaxsz=sizeof(objTT.acSTCurrCode);		
		break;


		case StructTTUB::STSMSPORTIONINCHCY: 
		fout = &objTT.dSTSmsPortionInChcy;		
		colmaxsz=sizeof(objTT.dSTSmsPortionInChcy);	
		enDT=FLOAT1;	
		break;
					

		case StructTTUB::SERVCD: 
		out = objTT.acServcd;		
		colmaxsz=sizeof(objTT.acServcd);		
		break;
					

		case StructTTUB::TXNLCID: 
		out = objTT.acTxnlcId;		
		colmaxsz=sizeof(objTT.acTxnlcId);		
		break;
					

		case StructTTUB::MENAME0: 
		out = objTT.acMeName;		
		colmaxsz=sizeof(objTT.acMeName);		
		break;
					

		case StructTTUB::HRGBKREASON: 
		out = objTT.acChrgbkreason;		
		colmaxsz=sizeof(objTT.acChrgbkreason);		
		break;
				


		case StructTTUB::NOOFCHRGBK: 
		out = objTT.acNumofchrgbk;		
		colmaxsz=sizeof(objTT.acNumofchrgbk);		
		break;


		case StructTTUB::POSDATACODE1: 
		out = objTT.acPOSDataCode;		
		colmaxsz=sizeof(objTT.acPOSDataCode);		
		break;


		case StructTTUB::B5ISSATHDTRESPCDE : 
		out = objTT.acB5IssathdtRespCde;		
		colmaxsz=sizeof(objTT.acB5IssathdtRespCde);		
		break;
					

		case StructTTUB::B2TRANTYPE: 
		out = objTT.acB2TranType;		
		colmaxsz=sizeof(objTT.acB2TranType);		
		break;
					

		case StructTTUB::B3EMVTERMCAP: 
		out = objTT.acB3EmvTermCap;		
		colmaxsz=sizeof(objTT.acB3EmvTermCap);		
		break;
										

		case StructTTUB::B2TRANENTRYCDE: 
		out = objTT.acB2TranEntryCde;		
		colmaxsz=sizeof(objTT.acB2TranEntryCde);		
		break;
					


		case StructTTUB::B3TERMSRLNO: 
		out = objTT.acB3TermSrlNum;		
		colmaxsz=sizeof(objTT.acB3TermSrlNum);		
		break;
					

		case StructTTUB::B2UNPREDICTNO: 
		out = objTT.acB2UnpredictNum;		
		colmaxsz=sizeof(objTT.acB2UnpredictNum);		
		break;
					

		case StructTTUB::B2ATC: 
		out = objTT.acB2Atc;		
		colmaxsz=sizeof(objTT.acB2Atc);		
		break;

		case StructTTUB::B2A1P: 
		out = objTT.acB2A1p;		
		colmaxsz=sizeof(objTT.acB2A1p);		
		break;

		case StructTTUB::B2ARQC: 
		out = objTT.acB2Arqc;		
		colmaxsz=sizeof(objTT.acB2Arqc);		
		break;
					

		case StructTTUB::B2ISSAPPDATA0: 
		out = objTT.acB2IssAppData;		
		colmaxsz=sizeof(objTT.acB2IssAppData);		
		break;
					

		case StructTTUB::B2TVR: 
		out = objTT.acB2Tvr;		
		colmaxsz=sizeof(objTT.acB2Tvr);		
		break;
					

		case StructTTUB::B2AMTAUTH: 
		fout = &objTT.dB2AmtAuth;		
		colmaxsz=sizeof(objTT.dB2AmtAuth);
		enDT=FLOAT1;		
		break;
					


		case StructTTUB::B6ISSSCRDATA0: 
		out = objTT.acB6IssScrData;		
		colmaxsz=sizeof(objTT.acB6IssScrData);		
		break;
					


		case StructTTUB::B2CRYPTOINFODATA: 
		out = objTT.acB2CryptoInfoData;		
		colmaxsz=sizeof(objTT.acB2CryptoInfoData);		
		break;



		case StructTTUB::B2TERMCRNCYCDE: 
		out = objTT.acB2TermCrncyCde;		
		colmaxsz=sizeof(objTT.acB2TermCrncyCde);		
		break;
					

		case StructTTUB::B2AMTOTHER: 
		fout = &objTT.dB2AmtOther;		
		colmaxsz=sizeof(objTT.dB2AmtOther);		
		enDT=FLOAT1;
		break;
					

		case StructTTUB::B3CVMRSLTS: 
		out = objTT.acB3CvmRslts;		
		colmaxsz=sizeof(objTT.acB3CvmRslts);		
		break;


		case StructTTUB::B3EMVTERMTYPE: 
		out = objTT.acB3EmvTermType;		
		colmaxsz=sizeof(objTT.acB3EmvTermType);		
		break;
					
		case StructTTUB::B3NAME2: 
		out = objTT.acB3Name;		
		colmaxsz=sizeof(objTT.acB3Name);		
		break;
					


		case StructTTUB::B3APPLVERNO: 
		out = objTT.acB3ApplVerNum;		
		colmaxsz=sizeof(objTT.acB3ApplVerNum);		
		break;
					

		case StructTTUB::B5ISSATHDTADDDATA: 
		out = objTT.acB5IssathdtAddData;		
		colmaxsz=sizeof(objTT.acB5IssathdtAddData);		
		break;
					

		case StructTTUB::MECITY: 
		out = objTT.acMECity;		
		colmaxsz=sizeof(objTT.acMECity);		
		break;


		case StructTTUB::MECOUNTRY: 
		out = objTT.acMECountry;		
		colmaxsz=sizeof(objTT.acMECountry);		
		break;

		case StructTTUB::MEZIP: 
		out = objTT.acMEZip;		
		colmaxsz=sizeof(objTT.acMEZip);		
		break;



		case StructTTUB::MOTOIND: 
		out = &objTT.cMOTOIND;		
		colmaxsz=sizeof(objTT.cMOTOIND);
		enDT=CHAR1;		
		break;
										


		case StructTTUB::PROCESSINGCODE: 
		out = objTT.acProcessingCode;		
		colmaxsz=sizeof(objTT.acProcessingCode);		
		break;
					


		case StructTTUB::POSDATACODE: 
		out = objTT.acPosDataCode;		
		colmaxsz=sizeof(objTT.acPosDataCode);		
		break;
					



		case StructTTUB::TRANLCYCLEID: 
		out = objTT.acTranLCycleID;		
		colmaxsz=sizeof(objTT.acTranLCycleID);		
		break;
									



		case StructTTUB::CRDHOLDERPRESIND: 
		out = &objTT.cCrdHolderPresInd;		
		colmaxsz=sizeof(objTT.cCrdHolderPresInd);
		enDT=CHAR1;		
		break;
				



			}

			// set temp pointer to orig value
			Tmpvalue = value;

			switch (enDT)
			{
				case CHAR1 :
					strncpy(out,value,1);
					break;
				case VARCHAR1 :
					if(!(valSz<colmaxsz))
					{
						iErrOutVal=	colmaxsz;
						return 2;						
					}
					strcpy(out,value);
					break;	
				case FLOAT1 :

					while(*Tmpvalue != '\0'&& ( (*Tmpvalue >='0' && *Tmpvalue <='9') || *Tmpvalue=='.') && ++Tmpvalue);

					if(*Tmpvalue !='\0')
					{
						iErrOutVal=FLOAT1;
						return 2;
					}

					// store into out var
					fTmp = atof(value);
					*fout = fTmp;

					break;
				case DOUBLE1 :
					while(*Tmpvalue != '\0'&& ( (*Tmpvalue >='0' && *Tmpvalue <='9') || *Tmpvalue=='.') && ++Tmpvalue);

					if(*Tmpvalue != '\0')
					{
						iErrOutVal=DOUBLE1;
						return 2;
					}
						dTmp = atof(value);
						*dout = dTmp;
					break;
				case INTEGER :

					while(*Tmpvalue != '\0'&&  (*Tmpvalue >='0' && *Tmpvalue <='9') && ++Tmpvalue);

					if(*Tmpvalue != '\0')
					{
						iErrOutVal=INTEGER;
						return 2;
					}
						iTmp = atoi(value);
						*iout = iTmp;
					break;	
				case DATE :        			
					// YYMMDD
					strncpy(day,Tmpvalue,2);
					iday=atoi(day);
					strncpy(day,Tmpvalue+2,2);
					imonth=atoi(day);
					strncpy(day,Tmpvalue+4,2);
					iyear =  atoi(day);

					if(!IsDateValid(iyear,imonth,iday)){
						iErrOutVal=DATE;
						return 2;
					}
					break;						
			}

			return 0;
		}

		/*char * GetData(StructTTUB::TTCOL enColId)
		{
			char * out;
			switch(enColId)
			{
				case StructTTUB::FORMATTYPE:													
					out = objTT.acFormatType;		
					break;
				case StructTTUB::FILEIDENTITYNO:														
					out = objTT.acFileIdentityNum;		
					break;
				case StructTTUB::DC:														
					out = &objTT.cDC;		
					break;
				case StructTTUB::DSEC:														
					out = objTT.acDS;		
					break;
				case StructTTUB::TXNSIGN:														
					out = &objTT.cTxnSign;		
					break;
				case StructTTUB::PROCDT:														
					out = objTT.acProcDate;		
					break;
				case StructTTUB::FILENO:														
					out = objTT.acFileNumber;		
					break;
				case StructTTUB::MEID:														
					out = objTT.acMEId;		
					break;
				case StructTTUB::SEQ2:														
					out = &objTT.cSequencer2;		
					break;
				case StructTTUB::BATCHDT:														
					out = objTT.acBatchDate;		
					break;
				case StructTTUB::TID:														
					out = objTT.acTID;		
					break;
				case StructTTUB::BATCHNO:														
					out = objTT.acBatchNo;		
					break;
				case StructTTUB::BINCODE:														
					out = objTT.acBinCode;		
					break;
				case StructTTUB::BINGROUP:														
					out = objTT.acBinGroup;		
					break;
				case StructTTUB::CARDPROGRAM:														
					out = &objTT.cCardProgram;		
					break;
				case StructTTUB::CARDKIND:														
					out = &objTT.cCardKind;		
					break;
				case StructTTUB::NETWORK:														
					out = &objTT.cNetwork;		
					break;
				case StructTTUB::ISSUERSTATUS:														
					out = &objTT.cIssuerStatus;		
					break;
				case StructTTUB::ONOFFUS:														
					out = &objTT.cOnOffus;		
					break;
				case StructTTUB::TRANSDT:														
					out = objTT.acTransDate;		
					break;
				case StructTTUB::CARDNO:														
					out = objTT.acCardNo;		
					break;
				case StructTTUB::AUTHCODE:														
					out = objTT.acAuthCode;		
					break;
				case StructTTUB::MCCCODE:														
					out = objTT.acMccCode;		
					break;
				case StructTTUB::MCCGROUP:														
					out = objTT.acMccGroup;		
					break;
				case StructTTUB::SEQ0:														
					out = &objTT.cSequencer0;		
					break;
				case StructTTUB::SEQ3:														
					out = objTT.acSequencer3;		
					break;
				case StructTTUB::STAYSKEY:														
					out = objTT.ac3STAYSKEY;		
					break;
				case StructTTUB::IATAINVOICENO:														
					out = objTT.acIATAInvoiceNo;		
					break;
				case StructTTUB::IATABSP:														
					out = objTT.acIATABSP;		
					break;
				case StructTTUB::CODE2:														
					out = &objTT.cCODE2;		
					break;
				case StructTTUB::CODE3:														
					out = objTT.acCODE3;		
					break;
				case StructTTUB::CODE4:														
					out = objTT.acCODE4;		
					break;
				case StructTTUB::CODE5:														
					out = &objTT.cCODE5;		
					break;
				case StructTTUB::ERRORCODE:														
					out = objTT.acErrorCode;		
					break;
				case StructTTUB::SRLSEQNO1:														
					out = objTT.acSrlSeqNo1;		
					break;
				case StructTTUB::SRLSEQNO2:														
					out = objTT.acSrlSeqNo2;		
					break;
				case StructTTUB::TRIVIALERROR:														
					out = &objTT.cTrivialError;		
					break;
				case StructTTUB::ORIGPROCDT:														
					out = objTT.acOrigProcDate;		
					break;
				case StructTTUB::ORIGDATAP:														
					out = objTT.acOrigDataCap;		
					break;
				case StructTTUB::ORIGFILENO:														
					out = objTT.acOrigFileNo;		
					break;
				case StructTTUB::ORIGBATCHDT:														
					out = objTT.acOrigBatchDate;		
					break;
				case StructTTUB::ORIGBATCHNO:														
					out = objTT.acOrigBatchNo;		
					break;
				case StructTTUB::ORIGSEQNO1:														
					out = objTT.acOrigSeqNo1;		
					break;
				case StructTTUB::ORIGSEQNO2:														
					out = objTT.acOrigSeqNo2;		
					break;
				case StructTTUB::ORIGTID:														
					out = objTT.acOrigTid;		
					break;
				case StructTTUB::DUPDC:														
					out = &objTT.cDupDC;		
					break;
				case StructTTUB::DUPDS:														
					out = objTT.acDupDS;		
					break;
				case StructTTUB::DUPTXNSIGN:														
					out = &objTT.cDupTxnSign;		
					break;
				case StructTTUB::PRODUCTCODE:														
					out = &objTT.cProductCode;		
					break;
				case StructTTUB::SUBPRODUCT:														
					out = objTT.acSubProduct;		
					break;
				case StructTTUB::BSA:														
					out = &objTT.cBSA;		
					break;
				case StructTTUB::MAJCY:														
					out = &objTT.cMajCy;		
					break;
				case StructTTUB::EMCODE:														
					out = &objTT.cEMCode;		
					break;
				case StructTTUB::ADFIRATE:														
					sprintf(out, "%f",objTT.fAdfiRate);		
					break;
				case StructTTUB::BANK2:														
					out = objTT.acBank2;		
					break;
				case StructTTUB::SMSDMS:														
					out = &objTT.cSmsDms;		
					break;
				case StructTTUB::OGFILENO:														
					out = objTT.acOGFileNo;		
					break;
				case StructTTUB::RECAPNO:														
					out = objTT.acRecapNo;		
					break;
				case StructTTUB::OGBATCHNO:														
					out = objTT.acOGBatchNo;		
					break;
				case StructTTUB::DSFEXP:														
					out = &objTT.cDSFEXP;		
					break;
				case StructTTUB::SSFEXP:														
					out = &objTT.cSSFEXP;		
					break;
				case StructTTUB::RSNGLOBAL:														
					out = objTT.acRSNGlobal;		
					break;
				case StructTTUB::RSNFILE:														
					out = objTT.acRSNFile;		
					break;
				case StructTTUB::RSNBATCH:														
					out = objTT.acRSNBatch;		
					break;
				case StructTTUB::RSNUNIQ:														
					out = objTT.acRSNUNIQ;		
					break;
				case StructTTUB::RRN1:														
					out = objTT.acRrn;		
					break;
				case StructTTUB::ARN1:														
					out = objTT.acArn;		
					break;
				case StructTTUB::URN1:														
					out = objTT.acUrn;		
					break;
				case StructTTUB::TSK8:														
					out = objTT.acTSK;		
					break;
				case StructTTUB::SURRCP:														
					out = &objTT.cSurRcp;		
					break;
				case StructTTUB::SURFIXAMT:														
					sprintf(out, "%f",objTT.fSurFixAmt);		
					break;
				case StructTTUB::SURPERAMT:														
					sprintf(out, "%f",objTT.fSurPerAmt);		
					break;
				case StructTTUB::SURCASHADVRECIPE:														
					out = &objTT.cSurCashAdvRecipe;		
					break;
				case StructTTUB::SURCASHADVFIXAMT:														
					sprintf(out, "%f",objTT.fSurCashAdvFixAmt);		
					break;
				case StructTTUB::SURCASHADVPERCENT:														
					sprintf(out, "%f",objTT.fSurCashAdvPercent);		
					break;
				case StructTTUB::WORKINGDAYS:														
					out = &objTT.cWorkingDays;		
					break;
				case StructTTUB::GRACEPERIOD:														
					out = &objTT.cGracePeriod;		
					break;
				case StructTTUB::PENDEFAULT:														
					sprintf(out, "%f",objTT.fPenDefault);		
					break;
				case StructTTUB::PENDELAY:														
					sprintf(out, "%f",objTT.fPenDelay);		
					break;
				case StructTTUB::TOTALPENPERCENT:														
					sprintf(out, "%f",objTT.fTotalPenPercent);		
					break;
				case StructTTUB::MESHARERCPCOMM:														
					out = &objTT.cMeshareRCPComm;		
					break;
				case StructTTUB::MESHAREFIXCM:														
					sprintf(out, "%f",objTT.fMeShareFixCm);		
					break;
				case StructTTUB::MESHAREPCCM:														
					sprintf(out, "%f",objTT.fMeSharePcCm);		
					break;
				case StructTTUB::MESHARERCPSUR:														
					out = &objTT.cMeshareRCPSur;		
					break;
				case StructTTUB::MESHAREFIXSUR:														
					sprintf(out, "%f",objTT.fMeShareFixSur);		
					break;
				case StructTTUB::MESHAREPCSUR:														
					sprintf(out, "%f",objTT.fMeSharePcSur);		
					break;
				case StructTTUB::MESHARERCPSCA:														
					out = &objTT.cMeshareRCPSCA;		
					break;
				case StructTTUB::MESHAREFIXSCA:														
					sprintf(out, "%f",objTT.fMeShareFixSca);		
					break;
				case StructTTUB::MESHAREPCSCA:														
					sprintf(out, "%f",objTT.fMeSharePcSca);		
					break;
				case StructTTUB::PESHARERCPSUR:														
					out = &objTT.cPeshareRCPSur;		
					break;
				case StructTTUB::PESHAREFIXSUR:														
					sprintf(out, "%f",objTT.fPeShareFixSur);		
					break;
				case StructTTUB::PESHAREPCSUR:														
					sprintf(out, "%f",objTT.fPeSharePcSur);		
					break;
				case StructTTUB::PESHARERCPSCA:														
					out = &objTT.cPeshareRCPSCA;		
					break;
				case StructTTUB::PESHAREFIXSCA:														
					sprintf(out, "%f",objTT.fPeShareFixSca);		
					break;
				case StructTTUB::PESHAREPCSCA:														
					sprintf(out, "%f",objTT.fPeSharePcSca);		
					break;
				case StructTTUB::PETCOCODE:														
					out = objTT.acPETCOCode;		
					break;
				case StructTTUB::MESETCCCDCC:														
					sprintf(out, "%f",objTT.fMeSetCccDcc);		
					break;
				case StructTTUB::RAWAMOUNT1:														
					sprintf(out, "%lf",objTT.dRawAmount1);		
					break;
				case StructTTUB::RAWAMOUNT2:														
					sprintf(out, "%lf",objTT.dRawAmount2);		
					break;
				case StructTTUB::DCCLOCALAMT:														
					sprintf(out, "%lf",objTT.dDCCLocalAmt);		
					break;
				case StructTTUB::BASELINECOMMPRCNT:														
					sprintf(out, "%f",objTT.fBaselineCommPrcnt);		
					break;
				case StructTTUB::COMMADONPRCNT:														
					sprintf(out, "%f",objTT.fCommADONPrcnt);		
					break;
				case StructTTUB::COMMTOTALPRCNT:														
					sprintf(out, "%f",objTT.fCommTotalPrcnt);		
					break;
				case StructTTUB::CODE:														
					out = &objTT.cCDCode;		
					break;
				case StructTTUB::HCURRCODE :														
					out = objTT.acCHCurrCode;		
					break;
				case StructTTUB::MEPAYCURRCODE :														
					out = objTT.acMepayCurrCode;		
					break;
				case StructTTUB::CHCYINR:														
					sprintf(out, "%f",objTT.fCHCYInr);		
					break;
				case StructTTUB::MECYINR:														
					sprintf(out, "%f",objTT.fMECYInr);		
					break;
				case StructTTUB::CHCYMAINCHARGE:														
					sprintf(out, "%lf",objTT.dCHCYMainCharge);		
					break;
				case StructTTUB::CHCYTIPS:														
					sprintf(out, "%lf",objTT.dCHCYTips);		
					break;
				case StructTTUB::CHCYADJ:														
					sprintf(out, "%lf",objTT.dCHCYAdj);		
					break;
				case StructTTUB::CHCYCASHADVNC:														
					sprintf(out, "%lf",objTT.dCHCYCashAdvnc);		
					break;
				case StructTTUB::CHCYGROSSAMT:														
					sprintf(out, "%lf",objTT.dCHCYGrossAmt);		
					break;
				case StructTTUB::INRMAINCHARGE:														
					sprintf(out, "%lf",objTT.dINRMainCharge);		
					break;
				case StructTTUB::INRTIPS:														
					sprintf(out, "%lf",objTT.dINRTips);		
					break;
				case StructTTUB::INRADJ:														
					sprintf(out, "%lf",objTT.dINRAdj);		
					break;
				case StructTTUB::INRCASHADV:														
					sprintf(out, "%lf",objTT.dINRCashAdv);		
					break;
				case StructTTUB::INRGROSSAMT:														
					sprintf(out, "%lf",objTT.dINRGrossAmt);		
					break;
				case StructTTUB::INRGROSSAMTNW:														
					sprintf(out, "%lf",objTT.dINRGrossAmtNW);		
					break;
				case StructTTUB::INRSURNW:														
					sprintf(out, "%lf",objTT.dINRSurNW);		
					break;
				case StructTTUB::INRSCANW:														
					sprintf(out, "%lf",objTT.dINRScaNW);		
					break;
				case StructTTUB::INRSERVTAXNW:														
					sprintf(out, "%lf",objTT.dINRServTaxNW);		
					break;
				case StructTTUB::INRNWR:														
					sprintf(out, "%lf",objTT.dINRNwr);		
					break;
				case StructTTUB::RECSMSINR:														
					sprintf(out, "%lf",objTT.dRecSMSInr);		
					break;
				case StructTTUB::RECDMSINR:														
					sprintf(out, "%lf",objTT.dRecDMSInr);		
					break;
				case StructTTUB::HCYCURRCODE:														
					out = objTT.acCHCYCurrCode;		
					break;
				case StructTTUB::RECAMTOGUPLOAD:														
					sprintf(out, "%lf",objTT.dRecAmtOGUpload);		
					break;
				case StructTTUB::RECSMS324:														
					sprintf(out, "%lf",objTT.dRecSMS324);		
					break;
				case StructTTUB::RECDMSOGUPLOAD:														
					sprintf(out, "%lf",objTT.dRecDMSOGUpload);		
					break;
				case StructTTUB::GROSSAMT:														
					sprintf(out, "%lf",objTT.dGrossAmt);		
					break;
				case StructTTUB::COMM:														
					sprintf(out, "%lf",objTT.dComm);		
					break;
				case StructTTUB::PENALTY:														
					sprintf(out, "%lf",objTT.dPenalty);		
					break;
				case StructTTUB::SERVTAX:														
					sprintf(out, "%lf",objTT.dServTax);		
					break;
				case StructTTUB::MESHARECOMM:														
					sprintf(out, "%lf",objTT.dMeShareComm);		
					break;
				case StructTTUB::MESHARESURCHARGE:														
					sprintf(out, "%lf",objTT.dMeShareSurcharge);		
					break;
				case StructTTUB::MESHARESCA:														
					sprintf(out, "%lf",objTT.dMeShareSCA);		
					break;
				case StructTTUB::POSRENT:														
					sprintf(out, "%lf",objTT.dPosRent);		
					break;
				case StructTTUB::RENTADVADJ:														
					sprintf(out, "%lf",objTT.dRentAdvAdj);		
					break;
				case StructTTUB::ADHOCPAYME:														
					sprintf(out, "%lf",objTT.dAdhocPayMe);		
					break;
				case StructTTUB::ADHOCRECME:														
					sprintf(out, "%lf",objTT.dAdhocRecMe);		
					break;
				case StructTTUB::SERVTAXONADHOCREC:														
					sprintf(out, "%lf",objTT.dServTaxOnAdhocRec);		
					break;
				case StructTTUB::MEPAYABLE:														
					sprintf(out, "%lf",objTT.dMePayable);		
					break;
				case StructTTUB::MEPAYABLEININR:														
					sprintf(out, "%lf",objTT.dMePayableInINR);		
					break;
				case StructTTUB::MEPAYABLEINMECY:														
					sprintf(out, "%lf",objTT.dMePayableInMECY);		
					break;
				case StructTTUB::MEPAYABLETOMECY:														
					sprintf(out, "%lf",objTT.dMePayableToMECY);		
					break;
				case StructTTUB::PETCOSURAMT:														
					sprintf(out, "%lf",objTT.dPetCoSurAmt);		
					break;
				case StructTTUB::PETCOSCHRGCASHADVAMT:														
					sprintf(out, "%lf",objTT.dPetCoSChrgCashAdvAmt);		
					break;
				case StructTTUB::PETCOPAYABLE:														
					sprintf(out, "%lf",objTT.dPetcoPayable);		
					break;
				case StructTTUB::BASELINECOMM:														
					sprintf(out, "%lf",objTT.dBaselineComm);		
					break;
				case StructTTUB::FEERATE:														
					sprintf(out, "%lf",objTT.dFeeRate);		
					break;
				case StructTTUB::FIXEDFEEAMOUNT:														
					sprintf(out, "%f",objTT.fFixedFeeAmount);		
					break;
				case StructTTUB::FEEPLANIND:														
					out = &objTT.cFeePlanInd;		
					break;
				case StructTTUB::STCURRCODE:														
					out = objTT.acSTCurrCode;		
					break;
				case StructTTUB::STCYINRCONVRATE:														
					sprintf(out, "%f",objTT.fStcyInrConvRate);		
					break;
				case StructTTUB::STSMSPORTIONINCHCY:														
					sprintf(out, "%lf",objTT.dSTSmsPortionInChcy);		
					break;
				case StructTTUB::STDMSPORTIONINCHCY:														
					sprintf(out, "%lf",objTT.dSTDmsPortionInChcy);		
					break;
				case StructTTUB::STRECSMSPORTIONINSTCY:														
					sprintf(out, "%lf",objTT.dSTRecSmsPortionInStcy);		
					break;
				case StructTTUB::STRECDMSPORTIONINSTCY:														
					sprintf(out, "%lf",objTT.dSTRecDmsPortionInStcy);		
					break;
				case StructTTUB::SMSPORTIONFLG:														
					out = &objTT.cSmsPortionFlg;		
					break;
				case StructTTUB::MSPORTIONFLG:														
					out = &objTT.cDmsPortionFlg;		
					break;
				case StructTTUB::DMSFORECASTFEES:														
					sprintf(out, "%lf",objTT.dDmsForecastFees);		
					break;
				case StructTTUB::DMSPRORATEDFEES:														
					sprintf(out, "%lf",objTT.dDmsProratedFees);		
					break;
				case StructTTUB::VISADMSFEESDIFF:														
					sprintf(out, "%lf",objTT.dVisaDmsFeesDiff);		
					break;
				case StructTTUB::DMSACTUALFEES:														
					sprintf(out, "%lf",objTT.dDmsActualFees);		
					break;
				case StructTTUB::SMSACTUALFEES:														
					sprintf(out, "%lf",objTT.dSmsActualFees);		
					break;
				case StructTTUB::RRN:														
					out = objTT.acRRN;		
					break;
				case StructTTUB::DCCLOCALAMT1:														
					sprintf(out, "%lf",objTT.dDcclocalAmt1);	
					break;
				case StructTTUB::SERVCD:														
					out = objTT.acServcd;		
					break;
				case StructTTUB::TXNLCID:														
					out = objTT.acTxnlcId;		
					break;
				case StructTTUB::ACTION :														
					out = objTT.acAction;		
					break;
				case StructTTUB::NWREGIONISSUER:														
					out = objTT.acNwRegionIssuer;		
					break;
				case StructTTUB::NWREGIONACQUIRER  :														
					out = objTT.acNwRegionAcquirer;		
					break;
				case StructTTUB::MENAME0:														
					out = objTT.acMeName;		
					break;
				case StructTTUB::ACCTERMIN:														
					out = &objTT.cAcctermin;		
					break;
				case StructTTUB::ACQID:														
					out = objTT.acAcqId;		
					break;
				case StructTTUB::TXNORGID:														
					out = objTT.acTxnorgid;		
					break;
				case StructTTUB::RDCNTY:														
					out = objTT.acCrdcnty;		
					break;
				case StructTTUB::ARN:														
					out = objTT.acARN;		
					break;
				case StructTTUB::INTCHGRATEDESG:														
					out = objTT.acIntchgratedesg;		
					break;
				case StructTTUB::HRGBKREASON:														
					out = objTT.acChrgbkreason;		
					break;
				case StructTTUB::NOOFCHRGBK:														
					out = objTT.acNumofchrgbk;		
					break;
				case StructTTUB::PANENTRYMODE:														
					out = objTT.acPanEntryMode;		
					break;
				case StructTTUB::POICURRCODE:														
					out = objTT.acPoicurrcode;		
					break;
				case StructTTUB::POICURREXP:														
					out = objTT.acPoicurrexp;		
					break;
				case StructTTUB::CVDFLD:														
					out = objTT.acC0cvdfld;		
					break;
				case StructTTUB::MERCHVERIVAL:														
					out = objTT.acMerchverival;		
					break;
				case StructTTUB::TMUTILFLG:														
					out = &objTT.cTmUtilflg;		
					break;
				case StructTTUB::POSDATACODE:														
					out = objTT.acPosDataCode;		
					break;
				case StructTTUB::PURCHASEIDFORMAT:														
					out = &objTT.cPurchaseIdFormat;		
					break;
				case StructTTUB::PURCHASEID5:														
					out = objTT.acPurchaseId;		
					break;
				case StructTTUB::AUTHCURRCODE:														
					out = objTT.acAuthCurrCode;		
					break;
				case StructTTUB::B5ISSATHDTRESPCDE :														
					out = objTT.acB5IssathdtRespCde;		
					break;
				case StructTTUB::AUTHCHRCTSIND:														
					out = &objTT.cAuthChrctsInd;		
					break;
				case StructTTUB::TERMCAPABILITYIND:														
					out = &objTT.cTermCapabilityInd;		
					break;
				case StructTTUB::FEEPROGIND:														
					out = objTT.acFeeProgInd;		
					break;
				case StructTTUB::SRVCDEVFIELD:														
					out = &objTT.cSrvcDevField;		
					break;
				case StructTTUB::AVSRESPCODE:														
					out = &objTT.cAvsRespCode;		
					break;
				case StructTTUB::ACCNTSELCTN:														
					out = &objTT.cAccntSelctn;		
					break;
				case StructTTUB::POSENV:														
					out = &objTT.cPosEnv;		
					break;
				case StructTTUB::MLTPLCLRNGSEQNO :														
					out = objTT.acMltplClrngSeqNum;		
					break;
				case StructTTUB::MLTPLCLRNGSEQCNT :														
					out = objTT.acMltplClrngSeqCnt;		
					break;
				case StructTTUB::RESPCODE:														
					out = objTT.acRespCode;		
					break;
				case StructTTUB::AUTHDATAIND:														
					out = &objTT.cAuthDataInd;		
					break;
				case StructTTUB::ECOMMGOODSIND:														
					out = objTT.acEcommGoodsInd;		
					break;
				case StructTTUB::PRODUCTID:														
					out = objTT.acProductId;		
					break;
				case StructTTUB::PROGRAMID:														
					out = objTT.acProgramId;		
					break;
				case StructTTUB::CVV2RESULTCODE:														
					out = &objTT.cCvv2ResultCode;		
					break;
				case StructTTUB::B4TERMENTRYCAP:														
					out = &objTT.cB4TermEntryCap;		
					break;
				case StructTTUB::B2TRANTYPE:														
					out = objTT.acB2TranType;		
					break;
				case StructTTUB::B2TRANDT:														
					out = objTT.acB2TranDate;		
					break;
				case StructTTUB::B3EMVTERMCAP:														
					out = objTT.acB3EmvTermCap;		
					break;
				case StructTTUB::B2TRANENTRYCDE:														
					out = objTT.acB2TranEntryCde;		
					break;
				case StructTTUB::B3TERMSRLNO:														
					out = objTT.acB3TermSrlNum;		
					break;
				case StructTTUB::B2UNPREDICTNO:														
					out = objTT.acB2UnpredictNum;		
					break;
				case StructTTUB::B2ATC:														
					out = objTT.acB2Atc;		
					break;
				case StructTTUB::B2A1P:														
					out = objTT.acB2A1p;		
					break;
				case StructTTUB::B2ARQC:														
					out = objTT.acB2Arqc;		
					break;
				case StructTTUB::B2ISSAPPDATA0:														
					out = objTT.acB2IssAppData;		
					break;
				case StructTTUB::B2TVR:														
					out = objTT.acB2Tvr;		
					break;
				case StructTTUB::B2AMTAUTH:														
					sprintf(out, "%lf",objTT.dB2AmtAuth);		
					break;
				case StructTTUB::B6ISSSCRDATA0:														
					out = objTT.acB6IssScrData;		
					break;
				case StructTTUB::B2CRYPTOINFODATA:														
					out = objTT.acB2CryptoInfoData;		
					break;
				case StructTTUB::B2TERMCRNCYCDE:														
					out = objTT.acB2TermCrncyCde;		
					break;
				case StructTTUB::B2AMTOTHER:														
					sprintf(out, "%lf",objTT.dB2AmtOther);		
					break;
				case StructTTUB::B3CVMRSLTS:														
					out = objTT.acB3CvmRslts;		
					break;
				case StructTTUB::B3EMVTERMTYPE:														
					out = objTT.acB3EmvTermType;		
					break;
				case StructTTUB::B3NAME2:														
					out = objTT.acB3Name;		
					break;
				case StructTTUB::B3APPLVERNO:														
					out = objTT.acB3ApplVerNum;		
					break;
				case StructTTUB::B5ISSATHDTADDDATA:														
					out = objTT.acB5IssathdtAddData;		
					break;
				case StructTTUB::VISAID:														
					out = objTT.acVisaId;		
					break;
				case StructTTUB::RUPAYSETBIN:														
					out = objTT.acRupaySetBin;		
					break;
				case StructTTUB::INERSICA:														
					out = objTT.acDinersICA;		
					break;
				case StructTTUB::TRANSACTIONCODE:														
					out = objTT.acTransactionCode;		
					break;
				case StructTTUB::MECITY:														
					out = objTT.acMECity;		
					break;
				case StructTTUB::MECOUNTRY:														
					out = objTT.acMECountry;		
					break;
				case StructTTUB::MEZIP:														
					out = objTT.acMEZip;		
					break;
				case StructTTUB::MESTATE:														
					out = objTT.acMEState;		
					break;
				case StructTTUB::POSTERMINALCAPABILITY:														
					out = &objTT.cPosTerminalCapability;		
					break;
				case StructTTUB::ARDHOLDERIDMETHOD:														
					out = objTT.acCardholderIDMethod;		
					break;
				case StructTTUB::COLLECTIONONLYFLAG:														
					out = &objTT.cCollectionOnlyFlag;		
					break;
				case StructTTUB::POSENTRYMODE:														
					out = objTT.acPOSEntryMode;		
					break;
				case StructTTUB::REIMBURSEMENTATTRIBUTE:														
					out = &objTT.cReimbursementAttribute;		
					break;
				case StructTTUB::FEEPROGRAMINDICATOR:														
					out = objTT.acFeeProgramIndicator;		
					break;
				case StructTTUB::MOTOIND:														
					out = &objTT.cMOTOIND;		
					break;
				case StructTTUB::CASHBACKAMT:														
					sprintf(out, "%lf",objTT.dCashBackAmt);		
					break;
				case StructTTUB::POSENVIRONMENT:														
					out = &objTT.cPOSEnvironment;		
					break;
				case StructTTUB::PROCESSINGCODE:														
					out = objTT.acProcessingCode;		
					break;
				case StructTTUB::POSDATACODE1:														
					out = objTT.acPOSDataCode;		
					break;
				case StructTTUB::UNCCODE:														
					out = objTT.acFuncCode;		
					break;
				case StructTTUB::TERMTYPE:														
					out = objTT.acTermType;		
					break;
				case StructTTUB::ECOMMSECLEVIND:														
					out = objTT.acECommSecLevInd;		
					break;
				case StructTTUB::SCURREXP:														
					sprintf(out, "%d",objTT.sCurrExp);		
					break;
				case StructTTUB::TERMCOMPIND:														
					out = objTT.acTermCompInd;		
					break;
				case StructTTUB::AMTADD:														
					sprintf(out, "%lf",objTT.dAmtAdd);		
					break;
				case StructTTUB::TRANLCYCLEID:														
					out = objTT.acTranLCycleID;		
					break;
				case StructTTUB::MSGNO:														
					out = objTT.acMsgNum;		
					break;
				case StructTTUB::DATETYPE:														
					out = objTT.acDateType;		
					break;
				case StructTTUB::HARGETYPE:														
					out = objTT.acChargeType;		
					break;
				case StructTTUB::MEADDRESS5:														
					out = objTT.acMEAddress;		
					break;
				case StructTTUB::CRDHOLDERPRESIND:														
					out = &objTT.cCrdHolderPresInd;		
					break;
				case StructTTUB::CRDPRESENTIND:														
					out = &objTT.cCrdPresentInd;		
					break;
				case StructTTUB::CRDINPDATAMETHOD:														
					out = &objTT.cCrdInpDataMethod;		
					break;
				case StructTTUB::CRDDATAINPCAPIND:														
					out = &objTT.cCrdDataInpCapInd;		
					break;
				case StructTTUB::HGDTTIME:														
					out = objTT.acChgDtTime;		
					break;
				case StructTTUB::ECOMFLAG :														
					out = &objTT.cEcomFlag;		
					break;
				case StructTTUB::LNISSR:														
					out = objTT.acLniSsr;		
					break;
				case StructTTUB::POSCONDCD:														
					out = objTT.acPosCondCd;		
					break;
				case StructTTUB::PASSENGERNAME0:														
					out = objTT.acPassengerName;		
					break;
				case StructTTUB::DEPARTDT:														
					out = objTT.acDepartDate;		
					break;
				case StructTTUB::PASSENGERTCKNO :														
					out = objTT.acPassengerTckNum;		
					break;
				case StructTTUB::TRAVELAGENCYCODE :														
					out = objTT.acTravelAgencyCode;		
					break;
				case StructTTUB::POSAGENTNAME5:														
					out = objTT.acPOSAgentName;		
					break;
				case StructTTUB::ISSUEDT:														
					out = objTT.acIssueDate;		
					break;
				case StructTTUB::FARETAILERID:														
					out = objTT.acFaRetailerId;		
					break;
				case StructTTUB::FAISO:														
					out = objTT.acFaISO;		
					break;
				case StructTTUB::FAMEID:														
					out = objTT.acFaMeid;		
					break;
				case StructTTUB::SAGINGDAYS:														
					sprintf(out, "%d",objTT.sAgingDays);		
					break;
				case StructTTUB::INDEPENDENTSALEORGID:														
					out = objTT.acIndependentSaleOrgId;		
					break;
				case StructTTUB::SUBMERCHANTID:														
					out = objTT.acSubMerchantId;		
					break;
				case StructTTUB::PAYMENTFACILITORNAME:														
					out = objTT.acPaymentFacilitorname;		
					break;
				case StructTTUB::SUBMENAME2:														
					out = objTT.acSubMEName;		
					break;
				case StructTTUB::SUBMESTREETADRR5:														
					out = objTT.acSubMEStreetAdrr;		
					break;
				case StructTTUB::SUBMECITY:														
					out = objTT.acSubMECity;		
					break;
				case StructTTUB::SUBMESTATE:														
					out = objTT.acSubMEState;		
					break;
				case StructTTUB::SUBMECOUNTRYCODE:														
					out = objTT.acSubMECountryCode;		
					break;
				case StructTTUB::SUBMEPOSCOUNTRYCODE:														
					out = objTT.acSubMEPosCountryCode;		
					break;
				case StructTTUB::SUBMEPOSPOSTALCODE:														
					out = objTT.acSUbMEPosPostalCode;		
					break;
				case StructTTUB::SUBMEMCC:														
					out = objTT.acSubMEMCC;		
					break;
				case StructTTUB::ORIGINATOR1:														
					out = &objTT.cOriginator1;		
					break;
				case StructTTUB::TRANID:														
					out = objTT.acTranId;		
					break;
				case StructTTUB::TRACEID:														
					out = objTT.acTraceId;		
					break;
				case StructTTUB::VFGK5:														
					out = objTT.acVFGK;		
					break;
				case StructTTUB::OGUPLOADDT:														
					out = objTT.acOGUploadDt;		
					break;
				case StructTTUB::HOLDTAGDMS:														
					out = &objTT.cHoldTagDms;		
					break;
				case StructTTUB::SROTATIONNODMS:														
					sprintf(out, "%d",objTT.sRotationNumDms);		
					break;
				case StructTTUB::HOLDTAGSMS:														
					out = &objTT.cHoldTagSms;		
					break;
				case StructTTUB::SROTATIONNOSMS:														
					sprintf(out, "%d",objTT.sRotationNumSms);		
					break;
				case StructTTUB::TXNSTEPFLG:														
					out = objTT.acTxnStepFlg;		
					break;
				case StructTTUB::ROOTDS:														
					out = objTT.acRootDS;		
					break;
				case StructTTUB::ROOTPROCDT:														
					out = objTT.acRootProcDate;		
					break;
				case StructTTUB::STT211:														
					sprintf(out, "%d",objTT.sTT211);		
					break;
				case StructTTUB::STT212:														
					sprintf(out, "%d",objTT.sTT212);		
					break;
				case StructTTUB::STT213:														
					sprintf(out, "%d",objTT.sTT213);		
					break;
				case StructTTUB::STT214:														
					sprintf(out, "%d",objTT.sTT214);		
					break;
				case StructTTUB::STT215:														
					sprintf(out, "%d",objTT.sTT215);		
					break;
				case StructTTUB::STT216:														
					sprintf(out, "%d",objTT.sTT216);		
					break;
				case StructTTUB::STT217:														
					sprintf(out, "%d",objTT.sTT217);		
					break;
				case StructTTUB::MEDUEDT:														
					out = objTT.acMeDueDate;		
					break;
				case StructTTUB::DUPSEQ2:														
					out = &objTT.cDupSeq2;		
					break;
				case StructTTUB::BSACODE:														
					out = objTT.acBsaCode;		
					break;
				case StructTTUB::MTI:														
					out = objTT.acMti;		
					break;
				case StructTTUB::CABTYPE:														
					out = &objTT.cCabType;		
					break;
				case StructTTUB::PRODUCTCLASS:														
					out = objTT.acProductClass;		
					break;
				case StructTTUB::CHCYTOTALGROSSAMT:														
					sprintf(out, "%lf",objTT.dCHCYTotalGrossAmt);		
					break;
				case StructTTUB::CHCYCOMM:														
					sprintf(out, "%lf",objTT.dCHCYComm);		
					break;
				case StructTTUB::CHCYPENALTY:														
					sprintf(out, "%lf",objTT.dCHCYPenalty);		
					break;
				case StructTTUB::CHCYSERVTAX:														
					sprintf(out, "%lf",objTT.dCHCYServTax);		
					break;
				case StructTTUB::CHCYPOSRENT:														
					sprintf(out, "%lf",objTT.dCHCYPosRent);		
					break;
				case StructTTUB::CHCYRENTADVADJ:														
					sprintf(out, "%lf",objTT.dCHCYRentAdvAdj);		
					break;
				case StructTTUB::MECYCOMM:														
					sprintf(out, "%lf",objTT.dMECYComm);		
					break;
				case StructTTUB::MECYPENALTY:														
					sprintf(out, "%lf",objTT.dMECYPenalty);		
					break;
				case StructTTUB::MECYSERVTAX:														
					sprintf(out, "%lf",objTT.dMECYServTax);		
					break;
				case StructTTUB::MECYPOSRENT:														
					sprintf(out, "%lf",objTT.dMECYPosRent);		
					break;
				case StructTTUB::MECYRENTADVADJ:														
					sprintf(out, "%lf",objTT.dMECYRentAdvAdj);		
					break;
				case StructTTUB::MECYMAINCHARGE:														
					sprintf(out, "%lf",objTT.dMECYMainCharge);		
					break;
				case StructTTUB::MECYTIPS:														
					sprintf(out, "%lf",objTT.dMECYTips);		
					break;
				case StructTTUB::MECYADJ:														
					sprintf(out, "%lf",objTT.dMECYAdj);		
					break;
				case StructTTUB::MECYCASHADVNC:														
					sprintf(out, "%lf",objTT.dMECYCashAdvnc);		
					break;
				case StructTTUB::IDEFFEREDDAYS:														
					sprintf(out, "%d",objTT.iDefferedDays);		
					break;
				case StructTTUB::ACFILLER3:														
					out = objTT.acFiller3;		
					break;
				case StructTTUB::GRPDESC0:														
					out = objTT.acGrpDesc;		
					break;
				case StructTTUB::BATCHSTATUS:														
					out = &objTT.cBatchStatus;		
					break;
				case StructTTUB::RATETYPE:														
					out = &objTT.cRateType;		
					break;
				case StructTTUB::LUNIQID:														
					sprintf(out, "%lf",objTT.lUniqId);		
					break;
				case StructTTUB::SETTLEDT:														
					out = objTT.acSettleDt;		
					break;
				case StructTTUB::ISEQBATCHNO:														
					sprintf(out, "%d",objTT.iSeqBatchNo);		
					break;
				case StructTTUB::SCHEMECODE:														
					out = objTT.acSchemeCode;		
					break;
				case StructTTUB::COMMREPLICA:														
					sprintf(out, "%lf",objTT.dCommReplica);		
					break;
				case StructTTUB::PENALTYREPLICA:														
					sprintf(out, "%lf",objTT.dPenaltyReplica);		
					break;
				case StructTTUB::SERVTAXREPLICA:														
					sprintf(out, "%lf",objTT.dServTaxReplica);		
					break;
				case StructTTUB::POSRENTREPLICA:														
					sprintf(out, "%lf",objTT.dPosRentReplica);		
					break;
				case StructTTUB::RENTADVADJREPLICA:														
					sprintf(out, "%lf",objTT.dRentAdvAdjReplica);		
					break;
				case StructTTUB::ADHOCRECMEREPLICA:														
					sprintf(out, "%lf",objTT.dAdhocRecMeReplica);		
					break;
				case StructTTUB::SERVTAXONADHOCRECREPLICA:														
					sprintf(out, "%lf",objTT.dServTaxOnAdhocRecReplica);	
					break;
				case StructTTUB::SEQSUB:														
					out = &objTT.cSeqSub;		
					break;
				case StructTTUB::ACEXTRAKEY0:														
					out = objTT.acExtraKey;		
					break;
				case StructTTUB::PAYHLDFLG:														
					out = &objTT.cPayHldFlg;		
					break;
				case StructTTUB::IROTATIONNO:														
					sprintf(out, "%d",objTT.iRotationNo);		
					break;
				case StructTTUB::MECYADHOCRECME:														
					sprintf(out, "%lf",objTT.dMECYAdhocRecMe);		
					break;
				case StructTTUB::MECYADHOCPAYME:														
					sprintf(out, "%lf",objTT.dMECYAdhocPayMe);		
					break;
				case StructTTUB::QR:														
					out = &objTT.cQR;		
					break;
				case StructTTUB::VIP:														
					out = &objTT.cVIP;		
					break;
				case StructTTUB::PROCKEY :														
					out = objTT.acProckey;		
					break;
				case StructTTUB::SUBCARDPRGM:														
					out = objTT.acSubCardPrgm;		
					break;

			}
			return out;
		}*/
		

};



#endif 
