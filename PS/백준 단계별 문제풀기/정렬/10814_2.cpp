#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool compare(const pair<int, string>&p1, const pair<int, string>&p2) {
	return p1.first < p2.first;
}
int main() {
	int N;
	cin >> N;

	vector<pair<int, string>>v;
	for (int i = 0;i < N;i++) {
		int year;
		string s;
		cin >> year >> s;
		v.push_back({ year,s });
	}
	stable_sort(v.begin(), v.end(),compare);
	for (int i = 0;i < N;i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}

