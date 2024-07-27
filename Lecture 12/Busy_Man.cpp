#include<bits/stdc++.h>
using namespace std;
const int N = 0;


class Activity {
public:
	int ST;
	int ET;
};

Activity a[100005];
int n;
int t;

bool cmp(Activity x, Activity y) {

	if (x.ET == y.ET) {

		//If there ending point this code will sort the data
		//on the basis of starting point in asc. order
		//although if you would have sort the data on the
		//basis of starting point in dsc. order it would not have
		//mattered.

		if (x.ST < y.ST) {
			return true;
		} else {
			return false;
		}
	}


	if (x.ET < y.ET) {
		return true;
	} else {
		return false;
	}
}

void Solve() {

	/*
		Idea: We want the data to be arranged on the basis
		of end time.
	*/

	sort(a, a + n, cmp);

	int ans = 1;
	int Prev = a[0].ET;

	for (int i = 1; i < n; i++) {
		if (a[i].ST >= Prev) {
			ans++;
			Prev = a[i].ET;
		}
	}
	cout << ans << endl;

}

int main() {
	cin >> t;
	while (t--) {

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i].ST >> a[i].ET;
		}

		Solve();
	}
}