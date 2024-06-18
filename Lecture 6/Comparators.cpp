#include<iostream>
#include<algorithm>
using namespace std;
const int N = 0;

//C1: How do you want to compare each and every element of this container
//but two at a time.


//Comparators : True / False:

bool compare(int x, int y) {
	if (x < y) {
		//We Don't have to do anything.
		return true;
	} else {

		//Swap these element.
		return false;
	}

	//return (x > y);
}

int main() {

	int a[] = {1, 14, 3, 9, 7};
	int n = 5;

	sort(a, a + n, compare);

	for (auto x : a) {
		cout << x << " ";
	}


	//1,3,7,9,14



	//First element that is greater than or equal to target.
	//Address return karta hain.

	// //When element is not present: address of a+n.
	// cout << lower_bound(a, a + n, 21) - a;

	// vector<int>a1{1, 2, 3, 4, 5};

	// cout << lower_bound(a1.begin(), a1.end(), 17) - a1.begin();


}