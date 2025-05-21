#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 백준 9251 - LCS (Longest Common Subsequence)
* 
* 문제 발상:
* 1. 최장 공통 부분 수열(LCS)을 구하는 전형적인 DP 문제
* 2. 두 문자열의 부분 수열 중 가장 긴 공통 부분 수열의 길이를 구해야 함
* 3. dp[i][j] = 첫 번째 문자열의 i번째까지, 두 번째 문자열의 j번째까지 고려했을 때의 LCS 길이
* 4. 점화식:
*    - 두 문자가 같은 경우: dp[i][j] = dp[i-1][j-1] + 1
*    - 두 문자가 다른 경우: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
* 5. 최종적으로 dp[len1][len2]가 두 문자열의 LCS 길이가 됨
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str1, str2;
    cin >> str1 >> str2;
    
    int len1 = str1.length();
    int len2 = str2.length();
    
    // DP 테이블 초기화 (인덱스를 1부터 시작하기 위해 크기를 +1)
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    
    // LCS 계산
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                // 문자가 같은 경우
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                // 문자가 다른 경우
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // 최장 공통 부분 수열의 길이 출력
    cout << dp[len1][len2] << '\n';
    
    return 0;
}
