#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
bitset<10000>p;//By Default it is initialised with zero.
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
	//bitset<10005>p1;//Initialised with value 0:
	bool p1[10005] {0};
	//p1[i] = 0: Current i is a Prime Number.

	//I have to Iterate over Primes number from 0 ---> root(r).

	for (int i = 0; primes[i]*primes[i] <= r; i++) {

		//I want to Find the first element ya first multiple
		//of current prime number which is prime[i] in the
		//range of l,r to mark it as 1 and say ki this number
		//can never become prime.

		int start = (l / primes[i]) * primes[i];
		if (start < l) {
			start += primes[i];
		}

		//Now cut all the the multiple of this prime number
		//in the range of l to r.

		for (int j = start; j <= r; j += primes[i]) {

			//I have shifted array here. l is at 0 index.
			//hence j as number will be at what number:
			//j-a index.

			p1[j - l] = 1;//Array me j-l hain and j  number hain in the range l to r.
		}

		//PrecautionL if start == primes[i]

		if (start == primes[i]) {
			//Then remark this number as prime number.
			p1[start - l] = 0;
		}
	}
	for (int i = l; i <= r; i++) {
		if (p1[i - l] == 0) {
			cout << i << " ";
		}
	}

	cout << endl << endl;
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
		//cout << l << " " << r << endl;
		Segmented_Seive(l, r);
	}
}