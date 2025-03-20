#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
	string s;
	stack<int> stk;
	vector<pair<int, int>> vec;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') stk.push(i);
		else if (s[i] == ')') {
			vec.push_back({ stk.top(), i }); //º¤ÅÍ¿¡ °ýÈ£½ÖÀÇ ÁÂÇ¥¸¦ ÀúÀå
			stk.pop();
		}
	}
}