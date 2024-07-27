#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int n, m;
int a[200010] {0};
int student[101] {0};

void Function() {

	int total = 0;//Upto ith student time consumed kya hain.

	for (int i = 0; i < n; i++) {
		int diff = total - m + a[i];
		int Removed = 0;

		if (diff > 0) {
			for (int j = 100; j >= 1; j--) {
				int contribution = student[j] * j;

				if (contribution >= diff) {

					//Take the ceil value.
					Removed += ((diff + j - 1 ) / j);
					break;
				}
				Removed += student[j];
				diff -= contribution;
			}
		}

		student[a[i]]++;//Frequency Array Updated.
		total += a[i];//Update the total time consumed till i.
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


//Take Ceil value here: ceil (x / y) = floor((x - y + 1) / y);




// 40 40 40 40 40 40 40 40 50



// total = 320;

// diff = 320 + 50 - 100 = 270;

// 270 - 40 = 230 - 40 = 190 - 40 = 150 - 40 = 110 - 40 = 70 - 40 =  30 - 40;


// 270 / 40 = 6 + 1: extra time bach gaya hain uske liye student Remove karna padega na.