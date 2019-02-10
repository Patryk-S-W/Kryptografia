#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;
typedef unsigned long long ull;

int _mod(int a, long long int b, int c) {
	long long int r = a;
	if (b == 1) return abs(a%c);
	for (int i = 1; i < b; i++)
		r = abs(r*a % c);

	return r;
}

void Fer(unsigned int p, vector<int> &v, vector<int> &s) {
	while (p % 2 == 0) {
		p /= 2;
		v.push_back(2);
	}
	ull a, b, x, y;

	a = (ull)ceil(sqrt(p));
	do {
		b = (ull)floor(sqrt(a * a - p));
		if (a * a - p == b * b) {
			x = a + b;
			y = a - b;
			if (y == 1) break;
			Fer(x, v, s);
			Fer(y, v, s);
			return;
		}
		a++;
	} while (a + b < p);
	v.push_back(p);
	sort(v.begin(), v.end());
	s = v;
}


int um(int a, int b){
	int u, w, x, z, q;
	u = 1; w = a;
	x = 0; z = b;
	while (w){
		if (w < z){
			q = u; u = x; x = q;
			q = w; w = z; z = q;
		}
		q = w / z;
		u -= q * x;
		w -= q * z;
	}
	if (z == 1){
		if (x < 0) x += b;
		return x;
	}
}


bool p(int n) {
	int i = 5, w = 2;
	while (i * i <= n) {
		if(n % i == 0)
			return false;

		i = i + w;
		w = 6 - w;
	}
	return true;
}

bool pier(int n) {
	if (n == 2) return true;
	if (n == 3) return true;
	if (n % 2 == 0) return false;
	if (n % 3 == 0) return false;
	p(n);
	return true;
}

int let(string s){
	int j = 0;
	for (int i = 0; i < s.size(); i++){
		switch (s[i]){
			case 97:
			case 101:
			case 105:
			case 111:
			case 117:
			case 65:
			case 69:
			case 73:
			case 79:
			case 85:
				j++;
				break;
		}
	}
	return j;
}


int Spaces(string s){
	int j = 0;
	for (int i = 0; i < s.size(); i++){
		switch (s[i]){
		case 32: j++;
			break;
		}
	}
	return j;
}

int let_sp(string s) {
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 97:
		case 101:
		case 105:
		case 111:
		case 117:
		case 32:
		case 65:
		case 69:
		case 73:
		case 79:
		case 85:
			break;
		default: {
			if (isascii(s[i]))
				if (isalpha(s[i]))
					j++; break;
		}
		}
	}
	return j;
}

double jha(string m, int p, int q){
	int k = (7 * let(m)) - (3 * let_sp(m)) + (Spaces(m)*Spaces(m));
	if (k < 0)
		return um(_mod(q, -k, p), p);
	return _mod(q, k, p);
}

bool mod(int g, int q, int p){
	int a = q - 1;
	for (int i = a; i > 1; i--)
		if (_mod(g, i, p) == 1) return false;
	if (_mod(g, q, p) == 1)
		return true;
	else return false;
}
int main(){
	vector <int> v, s;
	int p, r, g, k;
	string p32k = "p jest wieksze od 32000\n",
		pp = "p to nie liczba pierwsza\n",
		again = "wpisz ponownie\n",
		gn = "g to nie liczba naturalna\n",
		gqp = "g to nie q-ty pierwiastek % p\n",
		km = "k powinno byc mniejsze niz q\n",
		kn = "k musi byc liczba naturalna\n",
		rq = "r musi byc mniejsze od q\n",
		rn = "r musi byc liczba naturalna\n";

	cout << "p: ";
	do{
		cin >> p;
		if (p >= 32000) cout << p32k;
		if (!pier(p)) cout << pp;
		if (p >= 32000 || !pier(p)) cout << again;

	} while (!pier(p) || p >= 32000);
	if (p > 1) Fer(p-1, v,s);
	int q = s[s.size() - 1];
	cout << "g: ";
	do{
		cin >> g;
		if (g < 0) cout << gn;
		if (!mod(g, q, p)) cout << gqp;
		if (!mod(g, q, p) || g < 0) cout << again;
	} while (g < 0 || !mod(g, q, p));
	cout << "k, r: ";
	do{
		cin >> k >> r;
		if (k >= q) cout << km;
		if (k < 0) cout << kn;
		if (r >= q) cout << rq;
		if (r < 0) cout << rn;
		if (r >= q || k >= q || k < 0 || r < 0) cout << again;
	} while (r >= q || k >= q || k < 0 || r < 0);

	ifstream file("tekst.txt");
	string str;
	getline(file, str);
	cout << "JHA: " << jha(str, p, q) << "\n(" << _mod(g, k, p) << "," << g << "," << p << "," << q << ")"
	 << "\n(" << _mod(g, k, p) % q << "," << (um(r, q)*_mod(jha(str, p, q) + k*_mod(g, k, p) % q, 1, q)) % q << ")\n";
	system("pause");
	return 0;
}