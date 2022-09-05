#include<iostream>
#include<set>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    set<string>s1;
    set<string>result;
    for (int i = 0;i < N;i++) {
        string temp;
        cin >> temp;
        s1.insert(temp);
    }

    for (int i = 0;i < M;i++) {
        string temp;
        cin >> temp;
        if (s1.find(temp) != s1.end()) {
            result.insert(temp);
        }
    }

    int count = result.size();
    cout << count << "\n";
    for (set<string>::iterator iter = result.begin();iter != result.end();iter++) {
        cout << *iter << "\n";
    }
    
    return 0;
}