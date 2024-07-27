#include<bits/stdc++.h>
using namespace std;
const int N = 10;

int n;
int grid[N][N] = {0};
int Total_Boxes = 0;

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};


//If your Knight is currently standing at 5,4--->knight can jump to:
//(5+dx[i],4+dy[i])  where i goes from 0 to 7.

void input_grid() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == 1) {
				Total_Boxes++;
			}
		}
	}
}


int ans = -1;//Out of the all the path max path length kya thi.

void Solve(int x, int y, int count) {

	ans = max(ans, count);

	//Abhi you are standing at x,y co-ordinate.

	for (int i = 0; i < 8; i++) {

		int x_coordinate = x + dx[i];
		int y_coordinate = y + dy[i];

		if (x_coordinate >= 0 and x_coordinate<N and y_coordinate >= 0 and y_coordinate < N and grid[x_coordinate][y_coordinate] == 1 ) {

			grid[x_coordinate][y_coordinate] = 0;
			Solve(x_coordinate, y_coordinate, count + 1);

			grid[x_coordinate][y_coordinate] = 1;//Backtracking

		}

	}

}

int main() {
	cin >> n;
	input_grid();

	grid[0][0] = 0;

	Solve(0, 0, 1);

	cout << Total_Boxes - ans << endl;
}