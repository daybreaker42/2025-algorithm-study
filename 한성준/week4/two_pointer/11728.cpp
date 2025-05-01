#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    vector<int> B(M);
    
    // 두 배열 입력
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    
    // 투 포인터 사용하여 두 배열 병합
    vector<int> result;
    int ptrA = 0, ptrB = 0;
    
    // 두 포인터 중 하나라도 끝에 도달할 때까지 반복
    while (ptrA < N && ptrB < M) {
        if (A[ptrA] <= B[ptrB]) {
            result.push_back(A[ptrA++]);  // A 배열의 현재 원소가 작거나 같으면 추가
        } else {
            result.push_back(B[ptrB++]);  // B 배열의 현재 원소가 작으면 추가
        }
    }
    
    // 남은 원소들 처리
    while (ptrA < N) {
        result.push_back(A[ptrA++]);
    }
    
    while (ptrB < M) {
        result.push_back(B[ptrB++]);
    }
    
    // 결과 출력
    for (int num : result) {
        cout << num << ' ';
    }
    
    return 0;
}
