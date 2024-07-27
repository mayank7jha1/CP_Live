#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
int a[N] = {0};
vector<bool>visited(N, 0);

int Min_Steps = INT_MAX;//Min Steps across all the paths.

/*
	int count: Current Path me kitne stairs ko visit kiya hain.
*/
void Solve(int i, int count) {

	if (i == n) {
		Min_Steps = min(Min_Steps, count);
		return;
	}

	visited[i] = 1;

	if (i + 1 <= n and visited[i + 1] == 0) {
		Solve(i + 1, count + 1);
	}

	if (i + a[i] <= n and i + a[i] >= 0 and visited[i + a[i]] == 0) {
		Solve(i + a[i], count + 1);
	}

	//For the current ith stair you have calculated all the path steps.

	visited[i] = 0;//Backtracking as in you can revisit this box again from any other path.

}


int main() {
	int t;
	cin >> t;


	while (t--) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (auto x : visited) {
			x = 0;
		}

		Solve(0, 0);
		cout << Min_Steps << endl;

		Min_Steps = INT_MAX;
	}
}