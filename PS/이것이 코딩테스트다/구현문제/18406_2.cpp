#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int num = stoi(s);

	int len = s.length();
	int sum1 = 0, sum2 = 0;
	for (int i = 0;i < len;i++) {
		if (i < len / 2) {
			sum1 += num%10;
		}
		else {
			sum2 += num%10;
		}
		num /= 10;
	}

	if (sum1 == sum2) {
		cout << "LUCKY" << "\n";
	}
	else {
		cout << "READY" << "\n";
	}

	return 0;
}