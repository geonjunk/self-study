#include<iostream>
using namespace std;
     
int main(){
    int n;
    int count=0;
    cin>>n;
     	
     	//125보다 큰 5의배수는 500이상임 
    for(int i=1;i<=n;i++){
     	if(i%125==0){
     		count+=3;
     	}else if(i%25==0){
     		count+=2;
     	}else if(i%5==0){
     		count+=1;
     	}
    }	
     	
     	
    cout<<count<<"\n";
     	
    return 0;
}