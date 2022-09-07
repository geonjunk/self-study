#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#define MAX 1e+9
#define MIN -1e+9

int n;
int arr[11];
int op[4];//덧셈, 뺄셈, 곱셉, 나눗셈

int minResult=MAX, maxResult=MIN;

void backtracking(int result, int cnt) {
    if (cnt == n) {
        if (minResult > result) {
            minResult = result;
        }
        if (maxResult < result) {
            maxResult = result;
        }
        return;
    }
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < op[i];j++) {
            op[i]--;
            switch (i)
            {
            case 0:
                backtracking(result+arr[cnt],cnt + 1);
                break;
            case 1:
                backtracking(result-arr[cnt],cnt + 1);
                break;
            case 2:
                backtracking(result*arr[cnt],cnt + 1);
                break;
            case 3:
                backtracking(result / arr[cnt], cnt + 1);
                break;
            }
            op[i]++;
        }
    }
}


int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    for (int i = 0;i < 4;i++) {
        cin >> op[i];
    }
    backtracking(arr[0],1);

    cout << maxResult << "\n" << minResult << "\n";
    return 0;
}