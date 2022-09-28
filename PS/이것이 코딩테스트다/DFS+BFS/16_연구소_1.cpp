#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int N, M;

int arr[9][9];

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int answer = 0;

void calSafeZone() {
	int temp[9][9];

	queue<pair<int, int>>q;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			temp[i][j] = arr[i][j];
			if (temp[i][j] == 2)
				q.push({ i,j });
		}
	}


	
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0;i < len;i++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int j = 0;j < 4;j++) {
				int dr = r + dir[j][0];
				int dc = c + dir[j][1];

				if (dr < 1 || dr > 8 || dc < 1 || dc>8)
					continue;

				if (temp[dr][dc] == 0) {
					temp[dr][dc] = 2;
					q.push({ dr,dc });
				}
			}
		}
	}

	int tempAnswer = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (temp[i][j] == 0) {
				tempAnswer++;
			}
		}
	}

	answer = max(answer, tempAnswer);


	
}

void setWall(int count) {
	if (count == 3) {
		calSafeZone();
		return;
	}


	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				setWall(count + 1);
				arr[i][j] = 0;
			}
		}
	}
}


int main() {
	cin >> N >> M;
	

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> arr[i][j];
		}
	}

	setWall(0);
	cout << answer << "\n";
	return 0;
}