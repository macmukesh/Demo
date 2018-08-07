#include "BaseParser.h"
#include "enum_DCF.h"
#include "Utility.h"

class DCF:public BaseParser
{
	public:
					DCF();
					~DCF();					

	private:
					Utility			ObjUtility;
					void ValidateInputRawData(const char *,size_t);
					void IdentifyParserCd(const char *,size_t,PARSERCD &);
					void TransformCol(const char *,const StructTTUB::TTCOL &,char * out);

					void SetHdrFormat(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &);
					void SetTrlFormat(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &);
					void SetD1Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &);
					void SetD2Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &);
					void SetD3Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &);
					void SetD4Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &);
					void SetD5Format(const unsigned int,unsigned int &,FMTATTR &,StructTTUB::TTCOL &,string &);
};

