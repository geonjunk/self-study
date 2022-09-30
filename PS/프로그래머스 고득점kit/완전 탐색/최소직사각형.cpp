#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxR=0,minC=0;
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0]<sizes[i][1]){
            maxR=max(sizes[i][1],maxR);
            minC=max(sizes[i][0],minC);
        }else{
            maxR=max(sizes[i][0],maxR);
            minC=max(sizes[i][1],minC);
        }
    }
    answer=maxR*minC;
    return answer;
}