#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    fastio;
    
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // 배열이 1개 또는 2개면 그대로 반환
    if (N <= 2) {
        cout << N << endl;
        return 0;
    }
    
    // 배열 정렬
    sort(arr.begin(), arr.end());
    
    int maxLength = 2; // 기본적으로 2개는 항상 가능
    
    // 모든 두 수 쌍 (i, j)에 대해 확인
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            // i와 j를 첫 두 원소로 하는 부분 삼각 수열 길이 계산
            int length = 2;
            
            // k를 추가 가능한지 확인
            for (int k = j+1; k < N; k++) {
                // 삼각 부등식 확인 (A[i] + A[j] > A[k])
                if (arr[i] + arr[j] > arr[k]) {
                    length++;
                } else {
                    break; // 더 큰 값은 모두 조건을 만족하지 못함
                }
            }
            
            maxLength = max(maxLength, length);
        }
    }
    
    cout << maxLength << endl;
    
    return 0;
}

/* 
문제 요약: 주어진 배열에서 가장 긴 부분 삼각 수열의 길이 구하기
- 부분 삼각 수열은 임의의 세 수가 삼각형 조건을 만족하는 수열
- 삼각형 조건: 두 변의 길이 합 > 가장 긴 변의 길이

접근 방법:
1. 배열을 오름차순으로 정렬
2. 모든 가능한 시작점 (i, j)에 대해 최대 길이 계산
3. 정렬 후에는 A[i] + A[j] > A[k]만 확인하면 됨 (다른 조건은 항상 만족)
4. 최대 부분 삼각 수열 길이 출력
*/
