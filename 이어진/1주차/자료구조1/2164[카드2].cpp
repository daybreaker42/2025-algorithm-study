#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> Q;
	int N;

	cin >> N;

	//큐 구조 ->Back[N, N-1, N-2, ... , 2, 1]->Front
	for (int i = 1; i <= N; i++) {
		Q.push(i);
	}
	
	while (Q.size() > 1) {
		//1. 맨 위의 한 장을 제거함
		Q.pop();
		//2. 그 아래에 있던 카드를 맨 아래로 이동시킴
		int temp = Q.front();
		Q.pop();
		Q.push(temp);
	}

	cout << Q.front() << endl;
}