#include<iostream>
#include<vector>
using namespace std;

int arr[1000000];
int result[1000000];
int position[1000000];
int binary_search(int key,int s,int e){//반복 
	int mid;
	while(s<=e){
		mid=(s+e)/2;
		if(result[mid]>key){
			e=mid-1;	
		}else if(result[mid]<key){
			s=mid+1;
		}else{
			return mid;
		}
	}
	return s;//or e
} 
int binary_search2(int key,int s,int e){//반복 
	if(s>=e) return -1;
	int mid=(s+e)/2;
	if(result[mid]==key) return mid;
	if(result[mid]>key) return binary_search2(key,s,mid-1);
	if(result[mid]<key)  return binary_search2(key,mid+1,e);
	return s;// 현재 인덱스 출력 
} 


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	result[0]=arr[0];
	position[0]=0;
	int idx;
	int size=1;
	for(int i=1;i<n;i++){
		idx=binary_search(arr[i],0,size-1);
		if(idx<size) {
			result[idx]=arr[i];
			position[i]=idx; 
		}
		else {
		position[i]=size;
		result[size++]=arr[i];	
	
		}
	}
	
	cout<<size<<"\n";
	int temp=size-1;
	for(int i=n-1;i>=0;i--){
		 if(position[i]==temp){
		 	result[temp]=arr[i];
			temp--;
		 }
		 if(temp<0) break;
	}
	for(int i=0;i<size;i++){
		cout<<result[i]<<" ";
	}
	cout<<"\n";
	//1. 크기만 아는 법  : 1. 순차탐색 이용(o(n^2)) 2. 이진탐색 이용 3. 이진탐색 c++ 함수이용 O(nlogn) 4.dp O(n^2)
	// 벡터 이용 or 배열 이용 
	//2. 안에 내용도 아는법 : 위치 값 저장하는 변수 추가 + 역순으로 진행하여 인덱스를 순차적으로 넣어 처음 까지 찾음 
	// upper, lower bound 개념 
	
	return 0;
}