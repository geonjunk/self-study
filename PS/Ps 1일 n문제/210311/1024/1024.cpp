#include<iostream>
using namespace std;

int main(){
	int n,l;
	cin>>n>>l;
	int s=-1,e=-1;
	for(int i=l;i<=100;i++){
		if(i%2==1){//홀수
			if(n%i==0){
				s=n/i-i/2;
				e=n/i+i/2;
				break;
			} 
			
		}else{//짝수 
			if(n%i==i/2){
				s=n/i-i/2+1;
				e=n/i+i/2;
				break;
			} 
		}
	} 
	if(s<0) cout<<-1;
	else {
		for(;s<=e;s++){
			cout<<s<<" ";
		}
	}
	cout<<"\n";
	return 0;
}