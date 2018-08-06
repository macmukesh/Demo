#ifndef _FILEREADER_H_
#define _FILEREADER_H_

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <errno.h>
#include "StringConv.h"
#include "CommonQueueData.h"

# define MAX_RAWDATA_LEN 5121 

using namespace std;

class FileReadException : public exception
{
	public:
		FileReadException(const string &message, bool inclSysMsg = false) throw();
		~FileReadException() throw();
		const char *what() const throw();

	private:
		string userMessage;
};


class FileReader
{
	public:
						FileReader();
						FileReader(unsigned int (*f)(const char * ,long ,bool,string & ));	// constr
						~FileReader();																											// destr
						void Open(char * );																									// open the file
						void Close();																												// close the file
						inline bool IsEOF(){return bEOF;};
						const vector<ArrBufferData> & GetBufferData();

	private:
						static const unsigned int BLOCKREADSZ=4096;											 		// max buffer size
						char acreaddata[BLOCKREADSZ];																				// rawdata holder
						bool bEOF;
						unsigned int ileftoverpos;																					// pos in buf of unprocessed data
						int isizeofLeftover;																								// size of unprocessed data
						vector<ArrBufferData> vecRowData;																		// buffer of vector
						ArrBufferData ObjRowData;
						FILE * fp;
						ifstream ifs;
						unsigned int iReadPos;																						// byte read position in file
						unsigned int iNoOfBlockRead;																			// no of block read
						size_t szReadSize;																								// total read byte count from file

						unsigned int (*FormLongStr)(const char * ,long ,bool,string & );	// function pointer to parser
						
						void ResetRow(ArrBufferData & );																	// reset rowdata	
						void PurifyAndStoreRow(const char *,char *,unsigned short & );		// purify data
	protected:
						void AddTxnRow(const char * ,unsigned int ,vector<ArrBufferData> &);						// add row in buffer
						unsigned int ParseNewLineStr(const char *,unsigned long,vector<ArrBufferData> & );			// prepare row data


};

#endif
