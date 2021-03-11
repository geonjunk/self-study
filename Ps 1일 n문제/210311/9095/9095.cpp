#include<iostream>
using namespace std;

int main(){
	int t,n;
	int add[11];
	add[1]=1;
	add[2]=add[1]+1;
	add[3]=add[1]+add[2]+1;
	for(int i=4;i<11;i++){
		add[i]=add[i-1]+add[i-2]+add[i-3];
	}
	cin>>t;
	for(;t>0;t--){
		cin>>n;
		cout<<add[n]<<"\n";
	}
	
	return 0;
}