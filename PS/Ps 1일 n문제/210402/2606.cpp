#include<iostream>
using namespace std;
int graph[101][101];
int visited[101];
int v, e;//v�� e��
int cp = 0;
void dfs(int x) {
	visited[x] = 1;
	for (int i = 1; i <= v; i++) {
		if (graph[x][i]&&!visited[i]) {
			cp++;//�������� ���� ����
			dfs(i);
		}
	}
}
int main() {
	
	int x, y;
	cin >> v;
	cin >> e;
	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}
	dfs(1);
	cout << cp << "\n";


	return 0;
}
//bfs + 인접리스트로도 해보기