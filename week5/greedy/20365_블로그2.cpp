#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string colors;
    
    cin >> N;
    cin >> colors;
    
    // 그리디 접근: 전체를 한 색으로 칠하고, 다른 색이 나올 때마다 추가로 칠하는 방식
    int blue_count = 0;
    int red_count = 0;
    
    // 색 변화 횟수 계산
    char prev = ' ';
    for (int i = 0; i < N; i++) {
        if (prev != colors[i]) {
            if (colors[i] == 'B') blue_count++;
            else red_count++;
            prev = colors[i];
        }
    }
    
    // 둘 중 더 적게 나오는 색의 개수 + 1(전체 칠하기)이 최소 작업 횟수
    int answer = min(blue_count, red_count) + 1;
    cout << answer << endl;
    
    return 0;
}
