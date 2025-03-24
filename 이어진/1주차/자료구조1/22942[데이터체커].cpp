#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first != b.first) return a.first < b.first; //시작점 기준 오름차순
	else return a.second > b.second; //좌표가 같다면 인덱스 기준 내림차순
}

int main() {
	int N, x, r;
	vector<pair<int, int>> vec; //원의 시작점(x-r) / 인덱스
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> r;
		vec.push_back({ x - r, i }); //원의 시작점을 저장
		vec.push_back({ x + r, i }); //원의 끝 점을 저장
	}
	sort(vec.begin(), vec.end(), compare);
	
	stack<int> stk;
	for (int i = 0; i < vec.size(); i++) {
		if (i != 0 && (vec[i - 1].first == vec[i].first)) break; //두 원이 접하므로 더이상 연산필요 x

		if (!stk.empty() && (vec[i].second == stk.top())) stk.pop(); //원의 인덱스가 같다면 정상적 입력임
		else stk.push(vec[i].second);
	}
	if (stk.empty()) cout << "YES";
	else cout << "NO";
	 
	return 0;
}
