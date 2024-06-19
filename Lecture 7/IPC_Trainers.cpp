#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int IPC() {

	int n, d;
	cin >> n >> d;

	int AD[N] = {0}, Lecture[N] = {0}, Sadness[N] = {0};

	//Max Heap: Kis teacher ki kitni sadness hain.
	priority_queue<pair<int, int>>pq;

	//Sadness,index of teacher.




	for (int i = 0; i < n; i++) {
		cin >> AD[i] >> Lecture[i] >> Sadness[i];
		pq.push({Sadness[i], i});
	}


	set<int>days;

	for (int i = 1; i <= d; i++) {
		days.insert(i);
	}

	int Lecture_Taken[N] = {0};

	while (!pq.empty()) {

		pair<int, int>teacher = pq.top();
		pq.pop();


		int Arrival = AD[teacher.second];
		int Optimistic_End_Day = Arrival + Lecture[teacher.second] - 1;


		for (int i = Arrival; i <= Optimistic_End_Day; i++) {

			auto it = days.lower_bound(i);//This returns an address.

			if (it == days.end()) {
				break;
			} else {

				Lecture_Taken[teacher.second]++;
				days.erase(it);
			}
		}

	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += ((Lecture[i] - Lecture_Taken[i]) * Sadness[i]);
	}


	return ans;
}



int main() {
	int t;
	cin >> t;

	while (t--) {
		cout << IPC() << endl;
	}
}