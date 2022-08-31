#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
int main() {
	int N;
	cin >> N;

	vector<pair<int, pair<int,string>>>v;
	for (int i = 0;i < N;i++) {
		int year;
		string s;
		cin >> year >> s;
		v.push_back({ year,{i,s} });
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < N;i++) {
		cout << v[i].first << " " << v[i].second.second << "\n";
	}
	return 0;
}

