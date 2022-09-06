#include<iostream>
#include<vector>
using namespace std;


int n, m;
int arr[9] = { 0, };

void backtracking(int cnt,int pre) {
    if (cnt == m) {
        for (int i = 1;i <=m;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = pre;i <= n;i++) {
        arr[cnt+1] = i;
        backtracking(cnt + 1, i);
    }

}



int main() {
    cin >> n >> m;
    backtracking(0, 1);
    return 0;
}