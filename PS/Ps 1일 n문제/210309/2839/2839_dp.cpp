#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int sugar[5001];
	int n;
	cin >> n;
	for (int i = 0; i <=n; i++) {
		sugar[i] = 9999;
	}
	sugar[3] = sugar[5] = 1;
	for (int i = 6; i <= n; i++) {
		sugar[i] = min(sugar[i - 3], sugar[i - 5]) + 1;
	}
	if (sugar[n] >= 9999) cout << -1 << "\n";
	else cout << sugar[n] << "\n";

	return 0;
}