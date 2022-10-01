#include<iostream>
#include<vector>
#include<queue>

using namespace std;


priority_queue<int>q;
int main() {
	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		q.push(-temp);
	}

	int answer=0;
	if(N>1) {
		while (!q.empty()) {
			int temp1 = -q.top();
			q.pop();
			if(!q.empty()) {
				int temp2 = -q.top();
				q.pop();
				q.push(-(temp1 + temp2));
				answer += temp1 + temp2;
			}
		}
	}

	cout << answer << "\n";

	

	return 0;
}