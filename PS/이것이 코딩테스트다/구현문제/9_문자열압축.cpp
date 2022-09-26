#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.length();
    int len = s.length();
    for(int i=1;i<=len/2;i++){
        int num=1;
        string temp="";
  
        string ss=s.substr(0,i);
        for(int j=i;j<len;j+=i){
            if(ss==s.substr(j,i)){
                num++;
            }else{
                if(num>1){
                    temp+=to_string(num);
                }
                temp+=ss;
                ss=s.substr(j,i);
                num=1;
            }
        }
        if(num>1){
            temp+=to_string(num);
        }
        temp+=ss;
        if(answer>temp.length()){
            answer=temp.length();
        }
    }
    
    return answer;
}