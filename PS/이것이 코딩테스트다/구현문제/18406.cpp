#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int len = s.length();
	int sum1 = 0, sum2 = 0;
	for (int i = 0;i < len;i++) {
		if (i < len / 2) {
			sum1 += s[i];
		}
		else {
			sum2 += s[i];
		}
	}

	if (sum1 == sum2) {
		cout << "LUCKY" << "\n";
	}
	else {
		cout << "READY" << "\n";
	}

	return 0;
}