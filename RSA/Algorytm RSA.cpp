#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

tuple<int, int, int> euk(int a, int b, vector<int> &t){
	if (a == 0)
		return make_tuple(b, 0, 1);

	int g, x, y;
	tie(g, x, y) = euk(b % a, a, t);
	t.push_back(x);

	return make_tuple(g, (y - (b / a) * x), x);
}

vector<int> sieve(const int n) {
	if (n >= 1) {
		vector<int> v;
		for (int i = 2; i < n; i++)
			v.push_back(i);

		for (int i = 0; v[i] <= sqrt(n); ++i) {
			vector<int> t;
			for (int j = 0; j <= i; j++) t.push_back(v[j]);
			for (int j = i + 1; j < v.size(); j++)
				if ((v[j] % v[i]) != 0) t.push_back(v[j]);
			v = t;
		}
		return v;
	}
	else
		return{ 0 };
}

int f() { return 0; };
int main(){
	vector<int> pn, nwd, h, u;
	int e, d = 0, i,j;
	cout << "Sito ma 199999, chwile to trwa\ni, j, e\n";
	cin >> i >> j >> e;
	pn = sieve(199999);

	int q = pn[j-1], p = pn[i - 1];
	unsigned long long int n = p * q, m = (p - 1) * (q - 1);
	cout << "p: " << p << " q: " << q << "\nn: " << n << " m: " << m << endl;

	tuple<int, int, int> t = euk(e, m, u);

	do {
		t = euk(e, m, u);
		h = u;
	} while (get<0>(t) != 1);
	
	cout << "nwd: " << get<0>(t) << " e: " << e << endl;
	(get<1>(t) < 0) ? get<1>(t) += m, ((get<1>(t) > 0) ? d = get<1>(t) : f()) : d = get<1>(t);
	cout << "d: " << d
		<< "\nKlucz publiczny (" << n << ", " << e << ")"
		<< "\nKlucz prywatny (" << n << ", " << d << ")" << endl;

	system("pause");
	return 0;
}
