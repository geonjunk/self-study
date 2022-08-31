#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int sugar[1001][1001];
int dp[1001][1001];// (1,1)부터 현재위치까지의 최댓값



int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> sugar[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] =max( dp[i][j-1],max(dp[i - 1][j - 1], dp[i - 1][j]));
			dp[i][j] = dp[i][j] + sugar[i][j];
			
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}