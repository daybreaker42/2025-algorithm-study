#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N;
vector<pair<int, int>> ingredients; // 신맛(곱)과 쓴맛(합) 저장
int minDiff = INT_MAX; // 신맛과 쓴맛의 차이 최솟값

// 모든 재료 조합을 확인하는 재귀 함수
void findMinDifference(int idx, int sour, int bitter, bool selected) {
    // 모든 재료를 확인했을 때
    if (idx == N) {
        // 최소 하나의 재료가 선택된 경우만 계산
        if (selected) {
            minDiff = min(minDiff, abs(sour - bitter));
        }
        return;
    }
    
    // 현재 재료를 선택하는 경우
    findMinDifference(idx + 1, sour * ingredients[idx].first, 
                      bitter + ingredients[idx].second, true);
    
    // 현재 재료를 선택하지 않는 경우
    findMinDifference(idx + 1, sour, bitter, selected);
}

int main() {
    fastio;
    
    cin >> N;
    ingredients.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> ingredients[i].first >> ingredients[i].second;
    }
    
    // 재료 선택 시작 (초기 신맛=1(곱셈의 항등원), 쓴맛=0(덧셈의 항등원))
    findMinDifference(0, 1, 0, false);
    
    cout << minDiff << endl;
    
    return 0;
}

/* 
문제 요약: N개의 재료로 요리할 때, 신맛과 쓴맛의 차이가 가장 작은 경우 찾기
- 재료의 신맛은 곱해지고, 쓴맛은 더해짐
- 적어도 하나의 재료는 사용해야 함
- 모든 재료 부분집합에 대해 신맛과 쓴맛의 차이 최솟값 구하기

접근 방법:
1. 모든 재료 조합(부분집합)을 탐색하는 브루트 포스 접근
2. 각 단계에서 현재 재료를 선택하거나 선택하지 않는 두 경우 탐색
3. 최종적으로 신맛과 쓴맛의 차이 최솟값 구하기
*/
