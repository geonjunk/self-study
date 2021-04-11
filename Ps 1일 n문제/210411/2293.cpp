#include<iostream>
using namespace std;

int coin[101];
int dp[10001];//i번째 코인까지만 사용하여 k를 만드는 경우의수
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <=n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j>=coin[i])dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k] << "\n";

	return 0;
}
