#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int N;
	pair<int, int> arr[50];//나보다 덩치큰 사람 수
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		arr[i].first = a;
		arr[i].second = b;
	}
	
	for (int i = 0;i < N;i++) {
		int first, second,rank=1;
		first = arr[i].first;
		second = arr[i].second;
		for (int j = 0;j < N;j++) {
			if (j == i) continue;
			if (first < arr[j].first&&second<arr[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
	}

	return 0;
}