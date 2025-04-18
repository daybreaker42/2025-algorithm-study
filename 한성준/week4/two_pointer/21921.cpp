#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, X;
    cin >> N >> X;
    
    vector<int> visitors(N);
    for (int i = 0; i < N; i++) {
        cin >> visitors[i];
    }
    
    // 슬라이딩 윈도우 초기화 (처음 X일 동안의 방문자 수 합계)
    int sum = 0;
    for (int i = 0; i < X; i++) {
        sum += visitors[i];
    }
    
    int maxVisitors = sum;  // 최대 방문자 수
    int maxCount = 1;       // 최대 방문자 수를 가진 기간의 수
    
    // 슬라이딩 윈도우 이동 (X일 기간의 윈도우를 한 칸씩 이동)
    for (int i = X; i < N; i++) {
        sum = sum - visitors[i - X] + visitors[i];  // 가장 왼쪽 값을 빼고 새로운 오른쪽 값을 더함
        
        if (sum > maxVisitors) {
            maxVisitors = sum;
            maxCount = 1;
        } else if (sum == maxVisitors) {
            maxCount++;
        }
    }
    
    if (maxVisitors == 0) {
        cout << "SAD" << '\n';
    } else {
        cout << maxVisitors << '\n';
        cout << maxCount << '\n';
    }
    
    return 0;
}
