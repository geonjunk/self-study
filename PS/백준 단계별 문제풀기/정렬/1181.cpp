#include<iostream>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

struct compare {
	bool operator()(const string& s1, const string& s2) const{ //연산자 () 재정의
		if (s1.length() != s2.length()) {
			return s1.length() < s2.length();
		}
		else {
			return s1 < s2;
		}
	}
};

int main() {
	int N;
	cin >> N;
	string s;
	set<string, compare>sets;
	for (int i = 0;i < N;i++) {
		cin >> s;
		sets.insert(s);
	}
	for (set<string>::iterator it = sets.begin(); it != sets.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}

