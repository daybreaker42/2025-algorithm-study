#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string expression;
    cin >> expression;
    
    // 발상: - 기호 이후의 모든 수는 괄호로 묶어 빼는 것이 최소값
    // 예: 55-50+40 => 55-(50+40) = -35
    
    int result = 0;
    string num = "";
    bool is_minus = false; // 마이너스 이후인지 체크하는 플래그
    
    for (int i = 0; i <= expression.size(); i++) {
        // 숫자가 끝나거나 식이 끝난 경우
        if (i == expression.size() || expression[i] == '+' || expression[i] == '-') {
            if (!num.empty()) {
                int current_num = stoi(num);
                
                // 마이너스 이후라면 빼고, 아니면 더함
                if (is_minus) {
                    result -= current_num;
                } else {
                    result += current_num;
                }
                
                num = "";
            }
            
            // 마이너스 기호가 나오면 그 이후의 모든 수는 빼기
            if (i < expression.size() && expression[i] == '-') {
                is_minus = true;
            }
        } else {
            // 숫자인 경우 문자열에 추가
            num += expression[i];
        }
    }
    
    cout << result << '\n';
    
    return 0;
}

