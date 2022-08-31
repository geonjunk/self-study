#include<iostream>
#include<vector>
using namespace std;


int n, m;
int arr[8][8];
int tmp[8][8];

int result = 0;
int r = 3;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<pair<int, int>>idx;

void map_copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < idx.size(); i++) {
		tmp[idx[i].first][idx[i].second] = 1; //여기서 2인것도 바꿈
	}
}
void check_safe_area() {
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0)c++;
		}
	}

	if (result < c)result = c;

	//cout << result << "\n";
}
void dfs(int r, int c) {
	int dx, dy;
	for (int i = 0; i < 4; i++) {
		dx = dir[i][0] + r;
		dy = dir[i][1] + c;
		if (dx >= 0 && dx < n&&dy >= 0 && dy < m&&tmp[dx][dy] == 0) {
			tmp[dx][dy] = 2;
			dfs(dx, dy);
		}
	}
}

void make_wall(int s) {
	if (r == idx.size()) {
		map_copy();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == 2) {
					dfs(i, j);
				}
			}
		}
		check_safe_area();
	}
	else if (s == m * n) {
		return;
	}
	else {
		if (arr[s / m][s%m] == 0) {

			idx.push_back({ s / m,s%m });
			make_wall(s + 1);
			idx.pop_back();
		}
		make_wall(s + 1);

	}

}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	make_wall(0);
	cout << result << "\n";

	return 0;
}
//삼성 SW역량 테스트 기출
/* 정리할 포인트
1. 조합 알고리즘 (조합 알고리즘 종류)
2. dfs의 여러 활용 ( ex) 탐색 o, 탐색x 나눠서 길 감)
3. 브루트포스 알고리즘의 경험
*/
/*

void Combination(vector<char>arr, vector<char>comb, int idx, int depth) {//원본배열, comb 배열, idx -> arr에서 현재 위치,depth ->3만큼만 반복(comb의 자릿수 만큼만 반복)
   if (depth == comb.size()) {
	  for (int i = 0; i < comb.size(); i++) {
		 cout << comb[i]<<" ";
	  }
	  cout << "\n";
	  return;
   }

   for (int i = idx; i < arr.size(); i++) {
	  comb[depth] = arr[i];
	  Combination(arr, comb, i + 1, depth + 1);
   }
}
int main()
{
   vector<char> vec = { 'a', 'b', 'c', 'd', 'e' };  // n = 5

   int r = 3;
   vector<char> comb(r);//comb의 자릿수 지정

   Combination(vec, comb, 0, 0);  // {'a', 'b', 'c', 'd', 'e'}의 '5C3' 구하기

   return 0;
}
void Combination(vector<char>arr, vector<char>comb,int r, int idx, int depth) {//depth는 arr를 순회, idx는comb를 순회
   if (r == 0) {
	  for (int i = 0; i < comb.size(); i++) {
		 cout << comb[i];
	  }
	  cout << "\n";
	  return;
   }

   if (depth == arr.size()) {
	  return;
   }

   comb[idx] = arr[depth];
   Combination(arr, comb, r-1, idx+1, depth+1);

   Combination(arr, comb, r , idx, depth+1);


}
int main() {
   vector<char> vec = { 'a', 'b', 'c', 'd', 'e' };  // n = 5

   int r = 3;
   vector<char> comb(3);
   Combination(vec, comb,r, 0, 0);
   return 0;
}
*/