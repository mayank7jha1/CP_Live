#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int Count[2][2];
string s;

//ababba

//i=1
//s[i]=b

// count[98-97][0]

void CountGoodSubstring() {
	int n = s.length();
	int odd = 0, even = 0;

	for (int i = 0; i < n; i++) {

		odd++;

		if (i % 2 == 1) {

			//This is a odd index and even position.
			// if (s[i] == 'a') {

			// }else{

			// }
			odd += Count[s[i] - 'a'][0];
			Count[s[i] - 'a'][0]++;
			even += Count[s[i] - 'a'][1];
		} else {

			//This is a even index and odd position.

			odd += Count[s[i] - 'a'][1];
			Count[s[i] - 'a'][1]++;
			even += Count[s[i] - 'a'][0];
		}
	}

	cout << even << " " << odd << endl;


}


int32_t main() {
	cin >> s;
	CountGoodSubstring();
}