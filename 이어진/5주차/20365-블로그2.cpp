#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;
    cin >> n >> s;
    
    // 발상: 기본색을 빨강 또는 파랑 중 더 많은 것으로 칠하고,
    // 다른 색은 부분적으로 덧칠하는 것이 최소 횟수가 됨
    
    int blue_count = 0, red_count = 0;
    char prev = ' ';
    
    for (int i = 0; i < n; i++) {
        if (s[i] != prev) {
            if (s[i] == 'B') blue_count++;
            else red_count++;
            prev = s[i];
        }
    }
    
    // 기본색 1번 + 다른 색 덧칠하는 횟수
    cout << min(blue_count, red_count) + 1 << '\n';
    
    return 0;
}