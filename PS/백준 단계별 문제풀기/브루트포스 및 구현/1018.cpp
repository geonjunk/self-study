#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
case 분류
1. B시작
2. W시작
*/

char input[50][50];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%s", &input[i]);
	}
	int ans=1000;
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int cntB = 0, cntW = 0;
			for (int k = i; k < i + 8; k++) {
				for (int t = j; t < j + 8; t++) {
					if ((k +t) % 2 == 0) {//짝짝, 홀홀
						if (input[k][t] == 'B') {
							cntW++;
						}
						else {
							cntB++;
						}
					}
					else {//짝홀,홀짝
						if (input[k][t] == 'B') {
							cntB++;
						}
						else {
							cntW++;
						}
					}
				}
			}
			ans = min(ans, cntW);
			ans = min(ans, cntB);
		}
	}
	cout << ans << "\n";

	return 0;
}
