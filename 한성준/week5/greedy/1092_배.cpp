#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    
    // 크레인 입력
    cin >> N;
    vector<int> cranes(N);
    for (int i = 0; i < N; i++) {
        cin >> cranes[i];
    }
    
    // 화물 입력
    cin >> M;
    vector<int> boxes(M);
    for (int i = 0; i < M; i++) {
        cin >> boxes[i];
    }
    
    // 내림차순 정렬 (가장 무거운 것부터 처리하기 위해)
    sort(cranes.begin(), cranes.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());
    
    // 가장 무거운 화물이 가장 큰 크레인으로도 옮길 수 없는 경우
    if (boxes[0] > cranes[0]) {
        cout << -1 << endl;
        return 0;
    }
    
    // 화물을 옮기는 데 필요한 시간 계산
    int time = 0;
    while (!boxes.empty()) {
        time++; // 새로운 작업 시간
        
        // 각 크레인이 처리할 수 있는 가장 무거운 화물 처리
        for (int i = 0; i < N; i++) {
            // 모든 화물을 처리했으면 종료
            if (boxes.empty()) break;
            
            // 현재 크레인이 옮길 수 있는 가장 무거운 화물 찾기
            for (int j = 0; j < boxes.size(); j++) {
                if (cranes[i] >= boxes[j]) {
                    boxes.erase(boxes.begin() + j); // 화물 제거
                    break;
                }
            }
        }
    }
    
    cout << time << endl;
    
    return 0;
}
