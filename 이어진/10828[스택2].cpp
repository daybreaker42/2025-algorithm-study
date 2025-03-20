#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> st;
	int n;
	cin >> n;

	while (n-- > 0) {
		string s;
		cin >> s;

		if (s == "push") {
			int temp;
			cin >> temp;
			st.push(temp);
		}

		else if (s == "pop") {
			if (s.empty()) {
				cout << "-1" << "\n";
				continue;
			}
			cout << st.top() << "\n";
			st.pop();
		}

		else if (s == "size") {
			cout << st.size() << "\n";
		}

		else if (s == "empty") {
			if (st.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}

		else if (s == "top") {
			if (st.empty()) {
				cout << "-1" << "\n";
				continue;
			}
			cout << st.top() << "\n";
		}
	}
}