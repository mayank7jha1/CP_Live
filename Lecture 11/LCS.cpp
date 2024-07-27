#include<bits/stdc++.h>
using namespace std;
const int N = 0;


class Solution {
public:

	int LengthLCS(string &s, string &t, int i, int j) {

		if (i >= s.length() or j >= t.length()) {
			return 0;
		}

		if (s[i] == t[j]) {
			return 1 + LengthLCS(s, t, i + 1, j + 1);
		} else {
			return max(LengthLCS(s, t, i + 1, j), LengthLCS(s, t, i, j + 1));
		}

	}

	int longestCommonSubsequence(string text1, string text2) {
		return LengthLCS(text1, text2, 0, 0);
	}
};

int main() {
	Solution st;
	string s, t;
	cin >> s >> t;

	cout << st.longestCommonSubsequence(s, t) << endl;
}