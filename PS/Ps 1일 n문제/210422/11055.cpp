#include<iostream>
#include<algorithm>
using namespace std;

int num[1001];
int dp[1001];
int main() {
	int n;
	int result;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	dp[1] = num[1];
	result = dp[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = num[i];
		for (int j = i; j > 0; j--) {
			if(num[j]<num[i])//증가하는
			dp[i] = max(dp[j]+num[i], dp[i]);
		}
		result = max(dp[i], result); //반복 줄임
	}
	
	cout << result << "\n";
	return 0;
}