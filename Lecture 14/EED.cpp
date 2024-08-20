#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int x, y, gcd;


//Log(b);
void EED(int a, int b) {

	if (b == 0) {

		//This represents equation:
		// ax+by=gcd(a,b)
		//ax+0=gcd(a,0);

		x = 1;
		y = 0;
		gcd = a;
		return;
	}

	EED(b, a % b);//Is Equation ka answer currently is x,y.

	//Current_x and current_y is the solution for a,b.: ax+by=gcd(a,b)
	int current_x = y;
	int current_y = x - ((a / b) * y);



	//Update my x and y as the solution for a,b.
	x = current_x;
	y = current_y;
}




int main() {
	int a, b;
	cin >> a >> b;

	int flag = 0;

	if (b > a) {
		flag = 1;
		swap(a, b);
	}

	EED(a, b);

	if (flag == 0) {

		cout << x << " " << y << " " << endl;

	} else {

		cout << y << " " << x << endl;
	}

	cout << gcd << endl;
}