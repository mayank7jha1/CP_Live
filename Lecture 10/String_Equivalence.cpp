#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int n;
char output[11];
int count1 = 0;

void Solve(int index, char mxc) {


	if (index == n) {
		count1++;
		output[index] = '\0';
		cout << output << endl;
		return;
	}

	for (char ch = 'a'; ch <= mxc; ch++) {

		output[index] = ch;
		if (ch == mxc) {
			Solve(index + 1, mxc + 1);
		} else {
			Solve(index + 1, mxc);
		}

	}
}


int main() {

	cin >> n;

	Solve(0, 'a');

	//cout << count1 << endl;

}