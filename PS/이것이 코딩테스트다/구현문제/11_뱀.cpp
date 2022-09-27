#include<iostream>
#include<queue>
using namespace std;

int flag[101][101] = { 0, };
pair<int,char> t[100];
int n, k, l;
queue<pair<int, int>>q;

void search() {
	int r = 1, c = 1;
	int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	int d = 0;
	int sec = 1;

	int s = 0;

	q.push({ r,c });
	
	while (true) {
		int tempR = r + dir[d][0];
		int tempC = c + dir[d][1];


		if (tempR > n || tempR<1 || tempC>n || tempC < 1||flag[tempR][tempC] == 2 ) {
			//벽에부?�히거나, ?�기?�신?�테 부?�힘
			break;
		}
		else {
			if (flag[tempR][tempC] == 0) {
				flag[q.front().first][q.front().second] = 0;
				q.pop();
			}
			q.push({ tempR,tempC });
			flag[tempR][tempC] = 2;
		}

		//방문
		flag[tempR][tempC] = 2;
		r = tempR;
		c = tempC;

		if (s<l&&t[s].first == sec) {
			if (t[s].second == 'D') {
				d = (d + 1) % 4;
			}
			else {
				d = (d +3) % 4;
			}
			s++;
		}
		sec++;
	}

	cout << sec << "\n";
}


int main() {
	

	cin >> n >> k;


	for (int i = 0;i < k;i++) {
		int r, c;
		cin >> r >> c;
		flag[r][c] = 1;
	}

	cin >> l;
	for(int i = 0;i < l;i++) {
		int x;
		char c;
		cin >> x >> c;
		t[i]={ x,c };
	}
	search();
	return 0;
}