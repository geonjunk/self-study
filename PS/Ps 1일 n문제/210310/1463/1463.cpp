#include<iostream>
#include<algorithm>
using namespace std;
int main(){//dp 
	int arr[1000001]; // 배열 크기 조건 잘보기 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		arr[i]=99999;
	}
	arr[1]=0;
	arr[2]=arr[3]=1;
	for(int i=4;i<=n;i++){  
		arr[i]=arr[i-1]+1;
		if(i%3==0) arr[i]=min(arr[i],arr[i/3]+1);
		if(i%2==0) arr[i]=min(arr[i],arr[i/2]+1);
	}
	cout<<arr[n]<<"\n";
}