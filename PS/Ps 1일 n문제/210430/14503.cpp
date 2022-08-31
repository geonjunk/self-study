#include<iostream>

using namespace std;



int arr[50][50];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int n, m;
int result = 1;
int r, c;
int d;

void dfs(int r, int c, int d) {

	int dr, dc;
	int tmp;
	//현재 방향 기준으로 왼쪽 방향부터 차례대로 탐색 
	for (int i = 0; i < 4;i++) {//d 반복문 수정 
		tmp= (d -i+ 3)%4;
		dr = r + dir[tmp][0];
		dc = c + dir[tmp][1];
		if (dr >= 0 && dr < n&&dc >= 0 && dc < m&&arr[dr][dc] == 0) {
			arr[dr][dc] = 2;
			result++;
			dfs(dr, dc, tmp);

		}

	}
	tmp = (d + 2) % 4;
	dr = r + dir[tmp][0];
	dc = c + dir[tmp][1];
	if (arr[dr][dc] == 1) {
		cout << result << "\n";
		exit(0);
	}
	dfs(dr, dc, d);//뒤쪽 방향으로 후진
	//탐색 4방향 빠져 나온경우 ->후진 가능 여부 판단 

}

int main() {



	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}

	}

	arr[r][c] = 2;//청소시작  
	dfs(r, c, d);


	cout << result << "\n";
	return 0;

}

