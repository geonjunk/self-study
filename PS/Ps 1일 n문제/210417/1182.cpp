#include<iostream>
using namespace std;


int arr[20];
int n, s;
int c;
void dfs(int x, int total) {
	if (x < n) {
		total += arr[x];
		if (total == s) {
			c++;
		}
		dfs(x + 1, total - arr[x]);
		dfs(x + 1, total);
	}


}
int main() {

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);
	cout << c << "\n";
	return 0;
}
//더하는것 , 더하지 않는것