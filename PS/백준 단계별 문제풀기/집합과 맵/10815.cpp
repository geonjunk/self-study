#include<iostream>
#include<set>
using namespace std;

int main() {
    int N,M;
    set<long long>sets;
    cin >> N;
    for (int i = 0;i < N;i++) {
        int tmp;
        scanf("%d",&tmp);
        sets.insert(tmp);
    }
    cin >> M;
    for (int i = 0;i < M;i++) {
        int tmp;
        scanf("%d", &tmp);
        if (sets.find(tmp) != sets.end()) {
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
    return 0;
}