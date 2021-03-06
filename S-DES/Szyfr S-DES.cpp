#include <iostream>
#include <cmath>
#include "main.h"
using namespace std;


class k :public p {
public:
	void permutacjaklucza10(bool klucz[10]);
	void kluczpierwszejrundy(bool klucz[10], bool pom1[5], bool pom2[5]);
	void inline zamiana(bool klucz[5]);
	void permutacjap10w8(bool klucz[10], bool kl_sper[10]) {
		for (int i = 0; i<8; i++)
			kl_sper[i] = klucz[p10w8[i]];
	}
	void kluczdrugiejrundy(bool klucz[10], bool pom1[5], bool pom2[5]);
};

void k::permutacjaklucza10(bool klucz[10]) {
	bool p[10];
	for (int i = 0; i<10; i++)
		p[i] = klucz[p10[i]];
	for (int i = 0; i<10; i++)
		klucz[i] = p[i];
}

void k::kluczpierwszejrundy(bool klucz[10], bool pom1[5], bool pom2[5]) {
	for (int i = 0; i<5; i++)
		pom1[i] = klucz[i];
	for (int i = 0; i<5; i++)
		pom2[i] = klucz[i + 5];
	zamiana(pom1);
	zamiana(pom2);
	for (int i = 0; i<5; i++)
		klucz[i] = pom1[i];
	for (int i = 0; i<5; i++)
		klucz[i + 5] = pom2[i];
}

void inline k::zamiana(bool klucz[5]) {
	bool p = klucz[0];
	for (int i = 1; i<5; i++) { klucz[i - 1] = klucz[i]; }
	klucz[4] = p;
}

void k::kluczdrugiejrundy(bool klucz[10], bool pom1[5], bool pom2[5]) {
	for (int i = 0; i<2; i++) {
		zamiana(pom1);
		zamiana(pom2);
	}
	for (int i = 0; i<5; i++)
		klucz[i] = pom1[i];
	for (int i = 0; i<5; i++)
		klucz[i + 5] = pom2[i];
}

void s::pwtekst(bool tekst[8]) {
	bool p[8];
	for (int i = 0; i<8; i++)
		p[i] = tekst[pw[i]];
	for (int i = 0; i<8; i++)
		tekst[i] = p[i];
}
void s::dzielenie(bool tekst[8], bool c_1[4], bool c_2[4], bool c_2_copy[4]) {
	for (int i = 0; i<4; i++)
		c_1[i] = tekst[i];
	for (int i = 0; i<4; i++)
		c_2[i] = c_2_copy[i] = tekst[i + 4];
}

void s::dzielenie(bool tekst[8], bool c_1[4], bool c_2[4]) {
	for (int i = 0; i<4; i++)
		c_1[i] = tekst[i];
	for (int i = 0; i<4; i++)
		c_2[i] = tekst[i + 4];
}

void inline s::permutacjap4w8(bool c_2[4], bool cool[8]) {
	for (int i = 0; i<8; i++)
		cool[i] = c_2[p4w8[i]];
}

void inline s::dodawanie_symetryczne(bool cool[8], bool klucz[8], int n) {
	for (int i = 0; i<n; i++) {
		if (cool[i] == 1 && klucz[i] == 1)
			cool[i] = 0;
		else
			cool[i] += klucz[i];
	}

}
void s::dziesietny(bool tiptip[4], int &a) {
	for (int i = 0, j = 3; i<4; i++, j--)
		a += tiptip[j] * pow(2, i);
}
void s::funkcjesbox(bool c_2[4], bool sbox[4], sb ciach) {
	bool sbox1[2], sbox2[2];
	int a = 0;
	dziesietny(c_2, a);

	sbox1[0] = ciach.sbox1[a][0];
	sbox1[1] = ciach.sbox1[a][1];
	a = 0;
	dziesietny(sbox, a);

	sbox2[0] = ciach.sbox2[a][0];
	sbox2[1] = ciach.sbox2[a][1];
	// program testowany na przykladach z internetu, bo tylko jeden przyklad w laborce :(
	// do zmiany zaleznie od zadania
	sbox[0] = sbox1[0];
	sbox[1] = sbox1[1];
	sbox[2] = sbox2[1];
	sbox[3] = sbox2[0];
	/*
	sbox[0] = sbox1[1];
	sbox[1] = sbox1[0];
	sbox[2] = sbox2[0];
	sbox[3] = sbox2[1];
	*/

}
void s::permutacjap4(bool sbox[4]) {
	bool tia[4];
	for (int i = 0; i<4; i++)
		tia[i] = sbox[p4[i]];
	for (int i = 0; i<4; i++)
		sbox[i] = tia[i];
}

