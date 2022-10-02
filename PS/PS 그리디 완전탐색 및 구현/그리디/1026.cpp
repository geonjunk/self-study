#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int A[50];
int main() {
	int N,S=0;
	cin >> N;

	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		A[i] = temp;
	}

	priority_queue<int>q;

	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}

	sort(A, A + N);
	

	for (int i = 0;i < N;i++) {
		int temp = q.top();
		S += A[i] * temp;
		q.pop();
	}
	cout << S << "\n";
	
	return 0;
}