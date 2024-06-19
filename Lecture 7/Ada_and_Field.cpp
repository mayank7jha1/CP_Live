#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
const int N = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// int x;
	// scanf("%d", &x);
	// printf("%s\n", x);

	// cout << x << endl;

	int t;
	cin >> t;
	while (t--) {

		int n, m, q;
		cin >> n >> m >> q;

		multiset<int>x, y, sx, sy;

		x.insert(0);
		x.insert(n);

		y.insert(0);
		y.insert(m);


		sx.insert(n);
		sy.insert(m);

		for (int i = 0; i < q; i++) {

			int a, b;
			cin >> a >> b;

			if (a == 0) {

				if (x.find(b) != x.end()) {
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
				}

				//Mujhe x Axis me Segment banana hain.

				auto small = x.lower_bound(b);
				small--;
				auto large = x.upper_bound(b);

				//x: 0,5,10
				//b=8:

				//You have to insert b inside small and large.

				sx.erase(sx.find(*large - *small));
				sx.insert(*large - b);
				sx.insert(b - *small);

				x.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());

				cout << LargestXSegment*LargestYSegment << endl;


			} else {

				if (y.find(b) != y.end()) {
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());

					cout << LargestXSegment*LargestYSegment << endl;

				}

				//Mujhe x Axis me Segment banana hain.
				auto small = y.lower_bound(b);
				small--;
				auto large = y.upper_bound(b);
				//x: 0,5,10
				//b=8:

				//You have to insert b inside small and large.
				sy.erase(sy.find(*large - *small));
				sy.insert(*large - b);
				sy.insert(b - *small);

				y.insert(b);
				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());

				cout << LargestXSegment*LargestYSegment << endl;

			}
		}
		//cout << "UO";
	}

//	cout << "nmnm";

}


/*


	iostream header file is sync with stdio.h ke sath

	input output processes becomes slow.

	spoj: code logic sahi hain but tle.
	C++: C ke codes chala sakte ho.



*/