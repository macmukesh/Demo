//#include "FileReader.h"
#include "AppendFormat.h"
#include "MPOS.h"
#include "AcqSwt.h"

int main(int argc,char * argv[])
{
	if(argc==1)
	{
		cout<<"Plz pass Input filenm to be read as arg"<<endl;
		return 0;
	}

	FileReader * ptrFR = new AppendFormat();
	BaseParser * ptrParser=new MPOS();
	AcqSwt * ptrAcq = new AcqSwt();
	
	char filnm[300];
	memset(filnm,0x00,sizeof(filnm));
	strcpy(filnm,argv[1]);
	try
	{
			ptrFR->Open(filnm);
			ptrParser->Init();	
	}
	catch(FileReadException & fx)
	{
		cout<<"Error while file operation.."<<fx.what()<<endl;
		return 0;
	}

	vector<ArrBufferData> vecData;
	unsigned int vecsz=0;
	// enter cyclic loop
	try
	{
			while(!ptrFR->IsEOF())
			{
				// prepare data
				vecData=ptrFR->GetBufferData();
				vecsz=vecData.size();
				for(int ix=0;ix<vecsz;++ix)
				{
					cout<<vecData[ix].acRawdata<<endl;	
					ptrParser->Process(vecData[ix]);
					ptrAcq->EnrichData(vecData[ix].ObjTT);
				}
				// P12...convert commondata into respective struct
				// store into mem..carry out update on it
			}
	}
	catch(FileReadException & fx)
	{
		cout<<"Error while file operation.."<<fx.what()<<endl;
		return 0;
	}


}


