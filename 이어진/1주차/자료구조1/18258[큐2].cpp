#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	queue<int> q;

	cin >> n;
	while (n-- > 0) {
		string s;
		cin >> s;

		if (s == "push") {
			int temp;
			cin >> temp;
			q.push(temp);
		}

		else if (s == "pop") {
			if (q.empty()) {
				cout << "-1" << "\n";
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
		}

		else if (s == "size") {
			cout << q.size() << "\n";
		}

		else if (s == "empty") {
			if (q.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}

		else if (s == "front") {
			if (q.empty()) {
				cout << "-1" << "\n";
				continue;
			}
			cout << q.front() << "\n";
		}

		else if (s == "back") {
			if (q.empty()) {
				cout << "-1" << "\n";
				continue;
			}
			cout << q.back() << "\n";
		}
	}
}