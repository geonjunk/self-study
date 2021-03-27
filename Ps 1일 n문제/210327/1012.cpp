#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
typedef struct pos {
	int x;
	int y;
}pos;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int arr[50][50];
int visited[50][50];
void dfs(int x, int y) {
	visited[x][y] = 1;
	int dx, dy;
	for (int i = 0; i < 4; i++) {
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (dx >= 0&&dx<=50&&dy>=0&&dy<=50&&!visited[dx][dy] && arr[dx][dy])
		{
			dfs(dx, dy);
		}
	}
}
void print_worm() {

	int m, n, k;
	queue<pos>q;
	cin >> m >> n >> k;
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		q.push(pos{ x,y });
	}
	pos temp;
	int count = 0;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (!visited[temp.x][temp.y]) {
			dfs(temp.x, temp.y);
			count++;
		}		 
	}
	cout << count << "\n";
	
	
}
void init() {
	for (int i = 0; i < 50; i++) {
		memset(arr[i], 0, sizeof(int) * 50);
		memset(visited[i], 0, sizeof(int) * 50);
	}
	
}
int main() {
	int t;
	cin >> t;
	while (t > 0) {
		init();
		print_worm();
		t--;
	}
	return 0;
}