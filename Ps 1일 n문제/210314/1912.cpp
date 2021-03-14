#include<iostream>
#include<algorithm>
using namespace std;
int num[100001];
int dp[100001];//dp[i] : i번째에서 끝나는 제일큰 연속합

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	dp[1] = num[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(num[i], dp[i - 1] + num[i]); 
	}
	int max = dp[1];
	for (int i = 2; i <= n; i++) {
		if (max < dp[i]) max = dp[i];
	}
	cout << max << "\n";
	return 0;
}