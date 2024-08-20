#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int32_t main() {
	int t;
	cin >> t;

	while (t--) {

		int a, b, q;
		cin >> a >> b >> q;

		/*		Flag[i]: Represents Ki i as a value satisfies the
				condition or not :
				Condition: (i % a) % b = (i % b) % a

				Pre[i]: No of values that satisfies the above condition
				form 0 to i.

		*/
		int flag[40001] {0};
		int pre[40001] {0};

		for (int i = 0; i < (a * b); i++) {

			if (((i % a) % b != (i % b) % a)) {
				flag[i] = 1;
			}

			if (i == 0) {
				pre[i] = flag[i];
			} else {
				pre[i] = pre[i - 1] + flag[i];
			}
		}


		int count1 = 0;//This represents no of x that satisfies the condition in range [0,L-1].
		int count2 = 0;//This represents no of x that satisfies the condition in range [0,R].

		while (q--) {

			int l, r;
			cin >> l >> r;

			l--;

			//We are finding the value of count1.
			int m = l / (a * b);
			int n = l % (a * b);
			count1 = (m * pre[((a * b) - 1)]) + pre[n];




			//We are find the value of count2.
			int m1 = r / (a * b);
			int n1 = r % (a * b);
			count2 = (m1 * pre[((a * b) - 1)]) + pre[n1];

			cout << count2 - count1 << " ";

		}
		cout << endl;
	}
}


//Totient:
//Fermat Little Theoram
//Prime and Segmented Sieve
//Questions: