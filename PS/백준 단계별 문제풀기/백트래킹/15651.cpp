#include<iostream>
using namespace std;
#define MAX 9

int n, m;
int arr[MAX] = { 0, };
bool flag[MAX] = { 0, };

void backtracking(int cnt) {
    if (cnt == m) {
        for (int i = 1;i < m + 1;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1;i <= n;i++) {
            arr[cnt+1] = i;
            backtracking(cnt + 1);
    }

}

int main() {
    cin >> n >> m;

    backtracking(0);

    return 0;
}