#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N, K,S, X, Y;
int virus[201][201] = { 0, };
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
vector < pair<int, pair<int, int>>>q;
void search() {
	int sec = 0;

	
	while (!q.empty()) {
		if (sec == S) {
			break;
		}
		int len = q.size();
		sort(q.begin(), q.end());

		for (int i = 0; i < len; i++) {
			int num = q[0].first;
			int x = q[0].second.first;
			int y = q[0].second.second;
			q.erase(q.begin());

			for (int j = 0; j < 4; j++) {
				int dx = dir[j][0] + x;
				int dy = dir[j][1] + y;

				
				if (dx<1 || dx>N || dy<1 || dy>N) {
					continue;
				}
				if (virus[dx][dy] == 0) {
					virus[dx][dy] = num;
					q.push_back({ num,{dx,dy} });
				}
			}

		}
		sec++;
	}

}

int main() {


	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> virus[i][j];
			if (virus[i][j] != 0) {
				q.push_back({ virus[i][j],{i,j} });
			}
		}
	}


	cin >> S >> X >> Y;

	search();

	cout << virus[X][Y] << "\n";
	return 0;
}