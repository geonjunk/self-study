#include<iostream>
using namespace std;

int arr[500][500];
int dp[500][500];//현재위치에서  도착점까지 가는 경로의 개수 
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int m,n;
int dfs(int r,int c){//현재위치에서 도착점까지의 경로수를 리턴 
	if(r==m-1&&c==n-1){
		return 1;
	}
	int dr,dc;
	if(dp[r][c]<0){
	dp[r][c]=0;//첫방문 표시 
	for(int i=0;i<4;i++){
		dr=dir[i][0]+r;
		dc=dir[i][1]+c;
		if(dr>=0&&dr<m&&dc>=0
		&&dc<n&&arr[dr][dc]<arr[r][c]){
			dp[r][c]+=dfs(dr,dc);
		}
	}
	}
	return dp[r][c];
	
}

int main(){

	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			dp[i][j]=-1;
		}
	}
	
	cout<<dfs(0,0)<<"\n";
	
	return 0;
}