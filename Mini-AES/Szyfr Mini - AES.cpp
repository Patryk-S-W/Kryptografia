#include <iostream>
#include <cmath>
#include <Windows.h>
#include <string>

using namespace std;

template <size_t N>
void show(string s, int(&a)[N]) {
	cout << s;
	for (int i : a)
		cout << i;
	cout << endl;
}

void Sbox(int *s, int *S, int n, bool a) {
	int sm = 10000 + s[0 + n] * 1000 + s[1 + n] * 100 + s[2 + n] * 10 + s[3 + n];
	if (a)
		switch (sm) {
		case 11110: {S[0] = 0; S[1] = 0; S[2] = 0; S[3] = 0; } break;
		case 10011: {S[0] = 0; S[1] = 0; S[2] = 0; S[3] = 1; } break;
		case 10100: {S[0] = 0; S[1] = 0; S[2] = 1; S[3] = 0; } break;
		case 11000: {S[0] = 0; S[1] = 0; S[2] = 1; S[3] = 1; } break;
		case 10001: {S[0] = 0; S[1] = 1; S[2] = 0; S[3] = 0; } break;
		case 11100: {S[0] = 0; S[1] = 1; S[2] = 0; S[3] = 1; } break;
		case 11010: {S[0] = 0; S[1] = 1; S[2] = 1; S[3] = 0; } break;
		case 11111: {S[0] = 0; S[1] = 1; S[2] = 1; S[3] = 1; } break;
		case 10111: {S[0] = 1; S[1] = 0; S[2] = 0; S[3] = 0; } break;
		case 11101: {S[0] = 1; S[1] = 0; S[2] = 0; S[3] = 1; } break;
		case 11001: {S[0] = 1; S[1] = 0; S[2] = 1; S[3] = 0; } break;
		case 10110: {S[0] = 1; S[1] = 0; S[2] = 1; S[3] = 1; } break;
		case 11011: {S[0] = 1; S[1] = 1; S[2] = 0; S[3] = 0; } break;
		case 10010: {S[0] = 1; S[1] = 1; S[2] = 0; S[3] = 1; } break;
		case 10000: {S[0] = 1; S[1] = 1; S[2] = 1; S[3] = 0; } break;
		case 10101: {S[0] = 1; S[1] = 1; S[2] = 1; S[3] = 1; } break;
		}
	else
		switch (sm) {
		case 11110: {S[0] = 0; S[1] = 0; S[2] = 0; S[3] = 0; } break;
		case 10100: {S[0] = 0; S[1] = 0; S[2] = 0; S[3] = 1; } break;
		case 11101: {S[0] = 0; S[1] = 0; S[2] = 1; S[3] = 0; } break;
		case 10001: {S[0] = 0; S[1] = 0; S[2] = 1; S[3] = 1; } break;
		case 10010: {S[0] = 0; S[1] = 1; S[2] = 0; S[3] = 0; } break;
		case 11111: {S[0] = 0; S[1] = 1; S[2] = 0; S[3] = 1; } break;
		case 11011: {S[0] = 0; S[1] = 1; S[2] = 1; S[3] = 0; } break;
		case 11000: {S[0] = 0; S[1] = 1; S[2] = 1; S[3] = 1; } break;
		case 10011: {S[0] = 1; S[1] = 0; S[2] = 0; S[3] = 0; } break;
		case 11010: {S[0] = 1; S[1] = 0; S[2] = 0; S[3] = 1; } break;
		case 10110: {S[0] = 1; S[1] = 0; S[2] = 1; S[3] = 0; } break;
		case 11100: {S[0] = 1; S[1] = 0; S[2] = 1; S[3] = 1; } break;
		case 10101: {S[0] = 1; S[1] = 1; S[2] = 0; S[3] = 0; } break;
		case 11001: {S[0] = 1; S[1] = 1; S[2] = 0; S[3] = 1; } break;
		case 10000: {S[0] = 1; S[1] = 1; S[2] = 1; S[3] = 0; } break;
		case 10111: {S[0] = 1; S[1] = 1; S[2] = 1; S[3] = 1; } break;
		}
}

void s(int *t1, int *t2, int *r, int f) {
	for (int i = 0; i < f; i++)
		r[i] = (t1[i] + t2[i]) % 2;
}

void z(int *a1, int *a2) {
	for (int i = 0; i < 8; i++)
		a1[i] = a2[i];
	for (int i = 0; i < 4; i++) {
		a1[8 + i] = a2[12 + i];
		a1[12 + i] = a2[8 + i];
	}
}

