#include<iostream>
using namespace std;

int dp[31][31];
/*int main(){
	int T,n,m;
	cin>>T;
	while(T>0){
		cin>>n>>m;
		for(int i=1;i<=m;i++) dp[1][i]=i;
		
		
		for(int i=2;i<=n;i++){
			dp[i][i]=1;
			for(int j=i+1;j<=m;j++){
				dp[i][j]=dp[i][j-1]+dp[i-1][j-1];//���� ������ �̿��� Ǯ�� 
			}
			
		}
		cout<<dp[n][m]<<"\n";
		T--;
	}
	
	
	
	return 0;
}
*/
int main(){
	int T,n,m;
	cin>>T;
	for(int i=1;i<=30;i++) dp[1][i]=i;
		for(int i=2;i<=30;i++){
			for(int j=i;j<=30;j++){
				for(int k=j;k>=i;k--){
					dp[i][j]+=dp[i-1][k-1];	
				}
			}
			
	}
	
	while(T>0){
		cin>>n>>m;
		cout<<dp[n][m]<<"\n";
		T--;
	}
	
	
	
	return 0;
}


// 1번 조합 공식을 이용한 풀이(맨 마지막 사이트를 고정으로 하여 생각) 
// 2번 반대로 생각 (맨 앞 사이트를 고정으로해서 생각) 
//최대 범위가 그렇게 크지않으므로 연산 다끝내고 n,m받기 

