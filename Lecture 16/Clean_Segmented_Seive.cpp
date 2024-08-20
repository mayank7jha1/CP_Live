#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
bitset<1000000>p;//By Default it is initialised with zero.
vector<int>primes;

void Seive() {
	for (int i = 3; i * i < N; i += 2) {
		if (p[i] == 0) {
			for (int j = i * i; j < N; j += i) {
				p[j] = 1;
			}
		}
	}

	primes.push_back(2);
	for (int i = 3; i < N; i += 2) {
		if (p[i] == 0) {
			primes.push_back(i);
		}
	}
}

void Segmented_Seive(int l, int r) {
	bitset<10000005>p1;//Initialised with value 0:
	// bool p1[10005] {0};

	for (int i = 0; primes[i]*primes[i] <= r; i++) {

		int start = (l / primes[i]) * primes[i];
		if (start < l) {
			start += primes[i];
		}
		for (int j = start; j <= r; j += primes[i]) {
			p1[j - l] = 1;
		}

		if (start == primes[i]) {
			p1[start - l] = 0;
		}
	}

	for (int i = l; i <= r; i++) {
		if (p1[i - l] == 0) {
			cout << i << " ";
		}
	}
	cout << endl;
}


int main() {
	Seive();
	int t;
	cin >> t;

	while (t--) {

		int l, r;
		cin >> l >> r;

		if (l == 1) {
			l++;
		}
		Segmented_Seive(l, r);
	}
}

//Totient: