#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;

int nwd(int a, int b){
	int c;
	while (b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int f1(ull n){
	double suma = n;
	int dzielnik = 2;
	while (n != 1){
		while (n % dzielnik != 0)
			dzielnik++;
		suma *= (1 - 1.0 / dzielnik);
		while (n % dzielnik == 0)
			n /= dzielnik;
	}
	return int(suma);
}

int smod(ull x, ull y, ull z){
	int w = x;
	if (nwd(x, z) == 1)
		y = y % f1(z);
	for (int i = 1; i < y; i++)
		w = (w * x) % z;
	return w;
}

void Fer(unsigned int p, vector<int> &v) {
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
			Fer(x, v);
			Fer(y, v);
			return;
		}
		a++;
	} while (a + b < p);
	v.push_back(p);
	sort(v.begin(), v.end());
}

void test_lucasa(unsigned int n, unsigned int q){
	unsigned int c, d;
	int e, zakres = 0;
	c = n - 1;

	int t[200000], dokad = floor(sqrt(zakres)), j;

	for (int i = 1; i <= zakres; i++)
		t[i] = 1;
	for (int i = 2; i <= dokad; i++){
		if (t[i] != 0){
			j = i + i;
			while (j <= zakres){
				t[j] = 0;
				j += i;
			}
		}
	}
}

int main(){
	int x, y, m, t1[100], t2[100];
	unsigned int a, n, q;
	vector <int> v;
	map<int, int> ma;

	cout << "liczba: ";
	cin >> x;
	cout << "potega: ";
	cin >> y;
	cout << "modulo:  ";
	cin >> m;
	cout << x << "^" << y << " mod m = " << smod(x, y, m) << endl;
	cout << "\n" << "Fermat: \n";
	cin >> a;
	if (a > 1) Fer(a, v);
	for (int i : v)
		cout << i << " ";
	cout << endl << endl;


	//krotnosci
	for (auto x : v) ++ma[x];
	for (auto p : ma)
		cout << p.first << ' ' << p.second << endl;

	cout << "\n" << "liczba n\n";
	cin >> n;
	cout << "q: \n";
	cin >> q;
	if (n > 1) Fer(n-1, v);

	for (int j = 0; j < v.size(); j++)
		t1[j] = t2[j] = v[j];
	int k = 0;

	for (int j = 0; j < v.size(); j++) {
		for (int i = 2; i <= v[j]; i++){
			while (v[j] % i == 0){
				v[j] /= i;
				t2[k] = i;
				k++;
				cout << t2[k] << " ";
			}
		}
	}
	k = 1;

	for (int j = 0; j < v.size(); j++){
		cout << smod(q, (n - 1) / t2[j], n) << " " << t2[j] << endl;

		if (smod(q, (n - 1) / t2[j], n) == 1)
			k++;
	}

	(k == 1) ? cout << "\n liczba pierwsza \n" : cout << "\n test nie rozstrzyga\n";

	system("pause");
	return 0;
}