#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 5557 - 1학년
* 
* 문제 발상:
* 1. N개의 숫자 중 N-2개 사이에 +, - 연산자를 넣어서 마지막 숫자와 같은 수식을 만드는 경우의 수
* 2. 중간 계산 결과는 항상 0 이상 20 이하의 정수여야 함
* 3. DP를 이용하여 해결: dp[i][j] = i번째 숫자까지 계산했을 때, 결과가 j인 경우의 수
* 4. 점화식:
*    - dp[i][j+num[i]] += dp[i-1][j] (j+num[i] <= 20인 경우)
*    - dp[i][j-num[i]] += dp[i-1][j] (j-num[i] >= 0인 경우)
* 5. 최종 결과는 dp[N-2][num[N-1]]
* 6. 경우의 수가 매우 커질 수 있으므로 long long 자료형 사용
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    // DP 테이블 초기화 (경우의 수가 매우 커질 수 있으므로 long long 사용)
    vector<vector<long long>> dp(N-1, vector<long long>(21, 0));
    
    // 초기값 설정: 첫 번째 숫자로 시작
    dp[0][numbers[0]] = 1;
    
    // DP 계산
    for (int i = 1; i < N-1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i-1][j] > 0) {
                // 덧셈 연산
                if (j + numbers[i] <= 20) {
                    dp[i][j + numbers[i]] += dp[i-1][j];
                }
                
                // 뺄셈 연산
                if (j - numbers[i] >= 0) {
                    dp[i][j - numbers[i]] += dp[i-1][j];
                }
            }
        }
    }
    
    // 결과 출력: 마지막 숫자가 numbers[N-1]이 되는 경우의 수
    cout << dp[N-2][numbers[N-1]] << '\n';
    
    return 0;
}
