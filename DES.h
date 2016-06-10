#ifndef MYDES
#define MYDES
#include <iostream.h>
#include <string>
#include <string.h>
#include <conio.h>
#include <bitset>
#include <fstream>
#include "KEY.h"

class DES {
private:
	string msg, bmsg;
	string L, R;
	KEY key;

public:
	DES();
	DES(string);
	~DES();
	void setMSG(string);
	void setKEY(string);
	void IP();
	string F(int);
	string xor(string, string);

	string SBOX(string);
	string S1(int,int);
	string S2(int,int);
	string S3(int,int);
	string S4(int,int);
	string S5(int,int);
	string S6(int,int);
	string S7(int,int);
	string S8(int,int);

	void Encription();
	void Description();
	void RIP();
	void DecBIT();
};
#endif
