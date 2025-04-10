#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, P, Q;
vector<int> numbers;
vector<int> group_assign;
int max_result = 0;

void calculate() {
    vector<int> groups(Q + 1, 0);
    
    // 각 숫자를 해당 그룹에 더하기
    for (int i = 0; i < N; i++) {
        groups[group_assign[i]] += numbers[i];
    }
    
    // 모든 그룹의 값을 곱하기
    int product = 1;
    for (int val : groups) {
        product *= val;
    }
    
    // 최대값 갱신
    max_result = max(max_result, product);
}

void assign_groups(int pos) {
    if (pos == N) {
        calculate();
        return;
    }
    
    // 현재 위치의 숫자를 가능한 모든 그룹에 할당
    for (int g = 0; g <= Q; g++) {
        group_assign[pos] = g;
        assign_groups(pos + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    numbers.resize(N);
    group_assign.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    cin >> P >> Q;
    
    // 모든 순열에 대해 처리
    sort(numbers.begin(), numbers.end());
    do {
        assign_groups(0);
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    cout << max_result << endl;
    
    return 0;
}