#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s;
int m;
int pre[N] = {0};


int main() {

	cin >> s;
	cin >> m;

	/*
		abcdef
		1--->6-1+1
		0--->6-1-0

		2-->6-2+1
		1--->6-1-1




	*/

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		pre[x - 1]++;
	}

	//Prefix Sum:

	for (int i = 1; i < s.length() / 2; i++) {
		pre[i] = pre[i - 1] + pre[i];
	}

	for (int i = 0; i < s.length() / 2; i++) {

		if (pre[i] % 2 == 1) {
			swap(s[i], s[s.length() - i - 1]);
		}
	}

	cout << s;
}