#include<iostream>
using namespace std;


int main(){
	int n,k;
	cin>>n>>k;
	int arr[201][201]={0,};

	for(int i=0;i<=k;i++) arr[0][i]=1; //n=0일때 항상 1
	for(int i=0;i<=n;i++) arr[i][1]=1;// k=1일때  항상 1
	

	for(int i=1;i<=n;i++){
	for(int j=2;j<=k;j++){
			arr[i][j]=arr[i-1][j]+arr[i][j-1];
			arr[i][j] %=1000000000;	
	}
	}
	
	cout<<arr[n][k]<<"\n";
	
	return 0;
}
