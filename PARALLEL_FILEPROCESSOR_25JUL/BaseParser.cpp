#include "BaseParser.h"

BaseParser::BaseParser()
{
	cout<<"Base called:"<<endl;
}

BaseParser::~BaseParser()
{
		//closing file streams
		foutReject.clear();
		foutReject.close();
}

void BaseParser::Init()
{

	// load parser detail
	LoadParserDetail();

	memset(acTrimData,0x00,sizeof(acTrimData));
	memset(acTransFormData,0x00,sizeof(acTransFormData));

	// prepare filenm
	string fileName="./Reject.txt";
	// open reject file
	foutReject.open(fileName.c_str() ,ofstream::app);
	if(foutReject.is_open())
	{
	}
	else
	{
			// cannot open reject file ...throw error
			cout<<"FREJ FILENM:"<<fileName<<endl;
			throw runtime_error("ERROR WHILE OPENING REJECT FILE"); 
	}
}
bool BaseParser::ParseDataIntoStruct(char * data,const size_t rawsize,const unsigned int pcd,Model & ObjOut,stringstream & errdesc)
{
		if(pcd==INVALID_PARSERCODE)
		return false;

		int errcd=0;
		FC * ptrFC=NULL;
		// set pointer as per parsercd
		PC * ptrPC=&vecParserFormat[pcd];
		StructTTUB::TTCOL  colid;
		unsigned int iOutSz=0;
		int iErrCd=0;			// default success
		int iErrVal=0;		// hold value of err returned by ttmodel
		char * ptrSrc=NULL;		// point to valid array: trimdata/transformeddata

		// enter loop to start parsing data		
		for(int ix=0;ix<ptrPC->iNoOfFields;++ix)		
		{
				// skip in case of no output
				if(!ptrPC->vecFC[ix].iOutColId)
				continue;

				// go for parsing
				// fetch field column
				ptrFC=&ptrPC->vecFC[ix];
				// reset outsz to 0
				iOutSz=0;
				// S1:validate data as per format..return false when matching failure
				iErrCd=ValidateData(data,ptrFC->iStart,ptrFC->iNoOfBytes,ptrFC->enFmtVal,acTrimData,iOutSz);
				if(!iErrCd)
				{
					acTransFormData[0]='\0';	
					// S2:check if any decode implementation in derived..
					//TransformCol(acTrimData,ptrFC->iOutColId,acTransFormData);
					// if decode implementation is defined then acTransFormData will change from '\0' to some valid char..this wll be output
					ptrSrc=acTrimData;
					if(acTransFormData[0]!='\0')
					{
						// recalculate size of tranformed data
						iOutSz=strlen(acTransFormData);
						ptrSrc=acTransFormData;
					}

					// S3: store in output coldata...return error only when overflow/datatype failure
					iErrCd=ObjOut.SetData(ptrFC->iOutColId,ptrSrc,iOutSz,iErrVal);					
				}
				else
				{
					// matching failure..error code
					iErrCd=3;			
				}
	
				// errcd is 0...means success..go for next col parsing
				if(!iErrCd)
				continue;

				// error handling
				switch(iErrCd)
				{
					case 1:
									// buffer overflow..returned by TTMODEL...iErrVal contain ACTUAL LENGTH OF TTCOL
									errdesc<<ptrPC->strParserNm<<":"<<ptrFC->strElemNm<<":"<<"BUFFER OVERFLOW"<<":"<<iErrVal<<":"<<ptrSrc;
									break;
					case 2:
									// datatype mismatch..returned by TTMODEL...iErrVal contain DATATYPE OF TTCOL
									errdesc<<ptrPC->strParserNm<<":"<<ptrFC->strElemNm<<":"<<"DATATYPE MISMATCH"<<":"<<ObjOut.GetEnumDataTypeName(iErrVal)<<":"<<ptrSrc;
									break;
					case 3:
									// matching failure..returned by self...iErrVal contain FORMATVAL OF PARSERCOLUMN
									errdesc<<ptrPC->strParserNm<<":"<<ptrFC->strElemNm<<":"<<"MATCHING FAILURE"<<":"<<GetEnumFmtValName(ptrFC->enFmtVal)<<":"
									<<GetSrcString(data+ptrFC->iStart,ptrFC->iNoOfBytes);
									break;
				}

				// come out of loop
				return false;
		}//end of loop
		
	return true;
}

