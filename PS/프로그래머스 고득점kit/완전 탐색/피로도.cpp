#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool flag[8];

int ans=-1;
void dfs(int k,vector<vector<int>> dungeons,int cnt){
    
    for(int i=0;i<dungeons.size();i++){
        if(flag[i]==0){
            if(k>=dungeons[i][0]){
                flag[i]=1;
                dfs(k-dungeons[i][1],dungeons,cnt+1);
                flag[i]=0;
            }
        }
    }
    ans=max(ans,cnt);
    
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    dfs(k,dungeons,0);
    answer=ans;
    return answer;
}