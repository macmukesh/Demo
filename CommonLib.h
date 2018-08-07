/*******************************************************************/
/*
   COPYRIGHT NOTICE
   Copyright @ 2013 In-Solutions Global Pvt Ltd (ISG). All rights reserved.

   These materials are confidential and proprietary to In-Solutions Global Pvt Ltd (ISG) and no part of these materials should be reproduced, published, transmitted or distributed in any form or by any means, electronic, mechanical, photocopying, recording or otherwise, or stored in any information storage or retrieval system of any nature nor should the materials be disclosed to third parties or used in any other manner for which this is not authorized, without the prior express written authorization of In-Solutions Global Pvt Ltd (ISG) Pvt Ltd. */
/*                                                                 */
/*******************************************************************/

/**********************************************************************
 *
 * Module Name         : 
 * File Name           :
 * Description         :  
 *
 *            Version Control Block
 *            ---------------------
 * Date             Version     Author               Description
 * ---------       --------  ---------------  ---------------------------
  13 Nov 14	    1.1            
*******************************************************************/

#ifndef _COMMONLIB_H_
#define _COMMONLIB_H_


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/socket.h>

#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/time.h>

#include <exception>

#include <malloc.h>
#include <time.h>
#include <dlfcn.h>
#include <sys/sem.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <pthread.h>
#include <math.h>
#include <assert.h>

#include <cstring>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <algorithm>
#include <typeinfo>
#include <exception>
#include <stdexcept>
#include <signal.h>
#include <execinfo.h>

#define MEMSET(Buffer)   	    memset(Buffer,0x00,sizeof(Buffer))

using namespace std;


#endif //_FRAMEWORKCOMMON_H_
