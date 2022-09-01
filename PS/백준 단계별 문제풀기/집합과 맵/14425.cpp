#include<iostream>
#include<set>
#include<string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int answer = 0;

    set<string>s;
    for (int i = 0;i < N;i++) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for (int i = 0;i < M;i++) {
        string tmp;
        cin >> tmp;
        if (s.find(tmp) != s.end())
            answer++;
    }

    printf("%d", answer);

    return 0;
}