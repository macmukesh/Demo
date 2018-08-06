/**********************************************************************************/
/*
   COPYRIGHT NOTICE
   Copyright @ 2014 In-Solutions Global Pvt Ltd (ISG). All rights reserved.

These materials are confidential and proprietary to In-Solutions Global Pvt Ltd (ISG) and no part of these materials should be reproduced, published, transmitted or distributed in any form or by any means, electronic, mechanical, photocopying, recording or otherwise, or stored in any information storage or retrieval system of any nature nor should the materials be disclosed to third parties or used in any other manner for which this is not authorized, without the prior express written authorization of In-Solutions Global Pvt Ltd (ISG) Pvt Ltd. */
/*                                                                 */
/***********************************************************************************/
/************************************************************************************
 *
 * Module Name	: 
 * File Name	: Utility.cpp
 * Description	: Various utility functions
 *
 *		Version Control Block
 *		---------------------
 * Date			Version		Author			Description
 * -------------	-------		--------------------	-------------------
   Jul 05 2013	       	1.0		Amul MUTHA		Base Version
   May 29 2015			1.1		Gaurav Kumar
   
*************************************************************************************/

#include "Utility.h"
//#include "etoa.h"


//By MERAJ Ansari 22-Feb-16
char* Utility::fnRightPadwithzero(char inp[], int padded_len, char pad)  // Right Pad With 0 (Zero)
{
    int len = strlen(inp);
    if (len >= padded_len) {
        return inp;
    }
    int i;
    for (i = 0; i < padded_len - len; i++) {
        //strcat(inp, pad);
        sprintf(inp+len+i, "%c", pad);
    }
    return inp;
}
char * Utility::ltrim(char* s) 
{
    char* newstart = s;

    while (isspace( *newstart)) {
        ++newstart;
    }

    // newstart points to first non-whitespace char (which might be '\0')
    memmove( s, newstart, strlen( newstart) + 1); // don't forget to move the '\0' terminator

    return s;
}

char * Utility::trim(char* s)
{
	int length = strlen(s);
	char acOut[length+1];
    strcpy(acOut, rtrim(ltrim(s)) );
	MEMSET(s);
    strcpy(s, acOut);
}

int Utility ::etoa( unsigned char *ch,  int len)
{
		for(;len > 0; --len, ++ch)
	//	*ch = ebcdic2ascii[*ch];

       return 0;
}

void Utility::fnTrimSpace(char *str)
{
	char	acInput[200+1];
	char	acOutput[200+1];
	memset(acInput, 0x00, sizeof(acInput));
	strncpy(acInput, str, strlen(str));

	int	iStart = 0;
	memset(acOutput, 0x00, sizeof(acOutput));
	// Find left index
	for(int i=0; i<strlen(acInput); i++)
	{
		if(str[i] != 32)
		{
			iStart = i;
			break;
		}
	}

	int	iEnd = 0;
	// Find right index
	for(int j=strlen(acInput)-1; j>=0; j--)
	{
		if(str[j] != 32)
		{
			iEnd = j;
			break;
		}
	}

	int	k=0;
	for(int i=iStart; i<=iEnd; i++)
	{
		acOutput[k++] = str[i];
	}
	acOutput[k] = '\0';

	if(strncmp(acOutput, " ", 1) == 0)
	{
		memset(acOutput, 0x00, sizeof(acOutput));
	}

	memset(str, 0x00, strlen(str));//PAYTMEBAY8
	strncpy(str, acOutput, strlen(acOutput));
}


int Utility::fnPadSpace(char inp[],int len,char *out) //RIGHT PAD with SPACE
{
        /* Local Variable Declaration begins here */
        char            acBuff[1024+1];
        int             i,j;

        memset(acBuff,0x00,sizeof(acBuff));
        sprintf(acBuff,"%s",inp);

        j=strlen(acBuff);
        if(j>len)
        {
                acBuff[len]='\0';
        }
        else
        {
                for(i=len-(strlen(inp));i>0;i--)
                {
                        acBuff[j++]=' ';
                }
                acBuff[j++]='\0';
        }
	strcpy(out,acBuff);
	return 0;
}

//By MERAJ Ansari 22-Feb-16
int Utility::fnLeftPad(char inp[],int len,char ch) // Left Pad with Zero
{
	char	acBuff[1024+1];
	int	i=0, j=0, k=0;

        memset(acBuff,0x00,sizeof(acBuff));

	k=strlen(inp);	// problem-1

        if(k>len)
        {
	        sprintf(acBuff,"%s",inp);	// problem-2
		acBuff[len]='\0';
        }
        else
        {
		for(i=0; i<(len-k); i++)
		{
			acBuff[i]=ch;
		}

		for(j=0; j<k; j++)
		{
			acBuff[i]=inp[j];
			++i;
		}
		acBuff[i]='\0';
	}

	memset(inp, 0x00, k);
	sprintf(inp, "%s", acBuff);

	return 0;
}
//By MERAJ Ansari 22-Feb-16
int Utility::fnLeftPadSpace(char inp[],int len,char *out) //Left Pad with Space
{
        /* Local Variable Declaration begins here */
        char            acBuff[1024+1];
        int             i,j;

        /*memset(acBuff,0x00,sizeof(acBuff));
        sprintf(acBuff,"%s",inp);
		*/
        //j=strlen(acBuff);
        j = 0;
        if(strlen(inp)>len)
        {
                acBuff[len]='\0';
        }
        else
        {
        		j = 0;
                for(i=len-(strlen(inp));i>0;i--)
                {
                        acBuff[j++]=' ';
                }
                
                for(i=0; i<strlen(inp); i++)
                {
                	acBuff[j++]= inp[i];
                }
                
                acBuff[j++]='\0';
        }
	strcpy(out,acBuff);
	return 0;
}




// This function removes spaces appended to data i.e. change  "abc1234   " to "abc1234"
int Utility::fnRemoveAppendedSpaces(char acInputData[], char acOutput[])
{
	char *acTempToken=NULL;

        // Save Original Input String before Tokenizing
	//acInputCopy=strdup(acInputData);
	
	//above function strdup is ereonous commenting -srini
	
	char acInputCopy [strlen(acInputData)+1];
	
	
	memset(acInputCopy,0x00,sizeof(acInputCopy));
	
	strncpy(acInputCopy,acInputData,strlen(acInputData));
	
        // Returns First Token ie. Data before Spaces in Input String
	if(acInputCopy[0] == ' ')
	{
		return 0;
	}
	else
	{
	        acTempToken=strtok(acInputData," ");

		// If the length of extracted token is less than input string
       		if(strlen(acTempToken)<=strlen(acInputCopy))
        	{
			strncpy(acOutput,acTempToken,strlen(acTempToken));
			/*
			MEMSET(acTempToken);		// PCI-DSS Norms
			MEMSET(acInputCopy);
			*/
			
			//above memsets are worng as this take sizeof to memset pointers -srini.
			memset(acTempToken,0x00,strlen(acTempToken));
			memset(acInputCopy,0x00,strlen(acTempToken));
			
			
			
			//free(acInputCopy);
			//above frreee changed by srini

			return 1;
        	}
        	else
        	{	/*
			MEMSET(acTempToken);		// PCI-DSS Norms
			MEMSET(acInputCopy);
			*/
			
			//above memsets are worng as this this take sizeof to memset pointers -srini.
			memset(acTempToken,0x00,strlen(acTempToken));
			memset(acInputCopy,0x00,strlen(acTempToken));
			
			
			//free(acInputCopy);
			//above frreee changed by srini


			
			return 0;
		}
        }
}

int Utility::fnGetTime(char acTime[])
{
        time_t          time_now;
        struct          tm tm_now;

        struct          timeval start;
        gettimeofday(&start, NULL);

        time(&time_now);
        localtime_r(&time_now,&tm_now);

	sprintf(acTime,"%02d/%02d/%04d %02d:%02d:%02d:%06d",tm_now.tm_mon+1, tm_now.tm_mday, tm_now.tm_year+1900, tm_now.tm_hour, tm_now.tm_min, tm_now.tm_sec, start.tv_usec);	
	return(1);
}

int Utility::fnMaskCardNumber(char acCardNumber[], char acTruncatedCardNum[])
{
        char acBin[6+1];
        char acLastFour[4+1];
        int iTruncateLength=0;

        MEMSET(acBin);
        MEMSET(acLastFour);
        MEMSET(acTruncatedCardNum);

        strncpy(acBin,acCardNumber,6);
        strncpy(acLastFour,&acCardNumber[strlen(acCardNumber)-4],4);
        strncpy(acTruncatedCardNum,acBin,6);
        iTruncateLength=strlen(acCardNumber)-10 ;
        for(int iCount=0;iCount<iTruncateLength;iCount++)
                strcat(acTruncatedCardNum,"X");
        strcat(acTruncatedCardNum,acLastFour);
	
	if(strlen(acCardNumber)==strlen(acTruncatedCardNum))			//Added by Charu
		return 0;
	else
		return 1;
}

