#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string t;
int wartosc(char a) { return (a - 97) % 26; }

string vinegrette(string t, string k){
	int j = 0;
	for (int i = 0; i < t.length(); i++, j++){
		if (j == k.length()) j = 0;
		t[i] = (wartosc(t[i]) + wartosc(k[j])) % 26 + 97;
	}
	return t;
}

double ksapuq(string c) {
	int l = 0, N = c.length();
	double s = 0.0;
	char a = 'a';

	for (int i = 0; a <= 'z'; i++) {
		if (i == N + 1) {
			i = 0;
			a++;
			s += l*(l - 1);
			l = 0;
		}
		if (c[i] == a) l++;
	}

	return s / (N*(N - 1));
}

double koi(string c1, string c2) {
	int lk1 = 0, lk2 = 0, k0 = c1.length(), k1 = c2.length(), k = k0;
	double s = 0.0;
	char a = 'a';
	if (k > k1) k = k1;

	for (int i = 0; a <= 'z'; i++) {
		if (i == k + 1) {
			i = 0;
			a++;
			s += lk1*lk2;
			lk1 = 0;
			lk2 = 0;
		}
		if (c1[i] == a) lk1++;
		if (c2[i] == a) lk2++;
	}

	return s / (k0*k1);
}

int main() {
	bool b = false;
	const double ang = 0.06735, idk = 1.0 / 100;
	string *c;
	int col, ncol = 0;
	double sum_t = 0, sr;
	fstream file;
	string str;
	string k = "abc";

	file.open("tekst.txt", ios::in);
	getline(file, str);
	file.close();

	t = vinegrette(str, k);

	file.open("zaszyfrowany.txt", ios::out);
	file << t;
	file.close();

	cout << "nr kolumny: ";
	cin >> col;
	cout << endl;
	c = new string[col];
	c[0] = str;
	c[1] = t;
	for (int i = 0; i < t.length(); i++) {
		c[ncol] += t[i];
		ncol++;
		if (ncol == col) ncol = 0;
	}
	for (int i = 0; i < col; i++) {
		sum_t += ksapuq(c[i]);
		cout << i + 1 << ": " << ksapuq(c[i]) << endl;
	}
	sr = sum_t / col;
	if ((ang - sr) <= idk && !b) cout << "dlugosc klucza: " << col << endl;

	for (int i = 0; i < col - 1; i++)
		cout << "wspolczynnik: " << koi(c[0], c[i + 1]) << endl;

	system("pause");
	return 0;
}