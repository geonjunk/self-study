#include<iostream>
using namespace std;

 

int n;
int arr[100][100];
long long dp[100][100];
long long dfs(int r,int c) {

	if (r == n - 1 && c == n - 1) {

		return 1;//dp[n-1][n-1]

	}

	if(arr[r][c]==0) return 0;

	
	if(!dp[r][c]){
	if (r + arr[r][c] < n) {

		dp[r][c]+=dfs(r + arr[r][c], c);

	}
	if (c + arr[r][c] < n) {

		dp[r][c]+=dfs(r, c + arr[r][c]);

	}
	}
	return dp[r][c];

}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	cout << dfs(0, 0) << "\n";

	return 0;

}

 
//백트래킹 이용한 dfs 이용
//arr[r][c] 가 0일때 걸러줘야함 -> 걸러주지 않으면 0인 자리에서 제자리 탐색 반복함

/*
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[100][100];
int route;
void dfs(int r,int c) {
	if (r == n - 1 && c == n - 1) {
		route++;
		return;
	}
	if (r + arr[r][c] < n) {
		dfs(r + arr[r][c], c);
	}
	if (c + arr[r][c] < n) {
		dfs(r, c + arr[r][c]);
	}
	
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);

	cout << route << "\n";
	return 0;
}
*/ 
//그냥 dfs로만 했을 때 -> 시간 초과 발생