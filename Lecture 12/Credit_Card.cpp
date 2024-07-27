#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int n, d;
int a[20009] {0};


void Solve() {

	//Check if My answer is -1 or not.
	//By Making my Bank Balance as minimum as possible on the day
	//of visit.

	int BB = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {

			if (BB < 0) {
				BB = 0;
			}
		} else {
			BB += a[i];

			if (BB > d) {
				cout << "-1" << endl;
				return;
			}
		}
	}


	//If I am Standing here then that means my answer exits:

	//I can put a certain amount of money on day visiting
	///bank and still my BB will not exceed d.

	//Mujhe Trips ko minimise karna hain.

	BB = 0;

	int visits = 0;

	for (int i = 0; i < n; i++) {

		if (a[i] == 0) {
			if (BB < 0) {
				BB = d;
				visits++;
			}

		} else {
			BB += a[i];
			if (BB > d) {
				BB = d;
			}
		}
	}


	cout << visits << endl;

}


int32_t main() {
	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	Solve();

}