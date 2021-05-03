#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int coin[101];
int dp[10001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		
	}
	for (int j = 0; j <= k; j++)dp[j] = 100001;
	
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i]) {
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			}
		}
	}
	if (dp[k] != 100001)
		cout << dp[k] << "\n";
	else cout << "-1" << "\n";
	return 0;
}