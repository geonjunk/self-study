#include <string>
#include <vector>
#include <stack>

using namespace std;


bool isRightString(string input) {

	stack<char>s;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			s.push(input[i]);
		}
		else {
			if (s.empty()) {
				return false;
			}
			else {
				s.pop();
			}
		}
	}
	return true;
}

string check(string p) {
	string temp = "";
	if (p == "") {
		return "";
	}

	int count1 = 0, count2 = 0;
	string u, v;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') {
			count1++;
		}
		if (p[i] == ')') {
			count2++;
		}
		if (count1 == count2) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}

	if (isRightString(u)) {
		v = check(v);
		temp = u + v;
		return temp;
	}else {
		temp += "(";
		temp += check(v);
		temp += ")";
		u.erase(0,1);
		u.erase(u.length() - 1, 1);
		for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		temp += u;
		return temp;
	}
}

string solution(string p) {
	string answer = "";

	answer = check(p);
	return answer;
}