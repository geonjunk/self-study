#include<iostream>
#include<queue>
using namespace std;


int visited[5001];
int main(){
	int n;
	int count=0;
	int size,temp;
	cin>>n;
	queue<int>q;
	visited[n]=1;
	q.push(n);
	while(!visited[0]&&!q.empty()){
		size=q.size();
		count++;
		for(int i=0;i<size;i++){
			temp=q.front();
			q.pop();
			if(temp/3>0&&!visited[temp-3]){
				visited[temp-3]=1;
				q.push(temp-3);
			}
			if(temp/5>0&&!visited[temp-5]){
				visited[temp-5]=1;
				q.push(temp-5);
			}		
		}
	}
	if(!visited[0]) count=-1;
	cout<<count<<"\n";
	return 0;
}

//안됐을때 -1 출력하는거 
