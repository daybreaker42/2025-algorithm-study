#include <iostream>

using namespace std;

int main() {
	int cnt = 0, result=0; //막대의 개수 / 결과값
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' && s[i + 1] == ')') {
			result += cnt;
			i++;
			continue;
		}

		if (s[i] == '(') {
			cnt++;
		}
		else { // s[i]==')'
			result++;
			cnt--;
		}
	}
	cout << result << endl;
}