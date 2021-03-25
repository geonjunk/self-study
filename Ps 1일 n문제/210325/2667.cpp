#include<iostream>
#include<algorithm>
using namespace std;
int arr[25][25];
bool visited[25][25];
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int building[323]={0,};
int num;
int n;
void dfs(int r,int c){//시작점 
	int t1,t2;	
	visited[r][c]=1;
	building[num]++;
	for(int i=0;i<4;i++){
		t1=r+d[i][0];
		t2=c+d[i][1];
		if(t1>=0&&t1<n&&t2>=0&&t2<n&&
		arr[t1][t2]==1&&!visited[t1][t2]){
		dfs(t1,t2);
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1&&!visited[i][j]){
				dfs(i,j);
				num++;
			}
		}
	}
	sort(building,building+num);//sort의 범위는 [start ,end) !! 
	cout<<num<<"\n";
	for(int i=0;i<num;i++)
	cout<<building[i]<<"\n";
	return 0;
}

//번호 매기는 거 없앰 
// 항상 n방향 탐색 시 배열 범위 생각하기 