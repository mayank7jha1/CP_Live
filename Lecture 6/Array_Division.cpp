#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int32_t main() {

	int n;
	cin >> n;

	int a[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	map<int, int>mp;//This is for

	//It is only possible to divide the array into two parts of
	//equal sum if the total sum of array is even.

	if (sum % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}

	sum /= 2;
	int l = 0;


	//Prefix me se ek element utha ke right me daal do.
	for (int i = 0; i < n; i++) {
		l += a[i];
		mp[a[i]]++;

		if (mp[l - sum] > 0) {
			cout << "YES" << endl;
			return 0;
		}
	}

	mp.clear();

	//Suffix me se ek element utha ke left me daal do.
	int r = 0;
	for (int i = n - 1; i >= 0; i--) {
		r += a[i];
		mp[a[i]]++;

		if (mp[r - sum] > 0) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;


}



// 2 2 3 7

// l=2-7
// l=4-7
// l=7-7
// l=14-7=7


//x x x y y y z z z t t t