#include<iostream>
#include<queue>
using namespace std;

typedef struct pos{
	int r;
	int c;
}pos;
int arr[101][101];
int visited[101][101]; 
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	int n,m;
	queue<pos> q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	pos temp;
	int size,count=1;

	q.push(pos{1,1});
	visited[1][1]=1;
	while(!visited[n][m]&&!q.empty()){
		size=q.size();
		for(int i=0;i<size;i++){
			temp=q.front();
			q.pop();
			for(int j=0;j<4;j++){
				if(temp.r+dir[j][0]>0&&temp.r+dir[j][0]<=100
				&&temp.c+dir[j][1]>0&&temp.c+dir[j][1]<=100
				&&arr[temp.r+dir[j][0]][temp.c+dir[j][1]]&&
				!visited[temp.r+dir[j][0]][temp.c+dir[j][1]]){
					q.push(pos{temp.r+dir[j][0],temp.c+dir[j][1]});
					visited[temp.r+dir[j][0]][temp.c+dir[j][1]]=1;
				}
			}
		}
		count++;
	}
		cout<<count<<"\n";
	
	return 0;
}
// 최소 칸수 이기때문에 bfs 로
 
