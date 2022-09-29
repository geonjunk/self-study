#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

string s;
vector<int>arr;
int main() {
	cin >> s;
	int pre = 0;
	int answer = 0;
	while (true) {
		int pos = s.find('-', pre);

		string temp1 = s.substr(pre, pos-pre);
		string temp2;
		stringstream ss(temp1);
		int part = 0;
		while (getline(ss, temp2, '+')) {
			part += stoi(temp2);
		}
		arr.push_back(part);
		pre = pos+1;
	
		if (pos == string::npos) {
			break;
		}

	}

	answer = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		answer -= arr[i];
	}
	cout << answer << "\n";

	return 0;
	}