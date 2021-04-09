#include<iostream>
#include<queue>
using namespace std;


int main() {
	int T, n, m;
	cin >> T;
	queue<pair<int, int>>q;
	priority_queue<int>pq;
	int temp;
	pair<int, int> tmp;
	while (T > 0) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			q.push(pair<int, int>(i, temp));
			pq.push(temp);
		}
		
		for (int i = 1; i <= n; i++) {
			temp = pq.top();
			pq.pop();
			while (q.front().second != temp) {
				tmp = q.front();
				q.pop();
				q.push(tmp);
			}
		
			if (q.front().first == m) {
				cout << i << "\n";
				break;
			}
			else {
				q.pop();
			}
		}
		while (!q.empty()) q.pop();
		while (!pq.empty()) pq.pop();//각 큐 비워 줘야함
		T--;
	}


	return 0;
}
//1번 그냥 배열로 구현:같은 수 들어가는 경우 나가는 순서 문제랑 틀릴 수 있음
//2. 우선 순위 큐 이용
