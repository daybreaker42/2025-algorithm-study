#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    int len1 = s1.length();
    int len2 = s2.length();
    
    // dp[i][j] = s1의 i번째 문자까지, s2의 j번째 문자까지 고려했을 때의 LCS 길이
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // 현재 문자가 같으면, 이전 LCS 길이에 1 추가
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            // 현재 문자가 다르면, 이전 상태에서의 최대 LCS 길이 선택
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[len1][len2] << '\n';
    
    return 0;
}
