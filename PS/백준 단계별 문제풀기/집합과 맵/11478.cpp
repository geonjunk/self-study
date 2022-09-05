#include<iostream>
#include<set>
#include<string>
using namespace std;

int main() {
    set<string>s;
    string str;
    cin >> str;

    for (int i = 0;i < str.length();i++) {
        for (int j = 1;j <=(str.length()-i);j++) {
            s.insert(str.substr(i, j));
        }
    }
    cout << s.size() << "\n";

    return 0;
}