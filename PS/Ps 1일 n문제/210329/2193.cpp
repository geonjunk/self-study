#include<iostream>
using namespace std;


long long dp[91][2];//범위가 틀림  
int main(){
	int n;
	cin>>n;
	dp[1][1]=1;
	
	for(int i=2;i<=n;i++){	
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}
	cout<<dp[n][0]+dp[n][1]<<"\n";
	
	return 0;
}

long long dp[91];
int main(){
	int n;
	cin>>n;
	dp[1]=dp[2]=1;
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-2]+dp[i-1];
	}
	cout<<dp[n]<<"\n";
}

//1. 자릿수와 마지막수 idx로 하는 2차원 배열을 이용한 풀이
//2. 마지막수가 0이면 다가능 + 1이면 그 앞자리는 무조건0 -> 피보나치 이용가능 
//int가 아니라 long 배열로
// 
