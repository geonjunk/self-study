#include<iostream>
#include<algorithm> 
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int n;
	int lis;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = 1;
	lis = dp[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = 1;//기본 값 1 초기화해줘야 함
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}
		if (lis < dp[i]) lis = dp[i];	//마지막수가 최대값 아니므로 lis에 최대값 저장
	}

	cout << lis << "\n";

	return 0;
}
//특이한 dp 생각하기 어렵지만 자주나오는 유형임  
// 1번 arr[n]을 n까지의 배열에서 최고의 길이로 생각하고 풀려했지만 이렇게 하면 이전 경우에다가 새 수를 더한게 최고의 경우가 아닐 수도 있음
// 따라서 부분문제로 쪼개는 방법을 다르게 생각 ->arr[n] ->n을 무조건 포함하는 최고의 경우 ->이걸 다구하고 이중 최대값 찾음 