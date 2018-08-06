#ifndef TankInterface_H
#define TankInterface_H

#include "TTModel.h"

class TankInterface
{
	public:
					TankInterface();
					~TankInterface();
					// parallel
					virtual void EnrichData(Model &)=0;
					// sequential 
					virtual void StoreRecordIntoMem(Model &)=0;
};

#endif