void mat(int *t, int *r, int l, int k) {
	int m1[4][8], t1[16] = { 0,0,1,1,0,0,1,0,0,0,1,0,0,0,1,1 };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 7; j++)
			m1[i][j] = 0;
	for (int j = 0; j < 4; j++)
		if (t[j + k] == 1)
			for (int i = 0; i < 4; i++)
				m1[j][i + j] = t1[i + l];
	for (int i = 0; i < 7; i++)
		r[i] = (((m1[0][i] + m1[1][i]) % 2 + m1[2][i]) % 2 + m1[3][i]) % 2;
}

void split(int *t1, int *t2) {
	int a[5] = { 1, 0, 0, 1, 1 };
	for (int i = 0; i < 3; i++)
		if (t1[i] == 1)
			for (int j = 0; j < 5; j++)
				t1[i + j] ^= a[j];
	for (int i = 0; i < 4; i++)
		t2[i] = t1[i + 3];
}
void mm(int *m, int *w) {
	int r1[4], r2[4], r3[4], r4[4], a1[7], a2[7], a3[7], a4[7], a5[7], a6[7], a7[7], a8[7], d1[7], d2[7], d3[7], d4[7], d5[7], d6[7], d7[7], d8[7];

	mat(m, a1, 12, 12);mat(m, a2, 8, 4);mat(m, a3, 12, 8);mat(m, a4, 8, 0);
	mat(m, a5, 4, 12);mat(m, a6, 0, 4);mat(m, a7, 4, 8);mat(m, a8, 0, 0);
	s(a8, a7, d1, 7);s(a6, a5, d2, 7);s(a4, a3, d3, 7);s(a2, a1, d4, 7);
	split(d1, r1);split(d2, r2);split(d3, r3);split(d4, r4);

	for (int i = 0; i < 4; i++) {
		w[i] = r1[i];
		w[4 + i] = r2[i];
		w[8 + i] = r3[i];
		w[12 + i] = r4[i];
	}
}

void f(int *m, int *r, bool f) {
	int c1[4], c2[4], c3[4], c4[4];
		Sbox(m, c1, 0, f);Sbox(m, c2, 4, f);Sbox(m, c3, 8, f);Sbox(m, c4, 12, f);

	for (int i = 0; i < 4; i++) {
		r[i] = c1[i];
		r[4 + i] = c2[i];
		r[8 + i] = c3[i];
		r[12 + i] = c4[i];
	}
}


int main() {
	int k1[16], k2[16], z_k1[16], dk[16], z_k2[16], _mm[16],
		si[16], sb[4], fsb1[16], fsb2[16], c1[4] = { 0,0,0,1 }, c2[4] = { 0,0,1,0 }, t[16],
		A, B, C, D;
	cout << "wpisz: \n A, B, C, D: \n";
	cin >> A >> B >> C >> D;
	int k_p[16] = { A,0,1,1,0,B,1,0,1,1,1,C,D,1,1,0 }, // 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0
		tekst[16] = { 0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1 }; // 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1

	s(tekst, k_p, t, 16);
	Sbox(k_p, sb, 12, true);

	for (int i = 0; i < 4; i++) {
		k1[i] = ((k_p[i] + sb[i]) % 2 + c1[i]) % 2;
		k1[8 + i] = (k_p[8 + i] + k1[i]) % 2;
		k1[4 + i] = (k_p[4 + i] + k1[8 + i]) % 2;
		k1[12 + i] = (k_p[12 + i] + k1[4 + i]) % 2;
	}

	Sbox(k1, sb, 12, true);

	for (int i = 0; i < 4; i++) {
		k2[i] = ((k1[i] + sb[i]) % 2 + c2[i]) % 2;
		k2[8 + i] = (k2[i] + k1[8 + i]) % 2;
		k2[4 + i] = (k2[8 + i] + k1[4 + i]) % 2;
		k2[12 + i] = (k2[4 + i] + k1[12 + i]) % 2;
	}

	show("klucz rundy pierwszej: ", k1);
	show("klucz rundy drugiej:", k2);

	f(t, fsb1, true);
	z(z_k1, fsb1);
	mm(z_k1, _mm);
	s(_mm, k1, dk, 16);
	f(dk, fsb2, true);
	z(z_k2, fsb2);
	s(z_k2, k2, si, 16);

	show("po FSBox(tekst, E): ", fsb1);
	show("po ZK(tekst): ", z_k1);
	show("staly*tekst: ", _mm);
	show("k1 + tekst: ", dk);
	show("po FSBox(tekst, E): ", fsb2);
	show("po ZK(tekst): ", z_k2);
	show("k2 + tekst: ", si);

	system("pause");
	return 0;
}