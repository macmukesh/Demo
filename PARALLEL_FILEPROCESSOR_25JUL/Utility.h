/**********************************************************************************/
/*
   COPYRIGHT NOTICE
   Copyright @ 2015 In-Solutions Global Pvt Ltd (ISG). All rights reserved.

These materials are confidential and proprietary to In-Solutions Global Pvt Ltd (ISG) and no part of these materials should be reproduced, published, transmitted or distributed in any form or by any means, electronic, mechanical, photocopying, recording or otherwise, or stored in any information storage or retrieval system of any nature nor should the materials be disclosed to third parties or used in any other manner for which this is not authorized, without the prior express written authorization of In-Solutions Global Pvt Ltd (ISG) Pvt Ltd. */
/*                                                                 */
/****************************************************************************/
/*! \mainpage Framework
 * \section intro_sec Introduction
 *
 * Copyright (c) 2015, In-Solutions Global Pvt. Ltd.
 * All rights reserved.
 *
 * @version     v1r1
 * @author      Amul V. Mutha
 * @Location    In-Solutions Global, Mumbai
 *
 * All the functions of the library are documented inside the comments of the file Utility.cpp.
 */
/**********************************************************************
 *            Version Control Block
 *            ---------------------
 * Date              Version     Author               Description
 * ---------         --------  ---------------  ---------------------------
 * Jul 05, 2013       1.0       AMUL MUTHA           Base Version
   May 29, 2015       1.1       GAURAV KUMAR         Base Version
 **********************************************************************/

#ifndef _UTILITY_H
#define _UTILITY_H

#include "CommonLib.h"
#include <sys/time.h>
#include "CommonMacro.h"

#define MAX_LONG_DATE_LEN	10+1

class Utility
{
	public:
		int 	fnPadSpace(char inp[],int len,char *out);
		int 	fnRemoveAppendedSpaces(char acInputData[], char acOutput[]);
		void 	fnTrimSpace(char *);
		int 	fnGetTime(char acTime[]);
		int 	fnMaskCardNumber(char acCardNumber[], char acTruncatedCardNum[]);
		int 	fnSHAHashing(char acClearInput[], char acHashOutput[], char acStatusMsg[]);
		int 	fnRemoveComma(char *inputStr, char *outputStr);
		char * 	fnTrim(char * str);
		void 	fnRTrim2(char *str);
		char* 	fnLeftTrimZero(char *sSrc);
		char* 	GetFormatedDT(char *);
		char * 	GetFormatedDate(char *);
		char * 	GetSettFormatedDate(char *);
		int 	fnGetFormatedDate(char *, char *);
		void 	fnGetYYMMDD(char[], char[]);
		void 	fnGetYYMMDDCBS(char[], char[]);
		void 	currentDateTime(char *);
		double 	fnTimeDiff(timeval ,timeval );
		void 	fnLeftTrim(char *str);
		void 	fnRTrim(char *str);
		int 	fnLeftPad(char inp[],int len,char ch);
		void 	fnGetDateFormat(char*, char*);
		char*	fnStringPadRight(char*, int, char*);

		double 	roundD(double, int);
		double 	roundNS(double, char);
		double 	fnRound(double, int);

		void  	getDateNOD(char *,int,char *);
		void 	getCurDate(int,char*); 
		void 	getDay(char*,char*);
		void 	getCurryear(char *ret);
		void  	getDiff(char *date);
		void 	getJulDate(char *date, char *,char * ret);
		void  	getJulDateforMMDD(char *date,char * ret);
		void 	getJCurDate(char *ret);
		void 	getCorrectdate(char* date,char *ret);
		void	fnGetCurrentDate(char *, char*);
		void	getFormattedDate(char *sdate, char* sformat,char * ddate,char * dformat,int nod1);

		int 	fnAsciiCheck(char* date);
		char* 	fnMssfnFilter(char* date, int flag, char* out);
		bool	fnLeapYearCheck(char[]);
		int	fnDaysInMonth(char *YYMM);

		void 	fnStaysKey(char *, int, char*);
	//			void 	fnStaysKey(char *,char *,char *, int, char*);
		void	fnDateFormat(char [], char [], char []);

		int 	convtodecnum(char hex[]);
		void 	dectohex(int decimalNumber, char hexadecimalNumber[]);
		char*   fnRightPadwithzero(char inp[], int padded_len, char pad); 
		int 	fnLeftPadSpace(char inp[],int len,char *out);
		char* 	funGetDDMMYY(char [],char []);
		char* funGetFmtDate(char date[],char rev[]);
		int	fnConvertHexToDec(char *);
		int  	fnDiffBetweenDates(char *acDate1, char *acDate2);
		int	dayofweek(int d, int m, int y);
		void 	fnGetDDMMYY(char [], char []);
		char* 	StrStrRange(char *,int ,char *);
		char * fnReplaceWithCh(char* s,char ch);
		int etoa( unsigned char *,  int );//to convert EBCDIC to ASCII
		void GetFmtDate(char *p_txnDate, char *ret);
		char * trim(char* ) ;
		char * ltrim(char* ) ;
		char * rtrim(char* ) ;

		void fnCardMask(char *str);

		size_t strlcpy(char *, const char *, size_t );
		vector<string> & split(const string &, char , vector<string> &);

		int StrnCmpIgnoreCase(char *, char *,short int);
		bool checkNum(char *);
		bool fnDirectoryExists( const char*);	

		bool MoveFile(const char * filenm,char cTyp,const char * outpath, const char *,char,const char *,const char *);
};

#endif //_UTILITY_H
