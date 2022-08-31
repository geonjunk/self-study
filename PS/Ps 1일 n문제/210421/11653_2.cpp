#include<iostream>
#include<math.h>
using namespace std;




int main(){
	int n;
	cin>>n;
	for(int i=2;i<=sqrt(n);i++){
		while(n%i==0){
			n/=i;
			cout<<i<<"\n";
		}
		if(n==1) break;
	}
	
	if(n>1) cout<<N<<"\n";
	return 0;
}
