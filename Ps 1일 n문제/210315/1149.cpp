#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	//int color[1001][3];
	int color[3]; 
	int dp[1001][3]={0,};
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>color[j];
		}
		dp[i][0]=min(dp[i-1][1],dp[i-1][2])+color[0];
		dp[i][1]=min(dp[i-1][0],dp[i-1][2])+color[1];
		dp[i][2]=min(dp[i-1][0],dp[i-1][1])+color[2];
	}
	int min=dp[n][0];
	for(int i=1;i<3;i++){
		if(min>dp[n][i])
			min=dp[n][i];
	}
	cout<<min<<"\n";
	return 0;
}
//배열 크기 줄여서 공간 줄임 
