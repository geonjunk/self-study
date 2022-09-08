#include<iostream>
#include<map>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T > 0) {
		map<string, int>m;
		int n;
		cin >> n;
		for (int i = 0;i < n;i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (m.find(s2) != m.end()) {
				m[s2]++;
			}
			else {
				m.insert({ s2,1 });
			}
		}

		int result = 1;
		for (auto iter = m.begin();iter != m.end();iter++) {
			result *= (iter->second)+1;
		}
		cout << (result - 1) << "\n";
		T--;
	}


	return 0;
}