#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
int a[N] = {0};

/*

	GLobal scope: 10^8


*/

int main() {

	/*
		Whenever you are creating a array/vector/container
		inside a functional scope:
		online Judge: 10^6 size.

		Error(x).

		int a[N],b[N],c[N],d[N],e[N];

		variable bana rakhe hain: 10^6

	*/




	/*
		For Every element of this Container I am going to represent
		it as a variable and do this task.

		()--->Condition Brackets
		{
			:Scope Brackets
		}

		For each Loop is employed whenever we want to do some task
		on every element of the container.

		auto :

	*/


	for (int x : a) {
		cout << x << " ";
	}



}