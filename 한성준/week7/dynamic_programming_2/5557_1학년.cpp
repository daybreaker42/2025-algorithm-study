#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    // dp[i][j] = i번째 숫자까지 사용했을 때, j라는 중간 결과를 만들 수 있는 경우의 수
    vector<vector<ll>> dp(N, vector<ll>(21, 0)); // 중간 결과는 0~20 범위
    
    // 초기값: 첫 번째 숫자로 시작
    dp[0][numbers[0]] = 1;
    
    // 두 번째 숫자부터 계산
    for (int i = 1; i < N - 1; i++) { // 마지막 숫자는 결과값이므로 제외
        for (int j = 0; j <= 20; j++) {
            if (dp[i-1][j] > 0) {
                // 더하기 연산
                if (j + numbers[i] <= 20) {
                    dp[i][j + numbers[i]] += dp[i-1][j];
                }
                
                // 빼기 연산
                if (j - numbers[i] >= 0) {
                    dp[i][j - numbers[i]] += dp[i-1][j];
                }
            }
        }
    }
    
    // 마지막 결과가 numbers[N-1]인 경우의 수 출력
    cout << dp[N-2][numbers[N-1]] << '\n';
    
    return 0;
}
