#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int p_stat[22][22];
int n;

int min_stat = 1e+9;
bool flag[22] = { 0, };



void backtracking(int cnt,int pos) {
    if (cnt == n/2) {
        int result ;
        int team1 = 0, team2 = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                if (flag[i] && flag[j]) team1 += p_stat[i][j];
                if (!flag[i] && !flag[j]) team2 += p_stat[i][j];
            }
        }
        result = abs(team1 - team2);
        if (min_stat > result) {
            min_stat = result;
        }
        return;
    }

    for (int i = pos;i <= n;i++) {
        if (!flag[i]) {
            flag[i] = true;
            backtracking(cnt + 1,i+1);
            flag[i] = false;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> p_stat[i][j];
        }
    }
   
    backtracking(0,1);
    cout << min_stat << "\n";
    return 0;
}