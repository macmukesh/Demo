#include "AppendFormat.h"
#include "MPOS.h"
#include "CommonQueueData.h"
#include "AcqSwt.h"
#include "StringConv.h"
/*
Pattern Description:
Policy classes can contain implementation, type definitions and so forth. Basically, the designer of the main template class will define what the policy classes
should provide, what customization points they need to implement.It may be a delicate task to create a good set of policies, just the right number 
(e.g., the minimum necessary). The different customization points, which belong together, should go into one policy argument, such as storage policy, 
validation policy and so forth. A good rule of thumb during design is that you should be able to give a name to your policy, which represents a concept, and not one
which represent an operation or some really tiny implementation detail. Persistence policy seems to be a good choice, while how to save policy does not.

Example Description:
Presented below is a simple (contrived) example of a C++ hello world program, where the text to be printed and the method of printing it are decomposed using policies.
In this example, HelloWorld is a host class where it takes two policies, one for specifying how a message should be shown and the other for the actual message being
printed. Note that the generic implementation is in run() and therefore the code is unable to be compiled unless both policies (print and message) are provided.
*/
 
template <typename ReaderPolicy, typename ParserPolicy, typename StoragePolicy>
class FPPolicy : private ReaderPolicy, private ParserPolicy,private StoragePolicy
{
    using ReaderPolicy::ParseFileTyp;
    using ParserPolicy::Init;
    using ParserPolicy::ValidateInputRawData ;
		using ParserPolicy::IdentifyParserCd;
		using ParserPolicy::ParseDataIntoStruct;
		using StoragePolicy::EnrichData;
		using StoragePolicy::StoreRecordIntoMem;
 
public:

		FPPolicy()
		{
		}
		~FPPolicy()
		{	
		}

    // Behaviour method
    bool run(const char * filenm)
    {
				const unsigned int BLOCKREADSZ=4096;											// max buffer size
				char acreaddata[BLOCKREADSZ];															// rawdata holder
				int isizeofLeftover=0;																			// size of unprocessed data
				bool bEOF=0;
				string strLongStr;	
				unsigned long iReadPos=0;
				vector<ArrBufferData> vecRowData;			
				// filecontrol object
				FileInfo	ObjFileInfo;															

				Init();

				// openn the file
				FILE * fp=fopen(filenm,"r");
				if(!fp)
				{
						string strErrorDesc=string("ERR101:FAIL TO OPEN FILE DESC:")+string(strerror(errno)+string(filenm) );
						throw runtime_error(strErrorDesc);
				}

				// fetch filenm excluding path
				string strFileNm(filenm);
				string strfilenmwithoutpath;
				size_t pos =strFileNm.rfind("/");
				if(pos!=std::string::npos)
				strfilenmwithoutpath=strFileNm.substr(pos+1);	
				else
				strfilenmwithoutpath=strFileNm;

				// copy filenm to FILEINFO
				strcpy(ObjFileInfo.acFileNm, strfilenmwithoutpath.c_str()); 

				// enter cyclic loop
				while(!bEOF){
				// read next block from file and save it into buf,right after the "left over" buffer
				long lBytesRead=fread((char *)acreaddata+isizeofLeftover,1,sizeof(acreaddata)-isizeofLeftover-1, fp);	
				if(feof(fp))
				bEOF=1;
				else if(ferror(fp)){
				// error while reading in bulk from file	
				string strErrorDesc="PAF002:ERROR WHILE BULK READING FROM FILE...";			
				ObjFileInfo.cErrCode='E';	
				throw runtime_error(strErrorDesc);					
				}
				// some problem with read / end of 
				if(lBytesRead<0)
				lBytesRead=0;

				// add null terminator at end of buffer
				acreaddata[lBytesRead+isizeofLeftover] = '\0';
				// call to form long string
				unsigned int ileftoverpos=ParseFileTyp(acreaddata,lBytesRead+isizeofLeftover,bEOF,strLongStr);
			
				// create array of rawdata...returns no of lines added to buffer
				int iNoOfLines=ParseNewLineStr(strLongStr.c_str(),strLongStr.size(),vecRowData);

				// update total row
				ObjFileInfo.lRNO+=iNoOfLines;

				// buffer now ready to be processed...vecRowData
				ProcessBuffer(vecRowData,iNoOfLines);

				// added to detect error while forming txn
				// soze of unprocessed data has to be less than or equal to input array..if greater then error
				if(ileftoverpos>(lBytesRead+isizeofLeftover))	
				{
					ObjFileInfo.cErrCode='D';		// set proper error code
					// error while reading in bulk from file	
					string strErrorDesc="PAF003:ERROR WHILE FORMING TRANSACTION....";				
					throw runtime_error(strErrorDesc);
				}

				// update read pointer
				iReadPos+=ileftoverpos;
				// read call counter
				++ObjFileInfo.iNoOfBlockRead;
				// bulk read accumulate
				ObjFileInfo.szReadSize+=lBytesRead;		

				// calculate leftover buf size
				// the remaining unprocessed buffer that was not processed by Process	
				isizeofLeftover=lBytesRead+isizeofLeftover-ileftoverpos;	

				// put check oon sizeofleftover
				if(isizeofLeftover<0)
				isizeofLeftover=0;
				else if(isizeofLeftover>(lBytesRead+isizeofLeftover))
				{
						string strErrorDesc="PAF004:NO SPACE LEFT ON BUFFER TO ACCOMODATE NEW LINE...LOGICAL PROBLEM IN IDENTIFYING ROW IN BUFFER";				
						throw runtime_error(strErrorDesc);
				}		

				// If we have a leftover unprocessed buffer, move it to the beginning of  
				// read buffer so that when reading the next block, it will connect to the 
				// current leftover and together complete a full readable line
				if(ileftoverpos!=0 && isizeofLeftover!=0) 
				memmove(acreaddata,acreaddata+ileftoverpos,isizeofLeftover);

				}//end of while	
    }

