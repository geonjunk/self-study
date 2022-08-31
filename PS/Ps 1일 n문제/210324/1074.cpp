#include<iostream>
#include<math.h>
using namespace std;

int count;
int n,row,col;
void search_z(int len,int rs,int cs){
 	int gap=len/2;
	if(row==rs&&col==cs){
			return;
	}
	if(rs<=row&&row<rs+gap){
	if(cs<=col&&col<cs+gap){
			search_z(n-1,rs,cs);
		}else{
			count+=((gap)*(gap));
			search_z(n-1,rs,cs+gap);
		}	
		}else{
		if(cs<=col&&col<cs+gap){
			count+=(gap*gap*2);
			search_z(n-1,rs+gap,cs);
		}else{
			count+=(gap*gap*3);
			search_z(n-1,rs+gap,cs+gap);
		}
		}
	
				
}//재귀 1 

//개선 -> 매재귀 마다 pow 계산하는 과정줄이기 위해 pow 자체를 인자로 받음
//-> if문 줄일 수 있게  -> 순서대로 탐색하면서 탐색위치 발견하면 출력 


void search(int len,int r,int c){
	if(r==row&&c==col){
		cout<<count<<"\n";
		return;
	}
	if(r<=row&&row<r+len&&c<=col&&col<c+len){
		search(len/2,r,c);
		search(len/2,r,c+len/2);
		search(len/2,r+len/2,c);
		search(len/2,r+len/2,c+len/2);
	}else count+=(len*len);
	
}

int main(){
	cin>>n>>row>>col;
	search(1<<n,0,0);//1의 2^n배 	 
	return 0;
}
//처음엔 arr이용하려 했음 -> 시간초과 
//순서에서 규칙 찾고 재귀 함수 만듬
//재귀함수 간단화 
