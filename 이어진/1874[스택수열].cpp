#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n;
	stack<int> stk;
	vector<char> vec;
	int cnt = 1; 

	cin >> n;

	for (size_t i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		//1부터 temp까지 스택에 push
		while (cnt <= temp) {
			stk.push(cnt);
			cnt++;
			vec.push_back('+');
		}

		//스택의 최상단 값이 temp와 같다면 pop
		if (temp == stk.top()) {
			stk.pop();
			vec.push_back('-');
		}

		//스택의 최상단 값보다 temp가 작다면 스택으로 만들 수 있는 수열이 아님
		else if (temp < stk.top()) {
			cout << "NO" << "\n";
			return 0;
		}
	}

	for (auto chr : vec) {
		cout << chr << "\n";
	}
}