#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
#define int long long
int Fact[N] {0};

//Addition Property
//O(1)
int Addition(int x, int y) {
	return ((x % P + y % P) % P);
}

//Substraction Property
//O(1)
int Subtraction(int x, int y) {
	return (((x % P) - (y % P)) + P) % P;
}

//Multiplication Property
//O(1)
int Multiply(int x, int y) {
	return ((x % P) * (y % P)) % P;
}


//Fast Power Using Recursion
//O(Log(y))
int Fast_Power2(int x, int y) {

	if (y == 0) {
		return 1;
	}

	int small_ans = Fast_Power2(x, y / 2);

	if (y % 2 == 1) {
		return small_ans * small_ans * x;
	} else {
		return small_ans * small_ans;
	}
}

//Fast Power using Iteration:
//O(log(y))
//(x^y)%P
int Fast_Power(int x, int y) {
	int result = 1;
	while (y > 0) {
		if (y % 2 == 1) {
			result = Multiply(result, x);
		}
		y /= 2;
		x = Multiply(x, x);
	}
	return result;
}

//(y^-1)%P
int Inverse(int y) {
	return Fast_Power(y, P - 2);
}


//O(log(y))
int division(int x, int y) {
	return Multiply(x, Inverse(y));
}

//Calculate Long Factorial:
void Calculate_Factorial() {
	Fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		Fact[i] = Multiply(Fact[i - 1], i);
	}
}

//nCr: Log(n)
/*
	nCr = (n! / r!*(n - r)!);
	t = n! * (r ^ -1)!;


	int t = Multiply(Fact[n], Inverse(Fact[r]));
	return Multiply(t, Inverse(Fact[n - r]));
*/


int nCr(int n, int r) {
	return Multiply(Multiply(Fact[n], Inverse(Fact[r])), Inverse(Fact[n - r]));
}




int32_t main() {
	cout << Fast_Power(2, 5) << endl;
}