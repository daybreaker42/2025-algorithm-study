#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main() {
	deque<pair<int, int>> deq;
	int N;
	cin >> N;

	//first: 풍선의 순서 / second: 풍선 내부 종이 값
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		deq.push_back(make_pair(i, temp));
	}

	while (deq.size() > 0) {
		cout << deq.front().first << " ";
		int move = deq.front().second;
		deq.pop_front();

		if (deq.empty()) break;

		if (move > 0) { 
			for (int i = 1; i < move; i++) {//루프문 초반에 pop_front를 한 번 수행함.
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else { //move < 0
			for (int i = 0; i < (-1)* move; i++) {
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
	}
}
