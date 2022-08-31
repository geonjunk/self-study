#include<iostream>
#include<algorithm>
using namespace std;

int st[301];
int dp[301];//가중치
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> st[i];
	}
	dp[1] = st[1];
	dp[2] = st[1] + st[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + st[i], dp[i - 3] + st[i - 1]+st[i]);
	}
	cout << dp[n] << "\n";
	return 0;
}