int Utility::fnSHAHashing(char acClearInput[], char acHashOutput[], char acStatusMsg[])
{
/*	int     iLength = 0;

	iLength = strlen(acClearInput);

	if(iLength)
	{
		byte    bHash[SHA256::DIGESTSIZE];
		byte    bInput[iLength+1];
		char    acTempBuff[2+1];

		memset(bHash,0x00,sizeof(bHash));
		memset(bInput,0x00,sizeof(bInput));

		memcpy(bInput,acClearInput,iLength);
		SHA256().CalculateDigest(bHash,bInput,strlen((const char *)bInput));

		for(int iCount = 0; iCount<20; iCount++)
		{
			memset(acTempBuff,0x00,sizeof(acTempBuff));
			snprintf(acTempBuff,2+1,"%02x",bHash[iCount]);
			strncat(acHashOutput,acTempBuff,2);
		}
		return(1);
	}
	else
	{
		strcpy(acStatusMsg, "ESH001: No input data available for Hashing\n");
		return(0);
	}
*/
}

int Utility::fnRemoveComma(char *inputStr, char *outputStr)
{

}

char * Utility::fnTrim(char * str)
{

}



/* fnLeftTrim()
 * Description:- Removes blank spaces that appear at the start of the given string.
 * Input Parameters:- sSrc - string from which spaces have to be removed.
 * Output Parameters:- pointer to string buffer that has been modified by removing spaces.
 */
/*char* Utility::fnLeftTrim(char *sSrc)
{
        short int iDiff=0, iSub;
        while( sSrc[ iDiff++] == ' ');
        for( iSub=0, iDiff--;  sSrc[ iDiff-1] != '\0';  iDiff++, iSub++)
                        sSrc[ iSub] = sSrc[ iDiff];
        return  sSrc;
}*/

/******************************* 
	fnLeftTrimZero
 *  * Description:- Removes '0' that appear at the start of the given string.
 *   * Input Parameters:- sSrc - string from which 0 have to be removed.
 *    * Output Parameters:- pointer to string buffer that has been modified by removing spaces.
 *     */

char* Utility::fnLeftTrimZero(char *sSrc)
{
        short int iDiff=0, iSub;
        while( sSrc[ iDiff++] == '0');
        for( iSub=0, iDiff--;  sSrc[ iDiff-1] != '\0';  iDiff++, iSub++)
                        sSrc[ iSub] = sSrc[ iDiff];
        return  sSrc;
}

/*
   Function Name : GetFormatedDT
Input         : Unformatted date in format DDMMYYYY
Output        : Formatted Date in format YYMMDD
Definition    : returns formatted date  
Author	      : Mukesh paliwal 	
 */
char* Utility::GetFormatedDT(char *p_txnDate)
{
	char l_txnDate[8+1];
	char p_formatedDT[6+1];
	strcpy(l_txnDate, p_txnDate);
	p_formatedDT[0] = l_txnDate[6];
	p_formatedDT[1] = l_txnDate[7];
	p_formatedDT[2] = l_txnDate[2];
	p_formatedDT[3] = l_txnDate[3];
	p_formatedDT[4] = l_txnDate[0];
	p_formatedDT[5] = l_txnDate[1];
	p_formatedDT[6] = '\0';
	MEMSET(p_txnDate);	
	strcpy(p_txnDate,p_formatedDT);
	return p_txnDate;
}

/*	Input:DDMMYY
	Output:YYMMDD
*/
void Utility::GetFmtDate(char *p_txnDate, char *ret)
{
	char l_txnDate[8+1];
	char p_formatedDT[6+1];


	strcpy(l_txnDate, p_txnDate);
	p_formatedDT[0] = l_txnDate[4];
	p_formatedDT[1] = l_txnDate[5];
	p_formatedDT[2] = l_txnDate[2];
	p_formatedDT[3] = l_txnDate[3];
	p_formatedDT[4] = l_txnDate[0];
	p_formatedDT[5] = l_txnDate[1];
	p_formatedDT[6] = '\0';
	//MEMSET(p_txnDate);	
	strcpy(ret,p_formatedDT);
	
}

/*
   Function Name : GetFormatedDT
Input         : Unformatted date in format MM/DD/YYYY
Output        : Formatted Date in format YYMMDD
Definition    : returns formatted date  
Author	      : Mukesh paliwal 	
 */
char* Utility::GetFormatedDate(char *p_txnDate)
{
	//char 	p_formatedDT[6+1];
	char 	temp[5][10+1];	
	char	*ptr;
	char	*pch;
	char	*rest;
	int k=0;

	ptr = p_txnDate;
	while(pch = strtok_r(ptr, "/", &rest)) 
	{
		memset(temp[k], 0x00, sizeof(temp[0]));
		//printf("%s ", pch);
		strcpy(temp[k], pch);
                ptr = rest;
        	k++;
	}
	MEMSET(p_txnDate);
	sprintf(p_txnDate, "%02d%02d%02d", atoi(temp[2]+2), atoi(temp[0]), atoi(temp[1]));
	//printf("\nGetFormatedDT : Date [%s]\n", p_txnDate);
	return p_txnDate;
}

/*
   Function Name : GetFormatedDT
Input         : Unformatted date in format MM-DD-YYYY
Output        : Formatted Date in format YYMMDD
Definition    : returns formatted date  
Author	      : Mukesh paliwal 	
 */
char* Utility::GetSettFormatedDate(char *p_txnDate)
{
	//char 	p_formatedDT[6+1];
	char 	temp[5][10+1];	
	char	*ptr;
	char	*pch;
	char	*rest;
	int k=0;

	ptr = p_txnDate;
	while(pch = strtok_r(ptr, "-", &rest)) 
	{
		memset(temp[k], 0x00, sizeof(temp[0]));
		//printf("%s ", pch);
		strcpy(temp[k], pch);
                ptr = rest;
        	k++;
	}
	MEMSET(p_txnDate);
	sprintf(p_txnDate, "%02d%02d%02d", atoi(temp[2]+2), atoi(temp[1]), atoi(temp[0]));
	//printf("\nGetFormatedDT : Date [%s]\n", p_txnDate);
	return p_txnDate;
}

/**********************************
	Input :	DD-MM-YYYY
	Output:	YYMMDD
**********************************/
void Utility::fnGetYYMMDDCBS(char acDate[], char acFrmtDate[])
{
	MEMSET(acFrmtDate);
	acFrmtDate[0] = acDate[8];
	acFrmtDate[1] = acDate[9];
	acFrmtDate[2] = acDate[3];
	acFrmtDate[3] = acDate[4];
	acFrmtDate[4] = acDate[0];
	acFrmtDate[5] = acDate[1];
	acFrmtDate[6] = '\0';
}

/**********************************
	Input :	YYYY-MM-DD
	Output:	YYMMDD
**********************************/
void Utility::fnGetYYMMDD(char acDate[], char acFrmtDate[])
{
	MEMSET(acFrmtDate);
	acFrmtDate[0] = acDate[2];
	acFrmtDate[1] = acDate[3];
	acFrmtDate[2] = acDate[5];
	acFrmtDate[3] = acDate[6];
	acFrmtDate[4] = acDate[8];
	acFrmtDate[5] = acDate[9];
	acFrmtDate[6] = '\0';
}

/*

Author : Mukesh 
Date : 25 Jan 2014
O/P  : Current date and time 
*/
void Utility:: currentDateTime(char * time1) {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    strcpy(time1 , buf);
}


/*

Author : Mukesh 
Date : 25 Jan 2014
I/P  : Start time and End time  
O/P  : diff in time in seconds 
*/
double Utility:: fnTimeDiff(timeval t11,timeval t22)
{
	double d;
	double milliSeconds = (t22.tv_sec - t11.tv_sec) * 1000 + (t22.tv_usec - t11.tv_usec)/1000;	// o/p in millisecond
//	double Seconds = (t22.tv_sec - t11.tv_sec); 	// o/p in Seconds
//	if(milliSeconds > 1000)
//	{
		d = milliSeconds/1000;
//	}
//	else*/
//		d = milliSeconds;
//	printf("Diff [%lf]  \n" , d);
	return d;
}

