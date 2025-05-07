#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> meetings(n);
    for (int i = 0; i < n; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }
    
    // 발상: 종료 시간이 빠른 순서대로 정렬한 후, 가능한 많은 회의를 선택
    // 종료 시간이 같다면 시작 시간이 빠른 순서대로 정렬
    sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    
    int count = 0;
    int end_time = 0;
    
    for (int i = 0; i < n; i++) {
        // 현재 회의의 시작 시간이 이전 회의의 종료 시간 이후라면 회의 선택
        if (meetings[i].first >= end_time) {
            count++;
            end_time = meetings[i].second;
        }
    }
    
    cout << count << '\n';
    
    return 0;
}

