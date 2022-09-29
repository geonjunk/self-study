#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int N;
vector<int>v;
int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j <=i;j++) {
			sum += v[j];
		}
	}
	cout << sum << "\n";
	return 0;
}