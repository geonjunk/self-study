#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int arr[100000];
int main() {
	int n, num = 1;
	cin >> n;
	stack<int>s;
	queue<char>q;//연산내용저장하는 큐 
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		while (num <= arr[i]) {//현재수와 같을때까지 푸시 
			s.push(num++);
			q.push('+');
		}
		if (s.top() > arr[i]) {//현재 스택 탑이 현재 수보다 크면 스택 수열 못만드는 경우(스택안에는 오름차순으로 들어가므로) 
			break;
		}
		if (s.top() == arr[i]) {
			q.push('-');
			s.pop();

		}

	}
	if (!s.empty()) cout << "NO" << "\n";
	else {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			cout << q.front() << "\n";
			q.pop();
		}
	}

	return 0;
}

