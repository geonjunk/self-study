#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(),s.end());

	int pos=-1;
	for (int i = 0;i < s.length();i++) {
		if (s[i] >= 65) {
			pos = i;
			break;
		}
	}
	for (int i = pos;i < s.length();i++) {
		cout << s[i];
	}
	int num = 0;
	for (int i = 0;i < pos;i++) {
		num += s[i] - '0';
	}
	cout << num << "\n";

	return 0;
}
