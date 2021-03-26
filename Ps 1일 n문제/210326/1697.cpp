#include<iostream>
#include<queue>
using namespace std;


int visited[100001];
int main(){
	int n,k;
	queue<int>q;
	cin>>n>>k;
	int count=0;
	int size;
	q.push(n);
	visited[n]=1;
	while(!visited[k]&&!q.empty()){
		size=q.size();
		for(int i=0;i<size;i++){
		n=q.front();
		q.pop();
		if(0<=n-1&&visited[n-1]==0){
		q.push(n-1);
		visited[n-1]=1;	
		} 
		if(n+1<=100000&&visited[n+1]==0){
		q.push(n+1);	
		visited[n+1]=1;
		} 
		if(2*n<=100000&&visited[2*n]==0){
		q.push(2*n);
		visited[2*n]=1;	
		} 
		}
		count++;
	}
		cout<<count<<"\n";

	return 0;
}//설탕배달도 bfs로 가능 -> DP로 복잡하면 BFS 생각해보기 
// 반복적인 연산? -> 종류가 한방향이 아닌경우에는 BFS? 
// 항상 넣을때 마킹 -> 큐에 들어갈 데이터 최소화 
