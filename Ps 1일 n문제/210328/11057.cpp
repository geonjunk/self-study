#include<iostream>
using namespace std;

int dp[1001][10];//0으로 시작가능
int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k >= 0; k--) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	int result = dp[n][0];
	for (int i = 1; i <= 9; i++) {
		result += dp[n][i];
		result %= 10007;
	}
	cout << result << "\n";


	return 0;
}