void Utility::fnLeftTrim(char *str)				//FOR USE
{      
 	int i, k=0;
	char out[50+1];
	int iCount=0;
	int f=0;
 	for(i=0; i<strlen(str); i++)	// problem-1
	{
		if((str[i]==32) && (f==0))	// problem-2
		{
			iCount++;
		}
		else
		{	
			out[k] = str[i];
			k++;
			f=1;
		}
	}
	out[k] = '\0';
	memset(str, 0x00, sizeof(str));
	strcpy(str,out);	// problem-3
	//cout<<"Final Output : ["<<str<<"]"<<endl;
	
}
char * Utility::rtrim( char* s)
{
    char* end = s + strlen( s);

    // find the last non-whitespace character
    while ((end != s) && isspace( *(end-1))) {
            --end;
    }

    // at this point either (end == s) and s is either empty or all whitespace
    //      so it needs to be made empty, or
    //      end points just past the last non-whitespace character (it might point
    //      at the '\0' terminator, in which case there's no problem writing
    //      another there).    
    *end = '\0';

    return s;
}

void Utility::fnRTrim(char *str)		//FOR USE
{
	int 	i=0;
	int 	k=0;
	int 	f=0;
	
	char	str1[300+1];
	char 	out[300+1];
	char 	in[300+1];

	MEMSET(out);
	MEMSET(in);
	MEMSET(str1);

	strcpy(str1, str);	// problem-1
	MEMSET(str);
	int 	s = strlen(str1)-1;	// problem-2

	for(i=s; i>=0; i-- )
	{	
		if((str1[i] != 32))	// problem-3
		{
			out[k] = str1[i];
			k++;
			f=1;
		}
 		else if((str1[i] == 32) && (f==1))
		{
			out[k] = str1[i];
			k++;
		}
		out[k]= '\0';
	
	}
	out[k]='\0';

	for(int k=strlen(out); k>=0; k--)	// problem-4
	{
		in[i] = out[k];
		i++;	

	}
	in[i]='\0';

	strcpy(str, in);	// problem-5
	//return str;
}

void Utility::fnRTrim2(char *str)
{
	int 	i=0;
	int 	k=0;
	int 	f=0;
	
	char	str1[300+1];
	char 	out[300+1];
	char 	in[300+1];

	MEMSET(out);
	MEMSET(in);
	MEMSET(str1);

	strcpy(str1, str);
	MEMSET(str);
	int 	s = strlen(str1)-1;

	for(i=s; i>=0; i-- )
	{	
		if((str1[i] != 32))
		{
			out[k] = str1[i];
			k++;
			f=1;
		}
 		else if((str1[i] == 32) && (f==1))
		{
			out[k] = str1[i];
			k++;
		}
		out[k]= '\0';
	
	}
	out[k]='\0';
	 
	 i=0;
	 f=0;
		
	for(int k=strlen(out)-1; k>=0; k--)
	{	if((out[k] == 32)&& f!=1)
		{
		
		}
		else
		{
		in[i] = out[k];
		i++;
		f=1;
		}	
		
	}	
	in[i]='\0';
	strcpy(str, in);
	//return str;
}



/*********************************
	Input	:  MM/DD/YYYY
	Output	:  YYMMDD
*********************************/
int Utility::fnGetFormatedDate(char *inp, char *out)
{
	char 	p_formatedDT[6+1];
	memset(p_formatedDT, 0x00, sizeof(p_formatedDT));

	p_formatedDT[0]=inp[8];
	p_formatedDT[1]=inp[9];
	p_formatedDT[2]=inp[0];
	p_formatedDT[3]=inp[1];
	p_formatedDT[4]=inp[3];
	p_formatedDT[5]=inp[4];
	p_formatedDT[6]='\0';
	//printf("local Formated Date : [%s]\n", p_formatedDT);
	strcpy(out, p_formatedDT);
	//printf("Formated Date : [%s]\n", out);
	return 0;
}

double Utility::roundD(double d,int pres)
{
	int tpres=1;
	for(int i=0;i<pres;i++)
	tpres=tpres*10;

	return (roundf(d*tpres))/(tpres);
}

double Utility::roundNS(double val,char pres)
{
	int i=(int)pres-48;
	return roundD(val,i);
}

double Utility::fnRound(double tt, int ii)
{

	double t1 = 0.00;
        int sign = 1;
        if (tt <0)
        {
                sign = -1;
                t1 = tt * sign;
        }
        else
                t1 = tt;
//return roundD(val, ii);
        double t2,res,tmp= 0.00;
		long int iRound = 0;
            tmp = t1*(pow(10,ii));
            t2 = tmp + 0.5;

                    iRound = static_cast<long int>(t2);
                    res = (double)iRound/(pow(10,ii));

	return res*sign;

}

/*	AUTHER : Tushar Shinde
	Date : 4th Nov 2014
 	INPUT : DD-MON-YY
	OUTPUT : YYMMDD
*/
void Utility::fnGetDateFormat(char* acDate, char* acFrmtDate)
{
	char month[3+1];
	memset(month, 0x00,sizeof(month));

	sprintf(month, "%c%c%c", acDate[3], acDate[4], acDate[5]);
	if((strncmp(month, "JAN", 3)==0) || (strncmp(month, "Jan", 3)==0))
	{
		acFrmtDate[2] = '0';
		acFrmtDate[3] = '1';
	}
	if((strncmp(month, "FEB", 3)==0) || (strncmp(month, "Feb", 3)==0))
	{
		acFrmtDate[2] = '0';
		acFrmtDate[3] = '2';
	}
	if((strncmp(month, "MAR", 3)==0) || (strncmp(month, "Mar", 3)==0))
	{
		acFrmtDate[2] = '0';
		acFrmtDate[3] = '3';
	}
	if((strncmp(month, "APR", 3)==0) || (strncmp(month, "Apr", 3)==0))
	{
		acFrmtDate[2] = '0';
		acFrmtDate[3] = '4';
	}
	if((strncmp(month, "MAY", 3)==0) || (strncmp(month, "May", 3)==0))
	{
		acFrmtDate[2] = '0';
		acFrmtDate[3] = '5';
	}
	if((strncmp(month, "JUN", 3)==0) || (strncmp(month, "Jun", 3)==0))
	{
		acFrmtDate[2] = '0';
		acFrmtDate[3] = '6';
	}
	if((strncmp(month, "JUL", 3)==0) || (strncmp(month, "Jul", 3)==0))
	{
		acFrmtDate[2] = '0';
		acFrmtDate[3] = '7';
	}
	if((strncmp(month, "AUG", 3)==0) || (strncmp(month, "Aug", 3)==0))
	{
		acFrmtDate[2] = '0';
		acFrmtDate[3] = '8';
	}
	if((strncmp(month, "SEP", 3)==0) || (strncmp(month, "Sep", 3)==0))
	{
		acFrmtDate[2] = '0';
		acFrmtDate[3] = '9';
	}
	if((strncmp(month, "OCT", 3)==0) || (strncmp(month, "Oct", 3)==0))
	{
		acFrmtDate[2] = '1';
		acFrmtDate[3] = '0';
	}
	if((strncmp(month, "NOV", 3)==0) || (strncmp(month, "Nov", 3)==0))
	{
		acFrmtDate[2] = '1';
		acFrmtDate[3] = '1';
	}
	if((strncmp(month, "DEC", 3)==0) || (strncmp(month, "Dec", 3)==0))
	{
		acFrmtDate[2] = '1';
		acFrmtDate[3] = '2';
	}
	acFrmtDate[0] = acDate[7];
	acFrmtDate[1] = acDate[8];
	acFrmtDate[4] = acDate[0];
	acFrmtDate[5] = acDate[1];
	acFrmtDate[6] = '\0';
}

void Utility::getDateNOD(char *date,int nod,char * ret)
{
	struct tm ts;
	struct tm *t2;
	time_t t;
	char  date2[19+1];
	memset(date2,0x00,sizeof(date2));
	strncpy(date2,date,10);
	strcat(date2," 00:00:00");
	strptime(date2,"%Y-%m-%d %H:%M:%S", &ts);
	t=mktime(&ts);
	t+=(nod*24*60*60);
	t2=localtime(&t);
	strftime(ret,11,"%Y-%m-%d",t2);
}

void Utility::getCurDate(int nod,char *ret)
{
	struct tm ts;
	struct tm *t2;
	time_t t;
	t=time(NULL);
	t+=(nod*24*60*60);
	t2=localtime(&t);
	strftime(ret,11,"%Y-%m-%d",t2);
}
/****************
yymmdd
yyyymm
yyyymmdd

****************/

