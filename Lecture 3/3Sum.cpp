#include<bits/stdc++.h>
using namespace std;
const int N = 0;
// #define int long long




int32_t main() {

	int t;
	cin >> t;
	while (t--) {

		int n;
		int cnt[10] = {0};

		cin >> n;
		int a[n];

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] %= 10;
			int digit = a[i];

			//Frequency Array for Digit.
			cnt[digit]++;
		}

		// cout << endl;
		// 1--->3
		// 2--->5
		// 3--->7
		// 4--->2

		// 1,1,1,2,2,2,3,3,3,4,4
		//Build the digit vala array.

		vector<int>v;

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < min(3, cnt[i]); j++) {
				v.push_back(i);
			}
		}


		int flag = 0;
		for (int i = 0; i < v.size(); i++) {

			for (int j = i + 1; j < v.size(); j++) {

				for (int k = j + 1; k < v.size(); k++) {

					if ((v[i] + v[j] + v[k]) % 10 == 3) {
						flag = 1;
						cout << "Yes" << endl;
						break;
					}
				}

				//Hi:
				if (flag == 1) {
					break;
				}
			}

			//Hi:
			if (flag == 1) {
				break;
			}
		}


		if (flag == 0) {
			cout << "No" << endl;
		}
	}
}