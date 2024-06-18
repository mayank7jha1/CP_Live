#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int Noise(string &s) {

	int CountS = 0;
	int ans = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 's') {
			CountS++;
		} else {
			ans += CountS;
		}
	}

	return ans;
}


bool C1(string &a, string &b) {

	string ab = a + b;
	string ba = b + a;

	if (Noise(ab) > Noise(ba)) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int t;
	cin >> t;

	string a[t];

	for (int i = 0; i < t; i++) {
		cin >> a[i];
	}

	sort(a, a + t, C1);

	string final = "";

	for (auto x : a) {
		final = final + x;
	}

	cout << Noise(final) << endl;

}