#include <iostream>
#include <queue>
#include <utility>

using namespace std;

//큐에서 중요도의 최댓값을 구함
int find_MAX(queue<pair<int, int>>& Q) {
	int max = 0;
	for (int i = 0; i < Q.size(); i++) {
		if (max <= Q.front().second) {
			max = Q.front().second;
		}
		Q.push(Q.front());
		Q.pop();
	}
	return max;
}

int main() {
	int T;
	cin >> T;

	while (T-- > 0) {
		queue<pair<int, int>> Q; //first: 인덱스 / second: 중요도 
		int N, M;
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			Q.push(make_pair(i, temp));
		}

		int cnt = 0; //출력된 순서
		while (1) {
			if (Q.front().second < find_MAX(Q)) { //중요도가 최댓값이 아니면
				Q.push(Q.front());
				Q.pop();
				//타겟 인덱스값 변경
				if (M - 1 < 0) M = Q.size() - 1; 
				else M--;
			}
			else { //중요도가 최댓값이면
				cnt++; //출력횟수 +1
				Q.pop();
				if (M == 0) break; //타겟 인덱스가 출력됐으면 중단
				else M--;
			}
		}
		cout << cnt << '\n';
	}
}