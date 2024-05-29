#include<iostream>
#include<algorithm>


using namespace std;
const int N = 0;
int x;

//C++ : Life Cycle of a C++ Program
//Life Cycle of a Algorithm

/*

	This code is very similar to the code provided to you in STL.

*/

int Lower_Bound(int *a, int n) {

	int s = 0, e = n - 1;

	//We are applying BS on Array indices.

	//int ans = -1;//You want to initialise it with a variable
	// that can never become my answer.
	int ans = n;

	while (s <= e) {

		int mid = (s + e) / 2;
		// int mid = (s + (e - s) / 2);
		// int mid = e - (e - s) / 2;


		if (a[mid] >= x) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	return ans;
}



int Upper_Bound(int *a, int n) {

	int s = 0, e = n - 1;

	//We are applying BS on Array indices.

	//int ans = -1;//You want to initialise it with a variable
	// that can never become my answer.
	int ans = n;

	while (s <= e) {

		int mid = (s + e) / 2;
		// int mid = (s + (e - s) / 2);
		// int mid = e - (e - s) / 2;


		if (a[mid] > x) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;

	// int ans = 10;
	int ans = Lower_Bound(a, n);
	cout << ans << endl;

	int ans2 = Upper_Bound(a, n);
	cout << ans2 << endl;

	cout << ans2 - ans << endl;//O(log(n))

	//Returns the address in case of derived Data types.
	//Containers ke case me it returns the iterator to the bucket.

	cout << lower_bound(a, a + n, 17) - a << endl;
	cout << upper_bound(a, a + n, 17) - a << endl;



	// if (0) {
	// 	cout << "Uo";
	// }

	// return 0;
}


// void :

//statements 0


//Stoping : 4 sec.



// lower()--->address of the bucket jaha element mila-address of base.
