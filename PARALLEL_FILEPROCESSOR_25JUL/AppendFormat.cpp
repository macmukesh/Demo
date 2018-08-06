#include "AppendFormat.h"

AppendFormat::AppendFormat()
{

}
AppendFormat::~AppendFormat()
{

}
// append format ..search for \nXXX0..if found break
// this logic is applicable for visactf/dcf/cyber/
unsigned int AppendFormat::ParseFileTyp(const char * rawdata,long lBufSz,bool beof,string & strOut)
{
	const char * curr=NULL;
	const char * prev=NULL;
	int isz=0,itcr=0;
	unsigned int currpos_typ6=0,currpos=0;

	// set to start
	prev=rawdata;

	while(1)
	{
		curr = (char*)memchr(rawdata+currpos, '\n', lBufSz-currpos);
	
		// if newline not found then break..come out of loop
		if(!curr)
		{
			break;
		}

		currpos+=curr-(rawdata+currpos);
		++currpos;	// past \n since curr point there

		if( *(curr+4)!='0')
		{
			continue;
		}

		// special case for cyber...tcrno=0 and appcode=CP01 then only break else continue
		// NOTE: Loop will continue on following conditions
		// 1. FileCode = CYBER AND
		// 2. Record starts with "33" AND		
		// 3. Record does not consist of "CP01" at position 16 AND(Taken as 17 becuase of '\n')
		// 4. Record does not consist of "TRLR" from position 16 AND
		// 5. Record does not have '0' at positions 3 and 4
/*
		if( ObjFileInfo.iFileCd==CYBER && (!strncmp(curr+1,"33",2)) && (strncmp(curr+17,"CP01",4)!=0) && (strncmp(curr+17,"TRLR",4)!=0) 
			&& (strncmp(curr+4,"00",2)!=0)){
			continue;
		}
*/
		// for visa ctf also currency data comes in append..so break those into multiples

		isz=curr-prev;
				
		//AddTxnRow(prev,isz);
		strOut.append(prev,isz);
		strOut.append("\n");

		// update prev pointer
		prev=curr+1;

	}

	if(beof)
	{
		// check if still some data is left to be processed
		isz=(rawdata+lBufSz)-prev;
		// some remaining data then copy
		if(isz>10)
		{
		//	AddTxnRow(prev,isz);
			strOut.append(prev,isz);
		}else{
			// no lefover data 
		}
		// point to end..in case of eof
		prev=rawdata+lBufSz;
	}

	// update last curr pos
	currpos_typ6=prev-rawdata;

	return currpos_typ6;	
}

