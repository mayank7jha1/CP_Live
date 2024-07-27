#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int n, k;
vector<int>taste, calorie;

int F(int index, int sum) {


	if (index == n) {
		if (sum == 0) {
			return 0;
		} else {
			return -1e12;
		}
	}

	int Op1 = taste[index] + F(index + 1, sum + (taste[index] - k * calorie[index]));
	int Op2 = 0 + F(index + 1, sum);

	return max(Op1, Op2);
}


int32_t main() {
	cin >> n >> k;
	taste.resize(n);
	calorie.resize(n);


	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	int ans = F(0, 0);


	if (ans <= 0) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}