		void ProcessBuffer(vector<ArrBufferData> & vecBuf,int iBuffSz)
		{
				// parallel area
				for(int iX=0;iX<iBuffSz;++iX)
				{
						stringstream strErrDesc="";
						// local object parsercd
						PARSERCD objpc=INVALID_PARSERCODE;
						// default error code=SUCCESS
						ErrCdList enErrCd=SUCCESS_NORM;
						
						// validate input..if invalid then set errorcd
						if(!ValidateInputRawData(vecBuf[iX].acRawdata,vecBuf[iX].iRowSz))
						vecBuf[iX].iErrCd=1;

						// identify parsercd and validation ...objpc will point to invalid_Pc in case of error
						IdentifyParserCd(vecBuf[iX].acRawdata,vecBuf[iX].iRowSz,objpc);

						// parsing into struct as per mapper
						ParseDataIntoStruct(vecBuf[iX].acRawdata,vecBuf[iX].iRowSz,objpc,vecBuf[iX].ObjTT,strErrDesc);	
						// store into Mem
						StoreBuffer(vecBuf[iX]);	
				}
		}

		void StoreBuffer(ArrBufferData & Buf)
		{	
			EnrichData(Buf.ObjTT);
			StoreRecordIntoMem(Buf.ObjTT);
		}

		// search for '\n' in string..input will be 
		unsigned int ParseNewLineStr(const char * rawdata,unsigned long lBufSz,vector<ArrBufferData> & vecdata)
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
					++icnt;
				}

				return icnt;
		}

		void AddTxnRow(const char * data,const unsigned int irowsz,vector<ArrBufferData> & vecData)
		{
			ArrBufferData ObjRowData;	
			if(!irowsz)
			{
				// some problem with data..bypass such data
				return;
			}
			else if(irowsz>sizeof(ObjRowData.acRawdata))
			{
					// raise error for buffer overflow..some logical problem...throw exception here
					string strErrorDesc="PAF001:ROWSZ:"+toString(irowsz)+" IS GREATER THAN MAX LENGTH:"+toString(MAX_RAWDATA_LEN);
					//throw FileReadException(strErrorDesc,true); write into reject file
			}

			// prepare input
			const char * locdata=data;
			ObjRowData.iRowSz=irowsz;
			// purify input data 
			PurifyAndStoreRow(locdata,ObjRowData.acRawdata,ObjRowData.iRowSz);

			// rowdata is ready to get add in buffer
			vecData.push_back(ObjRowData);
		}

		void PurifyAndStoreRow(const char * src,char * dest,unsigned short & isrclen)
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
};
 
int main(int argc,char * argv[])
{
		if(argc==1)
		{
			cout<<"Plz pass Input filenm to be read as arg"<<endl;
			return 0;
		}
	
		char filnm[300];
		memset(filnm,0x00,sizeof(filnm));
		strcpy(filnm,argv[1]);

    /* Example 1 */
    typedef FPPolicy<AppendFormat, MPOS,AcqSwt> Normaliser;
 
    Normaliser normObj;
    normObj.run(filnm); // process file
 
}
