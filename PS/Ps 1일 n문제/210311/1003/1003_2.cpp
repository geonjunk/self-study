#include<iostream>
using namespace std;

int main(){
	int t;
	int n;
	int fib[41];
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<=40;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	cin>>t;
	while(t>0){
		cin>>n;
		if(n==0) cout<<1<<" "<<fib[n]<<"\n";
		else cout<<fib[n-1]<<" "<<fib[n]<<"\n";
		t--;
	}

}