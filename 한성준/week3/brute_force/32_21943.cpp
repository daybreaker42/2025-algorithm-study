#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N; // 정수의 개수
vector<int> numbers; // 주어진 정수들
int P, Q; // 덧셈 연산자, 곱셈 연산자의 개수
long long maxResult = 0; // 최댓값 저장

// 그룹화된 정수들의 합을 계산하고 그룹 간 곱을 구하는 함수
void calculate(vector<vector<int>>& groups) {
    long long result = 1;
    
    // 각 그룹 내부의 합을 구하고, 그룹 간 곱셈 수행
    for (auto& group : groups) {
        int sum = 0;
        for (int num : group) {
            sum += num;
        }
        result *= sum;
    }
    
    // 최댓값 갱신
    maxResult = max(maxResult, result);
}

// 정수들을 Q+1개의 그룹으로 나누는 모든 방법을 시도하는 재귀 함수
void divide(vector<int>& nums, vector<vector<int>>& groups, int idx) {
    // 모든 정수가 그룹에 배치되면 계산 수행
    if (idx == N) {
        calculate(groups);
        return;
    }
    
    // 현재 숫자를 각 그룹에 배치해보기
    for (int i = 0; i < groups.size(); i++) {
        groups[i].push_back(nums[idx]);
        divide(nums, groups, idx + 1);
        groups[i].pop_back();
    }
}

int main() {
    fastio;
    
    // 입력 받기
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    cin >> P >> Q;
    
    // Q+1개의 그룹 생성 (곱셈 연산자 Q개를 사용해 Q+1개 그룹을 만들 수 있음)
    vector<vector<int>> groups(Q + 1);
    
    // 정수 순서의 모든 순열을 생성하여 최적의 방법 찾기
    do {
        divide(numbers, groups, 0);
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    // 결과 출력
    cout << maxResult << endl;
    
    return 0;
}

/* 250401
문제 설명:
- N개의 양의 정수와 P개의 더하기 연산자, Q개의 곱하기 연산자가 주어짐
- 정수 순서는 바꿀 수 있고, 괄호를 무수히 많이 사용 가능
- 연산자의 우선순위는 동일
- 최대값을 구하는 문제

해결 전략:
1. 정수를 Q+1개의 그룹으로 나누기 (곱셈 연산자를 기준으로)
2. 각 그룹 내에서는 덧셈 수행, 그룹 간에는 곱셈 수행
3. 모든 가능한 정수 순열과 그룹화 방법을 시도하여 최댓값 찾기
*/
