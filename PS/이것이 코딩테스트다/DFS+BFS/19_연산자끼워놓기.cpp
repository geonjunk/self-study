#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;



int N;
int arr[11];
int c1, c2, c3, c4;
int op[4];


int maxNum = -1e9, minNum = 1e9;
void backtracking(int dep,int num) {
	if (dep == N) {
		maxNum = max(num, maxNum);
		minNum = min(num, minNum);

		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < op[i]; j++) {
			switch (i)
			{
			case 0:
				op[i]--;
				backtracking(dep + 1, num + arr[dep ]);
				op[i]++;
				break;
			case 1:
				op[i]--;
				backtracking(dep + 1, num - arr[dep]);
				op[i]++;
				break;
			case 2:
				op[i]--;
				backtracking(dep + 1, num * arr[dep]);
				op[i]++;
				break;
			case 3:
				op[i]--;
				backtracking(dep + 1, num / arr[dep]);
				op[i]++;
				break;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	backtracking(1,arr[0]);
	cout << maxNum << "\n";
	cout << minNum << "\n";
	return 0;
}