#ifndef ACQSWT_H
#define ACQSWT_H

#include "TTModel.h"

class AcqSwt
{
	public:
					AcqSwt();
					~AcqSwt();

					void EnrichData(Model &);
					void StoreRecordIntoMem(Model &);
};

#endif
