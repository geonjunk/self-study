#include<iostream>
#include<string>
using namespace std;

int main() {
	int N;
	cin >> N;
	//666,1666,2666...10666,11666...19666,16660,1,2,3,
	//666이 포함된 
	int start = 666;
	int result = 0;
	while (true) {
		string str = to_string(start);
		if (str.find("666") != string::npos) {
			N--;
			if (N == 0) {
				result = start;
				break;
			}
		}
		start++;
	}
	cout << result << "\n";
	return 0;
}