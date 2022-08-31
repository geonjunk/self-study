#include<iostream>
using namespace std;

int dp[1001];
int main() {
	int n;
	cin >> n;
	dp[2] =dp[4]= 1;


	for (int i = 5; i <= n; i++) {
		if (!dp[i - 1] && !dp[i - 3])dp[i] = 1;
		else dp[i] = 0;
	}
	if (dp[n]) cout << "CY" << "\n";
	else cout << "SK" << "\n";

	return 0;
}
/*
int main() {
	int n;
	cin >> n;

	if (n % 2 == 0) {
		cout << "CY" << "\n";
	}
	else cout << "SK" << "\n";

	return 0;
}*/
//1. 홀수(1,3)으로만 연산하므로, 홀수+홀수=짝수 ,짝수+ 홀수 =홀수임을 이용하는 방법
//2. 이전 단계에서 승리자를 dp로 기록하여 현재 승리자 찾음