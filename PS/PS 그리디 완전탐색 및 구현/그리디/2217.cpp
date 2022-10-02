#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;
	long long answer = -1;
	vector<int>rope;
	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		rope.push_back(temp);
	}
	sort(rope.begin(), rope.end());
	
	for (int i = 0;i < N;i++) {
		long long temp = (long long)rope[i] * (N - i);
		if (temp > answer) {
			answer = temp;
		}
	}
	cout << answer << "\n";
	return 0;
}