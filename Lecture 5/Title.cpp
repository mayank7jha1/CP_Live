#include<bits/stdc++.h>
using namespace std;
const int N = 0;
string s;
int k;
bool map1[27] = {0};


void Title() {

	int i = 0;
	int j = s.length() - 1;

	while (i < j) {
		if (s[i] == '?' and s[j] == '?') {
			i++;
			j--;
			continue;
		} else if (s[i] == '?' and s[j] != '?') {
			s[i] = s[j];
			map1[s[i] - 'a' + 1] = 1;
			i++;
			j--;
		} else if (s[j] == '?' and s[i] != '?') {
			s[j] = s[i];
			map1[s[i] - 'a' + 1] = 1;
			i++;
			j--;
		} else if (s[i] == s[j]) {
			map1[s[i] - 'a' + 1] = 1;
			i++, j--;
		} else {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}

	if (i == j and s[i] != '?') {
		map1[s[i] - 'a' + 1] = 1;
	}



	//Currently You are standing at the innermost part of the pairs.

	while (i >= 0) {

		//You have to find the first missing character in the map1 array.
		//from the range of 1st to kth character.

		//Infact you would want to find the biggest missing number
		//as you want the biggest missing number to be placed in the
		//innermost string part in order to make the string lexographically
		//smallest.

		// k=5;-->map[5]===map[e]--true/false
		//b,c-->character missing
		// biggest character is: c.

		while (k > 1 and map1[k] == 1) {
			k--;
		}

		if (s[i] == '?' and s[j] == '?') {
			s[i] = s[j] = k - 1 + 'a';
			map1[k] = 1;
			i--; j++;
		} else {
			i--, j++;
		}
	}

	//Check If my answer exits

	if (k == 1 and map[1] == 1) {
		cout << s << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}



}

int main() {

	cin >> k;

	cin >> s;


	Title();
}


//STACK:Array se hi implemented hain.
//Map ka use kar sakte ho.