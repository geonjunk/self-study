#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown+yellow;
    
    for(int i=3;i<=sum/3;i++){//세로
        if(sum%i==0){
            int len=(sum)/i;//가로

            if(len>=i){
                if(yellow==((len-2)*(i-2))){
                    answer={len,i};
                    break;
                }
            }
        }
    }
    return answer;
}