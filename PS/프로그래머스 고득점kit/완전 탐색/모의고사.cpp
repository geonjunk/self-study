#include <string>
#include <vector>

using namespace std;

int arr[3]={0,};

vector<vector<int>>v(3);

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    v[0]={1,2,3,4,5};
    v[1]={2,1,2,3,2,4,2,5};
    v[2]={3,3,1,1,2,2,4,4,5,5};
    for(int i=0;i<answers.size();i++){ 
        int idx1=i%5;
        int idx2=i%8;
        int idx3=i%10;
        
        if(answers[i]==v[0][idx1]){
            arr[0]++;
        }
        
        if(answers[i]==v[1][idx2]){
            arr[1]++;
        }
        
        if(answers[i]==v[2][idx3]){
            arr[2]++;
        }
    }
    int maxAnswer=0;
    for(int i=0;i<3;i++){
        maxAnswer=max(maxAnswer,arr[i]);
    }
    
     for(int i=0;i<3;i++){
        if(maxAnswer==arr[i]){
            answer.push_back(i+1);
        }   
     }
    
    
    
    return answer;
}