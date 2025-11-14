#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int dx[3] = {};
int dy[3] = {};
int board[102][102];
int n;

int figure1(int x, int y) { //블록 별로 합 구하는 함수
	//cout << "figure1" << endl;
	int a, b;
	if (y + 3 >= n) a = INT_MIN;
	else { a = board[x][y] + board[x][y + 1] + board[x][y + 2] + board[x][y + 3]; }
	//cout << "figure1- a: " << a << endl;
	
	if (x + 3 >= n) b = INT_MIN;
	else { b = board[x][y] + board[x + 1][y] + board[x + 2][y] + board[x + 3][y]; }
	//cout << "figure1- b " << b << endl;
	
	return max(a, b);
}
int figure2(int x, int y) {
	int a, b;
	if (x+1 >= n || y + 2 >= n) a = INT_MIN;
	else { a = board[x][y] + board[x][y + 1] + board[x + 1][y + 1] + board[x + 1][y + 2]; }

	if (x + 2 >= n || y -1  < 0) b = INT_MIN;
	else { b = board[x][y] + board[x + 1][y] + board[x + 1][y-1] + board[x + 2][y-1]; }

	return max(a, b);
}

int figure3(int x, int y) {
	int a, b, c, d;

	if (x + 1 >= n || y + 2 >= n) a = INT_MIN;
	else { a = board[x][y] + board[x][y + 1] + board[x][y + 2] + board[x + 1][y + 2]; }

	if (x + 2 >= n || y - 1 < 0) b = INT_MIN;
	else { b = board[x][y] + board[x + 1][y] + board[x + 2][y] + board[x + 2][y - 1]; }

	if (x + 1 >= n || y + 2 >= n) c = INT_MIN;
	else { c = board[x][y] + board[x+1][y] + board[x+1][y + 1] + board[x + 1][y + 2]; }

	if (x + 2 >= n || y +1 >= n) d = INT_MIN;
	else { d = board[x][y] + board[x][y+1] + board[x + 1][y] + board[x + 2][y]; }

	return max({ a,b,c,d });
}
int figure4(int x, int y) {
	int a, b, c, d;

	if (x + 1 >= n || y + 2 >= n) a = INT_MIN;
	else { a = board[x][y] + board[x][y + 1] + board[x][y + 2] + board[x + 1][y + 1]; }

	if (x + 2 >= n || y - 1 < 0) b = INT_MIN;
	else { b = board[x][y] + board[x + 1][y] + board[x + 1][y-1] + board[x + 2][y]; }

	if (x + 1 >= n || y -1 < 0 || y+1 >=n) c = INT_MIN;
	else { c = board[x][y] + board[x + 1][y-1] + board[x + 1][y] + board[x + 1][y + 1]; }
	
	if (x + 2 >= n || y + 1 >= n) d = INT_MIN;
	else { d = board[x][y] + board[x+1][y] + board[x + 1][y+1] + board[x + 2][y]; }

	return max({ a,b,c,d });
}
int figure5(int x, int y) {
	int a;
	if (x + 1 >= n || y + 1 >= n) a = INT_MIN;
	else { a = board[x][y] + board[x][y + 1] + board[x+1][y] + board[x + 1][y + 1]; }

	return a;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0; 
	while (cin >>n) {
		if (n == 0) break;
		t++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		int sum = INT_MIN;
		//cout <<"min: " << sum << endl;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum = max(sum, figure1(i, j));
				//cout << "figure1: " << figure1(i, j) << endl;
				//cout << "sum: " << sum << endl;
				sum = max(sum, figure2(i, j));
				sum = max(sum, figure3(i, j));
				sum = max(sum, figure4(i, j));
				sum = max(sum, figure5(i, j));
			}
		}

		cout << t << ". " << sum << endl;

		memset(board, 0, sizeof(board));
	}

	return 0;
}