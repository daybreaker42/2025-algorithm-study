#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<double> stk;//중간 연산값을 저장

	int arr[26] = { 0, }; //A~Z값에 대응
	string s;
	int N;
	cin >>N >> s;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') { //피연산자이면
			stk.push(arr[s[i] - 'A']);
		}
		else { //연산자이면
			double a, b;
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();

			switch (s[i]) {
			case '+':
				stk.push(a + b);
				break;
			case '-':
				stk.push(b - a);
				break;
			case '*':
				stk.push(a * b);
				break;
			case '/':
				stk.push(b / a);
				break;
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << stk.top();
}