void Utility::fnGetCurrentDate(char *ret, char *fmt)
{
	struct tm ts;
	struct tm *t2;
	time_t t;
	t=time(NULL);
	//t+=(nod*24*60*60);
	t+=0;
	t2=localtime(&t);

	if(strncmp(fmt, "yymmdd", 6)==0)		// YYMMDD
		strftime(ret,11,"%y%m%d",t2);
	else if(strncmp(fmt, "ddmmyy", 6)==0)		// DDMMYY
		strftime(ret,11,"%d%m%y",t2);
	else if(strncmp(fmt, "dd-mmm-yy", 9)==0)	// DD-MMM-YY
		strftime(ret,11,"%d-%b-%y",t2);
	else if(strncmp(fmt, "yyyymm", 6)==0)		// YYYYMM
		strftime(ret,11,"%Y%m",t2);
	else if(strncmp(fmt, "yyyymmdd", 8)==0)		// YYYYMMDD
		strftime(ret,11,"%Y%m%d",t2);
	else if(strncmp(fmt, "ddmmyyyy", 8)==0)		// DDMMYYYY
		strftime(ret,11,"%d%m%Y",t2);
	else if(strncmp(fmt, "dd-mm-yyyy", 8)==0)		// DD-MM-YYYY
		strftime(ret,11,"%d-%m-%Y",t2);
	else if(strncmp(fmt, "mmmyy", 5)==0)		// MMMYY
		strftime(ret,11,"%b%y",t2);
	else						// YYYY-MM-DD
		strftime(ret,11,"%Y-%m-%d",t2);		
}

void Utility::getDay(char *date,char * ret)
{
	struct tm ts;
	struct tm *t2;
	time_t t;
	char  date2[19+1];
	memset(date2,0x00,sizeof(date2));
	strncpy(date2,date,10);
	strcat(date2," 00:00:00");
	strptime(date2,"%Y-%m-%d %H:%M:%S", &ts);
	t=mktime(&ts);

	t2=localtime(&t);
	strftime(ret,11,"%j",t2);
}


void Utility::getDiff(char *date)
{
	struct tm ts;
	struct tm *t2;
	time_t t;
	time_t t1;
	char  date2[19+1];
	memset(date2,0x00,sizeof(date2));
	strncpy(date2,date,10);
	strcat(date2," 00:00:00");
	strptime(date2,"%Y-%m-%d %H:%M:%S", &ts);
	t=mktime(&ts);
	t1=time(NULL);
	cout<<fixed<<difftime(t,t1)<<endl;
	cout<<fixed<<difftime(t1,t)<<endl;
}

void Utility::getCurryear(char *ret)
{
	struct tm *t3;
	time_t t1;
	t1=time(NULL);
	t3=localtime(&t1);
	strftime(ret,11,"%y",t3);
}
//sneha
void Utility::getJulDate(char *acSDate, char *dateformat, char * ret)	//(from YYMMDD to YYDDD, YDDD, YYYYDDD)
{
	char formatdate[4+1];	
	char JulDay[3+1];
	char julyear[4+1];

	memset(formatdate, 0x00, sizeof(formatdate));
	strncpy(formatdate,acSDate+2,4);			//mmdd	
	getJulDateforMMDD(formatdate, JulDay);			//get jul-day

	if(strcmp(dateformat, "YYDDD")==0)
	{
		memset(julyear, 0x00, sizeof(julyear));
		strncpy(julyear,acSDate,2);				//yy

		memset(ret, 0x00, sizeof(ret));
		sprintf(ret, "%-2s%-3s", julyear, JulDay);	
	}
	else if(strcmp(dateformat, "YDDD")==0)
	{
		memset(julyear, 0x00, sizeof(julyear));
		strncpy(julyear,acSDate+1,1);				//y

		memset(ret, 0x00, sizeof(ret));
		sprintf(ret, "%-1s%-3s", julyear, JulDay);	
	}	
	else if(strcmp(dateformat, "YYYYDDD")==0)
	{
		int year;

		memset(julyear, 0x00, sizeof(julyear));
		strncpy(julyear,acSDate,2);	

		year = atoi(julyear);

		if(year<50)
			year = 2000 + year;
		else
			year = 1900 + year;

		memset(julyear, 0x00, sizeof(julyear));
		sprintf(julyear, "%d", year);
					

		memset(ret, 0x00, sizeof(ret));
		sprintf(ret, "%-4s%-3s", julyear, JulDay);	
	}	
	
}

void Utility::getJulDateforMMDD(char *date,char * ret)
{
	struct tm ts;
	struct tm *t2;

	time_t t;
	char  date2[19+1];
	memset(date2,0x00,sizeof(date2));
	strncpy(date2,date,4);
	char year[2+1];
	memset(year,0x00,sizeof(year));


	getCurryear(year);

	strcat(date2,year);
	strcat(date2," 00:00:00");
	memset(&ts,0x00,sizeof(ts));
	
	strptime(date2,"%m%d%y %H:%M:%S", &ts);
	t=mktime(&ts);

	t2=localtime(&t);
	strftime(ret,11,"%j",t2);
}

void Utility::getJCurDate(char *ret)
{
	struct tm ts;
	struct tm *t2;
	time_t t;
	t=time(NULL);

	t2=localtime(&t);
	strftime(ret,11,"%j",t2);
}

void Utility::getCorrectdate(char* date,char *ret)
{
	char ret1[11+1];
	char ret2[11+1];
	memset(ret1,0x00,sizeof(ret1));
	memset(ret2,0x00,sizeof(ret2));
	getJulDateforMMDD(date,ret1);
	getJCurDate(ret2);

	int j1=atoi(ret1);
	int j2=atoi(ret2);

	char ret3[15+1];
	memset(ret3,0x00,sizeof(ret3));

	char ret4[11+1];
	memset(ret4,0x00,sizeof(ret4));

	getCurryear(ret3);

	int cyear=atoi(ret3);
	int pyear=cyear-1;

	if(j1>j2)
	{
		sprintf(ret4,"%s%d",date,pyear);
	}
	else
	{
		sprintf(ret4,"%s%d",date,cyear);
	}

	struct tm *t2;
	struct tm ts;
	time_t t;
	
	memset(&ts,0x00,sizeof(ts));
	strcat(ret4," 00:00:00");
	strptime(ret4,"%m%d%y %H:%M:%S", &ts);
	t=mktime(&ts);
	t2=localtime(&t);
	strftime(ret,15,"%d-%m-%Y",t2);
}

void Utility::getFormattedDate(char *sdate, char* sformat,char * ddate,char * dformat,int nod1)
{
	struct tm ts;
	struct tm *t1;
	struct tm *t2;
	//cout<<"#### " <<sdate<<endl;
	time_t t;
	char  date2[25+1];
	memset(date2,0x00,sizeof(date2));
	char  cdate[25+1];
	memset(cdate,0x00,sizeof(cdate));


	strncpy(date2,sdate,strlen(sdate));
	char  tsformat[40+1];
	memset(tsformat,0x00,sizeof(tsformat));
	strcpy(tsformat,sformat);	
	strcat(date2," 00:00:00");
	strcat(tsformat," %H:%M:%S");
	memset(&ts,0x00,sizeof(ts));
	strptime(date2,tsformat, &ts);
	t=mktime(&ts);

	t1=localtime(&t);
	strftime(cdate,25,sformat,t1);


	t+=(nod1*24*60*60);
	t2=localtime(&t);
	
	int clen=strlen(cdate);
	for(int i=0;i<clen;i++)
	{	
		cdate[i]=(char)toupper(cdate[i]);
		date2[i]=(char)toupper(date2[i]);
	}
	
	if(strncmp(cdate,date2,strlen(cdate))==0)
	strftime(ddate,25,dformat,t2);
	else
	strcpy(ddate,"\0");	
}

int Utility::fnAsciiCheck(char* date)
{
	char	acLine[8+1];
	memset(acLine, 0x00, sizeof(acLine));
	//cout<<"====" <<date <<endl;
	strncpy(acLine, date, 8);
	//cout<<acLine <<"====" <<strlen(acLine) <<endl;
	for(unsigned int k=0; k<strlen(acLine); k++)
	{
		int ascii = (int)acLine[k];
		
		if((ascii<48) || (ascii>57))						// Check other than 0-9
		{
			return 1;
			break;
		}
	}
	return 0;
}

