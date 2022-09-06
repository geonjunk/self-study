#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n, m;
bool flag[9] = { 0, };
vector<int>v;

void backtracking(int cnt) {
    if (cnt == m) {
        for (int i = 0;i < v.size();i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1;i <= n;i++) {
        if (!flag[i]) {
            flag[i] = 1;
            v.push_back(i);
            backtracking(cnt+1);
            
            flag[i] = 0;
            v.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    backtracking(0);
    return 0;
}