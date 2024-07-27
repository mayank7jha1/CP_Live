#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int n, h, l, r;
vector<int>a;


int F(int i, int WH) {

	if (i == n) {

		//I have taken all my sleeps.
		return 0;
	}


	int Op1_WH = (WH + a[i]) % h;
	int Op2_WH = (WH + a[i] - 1) % h;


	int ans1 = 0;
	int ans2 = 0;

	if (Op1_WH >= l and Op1_WH <= r) {
		ans1 = 1;
	}

	if (Op2_WH >= l and Op2_WH <= r) {
		ans2 = 1;
	}


	int Op1 = ans1 + F(i + 1, Op1_WH);
	int Op2 = ans2 + F(i + 1, Op2_WH);

	return max(Op1, Op2);
}

int32_t main() {
	cin >> n >> h >> l >> r;
	a.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	cout << F(0, 0);

}