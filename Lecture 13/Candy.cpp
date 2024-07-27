#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class Solution {
public:
	int candy(vector<int>& r) {

		int n = r.size();
		vector<int>candies(n, 1);


		//Loop1: Previous Comparison.
		for (int i = 1; i < n; i++) {
			//First Neighbour
			if (r[i] > r[i - 1]) {

				candies[i] = candies[i - 1] + 1;

			}
		}


		// rating:  4  3  2 1 6
		// candies: 1  1  1 1 2


		// rating:  4 3 2 1 6
		// candies: 4 3 2 1 2

		for (int i = n - 2; i >= 0; i--) {
			//Second Neighbour
			if (r[i] > r[i + 1]) {
				// candies[i] = candies[i + 1] + 1;//Wrong
				//Hosakta hain candies[i] par Loop1 ke karan already ek bada number ho.
				candies[i] = max(candies[i], candies[i + 1] + 1);
			}
		}

		int ans = 0;
		for (auto x : candies) {
			ans += x;
		}
		return ans;



	}
};
//               2    8   6

// - - - - - - - 10  11  3


int main() {

}




/*

Student :1 2 3 4 5 6 7 8
Rating  :- - - - - 3 8 6
Candies :- - - - - 4 5 1
	

	8 rating vale student ke pass jo rating abhi hain and 6 rating vala student hainn
	uske pass jo rating hain:

	candies[7]=candies[8]+1;
	candies[7]=1+1=2;
	candies[6]=4:rating of student[6]<student[7]

Candies: - - - - - - - 1


Pichhe vale neighbour ke comparison se hain.



*/