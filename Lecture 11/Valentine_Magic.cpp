#include<bits/stdc++.h>
using namespace std;
const int N = 5001;

int n, m;
int a[N], b[N];


int Solve(int i, int j) {

	if (i == n) {
		return 0;
	}

	if (j == m) {
		//This is not a valid path and you have to ignore this.

		//I return something that large that will ensure that this path
		//never becomes lcs.
		return 1e9;
	}

	//Boy i is not pairing  with the current girl j.
	int Op1 = Solve(i, j + 1);


	//Current boy makes pair with the current girl.

	int Op2 = abs(a[i] - b[j]) + Solve(i + 1, j + 1);


	return min(Op1, Op2);
}

int main() {


	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + m);

	cout << Solve(0, 0);
}