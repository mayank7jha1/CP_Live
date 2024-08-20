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
	EED(a, m);
	return (x + m) % m;
}




int32_t main() {

	int n, p, w, d;
	cin >> n >> p >> w >> d;

	int x, y, z;
	int g = __gcd(w, d);

	if (n * w < p) {
		cout << "-1" << endl;
		return 0;
	}

	if (p % g != 0) {
		cout << "-1" << endl;
		return 0;
	}

	p = p / g;
	d = d / g;
	w = w / g;


	//y Ki value find karo.
	y = (((p % w) * MMI(d, w))) % w;
	x = (p - y * d) / w;

	if (x + y > n) {
		cout << "-1" << endl;
		return 0;
	}

	if (x < 0) {
		cout << "-1" << endl;
		return 0;
	}

	z = n - x - y;
	cout << x << " " << y << " " << z << endl;

}
