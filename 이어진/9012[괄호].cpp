#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isVPS(string s) {
	//스택에 문자 입력
	stack<char> stk;
	for (char chr : s) {
		stk.push(chr);
	}

	int cnt = 0;
	int size = stk.size();
	while (size-- > 0) {
		//맨 오른쪽 문자가 여는 괄호면 false
		if (stk.top() == '(' && cnt < 1) return false;

		if (stk.top() == ')') {
			cnt++;
			stk.pop();
		}
		else if (stk.top() == '(') {
			cnt--;
			stk.pop();
		}
	}
	if (cnt == 0) return true;
	else return false;
}

int main() {
	int n;
	cin >> n;
	while (n-- > 0) {
		string s;
		cin >> s;
		if (isVPS(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}