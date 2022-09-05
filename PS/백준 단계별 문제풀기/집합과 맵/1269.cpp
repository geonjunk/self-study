#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int A, B;
    set<int>s1, s2;

    cin >> A >> B;
    for (int i = 0;i < A;i++) {
        int n;
        scanf("%d", &n);
        s1.insert(n);
    }

    for (int i = 0;i < B;i++) {
        int n;
        scanf("%d", &n);
        s2.insert(n);
    }

    int result1 = s1.size(), result2 = s2.size();
    for (auto iter = s1.begin();iter != s1.end();iter++) {
        if (s2.find(*iter) != s2.end()) {
            result2--;
        }
    }

    for (auto iter = s2.begin();iter != s2.end();iter++) {
        if (s1.find(*iter) != s1.end()) {
            result1--;
        }
    }
    cout << result1 + result2 << "\n";


    return 0;
}