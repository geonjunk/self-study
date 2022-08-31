#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001];
int main() {
	int n;
	cin >> n;
	//1은 SK, 0은 CY
	dp[1] = dp[3]=0;
	dp[2] = 1;
	for (int i = 4; i <= n; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0)dp[i] = 1;//이전 경우에서 졌다면 지금은 이길 것
		else dp[i] = 0;
	}
	if (dp[n])cout << "SK" << "\n";
	else cout << "CY" << "\n";

	return 0;
}