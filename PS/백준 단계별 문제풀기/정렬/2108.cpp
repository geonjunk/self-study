#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int arr[8001];
int main() {
	vector<int>v;
	int N;
	cin >> N;
	int sum = 0;
	int result = 0;
	for (int i = 0;i < N;i++) {
		int t;
		cin >> t;
		v.push_back(t);
		sum += t;
		arr[t + 4000]++;
	}

	result= round((double)sum / N);
	printf("%d\n", result);
	sort(v.begin(), v.end());
	cout << v[N / 2] << "\n";

	
	int max=-1, maxIdx = 0;
	int sameCount = 0;
	for (int i = 0;i < 8001;i++) {
		if (max < arr[i]) {
			max = arr[i];
			maxIdx = i -4000;
			sameCount = 1;
		}
		else if (max == arr[i]&&sameCount==1) {
			sameCount++;
			max = arr[i];
			maxIdx = i - 4000;
		}
	}
	cout << maxIdx << "\n";
	cout << v[N - 1] - v[0] << "\n";
	return 0;
} 