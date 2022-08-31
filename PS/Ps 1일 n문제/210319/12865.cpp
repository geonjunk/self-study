#include<iostream>
#include<algorithm>
using namespace std;
int dp[101][100001];//몇번째 물품까지 추가 , 무게
int arr[101][2];//무게 가치

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
				dp[i][j] = dp[i - 1][j];
			if(j>=arr[i][0]) dp[i][j] = max(dp[i][j], dp[i][j - arr[i][0]] + arr[i][1]);
		}
	}
	cout << dp[n][k] << "\n";
	return 0;
}