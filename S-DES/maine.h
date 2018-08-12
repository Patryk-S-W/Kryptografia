#pragma once
class p {
public:
	int p10[10] = { 2, 4, 1, 6, 3, 9, 0, 8, 7, 5 };
	int p10w8[8] = { 5, 2, 6, 3, 7, 4, 9, 8 };
	int pw[8] = { 1, 5, 2, 0, 3, 7, 4, 6 };
	int po[8] = { 3, 0, 2, 4, 6, 1, 7, 5 };
	int p4w8[8] = { 3, 0, 1, 2, 1, 2, 3, 0 };
	int p4[4] = { 1, 3, 2, 0 };
};

struct sb {
	bool sbox1[16][2] = { { 0, 1 },{ 1, 1 },{ 0, 0 },{ 1, 0 },{ 1, 1 },{ 0, 1 },{ 1, 0 },{ 0, 0 },{ 0, 0 },{ 1, 1 },{ 0, 1 },{ 0, 1 },{ 0, 1 },{ 1, 1 },{ 1, 1 },{ 1, 0 } };
	bool sbox2[16][2] = { { 0, 0 },{ 1, 0 },{ 0, 1 },{ 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 },{ 1, 1 },{ 1, 1 },{ 1, 0 },{ 0, 0 },{ 0, 1 },{ 0, 1 },{ 0, 0 },{ 0, 0 },{ 1, 1 } };
};

class s :public p {
	sb ciach;
	void dzielenie(bool tekst[8], bool c_1[4], bool c_2[4], bool c_2_copy[4]);
	void permutacjap4w8(bool c_2[4], bool cool[8]);
	void dodawanie_symetryczne(bool cool[8], bool klucz[8], int n);
	void dzielenie(bool tekst[8], bool c_1[4], bool c_2[4]);
	void funkcjesbox(bool c_2[4], bool sbox[4], sb ciach);
	void dziesietny(bool tiptip[4], int &a);
	void permutacjap4(bool sbox[4]);
	void laczenie(bool tekst[8], bool c_1[4], bool c_2_copy[4]);
public:
	void pwtekst(bool tekst[8]);
	void szyfrowanie(bool tekst[8], bool klucz[8]);
	void szyfrowanie2(bool tekst[8], bool klucz[8]);
	void permutacjaodw(bool tekst[8]);
	void permutujmy(bool tekst[10], bool tekst2[10], int p[10], int n);
}; 
