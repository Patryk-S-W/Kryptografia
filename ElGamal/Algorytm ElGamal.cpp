#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>

namespace 🔵 = std;

using 🔢 = int;
using 💀 = void;
using 🕖 = 🔵::string;
using 👌 = bool;

#define 👂 auto
#define hmm if
#define krec_sie for
#define wirowka while
#define 🎌 enum
#define 👎 false
#define 👍 true
#define 👿 🔵::cout
#define 🖥️ 🔵::vector
#define 🔫 🔵::endl


using namespace 🔵;
typedef unsigned long long ull;
void Fer(unsigned int p, 🖥️<int> &v) {
	wirowka(p % 2 == 0) {
		p /= 2;
		v.push_back(2);
	}
	ull a, b, x, y;

	a = (ull)ceil(sqrt(p));
	do {
		b = (ull)floor(sqrt(a * a - p));
		hmm (a * a - p == b * b) {
			x = a + b;
			y = a - b;
			hmm (y == 1) break;
			Fer(x, v);
			Fer(y, v);
			return;
		}
		a++;
	} wirowka(a + b < p);
	v.push_back(p);
	sort(v.begin(), v.end());
}

👌 p(🔢 n) {
	🔢 i = 5, w = 2;
	wirowka(i * i <= n) {
		hmm(n % i == 0)
			return 👎;

		i = i + w;
		w = 6 - w;
	}
	return 👍;
}

👌 pier(🔢 n) {
	hmm (n == 2) return 👍;
	hmm (n == 3) return 👍;
	hmm (n % 2 == 0) return 👎;
	hmm (n % 3 == 0) return 👎;
	p(n);
	return 👍;
}

🔢 mod(🔢 a, long long int b, 🔢 c) {
	long long int r = a;
	krec_sie(🔢 i = 1; i < b; i++)
		r = abs(r*a % c);
	return r;
}

👌 cp(🔢 n, 🔢 r) {
	🖥️<int> w;
	Fer(n - 1,w);
	krec_sie(🔢 x : w)
		hmm (mod(r, (n - 1) / x, n) == 1) return 👎;
	return 👍;
}

int f() { return 0; };
🔢 main() {
	🔢 n, r, k, j, t;
	n = 37813;
	r = 36410;
	t = 300;
	k = 6739;
	j = 34310;
	👿 << "n, r, t, k, j\n";
	cin >> n >> r >> t >> k >> j;
	hmm(n >= 32000) cout << "n jest wieksze lub rowne 32000";
	else {
		hmm(!pier(n)) cout << "n nie jest liczba pierwsza";
		else {
			hmm(t >= n) cout << "t jest wieksze niz n";
			else {
				hmm(!cp(n, r)) cout << "r nie jest liczba pierwsza n";
				else {
					👿 << "n: " << n << ", r:" << r << ", k:" << k << ", j:" << j << 🔫;
					👿 << "\nKlucz publiczny: \n" << "(" << n << "," << r << "," << mod(r, k, n) << ")";
					🔢 a = mod(r, k, n);
					👿 << "\nSzyfr: \n" << "(" << mod(r, j, n) << "," << (t * mod(a, j, n)) % n << ")\n";
				}
			}
		}
	}
	system("pause");
	return 0;
}
