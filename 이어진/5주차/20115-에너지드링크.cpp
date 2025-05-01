#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<double> drinks(n);
    for (int i = 0; i < n; i++) {
        cin >> drinks[i];
    }
    
    // 발상: 항상 가장 큰 음료는 버리지 않고, 나머지를 절반으로 합치는 것이 최적
    sort(drinks.begin(), drinks.end());
    
    double result = drinks[n-1]; // 가장 큰 음료
    for (int i = 0; i < n-1; i++) {
        result += drinks[i] / 2; // 나머지 음료들은 절반만 더함
    }
    
    // 정수로 딱 떨어지는 경우 정수로 출력
    if (result == (int)result) {
        cout << (int)result << '\n';
    } else {
        cout << result << '\n';
    }
    
    return 0;
}