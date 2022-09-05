#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    int N, M;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    map<int, int>m;

    for (int i = 0;i < N;i++) {
        int n;
        cin>>n;
        if (m.find(n) != m.end()) {
            m[n]++;
        }
        else {
            m.insert({ n,1 });
        }
    }
    cin >> M;
    for (int i = 0;i < M;i++) {
        int n;
        cin >> n;
        if (m.find(n) == m.end()) {
            cout << 0 << " ";
        }
        else {
            cout << m[n] << " ";
        }
    }
    return 0;
}