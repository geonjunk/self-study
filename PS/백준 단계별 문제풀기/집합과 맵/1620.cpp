#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    map<string, int>m1;
    map<int, string>m2;
    for (int i = 1;i <=N;i++) {
        string s;
        cin >> s;
        m1.insert({ s, i });
        m2.insert({ i,s });

    }
    for (int i = 0;i < M;i++) {
        string s;
        cin >> s;
        bool isNumber = true;
        for (int j = 0;j < s.length();j++) {
            if (isdigit(s[j])==0) {
                isNumber = false;
                break;
            }
        }
        if (isNumber) {
            cout << m2[stoi(s)] << "\n";
        }
        else {
            cout << m1[s] << "\n";
        }
    }

    return 0;
}