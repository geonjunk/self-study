#include<iostream>
using namespace std;

int main(){
	int n,l;
	cin>>n>>l;
	int s=-1;
	int temp;
	for(int i=l;i<=100;i++){
		temp=n-(i*(i-1)/2);
		if(temp/i>=0&&temp%i==0){ //음이 아닌 정수의 리스트이므로 0도 가능 
			s=temp/i;
			for(int k=s;k<(s+i);k++){
				cout<<k<<" ";
			}
				cout<<"\n";
				break;
		}
	}
	if(s<0) cout<<-1<<"\n";
	
	return 0;
} 