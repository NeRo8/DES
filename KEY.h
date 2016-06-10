#ifndef KEYS
#define KEYS
#include <iostream.h>
#include <string>
#include <string.h>
#include <conio.h>
#include <bitset>
#include <fstream>
class KEY {
private:
	string key, bk;
	string sbc[16];
	string C, D;

public:
	KEY();
	KEY(string);
	~KEY();
	string ZSUV(string, int);
	void PC1();
	void CreateSubKey();
	string PC2();
	string getSubKey(int);
	void setKey(string);
	void prtSK();
};
#endif
