#include "DES.h"

DES::DES() {
};

DES::DES(string m) : msg(m) {
	for (int i = 0; i < msg.length(); i++) {
		bitset<CHAR_BIT>bit(msg[i]);
		bmsg += bit.to_string();
	}
	key.setKey("neronero");
	IP();
	Encription();
};

DES::~DES() {
};

void DES::setMSG(string m) {
	this->msg = m;
	for (int i = 0; i < msg.length(); i++) {
		bitset<CHAR_BIT>bit(msg[i]);
		bmsg += bit.to_string();
	}
};

void DES::setKEY(string k) {
	key.setKey(k);
};

void DES::Encription() {
	IP();
	for (int i = 0; i < 16; i++) {
		string test = "";
		test = R;
		L = xor(L, F(i));
		R = L;
		L = test;
	}
	bmsg = R + L;
	RIP();
	cout << bmsg << endl;
	DecBIT();
};

void DES::Description() {
	IP();
	for (int i = 0; i < 16; i++) {
		string test = "";
		test = R;
		L = xor(L, F(15 - i));
		R = L;
		L = test;
	}
	bmsg = R + L;
	RIP();

	cout<<bmsg<<endl;
	ofstream file;
	file.open("Description.txt");
	file << bmsg << endl;
	for (int i = 0; i < 64; i += 8) {
		string val = "";
		for (int j = i; j < i + 8; j++) {
			val += bmsg[j];
		}
		bitset<CHAR_BIT>sim(val);
		cout << char(sim.to_ulong());
		file << char(sim.to_ulong());
	}
	file.close();
};

void DES::IP() {
	string t = "";
	L, R = "";
	char IP[8][8] = {
		{bmsg[57], bmsg[49], bmsg[41], bmsg[33], bmsg[25], bmsg[17], bmsg[9],
				bmsg[1]}, {bmsg[59], bmsg[51], bmsg[43], bmsg[35], bmsg[27],
				bmsg[19], bmsg[11], bmsg[3]},
		{bmsg[61], bmsg[53], bmsg[45], bmsg[37], bmsg[29], bmsg[21], bmsg[13],
				bmsg[5]}, {bmsg[63], bmsg[55], bmsg[47], bmsg[39], bmsg[31],
				bmsg[23], bmsg[15], bmsg[7]},
		{bmsg[56], bmsg[48], bmsg[40], bmsg[32], bmsg[24], bmsg[16], bmsg[8],
				bmsg[0]}, {bmsg[58], bmsg[50], bmsg[42], bmsg[34], bmsg[26],
				bmsg[18], bmsg[10], bmsg[2]},
		{bmsg[60], bmsg[52], bmsg[44], bmsg[36], bmsg[28], bmsg[20], bmsg[12],
				bmsg[4]}, {bmsg[62], bmsg[54], bmsg[46], bmsg[38], bmsg[30],
				bmsg[22], bmsg[14], bmsg[6]}};
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			t += IP[i][j];
		}
	}
	bmsg = t;
	for (int i = 0; i < 32; i++) {
		L += bmsg[i];
		R += bmsg[i + 32];
	}
};

string DES::xor(string a, string b) {
	string t = "";
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == b[i]) {
			t += "0";
		}
		else {
			t += "1";
		};
	}
	return t;
};

string DES::F(int step) {
	string E = "";
	char F[8][6] = {
		{R[31], R[0], R[1], R[2], R[3], R[4]},
		{R[3], R[4], R[5], R[6], R[7], R[8]},
		{R[7], R[8], R[9], R[10], R[11], R[12]},
		{R[11], R[12], R[13], R[14], R[15], R[16]},
		{R[15], R[16], R[17], R[18], R[19], R[20]},
		{R[19], R[20], R[21], R[22], R[23], R[24]},
		{R[23], R[24], R[25], R[26], R[27], R[28]},
		{R[27], R[28], R[29], R[30], R[31], R[0]}};

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 6; j++) {
			E += F[i][j];
		}
	}
	string over = SBOX(xor(E, key.getSubKey(step)));
	char P[4][8] = {
		{over[15], over[6], over[19], over[20], over[28], over[11], over[27],
				over[16]}, {over[0], over[14], over[22], over[25], over[4],
				over[17], over[30], over[9]},
		{over[1], over[7], over[23], over[13], over[31], over[26], over[2],
				over[8]}, {over[18], over[12], over[29], over[5], over[21],
				over[10], over[3], over[24]}};
	string the_end = "";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			the_end += P[i][j];
		}
	}
	return the_end;
};

void DES::RIP() {
	string t = "";
	char IP[8][8] = {
		{bmsg[39], bmsg[7], bmsg[47], bmsg[15], bmsg[55], bmsg[23], bmsg[63],
				bmsg[31]}, {bmsg[38], bmsg[6], bmsg[46], bmsg[14], bmsg[54],
				bmsg[22], bmsg[62], bmsg[30]},
		{bmsg[37], bmsg[5], bmsg[45], bmsg[13], bmsg[53], bmsg[21], bmsg[61],
				bmsg[29]}, {bmsg[36], bmsg[4], bmsg[44], bmsg[12], bmsg[52],
				bmsg[20], bmsg[60], bmsg[28]},
		{bmsg[35], bmsg[3], bmsg[43], bmsg[11], bmsg[51], bmsg[19], bmsg[59],
				bmsg[27]}, {bmsg[34], bmsg[2], bmsg[42], bmsg[10], bmsg[50],
				bmsg[18], bmsg[58], bmsg[26]},
		{bmsg[33], bmsg[1], bmsg[41], bmsg[9], bmsg[49], bmsg[17], bmsg[57],
				bmsg[25]}, {bmsg[32], bmsg[0], bmsg[40], bmsg[8], bmsg[48],
				bmsg[16], bmsg[56], bmsg[24]}};

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			t += IP[i][j];
		}
	}
	bmsg = t;
};

void DES::DecBIT() {
	ofstream file;
	file.open("Encript.txt");
	file << bmsg << endl;
	for (int i = 0; i < 64; i += 8) {
		string val = "";
		for (int j = i; j < i + 8; j++) {
			val += bmsg[j];
		}
		bitset<CHAR_BIT>sim(val);
		cout << char(sim.to_ulong());
		file << char(sim.to_ulong());
	}
	file.close();
};