char* Utility::fnMssfnFilter(char* date, int flag, char* out)
{
	int iCount;
	
	char acDate[10+1];
	memset(acDate, 0x00, sizeof(acDate));
	int iDateCount = 0;
	iCount = strlen(date);
	int	iCheck=0;
	
	if(iCount>0)
	{
		int i;
		for(i=0; i<iCount; i++)							// Pre-Flag check for between 32 and 127
		{
			if(acDate[i]<32 && acDate[i]>127)
			{
				iCheck=1;
				break;
			}
		}

		if(iCheck==1)
			return NULL;

		if(flag==1)								// For Numbers
		{
			for(int i=0; i<iCount; i++)
			{
				if(date[i]>=48 && date[i]<=57)
				{
					acDate[iDateCount] = date[i];
					iDateCount++;
				}				
			}
		}
		else if(flag==2)							// For Aplhabets
		{
			for(i=0; i<iCount; i++)
			{
				if((date[i]>=65 && date[i]<=90) || (date[i]>=97 && date[i]<=122))
				{
					acDate[iDateCount] = date[i];
					++iDateCount;
				}
			}			
		}
		else if(flag==3)							// For AlphaNumeric
		{
			for(i=0; i<iCount; i++)
			{
				if((date[i]>=48 && date[i]<=57) || (date[i]>=65 && date[i]<=90) || (date[i]>=97 && date[i]<=122))
				{
					acDate[iDateCount] = date[i];
					++iDateCount;
				}
			}
		}
		else
		{
			cout<<"INVALID FLAG PARAMETER."<<endl;
		}
	}
	//cout<<"Check 1.11 "<<acDate<<endl;
	//memset(date, 0x00, sizeof(date));
	strcpy(out, acDate);
	//myDate = acDate;
	return out;
}

/*
Author: Gaurav Kumar
Input : YY
Output: Bool
*/

bool Utility::fnLeapYearCheck(char acYear[])
{
	int year = atoi(acYear);
	if(year<50)
		year = 2000 + year;
	else
		year = 1900 + year;
	
	if((year%4 == 0) && !(year%100 == 0))
		return true;
	else if(year%400 == 0)
		return true;
	else
		return false;
}

/*
Author	: Gaurav Kumar
Date	: 29 May 2015
Input	: YYMM
Output	: int (No. of days in month)
*/
int Utility::fnDaysInMonth(char *YYMM)
{
	int	YY = 0;
	int	MM = 0;
	char	temp[2+1];
	
	memset(temp, 0x00, sizeof(temp));
	
	strncpy(temp, YYMM, 2);
	YY = atoi(temp);
	memset(temp, 0x00, sizeof(temp));
	
	strncpy(temp, YYMM+2, 2);
	MM = atoi(temp);
	
	if((MM==1) || (MM==3) || (MM==5) || (MM==7) || (MM==8) || (MM==10) || (MM==12))
		return 31;
	else if((MM==4) || (MM==6) || (MM==9) || (MM==11))
		return 30;
	else if((MM==2) && ((YY%4==0) && (YY%100!=0)) || (YY%400==0))
		return 29;
	else
		return 28;
}

/*
Author: MUKESH C PALIWAL (C1645)
Desc: This function replace space in string with input character i.e it act as replace by char
Input: String to be worked on ..and ch=char to be replaced by space
Output: Spaces in string will be replace with input ch. It modify the input and also return same string 
*/
char * Utility::fnReplaceWithCh(char* s,char ch) 
{

	if (strlen(s)>0)
	{	
		while (*s)
		{
			if (isspace(*s)) 
			 *s=ch;
			++s;   
		}
	}
	else
		printf("string empty\n");
	
	return s;

}

/*
Author: 
Desc: 
Input: 
Output: 
*/
/*
void Utility::fnStaysKey(char *a,char * b, char *c, int iLen, char *acResult)
{
	long int iKey = atoi (a) + atoi (b) + atoi (c);
	
	long int ires = iKey/iLen;
	
	sprintf(acResult, "%016d", ires);
}
*/

void Utility::fnStaysKey(char *stringbuff, int iLen, char *acResult)
{

	int	sum1=0, sum2=0, sum3=0, n, a, b, c, d, e, f;
	//char	stringbuff[100+1];
	char	dig1[5], dig2[5];

//	fnReplaceWithCh(stringbuff,'0');			// replace space by '0' VIP

//To find ascii of alphabets

	char	acLine[100+1];
	char	temp[2+1];
	int	j = 0;
	unsigned int k = 0;
	int ascii = 0;;

	memset(acLine, 0x00, sizeof(acLine));
	j = 0;

	for(k=0; k<iLen; k++)
	{
		ascii = (int)stringbuff[k];
		
		if( (ascii >= 48) && (ascii <= 57) )		// Check 0-9				
		{
			acLine[j] = stringbuff[k];	
			j++;
		}
		else					// Alphabets ascii
		{
			if(stringbuff[k] == 'A' || stringbuff[k] == 'J' || stringbuff[k] == 'S')
				acLine[j] = '1';
			else if(stringbuff[k] == 'B' || stringbuff[k] == 'K' || stringbuff[k] == 'T')
				acLine[j] = '2';
			else if(stringbuff[k] == 'C' || stringbuff[k] == 'L' || stringbuff[k] == 'U')
				acLine[j] = '3';
			else if(stringbuff[k] == 'D' || stringbuff[k] == 'M' || stringbuff[k] == 'V')
				acLine[j] = '4';
			else if(stringbuff[k] == 'E' || stringbuff[k] == 'N' || stringbuff[k] == 'W')
				acLine[j] = '5';
			else if(stringbuff[k] == 'F' || stringbuff[k] == 'O' || stringbuff[k] == 'X')
				acLine[j] = '6';
			else if(stringbuff[k] == 'G' || stringbuff[k] == 'P' || stringbuff[k] == 'Y')
				acLine[j] = '7';
			else if(stringbuff[k] == 'H' || stringbuff[k] == 'Q' || stringbuff[k] == 'Z')
				acLine[j] = '8';
			else if(stringbuff[k] == 'I' || stringbuff[k] == 'R' || stringbuff[k] == ' ')
				acLine[j] = '9';

			j++;
			
		}
	}
	//cout<<endl<<"New String :: "<<acLine<<endl<<endl;

	iLen=strlen(acLine);

// 2stays-key
	//cout<<"==============================2stays==================="<<endl;
	for(n=0; n<strlen(acLine); n=n+2)
	{
		memset(dig1, 0x00, sizeof(dig1));
		memset(dig2, 0x00, sizeof(dig2));
				
		strncpy(dig1, acLine + n, 1);
		strncpy(dig2, acLine + (n+1), 1);

		a = atoi(dig1);
		b = atoi(dig2);

		////cout<<"Num1====="<<a<<endl;
		////cout<<"Num2====="<<b<<endl<<endl;

		sum1 = a + b + sum1;
	}
	//printf("2 stays sum ============== %d \n\n", sum1);

//3stays-key
	//cout<<"==============================3stays==================="<<endl;
	for(n=0; n<strlen(acLine); n=n+4)
	{
		memset(dig1, 0x00, sizeof(dig1));
		memset(dig2, 0x00, sizeof(dig2));
		
		strncpy(dig1, acLine + n, 2);
		strncpy(dig2, acLine + (n+2), 2);

		c = atoi(dig1);
		d = atoi(dig2);

		//cout<<"Num1====="<<c<<endl;
		//cout<<"Num2====="<<d<<endl<<endl;
		sum2 = c + d + sum2;
	}
	//printf("3 stays sum ============== %d \n\n", sum2);

//4stays-key	
	//cout<<"==============================4stays==================="<<endl;
	for(n=0;n<strlen(acLine);n=n+6)
	{
		memset(dig1, 0x00, sizeof(dig1));
		memset(dig2, 0x00, sizeof(dig2));
		
		strncpy(dig1, acLine + n, 3);
		strncpy(dig2, acLine + (n+3), 3);

		e = atoi(dig1);
		f = atoi(dig2);

		//cout<<"Num1====="<<e<<endl;
		//cout<<"Num2====="<<f<<endl<<endl;
		sum3 = e + f + sum3;
	}
	//printf("4 stays sum ============== %d \n\n", sum3);

//Final String
	sprintf(acResult, "%03d%04d%05d", sum1, sum2, sum3);
	//cout<<"Resultant String :: "<<acResult<<endl<<endl;


/*	int	sum1=0, sum2=0, sum3=0, n, a, b, c, d, e, f;
	//char	stringbuff[100+1];
	char	dig1[5], dig2[5];

//	fnReplaceWithCh(stringbuff,'0');			// replace space by '0' VIP

//To find ascii of alphabets

	char	acLine[100+1];
	char	temp[2+1];
	int	j = 0;
	unsigned int k = 0;
	int ascii = 0;;

	memset(acLine, 0x00, sizeof(acLine));
	j = 0;

	for(k=0; k<iLen; k++)
	{
		ascii = (int)stringbuff[k];
		
		if( (ascii >= 48) && (ascii <= 57) )		// Check 0-9				
		{
			acLine[j] = stringbuff[k];	
			j++;
		}
		else					// Alphabets ascii
		{

			memset(temp, 0x00, sizeof(temp));
			sprintf(temp, "%d", ascii);
			//cout<<"temp======="<<temp<<endl;
			//cout<<"Ascii of "<<stringbuff[k]<<" :: "<<temp<<endl;
			acLine[j] = temp[0];
			j++;
			acLine[j] = temp[1];		
			j++;				
		}
	}
	//cout<<endl<<"New String :: "<<acLine<<endl<<endl;

	iLen=strlen(acLine);

// 2stays-key
	//cout<<"==============================2stays==================="<<endl;
	for(n=0; n<iLen; n=n+4)
	{
		memset(dig1, 0x00, sizeof(dig1));
		memset(dig2, 0x00, sizeof(dig2));
				
		strncpy(dig1, acLine + n, 2);
		strncpy(dig2, acLine + (n+2), 2);
		a = atoi(dig1);
		b = atoi(dig2);


		if(a >=0 && a <=9)
		{
			//cout<<"Num1=====["<<dig1<<"]"<<endl<<endl;							

			fnTrimSpace(dig1);
			fnRightPadwithzero(dig1, 2, '0');	
			//cout<<"Num1=====["<<dig1<<"]"<<endl<<endl;							
		}
		if(b >=0 && b <=9)
		{
			//cout<<"Num2=====["<<dig2<<"]"<<endl<<endl;					

			fnTrimSpace(dig2);
			fnRightPadwithzero(dig2, 2, '0');	
			//cout<<"Num2=====["<<dig2<<"]"<<endl<<endl;					
		}
		a = atoi(dig1);
		b = atoi(dig2);

		//cout<<"Num1====="<<a<<endl;
		//cout<<"Num2====="<<b<<endl<<endl;


		sum1 = a + b + sum1;
	}
	//printf("2 stays sum ============== %d \n\n", sum1);

//3stays-key
	//cout<<"==============================3stays==================="<<endl;
	for(n=0; n<iLen; n=n+6)
	{
		memset(dig1, 0x00, sizeof(dig1));
		memset(dig2, 0x00, sizeof(dig2));
		
		strncpy(dig1, acLine + n, 3);
		strncpy(dig2, acLine + (n+3), 3);
		c = atoi(dig1);
		d = atoi(dig2);

		if(c >=0 && c <=99)
		{
			//cout<<"Num1=====["<<dig1<<"]"<<endl<<endl;							

			fnTrimSpace(dig1);
			fnRightPadwithzero(dig1, 3, '0');	
			//cout<<"Num1=====["<<dig1<<"]"<<endl<<endl;					
		}
		if(d >=0 && d <=99)
		{
			//cout<<"Num2=====["<<dig2<<"]"<<endl<<endl;			

			fnTrimSpace(dig2);
			fnRightPadwithzero(dig2, 3, '0');
			//cout<<"Num2=====["<<dig2<<"]"<<endl<<endl;			
		}
		c = atoi(dig1);
		d = atoi(dig2);

		//cout<<"Num1====="<<c<<endl;
		//cout<<"Num2====="<<d<<endl<<endl;
		sum2 = c + d + sum2;
	}
	//printf("3 stays sum ============== %d \n\n", sum2);

//4stays-key	
	//cout<<"==============================4stays==================="<<endl;
	for(n=0; n<iLen; n=n+8)
	{
		memset(dig1, 0x00, sizeof(dig1));
		memset(dig2, 0x00, sizeof(dig2));
		
		strncpy(dig1, acLine + n, 4);
		strncpy(dig2, acLine + (n+4), 4);
		e = atoi(dig1);
		f = atoi(dig2);

		if(e >=0 && e <=999)
		{
			//cout<<"Num1=====["<<dig1<<"]"<<endl<<endl;							
			fnTrimSpace(dig1);
			fnRightPadwithzero(dig1, 4, '0');	
			//cout<<"Num1=====["<<dig1<<"]"<<endl<<endl;							
		}
		if(f >=0 && f <=999)
		{
			//cout<<"Num2=====["<<dig2<<"]"<<endl<<endl;					
			fnTrimSpace(dig2);
			fnRightPadwithzero(dig2, 4, '0');	
			//cout<<"Num2=====["<<dig2<<"]"<<endl<<endl;					
		}
		e = atoi(dig1);
		f = atoi(dig2);


		//cout<<"Num1====="<<e<<endl;
		//cout<<"Num2====="<<f<<endl<<endl;
		sum3 = e + f + sum3;
	}
	//printf("4 stays sum ============== %d \n\n", sum3);

	if(sum1 > 999)
		sum1 = 999;

	if(sum2 > 9999)
		sum2 = 9999;

	if(sum3 > 99999)
		sum3 = 99999;

//Final String
	sprintf(acResult, "%03d%04d%05d", sum1, sum2, sum3);
	//cout<<"Resultant String :: "<<acResult<<endl<<endl;
*/	
}

