#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int main() {
	string s;
	cin >> s;
	vector<int>v;
	for (int i = 0;i < s.length();i++) {
		v.push_back(s[i]-'0');
	}
	sort(v.begin(), v.end(),greater<>());
	for (int i = 0;i < s.size();i++) {
		cout << v[i];
	}
	return 0;
}