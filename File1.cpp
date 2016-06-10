#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

#include <stdio.h>
#include "KEY.h"
#include "DES.h"

int _tmain(int argc, _TCHAR* argv[]) {
	/*
	 DES d;
		d.setMSG("neronero");
		d.setKEY("neronero");
		d.Encription();
		*/
	 DES d;
		d.setMSG("jó'±ïü");
		d.setKEY("neronero");
        d.Description();
	getch();
	return 0;
}
