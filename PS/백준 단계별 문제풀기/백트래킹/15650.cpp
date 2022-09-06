#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int>v;
bool flag[9] = { 0, };


void backtracking(int cnt,int pre) {
    if (cnt == m) {
        for (int i = 0;i < m;i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = pre + 1;i <= n;i++) {
        if (!flag[i]) {
            flag[i] = 1;
            v.push_back(i);
            backtracking(cnt + 1, i);

            flag[i] = 0;
            v.pop_back();

        }

    }
}

int main() {
    cin >> n >> m;

    backtracking(0,0);

    return 0;
}