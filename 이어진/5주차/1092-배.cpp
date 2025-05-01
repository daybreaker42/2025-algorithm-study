#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> cranes(n);
    for (int i = 0; i < n; i++) {
        cin >> cranes[i];
    }
    
    int m;
    cin >> m;
    
    vector<int> boxes(m);
    for (int i = 0; i < m; i++) {
        cin >> boxes[i];
    }
    
    // 내림차순 정렬 (무거운 것부터)
    sort(cranes.rbegin(), cranes.rend());
    sort(boxes.rbegin(), boxes.rend());
    
    // 발상: 가장 무거운 박스를 가장 무거운 크레인이 처리할 수 없으면 불가능
    if (boxes[0] > cranes[0]) {
        cout << -1 << '\n';
        return 0;
    }
    
    // 옮겨진 박스 체크
    vector<bool> moved(m, false);
    int time = 0;
    int moved_count = 0;
    
    // 모든 박스를 옮길 때까지 반복
    while (moved_count < m) {
        // 각 크레인별로 옮길 수 있는 가장 무거운 박스를 찾아 옮김
        for (int i = 0; i < n; i++) {
            // 모든 박스에 대해 확인
            for (int j = 0; j < m; j++) {
                // 아직 옮기지 않았고, 크레인이 들 수 있는 박스인 경우
                if (!moved[j] && cranes[i] >= boxes[j]) {
                    moved[j] = true;
                    moved_count++;
                    break;  // 이 크레인은 박스를 하나 옮겼으므로 다음 크레인으로
                }
            }
        }
        
        time++;  // 모든 크레인이 한 번씩 작업한 후 시간 증가
    }
    
    cout << time << '\n';
    
    return 0;
}

