#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s, delimiter="."; //구분자
	cin >> s;

	int cur_pos = 0;
	int pos;
	while ((pos = s.find(delimiter, cur_pos)) != string::npos) {
		//문자열 파싱
		int len = pos - cur_pos;
		string temp = s.substr(cur_pos, len);
		cur_pos = pos + 1;
		
		//각 문장을 검사
		stack<char> stk;
		for (char chr : s) {
			if (!stk.empty()) {
				if ((chr == ')' || chr == ']')) {
					stk.push('-'); // 쓰레기값 삽입
					break;
				}
			}
			else{ //스택이 비어있지 않다면
				if (chr == '(') stk.push('(');
				else if (chr == '[') stk.push('[');

				else if (chr == ')') {
					if (stk.top() == '(') stk.pop();
					else break;
				}
				else if (chr == ']') {
					if (stk.top() == '[') stk.pop();
					else break;
				}
			}
		}
		if (stk.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}