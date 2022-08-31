#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1000];
int dp[1000];
int result;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	result = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i-1; j>=0; j--) {
			if (arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (result < dp[i])result = dp[i];
	}
	cout << result << "\n";
	
	return 0;
}