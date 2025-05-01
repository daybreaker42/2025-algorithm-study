#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    // 발상: 
    // 최댓값: 가능한 K를 독립적으로 변환 (MK -> 5×10^1)
    // 최솟값: 가능한 M을 모아서 변환 (MMM -> 1×10^3)
    
    // 최댓값 계산
    string max_result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'M') {
            int j = i;
            while (j < s.length() && s[j] == 'M') {
                j++;
            }
            
            // M으로만 끝나는 경우
            if (j == s.length()) {
                for (int k = i; k < j; k++) {
                    max_result += '1';
                }
            } 
            // K로 끝나는 경우
            else if (s[j] == 'K') {
                max_result += '5';
                for (int k = i; k < j; k++) {
                    max_result += '0';
                }
                i = j;
            }
        } else if (s[i] == 'K') {
            max_result += '5';
        }
    }
    
    // 최솟값 계산
    string min_result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'M') {
            int j = i;
            while (j < s.length() && s[j] == 'M') {
                j++;
            }
            
            // 첫번째 M은 1, 나머지는 0으로 변환
            min_result += '1';
            for (int k = i + 1; k < j; k++) {
                min_result += '0';
            }
            
            i = j - 1;
        } else if (s[i] == 'K') {
            min_result += '5';
        }
    }
    
    cout << max_result << '\n' << min_result << '\n';
    
    return 0;
}

