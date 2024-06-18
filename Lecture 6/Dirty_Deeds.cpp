#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

vector<int>f, s;//This makes the pair.

//x is an index: Pair(f[x],s[x]):

bool C1(int x, int y) {
	if (s[x] > s[y]) {
		return true;
	} else {
		return false;
	}
}


bool C2(int x, int y) {
	return f[x] < f[y];
}


int32_t main() {
	int n;
	cin >> n;

	vector<int>s1, s2;//This makes the sequence.

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		f.push_back(x);
		s.push_back(y);

		if (x < y) {
			s1.push_back(i);
		} else {
			s2.push_back(i);
		}
	}

	if (s1.size() > s2.size()) {
		sort(s1.begin(), s1.end(), C1);
	} else {
		sort(s2.begin(), s2.end(), C2);
	}


}