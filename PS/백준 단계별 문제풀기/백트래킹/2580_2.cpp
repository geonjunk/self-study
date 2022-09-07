#include<iostream>
#include<vector>
using namespace std;

int arr[9][9];
vector<pair<int, int>>space;
int zerocnt = 0;
bool finish = false;

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

void backtracking(int cnt) {
    if (zerocnt == cnt) {
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        finish = true;
        return;
     }
    

    for (int i = 1;i <=9;i++) {
        int r = space[cnt].first;
        int c = space[cnt].second;
        if (isPromising(space[cnt].first, space[cnt].second, i)) {
            arr[r][c] = i;
            backtracking(cnt + 1);
            arr[r][c] = 0;
        }
        if (finish) return;
    }
}


int main() {
    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                space.push_back({ i,j });
                zerocnt++;
            }
        }
    }
    backtracking(0);
    return 0;
}


//모든 pos 지나면서 0인지 판단해야함
//만약 0이면 탐색시작 -가로 세로, 9개