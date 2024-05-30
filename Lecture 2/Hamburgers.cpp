#include<iostream>
using  namespace std;
#define int long long

int32_t main() {

	string st;
	cin >> st;

	int nb, ns, nc;
	cin >> nb >> ns >> nc;

	int pb, ps, pc;
	cin >> pb >> ps >> pc;

	int r;
	cin >> r;


	int s = 0;
	int e = 1e13;

	int ans = 0; //Maximum amount of hamburger you can make.

	int sb = 0, ss = 0, sc = 0;

	for (int i = 0; i < st.length(); i++) {
		if (st[i] == 'B') {
			sb++;
		} else if (st[i] == 'S') {
			ss++;
		} else {
			sc++;
		}
	}


	while (s <= e) {

		int mid = (s + e) / 2;

		int BKP = (mid * sb - nb) * pb;
		if (BKP < 0) {
			BKP = 0;
		}

		int SKP = (mid * ss - ns) * ps;
		if (SKP < 0) {
			SKP = 0;
		}

		int CKP = (mid * sc - nc) * pc;
		if (CKP < 0) {
			CKP = 0;
		}


		int TP = BKP + SKP + CKP;

		if (TP <= r) {
			s = mid + 1;
			ans = mid;
		} else {
			e = mid - 1;
		}

	}

	cout << ans << endl;

}


















