#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define int long long

int n, m, k;
int a[N] = {0}, opcount[N] = {0}, diff[N] = {0};
int l[N], r[N], d[N];

int32_t main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> d[i];
	}


	//Resolving the query Range:

	for (int i = 1; i <= k; i++) {

		int x, y;
		cin >> x >> y;

		opcount[x]++;
		opcount[y + 1]--;
	}

	//Prefix of Operation Count:

	for (int i = 1; i <= m; i++) {
		opcount[i] = opcount[i - 1] + opcount[i];
	}


	// for (int i = 1; i <= m; i++) {
	// 	cout << opcount[i] << " ";
	// }

	// cout << endl;


	//Resolving the Operations Range:

	for (int i = 1; i <= N; i++) {
		int x = l[i];
		int y = r[i];


		diff[x] += (opcount[i] * d[i]);
		diff[y + 1] -= (opcount[i] * d[i]);
	}

	//Prefix Sum of Difference Array
	for (int i = 1; i <= n; i++) {
		diff[i] = diff[i - 1] + diff[i];
	}

	// for (int i = 1; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	//Diff+Original Array
	for (int i = 1; i <= N; i++) {
		a[i] += diff[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}

}