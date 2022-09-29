#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N, K;
vector<pair<int, int>>v;
vector<int>v2;

int main() {
	cin >> N;
	int answer = 0;
	for (int i = 0;i < N;i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ e,s });
	}

	sort(v.begin(), v.end());

	int time = 0;
	for (int i = 0;i < N;i++) {
		if (time <= v[i].second) {
			time = v[i].first;
			answer++;
		}
	}

	cout << answer << "\n";

	return 0;
}