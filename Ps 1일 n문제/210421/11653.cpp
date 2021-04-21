#include<iostream>
using namespace std;
     
 int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
     	while(n%i==0){
     		n/=i;
     		cout<<i<<"\n";
     	}
     	if(n==1) break;
    }
     	
  	return 0;
}
