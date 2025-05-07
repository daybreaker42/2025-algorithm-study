#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> lectures(n);
    for (int i = 0; i < n; i++) {
        cin >> lectures[i].first >> lectures[i].second;
    }
    
    // 발상: 강의 시작 시간으로 정렬하고, 
    // 우선순위 큐를 이용하여 현재 사용 중인 강의실의 끝나는 시간을 관리
    sort(lectures.begin(), lectures.end());
    
    // 우선순위 큐에는 강의실의 끝나는 시간이 저장됨
    priority_queue<int, vector<int>, greater<int>> rooms;
    
    // 첫 번째 강의를 위한 강의실 배정
    rooms.push(lectures[0].second);
    
    // 모든 강의에 대해 확인
    for (int i = 1; i < n; i++) {
        // 현재 강의가 시작하는 시간이 가장 빨리 끝나는 강의실의 끝나는 시간보다 크거나 같으면,
        // 그 강의실을 이어서 사용할 수 있음
        if (lectures[i].first >= rooms.top()) {
            rooms.pop();
        }
        
        // 현재 강의의 끝나는 시간을 우선순위 큐에 추가
        rooms.push(lectures[i].second);
    }
    
    // 우선순위 큐의 크기가 필요한 강의실의 수
    cout << rooms.size() << '\n';
    
    return 0;
}

