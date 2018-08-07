#ifndef _COMMONMACRO_H_
#define _COMMONMACRO_H_

#define FAILURE 		    0
#define SUCCESS 		    1
#define MEMSET(Buffer)   	    memset(Buffer,0x00,sizeof(Buffer))

#define SYSTEM_CONFIGURATION2_FILE		"../config/SYSTEM2.xml"
#define SYSTEM_CONFIGURATION3_FILE		"../config/SYSTEM3.xml"

#define MAX_DATA_TABLE_COUNT	20

#define MAX_TOKEN_FORMATTER_LEN 2048
#define MAX_SINGLE_RECORD_LEN   4096

#define MAX_TANKNM_LEN		   	25+1
#define MAX_TABLENM_LEN		   	25+1

#define MAX_DATE_LEN			6+1
#define MAX_FILE_NAME_LEN       50+1

#define DEFAULT_DATE			"991231"


#define MAX_FILENMWITHPATH_LEN  250+1
#define MAX_PATH_LEN 			200+1
#define FMAP					0
#define FSTREAM					1

// MAIN PARSER TYPE
#define MPT_MST_INCOM			1
#define MPT_MST_NP				2
#define MPT_VISA_INCOM			3
#define MPT_MAESTRO_INCOM		4
#define MPT_PTLF				5
#define MPT_MMAP				6
#define MPT_STREAM				7	
#define MPT_VISA_EP				8
#define MPT_MAESTRO_BIN			9
//PARSERCODE
// Visa
#define	CTF 		101
#define EP204 	102
#define ARDEF 	103
//Master
#define TT464 	201
#define TT112		202
#define TT113		203
#define TT057		204
#define TT067		205
#define TT068		206
#define TT458		207
//Master Incoming
#define MAXSUBFLDS 1
#define FIELDLEN     999 
#define MAX_DE 128
#define MAX_PDS 800/*1-799 PDS + 1 PDS800-PDS999 + 1 PDS10XX=801 in total.*/
#define MAX_ELEMENTS (MAX_DE+MAX_PDS+1) /*128+801=929*/
#define MAX_DATA 1000
#define MAX_BUFFER_LENGTH 3000
#define TOT_REC_FOR_CHECKING_BLOCK 5
#define DATA_POS 20
#define TOT_BITMAP 16
#define BYTE 7
#define MSTHDRCOUNT 100

//Rupay
#define ACK02		301
#define ACK04		302
#define IC01		303
#define IC81		304
#define IC83		305
//Diner
#define ACF			401
#define CYCL		402
//ONUS
#define ICOCB		501
//OFFUS
#define OGVRJ		601


//ENDOFPARSERCODE



#endif //_COMMONMACRO_H_
