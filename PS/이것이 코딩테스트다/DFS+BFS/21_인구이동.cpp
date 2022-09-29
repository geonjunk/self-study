#include<iostream>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;


int N, L, R;
int arr[51][51];


int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int answer = 0;

bool team[51][51];

vector<pair<int, int>> v;

bool bfs(int r,int c) {
	queue<pair<int, int>>q;
	team[r][c] = 1;
	q.push({ r,c });
	v.push_back({ r,c });

	int total = 0;
	total += arr[r][c];

	while (!q.empty()) {
		int sr =q.front().first;
		int sc = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int dr = sr + dir[i][0];
			int dc = sc + dir[i][1];

			if (dr<1 || dc<1 || dr>N || dc>N)
				continue;

			if (team[dr][dc] ==0) {
				int cal = abs(arr[sr][sc] - arr[dr][dc]);

				if (cal >= L && cal <= R) {
					q.push({ dr,dc });
					team[dr][dc] = 1;
					total += arr[dr][dc];
					v.push_back({ dr,dc });
				}
			}
		}
	}
	
	if (v.size() > 1) {
		total /= v.size();
		for (int i = 0;i < v.size();i++) {
			arr[v[i].first][v[i].second] = total;
		}
		return false;
	}
	else {
		return true;
	}


}

void initFlag() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			team[i][j] = 0;
		}
	}
}

bool cal() {
	bool isStop=true;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (team[i][j] == 0) {
				bool flag = bfs(i, j);
				v.clear();
				if (flag == false) {
					isStop = false;
				}
			}
		}
	}
	if(!isStop)
		answer++;

	initFlag();

	return isStop;
}

int main() {
	cin >> N>>L>>R;
	
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> arr[i][j];
		}
	}

	
	while (true)
	{
		if (cal())
			break;
	}

	cout << answer << "\n";

	return 0;
}