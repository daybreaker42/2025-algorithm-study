#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, K;
	queue<int> Q;
	int arr[5000] = { 0, };
	cin >> N >> K;

	//큐에 요소 입력(1부터 N까지)
	for (int i = 1; i <= N; i++) {
		Q.push(i);
	}
	
	int cnt = 0;
	while (Q.size() > 0) {
		//큐의 요소를 앞에서 뒤로 이동시킴(K-1번)
		for (int i = 0; i < K-1; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		//K번째 수를 답안에 저장하고, 큐에서 제거
		arr[cnt] = Q.front();
		Q.pop();
		cnt++;
	}
	//출력
	cout << "<";
	for (int i = 0; i < cnt; i++) {
		if (i == cnt - 1) {
			cout << arr[i] << ">";
			break;
		}
		cout << arr[i] << ", ";
	}
}