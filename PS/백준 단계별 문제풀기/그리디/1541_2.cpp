#include<iostream>
#include<string>
using namespace std;


string s;
int main() {
	cin>>s;
	bool isMinus = false;

	int answer = 0;
	string temp = "";
	for (int i = 0;i < s.size();i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (isMinus) {
				answer -= stoi(temp);
				temp = "";
			}
			else {
				answer += stoi(temp);
				temp = "";
				if (s[i] == '-') {
					isMinus = true;
				}
			}
		}
		else {
			temp += s[i];
		}
	}
	if (isMinus) {
		answer -= stoi(temp);
	}
	else {
		answer += stoi(temp);
	}
	cout << answer << "\n";
	
	return 0;
}