#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int n;
int loc[15];
int result = 0;

bool check(int cnt) {
    bool isPromising = true;

    //열이같은열인지
    //대각선인지
    for (int i = 0;i < cnt;i++) {
        if (loc[i] == loc[cnt] || abs(loc[cnt]-loc[i]) == abs(cnt - i)) {
            isPromising = false;
            break;
        }
    }
    return isPromising;
}


void backtracking(int cnt) {
    if (cnt == n) {
        result++;
        return;
    }

    for (int i =0;i <n;i++) {
        loc[cnt] = i;
        if (check(cnt)) {
            backtracking(cnt + 1);
        }
    }

}



int main() {
    cin >> n;
    backtracking(0);
    cout << result << "\n";
    return 0;
}