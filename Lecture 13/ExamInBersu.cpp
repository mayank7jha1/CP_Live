#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int n, m;
int a[200010] {0};
int student[101] {0};

//2*10^5*100: Work: 1 sec: 10^8 computations:

void Function() {

	int total = 0;//Upto ith student time consumed kya hain.



	for (int i = 0; i < n; i++) {

		int diff = total - m + a[i];
		//cout << diff << " ";
		int Removed = 0;

		if (diff > 0) {
			//Kuch Students ko remove karna padega.

			/*
				Since I want to minimise the number of failing
				students I want to remove students with
				the largest time upto i.
			*/

			for (int j = 100; j >= 1; j--) {

				if (student[j] > 0) {

					//Contribution of this jth index student nikal lo.
					int contribution = student[j] * j;

					if (contribution >= diff) {

						//Iska matlab mujhe j time vaale kuch students ko
						//remove karna hain.

						Removed += ((diff + j - 1 ) / j);;
						break;
					}

					//Varna contribution<diff: Mujhe j time
					//vale saare students remove karne padenge and bacha hua
					//diff time main dusre students se cover karunga.

					Removed += student[j];
					diff -= contribution;
				}
			}
		}

		// for (int i = 1; i < 6; i++) {
		// 	if (student[i] > 0) {
		// 		cout << i << " " << student[i] << endl;
		// 	}

		// }



		student[a[i]]++;//Frequency Array Updated.
		total += a[i];//Update the total time consumed till i.
		//cout << total << " ";
		cout << Removed << " ";
	}
}

int32_t main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	Function();
}


