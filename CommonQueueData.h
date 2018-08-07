#ifndef _COMMON_QUEUE_DATA_H_
#define _COMMON_QUEUE_DATA_H_


#include <cstdlib>
#include "CommonMacro.h"
#include "TTModel.h"
#include "enum_ParserCd.h"

#define MAX_ROW_LEN 1000
#define MAX_FILENM_LEN	100
#define MAX_FNAME_LEN	92

#define MAX_RAWDATA_LEN 5121
#define MAX_CNTAMT_SLOT 12

typedef struct
{
	char acRawdata[MAX_RAWDATA_LEN];		// rawdata length
  unsigned short iFilecd;							// file code
	unsigned short iRowSz;							// size of row	
	unsigned short iFileno;							// out fileno
	unsigned long lTankSeq;							// out tank seqno
	PARSERCD	enParserCd;								// parsercd
	Model ObjTT;												// out struct
}ArrBufferData;	//total size=5136

typedef struct
{
	unsigned long Cnt;
	double Amt1;
	double Amt2;
}CntAmt;

typedef struct
{
	// section1: to be filled by READER
	// file lvel info fetched from file itself
	short unsigned int iQno;
	char acOrgFileNm[MAX_FNAME_LEN];			// original file name	
	char acFileNm[MAX_FILENM_LEN];				// file name without path	....from filenm ..from back till '_'
	char acFiledt[MAX_DATE_LEN+1];				// fetch file date
	short unsigned cFileFmtTyp;						// transaction formation method...
	short unsigned bFileCtrlFlg;					// fetch tally ctrl flg..true=enabled/false=disabled...total success filecnt in case of accumulation

	char cErrCode;												// if file failed then tag errorcd..by default will be null

	// fields calc by program
	size_t szFileSize;										// size of file in mb..round up to nearest total

	short unsigned iFileCd;								// unique cd for file format...total file cnt in case of accumulation 
	short unsigned iFileno;								// file no allocate by program...total reject cnt in case of accumulation
	// reader performance analysis
	short unsigned iNoOfBlockRead;				// no of block read i.e bulk read	
	short unsigned iProcTime;							// total time in millisecond
	short unsigned iProcTime2;					  // normaliser time in millisecond	
	short unsigned iProcTime3;						// diff time in millisecond

	size_t szReadSize;										// total read size

	// formula to tally reader's control 	(szFileSize=szReadSize)..this should match at end if file is fully read

	// total txn level controls
	long unsigned lRNO;										// total no of txn/record formed by reader

	// section2: to be filled by NORMALISER
	long unsigned lSuccCnt;								// success stored in output
	long unsigned lBadCnt;								// bad record stored in file
	long unsigned lDiscCnt;								// record which failed when clause

	// file level controls								
	CntAmt arrCntAmt[MAX_CNTAMT_SLOT];									// array of 12 slot

}FileInfo;	// total size as given by compiler:360


#endif
