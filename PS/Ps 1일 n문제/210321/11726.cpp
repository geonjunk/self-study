#include<iostream>
using namespace std;

int arr[1001];
int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;
	}
	cout << arr[n] << "\n";
	return 0;
}

// n>=3일때 부터 점화식 설정
// n=3일때는 n=2일때에서 세로 사각형 하나 추가한 경우의수 + n=1일때에서 가로 사각형 2개 추가한경우의수
//즉, arr[n]=arr[n-1]+arr[n-2]