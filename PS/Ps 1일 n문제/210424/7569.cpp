#include<iostream>
#include<queue>
using namespace std;

typedef struct pos{
	int h;
	int r;
	int c;
}pos;
int m, n, h;//가로 세로 상자의 개수
int tomato[100][100][100];//상자의개수, 세로칸수 , 가로의칸수
queue<pos>q;
pos p;
int dir[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
int main() {
	int num = 0;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				cin >> tomato[i][r][c];
				if (tomato[i][r][c] == 1) {
					p.h = i;
					p.r = r;
					p.c = c;
					q.push(p);
				}
			}
		}

	}
	
	int size;
	int t, r, c;
	while (!q.empty()) {
		size = q.size();
		for (int i = 0; i < size; i++) {
			p = q.front();
			for (int j = 0; j < 6; j++) {
				t = p.h + dir[j][0];
				r = p.r + dir[j][1];
				c = p.c + dir[j][2];
				if (t >= 0 && t < h && r >= 0 && r < n && c >= 0 && c <m &&
					tomato[t][r][c] == 0) {
					tomato[t][r][c] = 1+tomato[p.h][p.r][p.c];//count수를 저장
					q.push(pos{ t,r,c });
				}
				
			}
			q.pop();
		}
	}
	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				if (tomato[i][r][c] == 0) {
					cout << "-1" << "\n";
					return 0;
				}
				if (count < tomato[i][r][c]) count = tomato[i][r][c];
			}
		}
	}

	cout << count - 1 << "\n";
	

	return 0;
}