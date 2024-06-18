#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int h, n;
int a[N] = {0}, c[N] = {0};

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int h, n;
		cin >> h >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}

		int s = 1, e = 1e11;

		int ans = -1;

		while (s <= e) {

			int mid = (s + e) / 2;
			int damage = 0;

			for (int i = 0; i < n; i++) {
				damage += ((mid + c[i] - 1) / c[i]) * a[i];
			}

			if (damage >= h) {
				ans = mid;
				e = mid - 1;
			} else {
				s = mid + 1;
			}
		}

		cout << ans << endl;

	}
}