void s::laczenie(bool tekst[8], bool c_1[4], bool c_2_copy[4]) {
	for (int i = 0; i<4; i++)
		tekst[i] = c_1[i];
	for (int i = 0; i<4; i++)
		tekst[i + 4] = c_2_copy[i];
}

void s::szyfrowanie(bool tekst[8], bool klucz[8]) {
	// bool cool[8];
	bool c_1[4] = { 0 }, c_2[4] = { 0 }, c_2_copy[4] = { 0 }, sbox[4] = { 0 };
	dzielenie(tekst, c_1, c_2, c_2_copy);
	//permutacjap4w8(c_2,tekst);
	permutujmy(c_2, tekst, p4w8, 8);
	dodawanie_symetryczne(tekst, klucz, 8);
	dzielenie(tekst, c_2, sbox);
	funkcjesbox(c_2, sbox, ciach);
	permutujmy(sbox, sbox, p4, 4);
	dodawanie_symetryczne(c_1, sbox, 4);
	laczenie(tekst, c_2_copy, c_1);
	cout << "tekst po zaszyfrowaniu kluczem 1 rundy: ";
	for (int i = 0; i<8; i++)
		cout << tekst[i];
	cout << "\n";
}

void s::szyfrowanie2(bool tekst[8], bool klucz[8]) {
	bool cool[8];
	bool c_1[4] = { 0 }, c_2[4] = { 0 }, c_2_copy[4] = { 0 }, sbox[4] = { 0 };
	dzielenie(tekst, c_1, c_2, c_2_copy);
	permutujmy(c_2, tekst, p4w8, 8);
	dodawanie_symetryczne(tekst, klucz, 8);
	dzielenie(tekst, c_2, sbox);
	funkcjesbox(c_2, sbox, ciach);
	//permutacjap4(sbox);
	permutujmy(sbox, sbox, p4, 4);
	dodawanie_symetryczne(c_1, sbox, 4);
	laczenie(tekst, c_1, c_2_copy);
	cout << "tekst po zaszyfrowaniu kluczem 2 rundy: ";
	for (int i = 0; i<8; i++)
		cout << tekst[i];
	cout << "\n";
}

void s::permutacjaodw(bool tekst[8]) {
	bool cos[8];
	for (int i = 0; i<8; i++)
		cos[i] = tekst[po[i]];
	for (int i = 0; i<8; i++)
		tekst[i] = cos[i];
}


void s::permutujmy(bool tekst[10], bool tekst2[10], int pe[10], int n) {
	bool p[10];
	for (int i = 0; i<n; i++)
		p[i] = tekst[pe[i]];
	for (int i = 0; i<n; i++)
		tekst2[i] = p[i];
}
int main() {
	bool tekst[] = { 1,0,1,0,1,0,1,0 };
	bool klucz[] = { 1,1,0,0,0,0,0,0,1,1 };
	bool pom1[5] = { 0 };
	bool pom2[5] = { 0 };
	bool kl_1_rundy[8] = { 0 };
	bool kl_2_rundy[8] = { 0 };
	k kl;
	s szyfrujemy;
	cout << "klucz poczatkowy: ";
	for (int i = 0; i<10; i++)
		cout << klucz[i];
	cout << endl;

	kl.permutacjaklucza10(klucz);
	kl.kluczpierwszejrundy(klucz, pom1, pom2);
	kl.permutacjap10w8(klucz, kl_1_rundy);
	cout << "klucz pierwszej rundy: ";
	for (int i = 0; i<8; i++)
		cout << kl_1_rundy[i];
	cout << endl;
	kl.kluczdrugiejrundy(klucz, pom1, pom2);
	kl.permutacjap10w8(klucz, kl_2_rundy);
	cout << "klucz drugiej rundy: ";
	for (int i = 0; i<8; i++)
		cout << kl_2_rundy[i];
	cout << endl;

	cout << "tekst: ";
	for (int i = 0; i<8; i++)
		cout << tekst[i];
	cout << endl;
	szyfrujemy.pwtekst(tekst);
	szyfrujemy.szyfrowanie(tekst, kl_1_rundy);
	szyfrujemy.szyfrowanie2(tekst, kl_2_rundy);
	szyfrujemy.permutacjaodw(tekst);
	cout << "tekst po zaszyfrowaniu: ";
	for (int i = 0; i<8; i++)
		cout << tekst[i];
	cout << "\n\n\n";

	szyfrujemy.pwtekst(tekst);
	szyfrujemy.szyfrowanie(tekst, kl_2_rundy);
	szyfrujemy.szyfrowanie2(tekst, kl_1_rundy);
	szyfrujemy.permutacjaodw(tekst);
	cout << "po odszyfrowaniu: ";
	for (int i = 0; i<8; i++)
		cout << tekst[i];
	cout << "\n";
	system("pause");
	return 0;
}
