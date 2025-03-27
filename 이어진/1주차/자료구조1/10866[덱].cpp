#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> deq;
	int n;
	cin >> n;
	while (n-- > 0) {
		string s;
		cin >> s;

		if (s == "push_front") {
			int temp;
			cin >> temp;
			deq.push_front(temp);
		}
		else if (s == "push_back") {
			int temp;
			cin >> temp;
			deq.push_back(temp);
		}
		//===============================
		else if (s == "pop_front") {
			if (deq.empty()) {
				cout << "-1" << "\n";
				continue;
			}
			cout << deq.front() << "\n";
			deq.pop_front();
		}
		else if (s == "pop_back") {
			if (deq.empty()) {
				cout << "-1" << "\n";
				continue;
			}
			cout << deq.back() << "\n";
			deq.pop_back();
		}
		//==============================
		else if (s == "size") {
			cout << deq.size() << "\n";
		}

		else if (s == "empty") {
			if (deq.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		//==============================
		else if (s == "front") {
			if (deq.empty()) {
				cout << "-1" << "\n";
				continue;
			}
			cout << deq.front() << "\n";
		}

		else if (s == "back") {
			if (deq.empty()) {
				cout << "-1" << "\n";
				continue;
			}
			cout << deq.back() << "\n";
		}
	}
}