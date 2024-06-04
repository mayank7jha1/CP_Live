#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define PI 3.14159265359

//This gives us the value of f(x) on a given x.
double Function(double x, double b, double c) {
	return ((x * x) + (b * x) + c) / sin(x);
}

//This gives us the value of f'(x) on a given x.

double Derivative(double x, double b, double c) {
	return ((2 * x + b) * (sin(x))) - (cos(x) * (x * x + b * x + c));
}

//Range: s-e>10^-6 and count.

//THis is Method 1: Using Ternary Search.
double IsThisJee(double b, double c) {

	double s = 0;
	double e = PI / 2;

	double ans;

	while (e - s > 1e-6) {

		double m1 = s + (e - s) / 3.0;
		double m2 = e - (e - s) / 3.0;

		if (Function(m1, b, c) > Function(m2, b, c)) {
			s = m1;
			ans = m2;
		} else if (Function(m1, b, c) < Function(m2, b, c)) {
			e = m2;
			ans = m1;
		} else {
			s = m1, e = m2;
			ans = m1;
		}
	}

	return ans;
}


//Using Binary Search

double IsThisJee2(double b, double c) {

	double s = 0;
	double e = PI / 2;

	double ans;
	int count = 0;

	while (s <= e) {

		double mid = (s + e) / 2;

		double val = Derivative(mid, b, c);

		if (val < 0) {
			ans = mid;
			s = mid;
		} else {
			ans = mid;
			e = mid;
		}

		count++;
		if (count > 100) {
			break;
		}
	}

	return ans;
}



int main() {
	int t;
	cin >> t;
	while (t--) {

		double b, c;
		cin >> b >> c;

		double ans = IsThisJee(b, c);
		double ans2 = IsThisJee2(b, c);

		cout << fixed << setprecision(7) << Function(ans, b, c) << endl;
		cout << fixed << setprecision(7) << Function(ans2, b, c) << endl;

	}


	// cout << fixed << setprecision(8) << 200 / 3.0;
}