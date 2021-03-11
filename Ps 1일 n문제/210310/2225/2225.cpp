#include<iostream>
using namespace std;

int arr[201][201];

int main(){
	int n,k;
	cin>>n>>k;

	arr[0][0]=1;
		
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=j;k++){
				arr[j][i]+=arr[j-k][i-1];
				arr[j][i] %=1000000000;
			}
		}
	}
	cout<<arr[n][k]<<"\n";
	return 0;
}