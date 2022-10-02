#include<iostream>
using namespace std;


int main() {
	long long S;
	cin >> S;

	int idx = 1;
	while (true) {
		long long tmpSum = (long long) idx * (idx + 1) / 2;
		if (tmpSum > S) {
			break;
		}
		idx++;
	}
	cout << idx - 1 << "\n";

	return 0;
}