#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; i++) {
        cin >> lectures[i].first >> lectures[i].second;
    }
    
    // 강의 시작 시간을 기준으로 정렬
    sort(lectures.begin(), lectures.end());
    
    // 강의실 종료 시간을 저장하는 최소 힙
    priority_queue<int, vector<int>, greater<int>> rooms;
    
    // 첫 번째 강의의 종료 시간 저장
    rooms.push(lectures[0].second);
    
    // 그리디 접근: 현재 열린 강의실 중 가장 빨리 끝나는 강의실에 새 강의를 배정
    for (int i = 1; i < N; i++) {
        // 현재 강의의 시작 시간이 가장 빨리 끝나는 강의실의 종료 시간 이후라면
        if (lectures[i].first >= rooms.top()) {
            rooms.pop(); // 해당 강의실을 재사용
        }
        // 새 강의의 종료 시간 저장 (새 강의실 사용 또는 기존 강의실 재사용)
        rooms.push(lectures[i].second);
    }
    
    // 필요한 최소 강의실 수 출력
    cout << rooms.size() << endl;
    
    return 0;
}
