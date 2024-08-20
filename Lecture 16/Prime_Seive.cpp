#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

/*
	p[i]==0 that means ki current i is a Prime Number and initially
	we are assuming every number is a Prime number.

	bitset<size>b; bits ko store karte ho. This is 8 times
	smaller than bool array of same size.
*/

// bool p[N] {0};

bitset<100000000>p;//By Default it is initialised with zero.

void Seive(int n) {
	for (int i = 3; i * i < n; i += 2) {
		if (p[i] == 0) {
			for (int j = i * i; j < n; j += i) {
				p[j] = 1;
			}
		}
	}

	if (n < 2) {
		return;
	}

	cout << 2 << " ";
	for (int i = 3; i < n; i += 2) {
		if (p[i] == 0) {
			cout << i << " ";
		}
	}
}

int main() {
	int n;
	cin >> n;
	Seive(n);
}