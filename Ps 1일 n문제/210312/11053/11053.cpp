#include<iostream>
#include<algorithm>
using namespace std;


int main(){
	
	int n;
	int num[1001];
	cin>>n;
	int arr[1001];
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int l=1;
	arr[1]=1;

	for(int i=2;i<=n;i++){
		arr[i]=1;
		for(int j=1;j<i;j++){
			if(num[j]<num[i]){
				arr[i]=max(arr[i],arr[j]+1);
			}
		}
		if(l<arr[i]) l=arr[i];	
	}
	cout<<l;
}
//11053 -> 특이한 dp 생각하기 어렵지만 자주나오는 유형임  
// 1번 arr[n]을 n까지의 배열에서 최고의 길이로 생각하고 풀려했지만 이렇게 하면 이전 경우에다가 새 수를 더한게 최고의 경우가 아닐 수도 있음
//-> 따라서 부분문제로 쪼개는 방법을 다르게 생각 ->arr[n] ->n을 무조건 포함하는 최고의 경우 ->이걸 다구하고 이중 최대값 찾음 