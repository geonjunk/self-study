#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n; 
	int arr[1001];
	int min=0;
	cin>>n;
	arr[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		arr[i]=arr[i-1]+arr[i];
		min+=arr[i];
	}
	cout<<min<<"\n";
	return 0;
}