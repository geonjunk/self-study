#include<iostream>
using namespace std;

int dp[31];
int n;
int main() {
	cin >> n;
	dp[2] = 3;
	dp[0] = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = dp[i - 2] * dp[2];
			for (int j = i - 4; j >= 0; j -= 2) {
				dp[i] += dp[j] * 2;
			}
	
		}
	}
	cout << dp[n] << "\n";

	return 0;
}