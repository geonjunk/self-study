#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


bool flag[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>>chicken;
int N, M;

vector<pair<int, int>>sel;
int answer = 1e9;


void calChicken() {
	int partAnswer = 0;

	for (int i = 0; i < house.size(); i++) {
		int partMin = 1e9;
		for (int j = 0; j < sel.size(); j++) {
			int len = abs(house[i].first - sel[j].first)
				+ abs(house[i].second - sel[j].second);
			if (partMin > len) {
				partMin = len;
			}
		}
		partAnswer += partMin;
	}

	if (answer > partAnswer) {
		answer = partAnswer;
	}
}


void searchChicken(int idx) {
	if (sel.size() == M) {
		calChicken();
		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		int r = chicken[i].first;
		int c = chicken[i].second;
		if (flag[r][c] == 0) {
			flag[r][c] = 1;
			sel.push_back({ r,c });
			searchChicken(i + 1);
			sel.pop_back();
			flag[r][c] = 0;
		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				house.push_back({ i,j });
			}
			if (temp == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	searchChicken(0);

	cout << answer << "\n";
	return 0;
}
