#include<iostream>
using namespace std;
     
int arr[1001];
int temp[1001];
int binary_search(int key,int s,int e){
    int m;
    while(s<=e){
     	m=(s+e)/2;
     	if(temp[m]==key) return m;
     	else if(temp[m]>key) e=m-1;
     	else s=m+1;
    }	
    return s;//처음 원본 값보다 배열 안에 값이 커지는 부분(마지막엔 s,e 위치 바뀌므로 s가 맞음) 
}
int main(){
    int n,size=1,idx;
    cin>>n;
    for(int i=1;i<=n;i++){
     	cin>>arr[i];
    }
    temp[1]=arr[1];
    for(int i=2;i<=n;i++){	
     	if(temp[size]<arr[i]) temp[++size]=arr[i];
     	else{
     		idx=binary_search(arr[i],1,size); 
     		temp[idx]=arr[i];
     	}
    }
    cout<<size<<"\n";
     	
    return 0;
}