//YYMMDD to MMDDhhmmss,YYMMDDhhmmss format
void Utility::fnDateFormat(char acSDate[], char acDateFormat[], char acDesDate[])
{
	time_t now1 = time(0);
	tm *ltm = localtime(&now1);	

	int hh, mm, ss;
	char dformatdate[4+1];		

	hh = ltm->tm_hour;
	mm = ltm->tm_min;
	ss = ltm->tm_sec;
	
	//cout<<hh<<":"<<mm<<":"<<ss<<endl;
	
	if(strcmp(acDateFormat, "MMDDhhmmss")==0)
	{
		memset(dformatdate, 0x00, sizeof(dformatdate));
		strncpy(dformatdate,acSDate+2,4);			//mmdd
		memset(acDesDate, 0x00, sizeof(acDesDate));
		sprintf(acDesDate, "%4s%02d%02d%02d",dformatdate, hh, mm, ss);	//MMDDhhmmss
	}
	else if(strcmp(acDateFormat, "YYMMDDhhmmss")==0)
	{
		memset(acDesDate, 0x00, sizeof(acDesDate));
		sprintf(acDesDate, "%6s%02d%02d%02d",acSDate, hh, mm, ss);	//MMDDhhmmss
	}

}

// Converts Hexadecimal to Decimal using sstream
int Utility::fnConvertHexToDec(char *hexData)
{
	int		iDecNum=0;
	stringstream	ObjSStrm;
	ObjSStrm.clear();

	ObjSStrm <<hexData;
	ObjSStrm >>hex >>iDecNum;
	return iDecNum;
}

//decimal to hex
int Utility::convtodecnum(char hex[])
{
	printf("Start: hex[%s]\n",hex);
	int y;
	string z(hex);
	cout <<"input [" << z <<"]" <<endl;

	stringstream objstream;
	//cout <<"Enter number/ string: ";
	//cin >> z;
	objstream << z;
	objstream >> hex >> y;
	cout <<"Decimal Output [" << y <<"]" <<endl;
	return y;

	printf("Start: hex[%s]\n",hex);
	char *hexstr;
	int length = 2;
	const int base = 16;     // Base of Hexadecimal Number
	int decnum = 0;
/*
	string 	sInput(hex);
	cout <<"sInput [" <<sInput <<"]" <<endl;

	stringstream 	objstream;
	objstream << sInput;
	objstream >> hex >> decnum;
	cout <<decnum <<endl;
	printf("Start: Decimal no [%d]\n", decnum);
	printf("Start: Decimal no char [%c]\n", decnum);
*/
	// Find Hexadecimal Number
/*	hexstr = hex;
	for (int i = 0; *hexstr != '\0' && i < length; i++, hexstr++)
	{
	// Compare *hexstr with ASCII values
		if (*hexstr >= 48 && *hexstr <= 57)   			// is *hexstr Between 0-9
		{
			decnum += (((int)(*hexstr)) - 48) * pow(base, length - i - 1);
		}
		else if ((*hexstr >= 65 && *hexstr <= 70))  		 // is *hexstr Between A-F
		{
			decnum += (((int)(*hexstr)) - 55) * pow(base, length - i - 1);
		}
		else if (*hexstr >= 97 && *hexstr <= 102)   		// is *hexstr Between a-f
		{
			decnum += (((int)(*hexstr)) - 87) * pow(base, length - i - 1);
		}
		else
		{
			cout<<"Utility:: Invalid Hexadecimal Number \n";
		}
	}
*/
	return decnum;
}

