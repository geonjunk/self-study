#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int arr[9][9];


bool isPromising(int r,int c,int a) {
    //가로, 세로
    for (int i = 0;i < 9;i++) {
        if (arr[r][i] == a)return false;
        if (arr[i][c] == a)return false;
    }

    int startR = (r / 3) * 3, startC = (c/3)*3;

    for (int i = startR;i < startR + 3;i++) {
        for (int j = startC;j < startC + 3;j++) {
            if (arr[i][j] == a)return false;
        }
    }
    return true;
    //9자 판단
}

void backtracking(int r,int c) {
    if (r == 9) {
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
     }


    if (c == 9) {
        backtracking(r + 1, 0);
    }else if (arr[r][c]==0) {
        for (int i = 1;i <= 9;i++) {
            if (isPromising(r, c, i)) {
                arr[r][c] = i;
                backtracking(r, c + 1);
                arr[r][c] = 0;
            }
        }
    }else backtracking(r, c + 1);

}


int main() {
    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9;j++) {
            cin >> arr[i][j];
        }
    }
    backtracking(0, 0);
    return 0;
}


//모든 pos 지나면서 0인지 판단해야함
//만약 0이면 탐색시작 -가로 세로, 9개