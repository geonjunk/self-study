#include<iostream>
#include<algorithm> 
using namespace std;
     
int arr[1001];
int temp[1001];
int main(){
    int n,size=1;
    int idx;
    cin>>n;
    for(int i=1;i<=n;i++){
     	cin>>arr[i];
    }
    temp[1]=arr[1];
    for(int i=2;i<=n;i++){	
     	if(temp[size]<arr[i]) temp[++size]=arr[i];
     	else{
     		idx=lower_bound(temp+1,temp+size,arr[i])-temp; 
     		temp[idx]=arr[i];
     	}
    }
    cout<<size<<"\n";
     	
    return 0;
}