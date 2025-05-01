#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<double> drinks(N);
    for (int i = 0; i < N; i++) {
        cin >> drinks[i];
    }
    
    // 그리디 접근: 가장 큰 용량을 남기고 나머지는 절반씩 섞음
    sort(drinks.begin(), drinks.end());
    
    double result = drinks[N-1]; // 가장 큰 용량
    
    // 나머지 음료들을 절반씩 섞음
    for (int i = 0; i < N-1; i++) {
        result += drinks[i] / 2.0;
    }
    
    // 결과 출력 (정수인 경우 소수점 제거)
    if (result == (int)result) {
        cout << (int)result << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}
