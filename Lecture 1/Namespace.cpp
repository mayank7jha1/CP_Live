#include<iostream>
// using namespace std;

/*
	Naming Conflicts ko resolve karne ke liye kiye jaate hain.
*/

// <>--.Standard
//""

// #include"Mayank.h"


namespace Mayank {
void sum(int x, int y) {
	std::cout << x + y << std::endl;
}
};

namespace Samyak {
void sum(int x, int y) {
	std::cout << x - y << std::endl;
}
};

int main() {
	std::cout << "Mayank" << std::endl;
	// C++: Overloading Allow

	// output stream:


	// cout{

	// };


	// cout << "Mayank";

	Mayank::sum(10, 16);
	Samyak::sum(1, 13);
}