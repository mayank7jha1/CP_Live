#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int x, y, gcd;
#define int long long

int GCD(int x, int  y) {

	if (y == 0) {
		return x;
	}
	return GCD(y, x % y);
}

void EED(int a, int b) {

	if (b == 0) {
		x = 1;
		y = 0;
		gcd = a;
		return;
	}

	EED(b, a % b);

	//Current_x and current_y is the solution for a,b.: ax+by=gcd(a,b)
	int current_x = y;
	int current_y = x - ((a / b) * y);

	//Update my x and y as the solution for a,b.
	x = current_x;
	y = current_y;
}

int MMI(int a, int m) {

	if (GCD(a, m) != 1) {
		cout << "MMI doesn't Exist" << endl;
		return -1;
	}

	EED(a, m);

	return (x + m) % m;
}


int32_t main() {
	int a, m;
	cin >> a >> m;

	cout << MMI(a, m) << endl;
}
