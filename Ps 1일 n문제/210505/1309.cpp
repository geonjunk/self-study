#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[100001][3];
int main() {
	cin >> n;
	dp[1][0] = dp[1][1]=dp[1][2]=1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])%9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%9901;
	
	}
	cout << (dp[n][0] + dp[n][1] + dp[n][2])%9901 << "\n";

	return 0;
}

//힌트 : 배열을 2차원 배열로 생성함
//각 배치에 따라 이전에 올수있는게 달라짐 -> case 분류하여 dp 함
//이런 배치 문제 -> 대부분 case 분류하여 2차원 배열 이용
//2*(n-1)+n-2 로도 가능