#include<iostream>
#include<algorithm>
using namespace std;



int main(){
	int n;
	int dp[1001]={0,};
	int arr[1001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[1]=arr[1];
	for(int i=2;i<=n;i++){
		dp[i]=arr[i];		
		for(int j=i-1;j>0;j--){
			dp[i]=max(dp[i],dp[j]+arr[i-j]);
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}