//Hex to Decimal
void Utility::dectohex(int decimalNumber, char hexadecimalNumber[])
{
	long int remainder,quotient;
	int i=1,j,temp, k=0;
	char tp[100+1];

	quotient = decimalNumber;
	memset(tp, 0x00, sizeof(tp));
	memset(hexadecimalNumber, 0x00, sizeof(hexadecimalNumber));

	while(quotient!=0)
	{
		temp = quotient % 16;

		//To convert integer into character
		if( temp < 10)
			temp =temp + 48;
		else
			temp = temp + 55;

		tp[i++]= temp;
		quotient = quotient / 16;
	}

	for(j = i -1,k=0 ;j> 0;j--,k++)
		hexadecimalNumber[k]=tp[j];
	hexadecimalNumber[k]='\0';

	//cout<<"nEquivalent hexadecimal number of "<<decimalNumber<<" is : "<<hexadecimalNumber<<endl;
}

/*	AUTHER : abhijeet awari
 	INPUT : YYMMDD
	OUTPUT : DDMMYY
*/
char* Utility::funGetDDMMYY(char date[],char rev[])
{
	memset(rev,0x00,sizeof(rev));
	
	rev[0] = date[4];
	rev[1] = date[5];
	rev[2] = date[2];
	rev[3] = date[3];
	rev[4] = date[0];
	rev[5] = date[1];
	rev[6] = '\0';

	return rev;
}

//IP:ddmmyy
//yymmdd
char* Utility::funGetFmtDate(char date[],char rev[])
{
	memset(rev,0x00,sizeof(rev));
	
	rev[0] = date[4];
	rev[1] = date[5];
	rev[2] = date[2];
	rev[3] = date[3];
	rev[4] = date[0];
	rev[5] = date[1];
	rev[6] = '\0';

	return rev;
}


//date1:yymmdd transdate
//date2:yymmdd procdate
//return count of days between two dates(excluding sundays)

