#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



int N, M, K, X;

vector<vector<pair<int, int>>>v(300001);
int dist[300001];
priority_queue<pair<int, int>>q;

int main() {
	cin >> N >> M >> K >> X;
	for (int i = 1;i <= N;i++) {
		dist[i] = 1e9;
	}

	
	for (int i = 0;i < M;i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back({ 1,B });
	}
	
	q.push({ 0,X });
	
	while (!q.empty()) {
		int len = -q.top().first;
		int now= q.top().second;
		
		q.pop();
		if (dist[now]<len) {
			continue;
		}
		dist[now] = len;
		for (int i = 0;i < v[now].size();i++) {
			int pos = v[now][i].second;
			int cost = v[now][i].first;
			if (dist[pos] > dist[now] + cost) {
				q.push({ -(cost + dist[now]),pos });
				dist[pos] = dist[now] + cost;
			}
				
		}

	}

	bool isEmpty=true;
	for (int i = 1;i <=N;i++) {
		if (dist[i] == K) {
			cout << i << "\n";
			isEmpty = false;
		}
	}
	if (isEmpty)
		cout << -1 << "\n";
	return 0;
}


//다익스트라
//방문여부
//최소거리 저장 배열

//1~2