#include<iostream>
#include<algorithm>
using namespace std;

int plan[16][2];
int dp[16];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> plan[i][0] >> plan[i][1];
	}
	if (plan[n][0] == 1)dp[n] = plan[n][1];
	for (int i = n-1; i > 0; i--) {
		if (i + plan[i][0] -1<= n)
			dp[i] = max(dp[i + 1], dp[i + plan[i][0]] + plan[i][1]);
		else dp[i] = dp[i + 1];
	}
	cout << dp[1] << "\n";
	return 0;
}
//삼성전자 sw 역량테스트 기출
//경우의 수가 적다고 판단되면 dfs를 이용한 완전탐색이 제일 확실한 방법 
//상담하는 경우의수 1) 해당날 상담x 하고 다음날 2) 해당날 상담하고 걸리는 총일수만큼 넘어감
// 1. dfs 2. dp top down 방식 이용!