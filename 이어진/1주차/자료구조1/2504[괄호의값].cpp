#include <iostream>
#include <stack>

using namespace std;

int main() {
	string s;
	stack<char> stk;
	cin >> s;

	int temp = 1, result = 0; //temp: 연산값(인수) / result: 연산값의 합

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			temp *= 2;
			stk.push('(');
		}
		else if (s[i] == '[') {
			temp *= 3;
			stk.push('[');
		}

		else if (s[i] == ')') {
			temp /= 2;
			if (stk.empty() || stk.top() != '(') {//괄호가 대응되지 않는 경우
				result = 0;
				break;
			}
			stk.pop();

			//() 또는 []이 앞서 나온 경우, 이미 연산을 했으므로 pass
			if (s[i - 1] == ')' || s[i-1]==']') { 
				continue;
			}
			result += temp*2;
		}
		
		else if (s[i] == ']') {
			temp /= 3;
			if (stk.empty()||stk.top() != '[') { // 괄호가 대응되지 않는 경우
				result = 0;
				break;
			}
			stk.pop();

			//() 또는 []이 앞서 나온 경우, 이미 연산을 했으므로 pass
			if (s[i - 1] == ']' || s[i-1]==')') { 
				continue;
			}
			result += temp*3;
		}
	}
	if (stk.empty())	cout << result;
	else cout << "0"; //추가적인 괄호가 있는 경우

}