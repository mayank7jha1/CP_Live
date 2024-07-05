#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int t;
// F(t, x'): 0;
//F(x',y'): INT_MAX

//Basic:
int F(int x, int y) {


	if (x > t or y > t) {
		return 1e8;
	}

	if (x == t or y == t) {
		return 0;
	}


	int Op1 = F(x + y, y);
	int Op2 = F(x, y + x);

	int ans = 1 + min(Op1, Op2);
	return ans;
}


//Optimised.
int Min_Steps = INT_MAX;

void F2(int x, int y, int count) {

	if (x == 1 and y == 1) {
		Min_Steps = min(Min_Steps, count);
		return;
	}

	if (y - x > 0) {
		F2(x, y - x, count + 1);
	}
	if (x - y > 0) {
		F2(x - y, y, count + 1);
	}

}

void Pair() {

	if (t == 1) {
		cout << 0;
		return;
	}
	for (int i = 1; i < t; i++) {
		F2(i, t - i, 1);
	}

}

int main() {
	cin >> t;
	cout << F(1, 1) << endl;
	Pair();
	cout << Min_Steps << endl;
}