#include <string>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

bool pole[101][101];
bool bo[101][101];

bool install_bulld(int n,bool buildType,int x,int y){
    if(buildType){ //보
        if(y>0&&pole[y-1][x])//아래가 기둥
            return true;
        if(y>0&&x<n&&pole[y-1][x+1])//오른쪽아래가 기둥
            return true;
        if(x>0&&x<n&&(bo[y][x-1]&&bo[y][x+1]))//양쪽이 보
            return true;
    }else{//기둥
        if(y==0) 
            return true;
        if(y>0&&pole[y-1][x]) //아래가 기둥
            return true;
        if(x>0&&bo[y][x-1])//보의 오른쪽 끝
            return true;
        if(bo[y][x])//보의 왼쪽 끝
            return true;
    }
    return false;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> s;
    
    for(int i=0;i<build_frame.size();i++){
        int x=build_frame[i][0];
        int y=build_frame[i][1];
        bool buildType=build_frame[i][2];
        bool buildFlag=build_frame[i][3];
        
        if(buildType){
            //보다
            if(buildFlag){
                if(install_bulld(n,buildType,x,y)){
                    s.insert({x,y,buildType});
                    bo[y][x]=1;
                }
            }else{
                bo[y][x]=0;
                s.erase({x,y,buildType});
                for(auto iter = s.begin();iter!=s.end();iter++){
                    if(!install_bulld(n,(*iter)[2],(*iter)[0],(*iter)[1])){
                        s.insert({x,y,buildType});
                        bo[y][x]=1;
                        break;
                    }
                }
            }
        }else{
            if(buildFlag){
                if(install_bulld(n,buildType,x,y)){
                    s.insert({x,y,buildType});
                    pole[y][x]=1;
                }
            }else{
                pole[y][x]=0;
                s.erase({x,y,buildType});
                for(auto iter = s.begin();iter!=s.end();iter++){
                    if(!install_bulld(n,(*iter)[2],(*iter)[0],(*iter)[1])){
                        s.insert({x,y,buildType});
                        pole[y][x]=1;
                        break;
                    }
                }
            }
            
            
        }

    } 
    for(auto iter = s.begin();iter!=s.end();iter++){
        answer.push_back({(*iter)[0],(*iter)[1],(*iter)[2]});
    }
    return answer;
}