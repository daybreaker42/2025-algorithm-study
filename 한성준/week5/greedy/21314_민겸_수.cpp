#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string mkString;
    cin >> mkString;
    
    string max_value = ""; // 가장 큰 값
    string min_value = ""; // 가장 작은 값
    
    int m_count = 0; // 연속된 M의 개수
    
    // 최댓값: M과 K가 묶여 있으면 5×10^k 형태로 변환
    for (int i = 0; i <= mkString.length(); i++) {
        if (i == mkString.length() || mkString[i] == 'K') {
            // K를 만나거나 문자열 끝에 도달한 경우
            if (i < mkString.length() && mkString[i] == 'K') {
                // MK 형태: 5 * 10^m_count
                max_value += '5';
                for (int j = 0; j < m_count; j++) {
                    max_value += '0';
                }
            } else {
                // 문자열 끝에서 M만 있는 경우: 각각 1로 처리
                for (int j = 0; j < m_count; j++) {
                    max_value += '1';
                }
            }
            m_count = 0;
        } else if (mkString[i] == 'M') {
            m_count++;
        }
    }
    
    // 최솟값: M은 묶어서 처리, K는 단독으로 처리
    m_count = 0;
    for (int i = 0; i <= mkString.length(); i++) {
        if (i == mkString.length() || mkString[i] == 'K') {
            if (m_count > 0) {
                // 연속된 M: 첫자리 1, 나머지 0
                min_value += '1';
                for (int j = 1; j < m_count; j++) {
                    min_value += '0';
                }
            }
            
            // K를 만난 경우: 5 추가
            if (i < mkString.length() && mkString[i] == 'K') {
                min_value += '5';
            }
            m_count = 0;
        } else if (mkString[i] == 'M') {
            m_count++;
        }
    }
    
    cout << max_value << endl;
    cout << min_value << endl;
    
    return 0;
}
