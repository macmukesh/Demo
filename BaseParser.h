#ifndef BASEPARSER_H_
#define BASEPARSER_H_

#include "CommonLib.h"
#include "CommonQueueData.h"
#include "enum_ErrorCode.h"
//#include "DataParser.h"
#include "enum_FieldAttr.h"
#include "enum_ParserCd.h"

/*
ERROR FORMAT DESIGN:
3:matching failure
ELEMNO:TTCOLID:FMT MATCHING FAILURE:FMTVAL:DATA(START,NOOFBYTE)
2:datatype mismatch
ELEMNO:TTCOLID:DATATYPE MISMATCH:DATATYPE:acTrimData/acTransformedData
1:buffer overflow
ELEMNO:TTCOLID:BUFFER OVERFLOW:ACTUAL_LENGTH:acInpData 
*/

typedef struct
{
		short int iStart;
		short int iNoOfBytes;
		FMTATTR enFmtVal;								// A=alphanumeric,B=alphabet,C=numeric
		StructTTUB::TTCOL iOutColId;		// col id of common data struct
		string strElemNm;								// element name ..for writing only
}FC;

typedef struct
{
		string strParserNm;				// name of parser..for writing only
		short int iNoOfFields;		// no of fields
		PARSERCD iParserCd;				// parser code	
		vector<FC> vecFC;					// array of FC 
}PC;

class BaseParser
{
	public:	
					BaseParser();
					~BaseParser();
					void Init();

	protected:
					static const unsigned int iMaxParsercd=10;
					// hdr/trl format
					virtual void SetHdrFormat(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &)=0;
					virtual void SetTrlFormat(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &)=0;
					// there can be 5 data format
					virtual void SetD1Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &)=0;
					virtual void SetD2Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &)=0;
					virtual void SetD3Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &)=0;
					virtual void SetD4Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &)=0;
					virtual void SetD5Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &)=0;		

					bool ParseDataIntoStruct(char *,const size_t ,const unsigned int ,Model &,stringstream &);
	private:
					vector<PC> vecParserFormat;					// store multiple parsercd	
					typedef void (BaseParser::*PARSEFMT)(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &);
					static const int iMaxTempSz=1048;
					char  acTrimData[iMaxTempSz];
					char  acTransFormData[iMaxTempSz];
					ofstream foutReject;

					void LoadParserDetail(int ipcd=0);
					bool ValidateData(char * rawdata,const int &,const int &,const FMTATTR &,char*,unsigned int &);
					string GetEnumFmtValName(const FMTATTR &);
					string GetSrcString(const char *,int );
};

#endif /* BASEPARSER_H_ */
