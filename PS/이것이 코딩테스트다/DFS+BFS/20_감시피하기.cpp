#include <string>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

char arr[7][7];
int N;
vector<pair<int, int>>teacherPos;
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

bool isPossible = false;


bool check() {
	for (int i = 0; i < teacherPos.size(); i++) {
		int r = teacherPos[i].first;
		int c = teacherPos[i].second;
		for (int j = 0; j < 4; j++) {
			int dr = r + dir[j][0];
			int dc = c + dir[j][1];
			
			while (!(dr<1 || dr>N || dc<1 || dc>N)) {
				if (arr[dr][dc] == 'O')
					break;
				if (arr[dr][dc] == 'S') {
					return false;
				}
				dr += dir[j][0];
				dc += dir[j][1];
			}
			
		}
	}
	return true;
}

void selectPos(int count) {
	if (count == 3) {
		if (check()) {
			isPossible = true;
		}
		return;
	}
	if (isPossible) {
		return;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 'X') {
				arr[i][j] = 'O';
				selectPos(count + 1);
				arr[i][j] = 'X';
			}
		}
	}
	
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T') {
				teacherPos.push_back({ i,j });
			}
		}
	}
	selectPos(0);
	if (isPossible) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
	return 0;
}