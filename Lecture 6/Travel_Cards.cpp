#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int n, a, b, k, f;



int32_t main() {
	cin >> n >> a >> b >> k >> f;

	map<pair<string, string>, int>mp;
	//trip--->cost.


	string prev = "";//This will help me out in transhipment.

	for (int i = 0; i < n; i++) {

		string SP, EP;
		cin >> SP >> EP;

		int price = 0;

		if (prev == SP) {
			//This is a Transhipment.
			price = b;
		} else {
			price = a;
		}

		prev = EP;

		if (SP > EP) {
			swap(EP, SP);
		}

		//Har trip ka cost nikalna chahte hain.

		/*

				x y = a
				-
				-
				-
				y x = a

				(x,y)=2a

		*/

		mp[ {SP, EP}] += price;

	}

	vector<int>cost;

	int TP = 0;

	for (pair<pair<string, string>, int> x : mp) {
		cost.push_back(x.second);
		TP += x.second;
	}

	// sort(cost.begin(), cost.end(), greater<int>());
	sort(cost.rbegin(), cost.rend());

	for (int i = 0; i < cost.size() and i < k; i++) {

		if (cost[i] > f) {
			TP = TP - cost[i] + f;
		} else {
			//If you are standing here that means you cannot buy the travel
			//card for the current trip i.e. cost[i]<f and since
			//cost vector is sorted in desc. order all the cost[i] for i
			//greater than the current i will also smaller than f.

			break;
		}
	}

	cout << TP << endl;;
}