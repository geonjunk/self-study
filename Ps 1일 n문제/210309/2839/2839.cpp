#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int result=-1;
	int n;
	int temp;
	cin >> n;
	temp = n;
	for (int i = 0; i <= (n / 3); i++) {
		temp = n-(3*i);
		if (temp % 5 == 0) {
			result = temp / 5 + i;
			break;
		}
	}
	cout << result << "\n";

	return 0;
}