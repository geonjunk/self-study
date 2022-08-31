#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


int main() {
	int N;
	vector<int>v1,v2;
	cin >> N;
	
	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		v1.push_back(temp);
	}
	v2.assign(v1.begin(), v1.end());

	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());

	for (int i = 0;i < N;i++) {
		int result = lower_bound(v1.begin(), v1.end(), v2[i])-v1.begin() ;
		cout << result << " ";
	}

	return 0;
}

