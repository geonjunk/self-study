#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[100][100];
int route;
void dfs(int r,int c) {
	if (r == n - 1 && c == n - 1) {
		route++;
		return;
	}
	if (r + arr[r][c] < n) {
		dfs(r + arr[r][c], c);
	}
	if (c + arr[r][c] < n) {
		dfs(r, c + arr[r][c]);
	}
	
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);

	cout << route << "\n";
	return 0;
}
