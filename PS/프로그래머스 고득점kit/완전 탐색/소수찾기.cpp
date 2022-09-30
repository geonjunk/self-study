#include <string>
#include <vector>
#include <set>

using namespace std;

#define MAX 10000000

set<int>s;

bool isPrime[MAX];//1이면 소수 X, 0이면 소수
bool flag[8];

void calPrime(){
    isPrime[0]=isPrime[1]=1;
    for(int i=2;i<MAX;i++){
        if(isPrime[i]!=1){
            for(int j=i;j<MAX;j+=i){
                if(j!=i){
                    isPrime[j]=1;
                }
            }
        }
    }
}

void dfs(string numbers,string ans,int depth){
    if(ans.size()==depth){
        int num=stoi(ans);
        if(!isPrime[num])
            s.insert(num);
        
        return;
    }
    
    for(int i=0;i<numbers.size();i++){
        if(flag[i]==0){
            flag[i]=1;
            dfs(numbers,ans+numbers[i],depth);
            flag[i]=0;
        }
        
    }
}

int solution(string numbers) {
    int answer = 0;
    
    calPrime();
    for(int i=0;i<numbers.size();i++){
        dfs(numbers,"",i+1);
    }
    answer=s.size();
    return answer;
}