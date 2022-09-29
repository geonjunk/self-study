#include<iostream>

using namespace std;


int N, K;
int coin[10];
int main() {
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		cin >> coin[i];
	}
	int answer = 0;
	
	for (int i = N-1;i >=0;i--) {
		answer += (K / coin[i]);
		K %= coin[i];
		if (K == 0) {
			break;
		}
	}
	cout << answer << "\n";

	return 0;
}