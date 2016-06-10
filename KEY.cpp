#include "KEY.h"

KEY::~KEY() {
};

KEY::KEY() {
};

KEY::KEY(string k) : key(k) {
	for (int i = 0; i < key.length(); i++) {
		bitset<CHAR_BIT>bit(key[i]);
		bk += bit.to_string();
	}
	PC1();
	CreateSubKey();
	prtSK();
};

void KEY::setKey(string k) {
	this->key = k;
	for (int i = 0; i < key.length(); i++) {
		bitset<CHAR_BIT>bit(key[i]);
		bk += bit.to_string();
	}
	PC1();
	CreateSubKey();
	prtSK();
};

void KEY::PC1() {
	C, D = "";
	char C0[4][8] = {
		{bk[56], bk[48], bk[40], bk[32], bk[24], bk[16], bk[8]},
		{bk[0], bk[57], bk[49], bk[41], bk[33], bk[25], bk[17]},
		{bk[9], bk[1], bk[58], bk[50], bk[42], bk[34], bk[26]},
		{bk[18], bk[10], bk[2], bk[59], bk[51], bk[43], bk[35]}};
	char D0[4][8] = {
		{bk[62], bk[54], bk[46], bk[38], bk[30], bk[22], bk[14]},
		{bk[6], bk[61], bk[53], bk[45], bk[37], bk[29], bk[21]},
		{bk[13], bk[5], bk[60], bk[52], bk[44], bk[36], bk[28]},
		{bk[20], bk[12], bk[4], bk[27], bk[19], bk[11], bk[3]}};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			C += C0[i][j];
			D += D0[i][j];
		}
	}
};

string KEY::ZSUV(string x, int val) {
	string t = "";
	for (int i = val; i < x.length(); i++) {
		t += x[i];
	}
	for (int i = 0; i < val; i++) {
		t += x[i];
	}
	return t;
};

void KEY::CreateSubKey() {
	for (int i = 0; i < 16; i++) {
		if ((i == 0) || (i == 1) || (i == 8) || (i == 15)) {
			C = ZSUV(C, 1);
			D = ZSUV(D, 1);
		}
		else {
			C = ZSUV(C, 2);
			D = ZSUV(D, 2);
		};
		sbc[i] = PC2();
	}
};

string KEY::PC2() {
	string n = C + D;
	string t = "";
	char P2[8][6] = {
		{n[13], n[16], n[10], n[23], n[0], n[4]},
		{n[2], n[27], n[14], n[5], n[20], n[9]},
		{n[22], n[18], n[11], n[3], n[25], n[7]},
		{n[15], n[6], n[26], n[19], n[12], n[1]},
		{n[40], n[51], n[30], n[36], n[46], n[54]},
		{n[29], n[39], n[50], n[44], n[32], n[47]},
		{n[43], n[48], n[38], n[55], n[33], n[52]},
		{n[45], n[41], n[49], n[35], n[28], n[31]}};
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 6; j++) {
			t += P2[i][j];
		}
	}
	return t;
};

string KEY::getSubKey(int index) {
	return sbc[index];
};

void KEY::prtSK() {
	ofstream file;
	file.open("sub_key.txt");
	for (int i = 0; i < 16; i++) {
		file << getSubKey(i)<<endl;
	}
	file.close();
};