int Utility::fnDiffBetweenDates(char *acDate1, char *acDate2)		//find difference between two dates (excluding sundays)
{


	int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int first_day, second_day;

	static int months_total_temp = 0;

	int first_month, second_month;

	int first_year, second_year;

	int years_difference, days_difference;

	int months_total;

	int reg_year = 365;
	

	char acYear1[4+1];
	char acYear2[4+1];
	
	char acDay1[2+1];
	char acDay2[2+1];

	char acMonth1[2+1];
	char acMonth2[2+1];

	short days_total;

	memset(acYear1, 0x00, sizeof(acYear1));
	memset(acMonth1, 0x00, sizeof(acMonth1));
	memset(acDay1, 0x00, sizeof(acDay1));

	strncpy(acYear1, acDate1, 2);
	strncpy(acMonth1, acDate1+2, 2);
	strncpy(acDay1, acDate1+4, 2);

	memset(acYear2, 0x00, sizeof(acYear2));
	memset(acMonth2, 0x00, sizeof(acMonth2));
	memset(acDay2, 0x00, sizeof(acDay2));

	strncpy(acYear2, acDate2, 2);
	strncpy(acMonth2, acDate2+2, 2);
	strncpy(acDay2, acDate2+4, 2);

	first_day = atoi(acDay1);
	second_day = atoi(acDay2);


	first_month = atoi(acMonth1);
	second_month = atoi(acMonth2);

	first_year = atoi(acYear1);
	second_year = atoi(acYear2);

	if(first_year<50)
		first_year = 2000 + first_year;
	else
		first_year = 1900 + first_year;

	if(second_year<50)
		second_year = 2000 + second_year;
	else
		second_year = 1900 + second_year;

	//cout<<"first_year :: "<<first_year<<endl;
	//cout<<"second_year :: "<<second_year<<endl;


	if(first_day > 31 || first_day <= 0)
	{
		cout<<"UTILITY::Incorrect day1 "<<endl;
		cin.ignore();
		return 0;
	}

	if(first_month > 12 || first_month <= 0)
	{
		cout<<"UTILITY::Incorrect Month1 "<<endl;
		cin.ignore();
		return 0;
	}

	if(first_year > 9999 || first_year < 0)
	{
		cout<<"UTILITY::Incorrect Year1 "<<endl;
		cin.ignore();
		return 0;
	}

	if(second_day > 31 || second_day <= 0)
	{
		cout<<"UTILITY::Incorrect day2 "<<endl;
		cin.ignore();
		return 0;
	}
	

	if(second_month > 12 || second_month <= 0)
	{
		cout<<"UTILITY::Incorrect Month2 "<<endl;
		cin.ignore();
		return 0;
	}
	
	if(second_year > 9999 || second_year < 0)
	{
		cout<<"UTILITY::Incorrect Year2 "<<endl;
		cin.ignore();
		return 0;
	}

	/////////////////////////////Years/////////////////////////////////

	
	if(first_year == second_year)
	{
		years_difference = 0;
	}
	else
	{
		if(first_year % 4 == 0 && first_year % 100 != 0 || first_year % 400 == 0)
		{
			if(second_year % 4 == 0 && second_year % 100 != 0 || second_year % 400 == 0)
			{
				if(first_year > second_year)
				{
					years_difference = (first_year - second_year) * (reg_year) + 2;
				}
				else
				{
					years_difference = (second_year - first_year) * (reg_year) + 2;
				}
				if(second_month > first_month)
				{
					if(days_in_months[first_month - 1] > days_in_months[1])
					{
						--years_difference;
					}
				}
			}
			else
			{
				if(first_year > second_year)
				{
					years_difference = (first_year - second_year) * (reg_year) + 1;
				}
				else
				{
					years_difference = (second_year - first_year) * (reg_year) + 1;
				}
				if(first_month > second_month)
				{
					if(days_in_months[second_month - 1] > days_in_months[1])
					{
						--years_difference;
					}
				}
			}
		}
		else
		{
			if(first_year > second_year)
			{
				years_difference = (first_year - second_year) * (reg_year);
			}
			else
			{
				years_difference = (second_year - first_year) * (reg_year);
			}
		}
	}

	/////////////////////////////Months////////////////////////////////////

	
	if(first_month == second_month)
	{
		months_total = 0;
	}
	else
	{
		if(first_month > second_month)
		{
			for(int i = (first_month - 1); i > (second_month - 1); i--)
			{
				//int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
		else
		{
			for(int i = (first_month - 1); i < (second_month - 1); i++)
			{
				//int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
	}

	////////////////////////////Days//////////////////////////////////


	if (first_day == second_day)
	{
		days_difference = 0;
		days_total = (years_difference + months_total) - days_difference;
	}
	else
	{
		if(first_day > second_day)
		{
			days_difference = first_day - second_day;
			days_total = (years_difference + months_total) - days_difference;
		}
		else
		{
			days_difference = second_day - first_day;
			days_total = (years_difference + months_total) + days_difference;
		}
	}

	

	//////////////////////////In Between Leap Years///////////////////////////////

	if(first_year == second_year)
	{
	}
	else
	{
		if(first_year > second_year)
		{
			for(int i = (second_year + 1); i < first_year; i++)
			{
				if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					//cout<<endl;
					//cout<<i<<endl;
					++days_total;
				}
			}
		}
		else
		{
			for(int i = (first_year + 1); i < second_year; i++)
			{
				if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					//cout<<endl;
					//cout<<i<<endl;
					++days_total;
				}
			}
	        }
	}


	//////////////////////////Leap Year//////////////////////////////////
	
	if(first_year != second_year)
	{
		if(fnLeapYearCheck(acYear1) || fnLeapYearCheck(acYear2) )
			days_total = days_total +1;
	}


	////////////////////////////Excluding Sundays//////////////////////////////////

	//cout<<"\nThe total days in between your dates are: "<<days_total<<endl;

	int i, c, suncnt, j, lp=0;
	int total_days;

	i=0;
	c = 0;
	suncnt = 0;

	if(first_month == 2)
	{
		if(fnLeapYearCheck(acYear1))
		{
			total_days = 29;
		}
		else
			total_days = 28;
	}
	else	
		total_days = days_in_months[first_month-1];

	suncnt = 0;

	if(second_year == first_year)							//same year
	{
		if(first_month = second_month)
		{
			for(i=first_day;i<=second_day;i++)				//for same month
			{
				c = dayofweek(i, second_month, second_year);
				if(c ==0)
					suncnt++;
			}
		}
		else
		{
			for(i=first_day;i<=total_days;i++)			//1st month
			{
				c = dayofweek(i, first_month, first_year);
				if(c ==0)
					suncnt++;
			}

			for(i=1;i<second_day;i++)				//2nd month
			{
				c = dayofweek(i, second_month, second_year);
				if(c ==0)
					suncnt++;
			}
			
			for(i=first_month ;i<second_month-1;i++)	//In between Months
			{
				if(i==1)
				{
					if(fnLeapYearCheck(acYear1))
					{
						lp = 29;
					}
					else
						lp = 28;
				}
				else
					lp = days_in_months[i];
		
				for(j=1;j<=lp;j++)
				{
					c = dayofweek(j, i+1, second_year);	
					if(c==0)
						suncnt++;
				}
			}
		}
	}
	else
	{

		for(i=first_day;i<=total_days;i++)			//1st month
		{
			c = dayofweek(i, first_month, first_year);
			if(c ==0)
				suncnt++;
		}

		for(i=1;i<second_day;i++)				//2nd month
		{
			c = dayofweek(i, second_month, second_year);
			if(c ==0)
				suncnt++;
		}

		if(first_year < second_year)						//not same year
		{
			//cout<<"Suncnt::"<<suncnt<<endl;
			for(i=first_month ;i<12;i++)			//1st year months
			{
				if(i==1)
				{
					if(fnLeapYearCheck(acYear1))
					{
						lp = 29;
					}
					else
						lp = 28;
				}
				else
					lp = days_in_months[i];

				//cout<<"lp::"<<lp<<endl;
		
				for(j=1;j<=lp;j++)
				{
					c = dayofweek(j, i+1, first_year);	
					if(c==0)
						suncnt++;
				}
			}


			//cout<<"Suncnt::"<<suncnt<<endl;

			for(i=0;i<second_month-1;i++)			//2nd year months
			{
				if(i==1)
				{
					if(fnLeapYearCheck(acYear2))
					{
						lp = 29;
					}
					else
						lp = 28;
				}
				else
					lp = days_in_months[i];

				//cout<<"lp::"<<lp<<endl;
		
				for(j=1;j<=lp;j++)
				{
					c = dayofweek(j, i+1, second_year);	
					if(c==0)
						suncnt++;
				}
			}
		}
		else
		{

			for(i=second_month ;i<12;i++)			//1st year months
			{
				if(i==1)
				{
					if(fnLeapYearCheck(acYear2))
					{
						lp = 29;
					}
					else
						lp = 28;
				}
				else
					lp = days_in_months[i];

				//cout<<"lp::"<<lp<<endl;
		
				for(j=1;j<=lp;j++)
				{
					c = dayofweek(j, i+1, second_year);	
					if(c==0)
						suncnt++;
				}
			}


			//cout<<"Suncnt::"<<suncnt<<endl;

			for(i=0;i<first_month-1;i++)			//2nd year months
			{
				if(i==1)
				{
					if(fnLeapYearCheck(acYear1))
					{
						lp = 29;
					}
					else
						lp = 28;
				}
				else
					lp = days_in_months[i];

				//cout<<"lp::"<<lp<<endl;
		
				for(j=1;j<=lp;j++)
				{
					c = dayofweek(j, i+1, first_year);	
					if(c==0)
						suncnt++;
				}
			}		
		}
	}

	char acyear[4+1];
	int k;
	if( ( (first_year - second_year) > 1) || ((second_year - first_year) > 1) )
	{
		for(i =first_year+1 ; i<second_year ; i++) 
		{
			//cout<<"i::"<<i<<endl;
			for(j= 0;j <12;j++)
			{
				if(j==1)
				{
					memset(acyear, 0x00, sizeof(acyear));
					sprintf(acyear, "%d",i);
					if(fnLeapYearCheck(acyear))
					{
						lp = 29;
					}
					else
						lp = 28;
				}
				else
					lp = days_in_months[j];

				for(k=1;k<=lp;k++)
				{
					c = dayofweek(k, j+1, i);	
					if(c==0)
						suncnt++;
				}	
			}
		}
	}
	
	months_total_temp = 0;
	
	//cout<<"sunday count ::"<<suncnt<<endl;
	days_total = days_total - suncnt;
	
	return days_total;
}

//day	dd
//month	mm	
//year	yyyy
//return eg.Monday return 1
int Utility::dayofweek(int d, int m, int y)
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}



//input:yyyymmdd	eg : [20160413]
//output:ddmmyy   	eg : [130416]

void Utility::fnGetDDMMYY(char acDate[], char acFrmtDate[])
{
	memset(acFrmtDate,0x00,sizeof(acFrmtDate));
	acFrmtDate[0] = acDate[6];
	acFrmtDate[1] = acDate[7];
	acFrmtDate[2] = acDate[4];
	acFrmtDate[3] = acDate[5];
	acFrmtDate[4] = acDate[2];
	acFrmtDate[5] = acDate[3];
	acFrmtDate[6] = '\0';
}

/* It is similar to strstr only it finds in range only */ 
char* Utility::StrStrRange(char *str,int Range,char *substr)
{
	  while (*str) 
	  {
		    char *Begin = str;
		    char *pattern = substr;
		    
		    // If first character of sub string match, check for whole string
		    while (*str && *pattern && *str == *pattern) 
			  {
			      str++;
			      pattern++;
		    }
		    // If complete sub string match, return starting address 
		    if (!*pattern)
		    	  return Begin;
		    	  
		    str = Begin + 1;	// Increament main string
				
				if(!(--Range))
				break;
	  }
	  return NULL;
}
bool Utility::checkNum(char* ab){
int i;
int size;
size=strlen(ab);
for(i=0 ;  (ab[i]!='\0'&& ((ab[i] >= 48  && ab[i] <=57) || ab[i]==46)  && i<size)  ; i++);
if(i == size)
	return 1;
else
	return 0;
}

vector<string> & Utility::split(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

/*
Input: String1 to be compared with String2
Output: Return 1 when char in String1 found to be greater than one at String2,-1 when found to be less,0 when complete match
Desc:	It compares char by char in string1 with string2 ignoring case of character
*/
int Utility::StrnCmpIgnoreCase(char *s1, char *s2,short int iNoOfByt)
{
    short int i;
    for (i = 0; s1[i] && s2[i]; ++i)
    {
				// compare upto this bytes only 
				if(i==(iNoOfByt-1))
				return 0;
        /* If characters are same or inverting the 6th bit makes them same */
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
           continue;
        else
           break;
    }
 
    /* Compare the last (or first mismatching in case of not same) characters */
    if (s1[i] == s2[i])
        return 0;
    if ((s1[i]|32) < (s2[i]|32)) //Set the 6th bit in both, then compare
        return -1;
    return 1;
}
void Utility::fnCardMask(char *str)
{
	short int i=6;
	if(strlen(str)>3)
		for(i=6; i<strlen(str)-4 && (str[i++]='X'););
}

/*
Author: Gaurav Kumar
Input : char*
Output: Bool (true: success, false: failure)
*/
bool Utility::fnDirectoryExists( const char* pzPath)
{
    if ( pzPath == NULL) return false;

    DIR *pDir;
    bool bExists = false;

    pDir = opendir (pzPath);

    if (pDir != NULL)
    {
        bExists = true;
        (void) closedir (pDir);
    }

    return bExists;
}

/*
Author: Mukesh ,Sudhir
Input : filenm,outpath,filetype
output :Bool (true: success, false: failure)
*/
bool Utility::MoveFile(const char * filenm,char cTyp,const char * outpath,const char * FolderName,char cFileInd, const char * RejFoldName,const char *RejOutPath)
{
    char acSysCmd[100+1];
    MEMSET(acSysCmd);
    
 /*   sprintf(acSysCmd, "cd \"%s\" ", outpath);        // use shred command
    system(acSysCmd);
    MEMSET(acSysCmd);
    
    sprintf(acSysCmd, "mkdir \"%s\"\"%s\" ", outpath,FolderName);        // use shred command
    system(acSysCmd);
    MEMSET(acSysCmd);
    
   	sprintf(acSysCmd, "mkdir \"%s\"\"%s\" ", RejOutPath,RejFoldName);        // use shred command
    system(acSysCmd);
    MEMSET(acSysCmd);
  */  
    switch(cTyp)
    {
        case 'M':
        				
        		if(cFileInd == 'T')	
    	                        sprintf(acSysCmd, "mv \"%s\" \"%s\"", filenm,outpath);        // use shred command
                            else
	                            sprintf(acSysCmd, "mv \"%s\" \"%s\"", filenm,RejOutPath);        // use shred command
                            break;
        case 'S':
                            sprintf(acSysCmd, "shred -n 1 -u  \"%s\" ", filenm);        // use shred command
                            break;                           
    	default:			
    						cout<<"No case match of file ctype ,and default move happen"<<endl;
    						sprintf(acSysCmd, "mv \"%s\" \"%s\" ", filenm,outpath);        // use shred command
    }

    int command = system(acSysCmd);

    if( !(command) )
    { 
      printf("\t-----------FILE[%s]  MOVED  SUCCESFULLY-----------  \n ", filenm);
    }
    else
    {
    	cout<<"filenm :"<<filenm<<"  is not found in  " <<"inputpath : "<<outpath<<endl;
        return false;
    }

    return true;
}

