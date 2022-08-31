#include<iostream>
#include<algorithm>
using namespace std;


int main(){
	int n,k;
	int coin[11];
	int total=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>coin[i];
	}

	
	for(int i=n;i>0&&k>0;i--){
		if(coin[i]<=k){
			total+=(k/coin[i]);
			k=k%coin[i];
		}
	}
	cout<<total<<"\n";
}