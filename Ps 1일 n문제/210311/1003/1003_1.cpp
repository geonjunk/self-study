#include<iostream>
using namespace std;

typedef struct Num{
	int n1,n2;//0의개수, 1의개수 
}num;
int main(){
	int t;
	int n;
	Num fib[41];
	fib[0].n1=fib[1].n2=1;
	fib[1].n1=fib[0].n2=0;
	for(int i=2;i<=40;i++){
		fib[i].n1=fib[i-1].n1+fib[i-2].n1;
		fib[i].n2=fib[i-1].n2+fib[i-2].n2;
	} 
	cin>>t;
	while(t>0){
		cin>>n;
		cout<<fib[n].n1<<" "<<fib[n].n2<<"\n";
		t--;
	}
	return 0;
}