/*
Input:rawdata,start,noofbyte,validation ascii,outputmemory,sizeofmemory
*/
bool BaseParser::ValidateData(char * rawdata,const int & iStart,const int & iNoOfBytes,const FMTATTR &ifval,char * destInp,unsigned int & outcnt)
{
		char * dest=destInp;																				// dest pointer
		char * data=rawdata;																				// poit to rawdata
		char * advCurr=NULL;
		int icurr=iStart-1;	// start is always initialised by 1 but array starts from 0

		if(iNoOfBytes!=9999)
		{
				data=rawdata+icurr;							// pointer to start	
				advCurr=data+iNoOfBytes;					// pointer to end
		}else{

		}

		// left trim whitespace
		while( (data!=advCurr) && isspace(*data)!=0 && (++data));	
		
		// trim right whitespace
		while( (data!=advCurr) && isspace(*(advCurr-1))!=0 && (--advCurr) );

		// (--szDest>1) ..her check is for 1 bytes reserved for null char
		// 'A'=alphabet,'B'=numeric,'C'=alphanumeric,'D'=numeric with left trim zero,'Z'=NO CHECK..direct copy
		if(ifval==NO_CHECK)
				while( (data!=advCurr) && (dest[outcnt++]=*data++) );
		else 	if(ifval==ALPHABET)	// 
				while( (isalpha(*data)!=0) && (dest[outcnt++]=*data++) && (data!=advCurr));
		else if(ifval==NUMERIC)
				while( (isdigit(*data)!=0) && (dest[outcnt++]=*data++) && (data!=advCurr));
		else if(ifval==ALPHANUMERIC)// alphanumeric
				while( (isalnum(*data)!=0) && (dest[outcnt++]=*data++) && (data!=advCurr));
		else if(ifval==NUMERIC_LEADING_ZEROES){
				// left trim zeros
				while((*data=='0') && (++data!= advCurr) );
				while( (data!=advCurr) && (isdigit(*data)!=0) && (dest[outcnt++]=*data++));	
		}else if(ifval==HEXADECIMAL){

		}

		// check if data is not equal to end then matching failure 
		if(data!=advCurr)
		return true;

		// append null at end+1
		dest[outcnt]='\0';

		return false;
}

string BaseParser::GetEnumFmtValName(const FMTATTR & enFmt)
{
	switch(enFmt)
	{
		case ALPHABET:
									return string("ALPHABET");
		case NUMERIC:
									return string("NUMERIC");
		case ALPHANUMERIC:
									return string("ALPHANUMERIC");
		case NUMERIC_LEADING_ZEROES:
									return string("NUMERIC_LEADING_ZEROES");
		case HEXADECIMAL:
									return string("HEXADECIMAL");
		default:								
									return string("DEFAULT");
	}
}

string BaseParser::GetSrcString(const char * inp,int sz)
{
	char acOutData[sz+1];
	memcpy(acOutData,inp,sz);
	acOutData[sz+1]='\0';

	return string(acOutData);
}

void BaseParser::LoadParserDetail(int ipcd)
{
	PARSEFMT parseFunc;	// poijter to functor
	int iElemNo=-1;
	unsigned int iNoOfBytes=0;	// local noofbytes
	// FC object
	FC ObjFc;
	ObjFc.iStart=0;	// initialised to 0 as it will be used do not change

	// parsercd
	PC ObjPC;
	ObjPC.iParserCd=(PARSERCD)ipcd;

	switch(ObjPC.iParserCd)
	{
		case DATA1:
								ObjPC.strParserNm="DATA1";
								parseFunc=&BaseParser::SetD1Format;	
								break;
		case DATA2:
								ObjPC.strParserNm="DATA2";
								parseFunc=&BaseParser::SetD2Format;
								break;
		case DATA3:
								ObjPC.strParserNm="DATA3";
								parseFunc=&BaseParser::SetD3Format;
								break;
		case DATA4:
								ObjPC.strParserNm="DATA4";
								parseFunc=&BaseParser::SetD4Format;
								break;
		case DATA5:
								ObjPC.strParserNm="DATA5";
								parseFunc=&BaseParser::SetD5Format;
								break;
		case HDR:
								ObjPC.strParserNm="HDR";
								parseFunc=&BaseParser::SetHdrFormat;
								break;
		case TRL:
								ObjPC.strParserNm="TRL";
								parseFunc=&BaseParser::SetTrlFormat;
								break;
		default:		// default return
								return;
	}

	while(1){

		iNoOfBytes=0;
		// call set field function
		(this->*parseFunc)(++iElemNo,iNoOfBytes,ObjFc.enFmtVal,ObjFc.iOutColId,ObjFc.strElemNm);

		// if noofbytes=0 then come out of loop..FC end
		if(!iNoOfBytes)
		break;

		// put validation on noofbyte..it must not be greater than tempsz allocated 

		if(ObjFc.iStart!=0)
		ObjFc.iStart+=ObjFc.iNoOfBytes;		// calculate start by adding prev row's noofbytes
		else
		ObjFc.iStart=1;		// 1st element start=1

		// update noof bytes
		ObjFc.iNoOfBytes=iNoOfBytes;

		// store output
		ObjPC.vecFC.push_back(ObjFc);
	}
	// update parsercd
	ObjPC.iNoOfFields=ObjPC.vecFC.size();

	// add to vector
	vecParserFormat.push_back(ObjPC);

	// go for recursive call..
	LoadParserDetail(++ipcd);
}
