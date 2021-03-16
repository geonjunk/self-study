#include<iostream>
#include<queue>

using namespace std;

 

typedef struct loc{
	int r;
	int c;
}loc;

 
int tomato[1001][1001];
queue<loc> q;

int main() {
	int m, n;//col,row
	cin >> m >> n;
	int count = 0;
	int size = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> tomato[i][j];
			if(tomato[i][j] == 1) {
				q.push({ i,j });
				size++;
			}
		}
	}
	loc temp;
	while (!q.empty()) {
		for (int i = 0; i < size; i++) {
			temp = q.front();
			if (temp.r < n&&tomato[temp.r + 1][temp.c]==0) {
				tomato[temp.r + 1][temp.c] = 1;
				q.push({ temp.r + 1,temp.c });
			}
			if (temp.r > 1 && tomato[temp.r -1][temp.c] == 0) {
				tomato[temp.r - 1][temp.c] = 1;
				q.push({ temp.r - 1,temp.c });
			}
			if (temp.c < m&&tomato[temp.r][temp.c+1] == 0) {
				tomato[temp.r][temp.c + 1] = 1;
				q.push({ temp.r,temp.c + 1 });
			}
			if (temp.c > 1 && tomato[temp.r ][temp.c-1] == 0) {
				tomato[temp.r][temp.c - 1] = 1;
				q.push({ temp.r ,temp.c - 1 });
			}
			q.pop();
		}
		size = q.size();
		count++;
	}
	if (count > 0)count--;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (tomato[i][j] == 0) {
				count = -1;
				break;
			}
		}
	}

	cout << count << "\n";



	return 0;
}