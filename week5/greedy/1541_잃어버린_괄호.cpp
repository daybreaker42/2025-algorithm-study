#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string expression;
    cin >> expression;
    
    // 그리디 접근: 뺄셈 이후의 모든 값을 최대한 크게 만들어 전체 값을 최소화
    int result = 0;
    int current_num = 0;
    bool is_minus = false;
    
    for (int i = 0; i <= expression.length(); i++) {
        // 숫자를 완성하거나 식이 끝났을 때
        if (i == expression.length() || expression[i] == '+' || expression[i] == '-') {
            if (is_minus) {
                // 이미 뺄셈이 나온 경우: 이후 숫자는 모두 빼기
                result -= current_num;
            } else {
                // 아직 뺄셈이 나오지 않은 경우: 숫자 더하기
                result += current_num;
            }
            
            // 뺄셈이 나오면 이후부터는 모두 빼기 연산
            if (i < expression.length() && expression[i] == '-') {
                is_minus = true;
            }
            
            current_num = 0; // 다음 숫자를 위해 초기화
        } else {
            // 숫자 파싱
            current_num = current_num * 10 + (expression[i] - '0');
        }
    }
    
    cout << result << endl;
    
    return 0;
}
