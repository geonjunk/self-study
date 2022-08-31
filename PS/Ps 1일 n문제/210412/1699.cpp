#include<iostream>
#include<algorithm>
using namespace std;


int dp[100001];
int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = i;// 다 1인게 최대값이므로 i가 최댓값 
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i - j * j] + 1, dp[i]);
		}
		//	cout<<i<<" : "<<dp[i]<<"\n";
	}

	cout << dp[n] << "\n";


	return 0;
}