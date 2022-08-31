#include<iostream>
#include<queue>

using namespace std;

 

typedef struct loc{
	int r;
	int c;
}loc;

 

int tomato[1001][1001];

queue<loc> q; 
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };


int main() {
	int m, n;//col,row
	cin >> m >> n;
	int size = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> tomato[i][j];
			if(tomato[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	size=q.size();
	//넣으면서 마킹 -> 꺼내면서 탐색
	loc temp;
	while (!q.empty()) {
		for (int i = 0; i < size; i++) {
			temp = q.front();
			for (int j = 0; j < 4; j++) {
				if (temp.r +dr[j]<= n
					&&temp.r+dr[j]>=1 
					&& temp.c+dc[j] <= m
					&&temp.c+dc[j]>=1
					&& tomato[temp.r + dr[j]][temp.c + dc[j]] == 0) {
					tomato[temp.r + dr[j]][temp.c+dc[j]] = tomato[temp.r][temp.c] + 1;
					q.push({ temp.r + dr[j],temp.c +dc[j]});
				}
			}
			q.pop();

		}
		size = q.size();
	
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (tomato[i][j] == 0) {
				cout << "-1" << "\n";
				return 0;
			}
			if (count < tomato[i][j]) count = tomato[i][j];
		}
	}

	cout << count-1 << "\n";


	return 0;
}
 