#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define mod 10007



//O(n):O(log(n)):

int SP(int x, int y) {

	int ans = 1;

	for (int i = 1; i <= y; i++) {
		ans = ((ans % mod * x % mod) % mod);
	}

	return ans % mod;
}



//There are 2 Parameters:

//O(logn):

int FP(int x, int y) {

	if (y == 0) {
		return 1;
	}

	int ans = (FP(x, y / 2)) % mod;

	if (y % 2 == 1) {
		return ((x % mod) * (ans % mod) * (ans % mod) % mod);
	} else {
		return ((ans % mod) * (ans % mod) % mod);
	}
}

int32_t main() {
	int n;
	cin >> n;

	int Part1 = (9 * FP(10, n - 1) % mod);
	int Part2 = FP(9, n) % mod;
	int Part3 = ((n - 1) * FP(9, n - 1)) % mod;

	cout << Part1 << " " << Part2 << " " << Part3 << endl;

	cout << (Part1 - Part2 - Part3 + 2 * mod) % mod << endl;
}



// %: Arithmetic Operator:

// (a + b)*c = ac + bc;


// (a + b) % c = (a % c + b % c)


//x>y
//x%m>y%m


//17>3

//17%5>3%5

