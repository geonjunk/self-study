#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int n;
stack<int>s;
queue<char>q;
int arr[100000];
int main() {
	cin >> n;
	for (int i =0; i <n; i++) {
		cin >> arr[i];
	}
	s.push(1);
	q.push('+');
	//처음값은 무조건 넣어주기
	int idx = 0;
	int num = 2;
	while (idx != n) {//s.empty() x스택이 빈경우도 있을 수 있음
		if (!s.empty() && s.top() > arr[idx]) {
			cout << "NO" << "\n";
			return 0;
		}
		while (num <=arr[idx]) {//s.top() 대신 num 사용(빈스택 참조 에러 방지)
			s.push(num++);
			q.push('+');
		}
		if (!s.empty() && s.top() == arr[idx]) {//여기서 while사용시 idx 초과 에러
			idx++;
			s.pop();
			q.push('-');
		}
	
	
	}
	while (!q.empty()) {
		cout << q.front() << "\n";
		q.pop();
	}

	return 0;
}

//빈스택 참조 에러