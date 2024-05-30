#include<iostream>
using  namespace std;
#define int long long





int32_t main() {

	int n, m;
	cin >> n >> m;

	int ans = 0;//The Min value of K.

	if (m >= n) {
		cout << n << endl;
		return 0;//Stop the Program.
	}

	//Define The SS.
	int s = 0;
	int e = 1e10;//(1*10^10);

	while (s <= e) {
		int mid = (s + e) / 2;

		int Value = (mid * (mid + 1)) / 2;

		if (Value >= n - m) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	//Total Day: m+k;
	cout << m + ans << endl;


}









