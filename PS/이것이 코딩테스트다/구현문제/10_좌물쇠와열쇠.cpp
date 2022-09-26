#include <string>
#include <vector>

using namespace std;


int N,M;

bool check(vector<vector<int>>key , vector<vector<int>>board,int r,int c){
    for(int i=r;i<r+M;i++){
        for(int j=c;j<c+M;j++){
            board[i][j]+=key[i-r][j-c];
        }
    }
    for(int i=M-1;i<M+N-1;i++){
        for(int j=M-1;j<M+N-1;j++){
            if(board[i][j]>1||board[i][j]==0){
               return false; 
            }
        }
    }
    return true;
    
}

void rotate(vector<vector<int>> &key){
    vector<vector<int>> tmp(M,vector<int>(M,0));
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            tmp[i][j]=key[M-j-1][i];
        }
    }
    key=tmp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    M=key.size();
    N=lock.size();
    vector<vector<int>>board(2*(M-1)+N,vector<int>(2*(M-1)+N,0));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i+M-1][j+M-1] = lock[i][j];
        }
    }
    
    for(int i=0;i<4;i++){

        for(int r=0;r<M+N-1;r++){
            for(int c=0;c<M+N-1;c++){
                if(check(key,board,r,c)){
                    return true;
                }
            }
        }
        rotate(key);
    }
    
    return answer;
}
