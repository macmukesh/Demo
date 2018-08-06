#include "FileReader.h"

// FileReadException Code
/*****************************************************************************/
//! Function              : FileReadException
/*! Description           : Parameterized Constructor */
/*! Input Parameters      : Exception message, System message */
/*! Returns               : void */
/*****************************************************************************/
FileReadException::FileReadException(const string &message, bool inclSysMsg) throw() : userMessage(message) 
{
  	if (inclSysMsg) 
	{
		userMessage.append(": ");
		userMessage.append(strerror(errno));
	}
}

/*****************************************************************************/
//! Function              : ~FileReadException
/*! Description           : Destructor	*/
/*! Input Parameters      :		*/
/*! Returns               : void	*/
/*****************************************************************************/
FileReadException::~FileReadException() throw() 
{

}

/*****************************************************************************/
//! Function              : what
/*! Description           : Returns Exception message	*/
/*! Input Parameters      : 		*/
/*! Returns               : char *	*/
/*****************************************************************************/
const char *FileReadException::what() const throw() 
{
	return userMessage.c_str();
}

FileReader::FileReader()
{
}
FileReader::FileReader(unsigned int (*f)(const char * ,long ,bool,string & ))																											
{
		bEOF=false;
		ileftoverpos=0;
		isizeofLeftover=0;
		iNoOfBlockRead=0;

		FormLongStr=f;
}
FileReader::~FileReader()
{


}
																											
void FileReader::Open(char * filenm)
{
		bool bOpenFlg=false;
		iReadPos=0;							// pos counter of file

		fp=fopen(filenm,"r");
		if(fp!=NULL)
		bOpenFlg=true;
		else
		bOpenFlg=false;

		// throw exception if flag is false 
		if(!bOpenFlg)
		{
			string strErrorDesc=string("ERR101:FAIL TO OPEN FILE DESC:")+string(strerror(errno)+string(filenm) );
			throw FileReadException(strErrorDesc,true);
		}
}

const vector<ArrBufferData> & FileReader::GetBufferData()
{
		long lBytesRead=0;									// bytes succesful read into buf

		// clear the buffer area
		vecRowData.clear();	

		string strLongStr;
		unsigned int iNoOfLines=0;

		// read next block from file and save it into buf,right after the "left over" buffer
		lBytesRead=fread((char *)acreaddata+isizeofLeftover,1,sizeof(acreaddata)-isizeofLeftover-1, fp);	
		if(feof(fp))
		bEOF=1;
		else if(ferror(fp)){
		// error while reading in bulk from file	
		string strErrorDesc="PAF002:ERROR WHILE BULK READING FROM FILE...";				
		throw FileReadException(strErrorDesc,true);							
		}

		if(lBytesRead<0)
		{
			// some problem with read / end of 
			lBytesRead=0;
		}

		// add null terminator at end of buffer
		acreaddata[lBytesRead+isizeofLeftover] = '\0';
					
		// form long string newline separated
		ileftoverpos=FormLongStr(acreaddata,lBytesRead+isizeofLeftover,bEOF,strLongStr);
					
		// create array of rawdata...returns no of lines added to buffer
		iNoOfLines=ParseNewLineStr(strLongStr.c_str(),strLongStr.size(),vecRowData);

		// added to detect error while forming txn
		// soze of unprocessed data has to be less than or equal to input array..if greater then error
		if(ileftoverpos>(lBytesRead+isizeofLeftover))	
		{
			//ObjFileInfo.cErrCode='D';		// set proper error code
			// error while reading in bulk from file	
			string strErrorDesc="PAF003:ERROR WHILE FORMING TRANSACTION....";				
			throw FileReadException(strErrorDesc,true);		
		}

		// update read pointer
		iReadPos+=ileftoverpos;
		// read call counter
		++iNoOfBlockRead;
		// bulk read accumulate
		szReadSize+=lBytesRead;		

		// calculate leftover buf size
		// the remaining unprocessed buffer that was not processed by Process	
		isizeofLeftover=lBytesRead+isizeofLeftover-ileftoverpos;	

		// put check oon sizeofleftover
		if(isizeofLeftover<0)
		isizeofLeftover=0;
		else if(isizeofLeftover>(lBytesRead+isizeofLeftover))
		{
				string strErrorDesc="PAF004:NO SPACE LEFT ON BUFFER TO ACCOMODATE NEW LINE...LOGICAL PROBLEM IN IDENTIFYING ROW IN BUFFER";				
				throw FileReadException(strErrorDesc,true);
		}		

    // If we have a leftover unprocessed buffer, move it to the beginning of  
    // read buffer so that when reading the next block, it will connect to the 
    // current leftover and together complete a full readable line
		if(ileftoverpos!=0 && isizeofLeftover!=0) 
		memmove(acreaddata,acreaddata+ileftoverpos,isizeofLeftover);

		// return filled buffer
		return vecRowData;
}

// search for '\n' in string..input will be 
unsigned int FileReader::ParseNewLineStr(const char * rawdata,unsigned long lBufSz,vector<ArrBufferData> & vecdata)
{
		const char * curr=NULL;
		int isz=0,icnt=0;
		unsigned int currpos=0;

		while(currpos<lBufSz)
		{
			//curr=strchr(rawdata+currpos,'\n');
			curr = (char*)memchr(rawdata+currpos, '\n', lBufSz-currpos);

			// if newline not found then break..come out of loop
			if(!curr)
			break;

			isz=curr-(rawdata+currpos);

			// copy till \r
			if( *(curr-1) =='\r')
			isz-=1;
			
			// add to buffer
			AddTxnRow(rawdata+currpos,isz,vecdata);

			currpos+=curr-(rawdata+currpos);
			++currpos;	// past \n since curr point there
		}

		return currpos;
}

void FileReader::AddTxnRow(const char * data,const unsigned int irowsz,vector<ArrBufferData> & vecData)
{

	if(!irowsz)
	{
		// some problem with data..bypass such data
		return;
	}
	else if(irowsz>sizeof(ObjRowData.acRawdata))
	{
			// raise error for buffer overflow..some logical problem...throw exception here
			string strErrorDesc="PAF001:ROWSZ:"+toString(irowsz)+" IS GREATER THAN MAX LENGTH:"+toString(MAX_RAWDATA_LEN);
			throw FileReadException(strErrorDesc,true);
	}

	// prepare input
	const char * locdata=data;
	ObjRowData.iRowSz=irowsz;
	// purify input data 
	PurifyAndStoreRow(locdata,ObjRowData.acRawdata,ObjRowData.iRowSz);

	// rowdata is ready to get add in buffer
	vecRowData.push_back(ObjRowData);
	// reset class var
	ResetRow(ObjRowData);
}

void FileReader::PurifyAndStoreRow(const char * src,char * dest,unsigned short & isrclen)
{
		int ipos=isrclen+1;
		const char * s=src;
		int ichar=0;
		while((--ipos)>0)	
		{
				ichar=(int)(*s);
				if( (ichar<32) || ichar>126 )
				{
					// bypass curr char..do not store it into out
					*s++;
					// reduce size by 1 for removing each char
					--isrclen;
					continue;
				}


				*dest++=*s++;	
		}

		// append null char at end after removing char
		if(!ipos)
		*dest='\0';
}

void FileReader::ResetRow(ArrBufferData & objdata)
{
	memset(objdata.acRawdata,0x00,sizeof(objdata.acRawdata));
	objdata.iRowSz=0;
}

void FileReader::Close()
{
		if(fp!=NULL)
		fclose(fp);

		fp=NULL;
}		

