#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int T;

int main() {
	cin >> T;

	while (T-- > 0) {
		int answer = 1;
		vector<pair<int, int>>v;
		int N;
		cin >> N;
		for (int i = 0;i < N;i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}

		sort(v.begin(), v.end());


		int idx = 0;
		for (int i = 1;i < N;i++) {
			if (v[idx].second > v[i].second) {
				idx = i;
				answer++;
			}
		}
		cout << answer << "\n";
	}

	return 0;
}