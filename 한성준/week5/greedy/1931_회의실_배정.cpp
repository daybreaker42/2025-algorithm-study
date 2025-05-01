#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int, int>> meetings(N);
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }
    
    // 그리디 접근: 종료 시간이 빠른 순으로 정렬, 종료 시간이 같다면 시작 시간이 빠른 순
    sort(meetings.begin(), meetings.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    );
    
    int count = 0;
    int end_time = 0;
    
    // 이전 회의가 끝난 시간 이후에 시작하는 회의 선택
    for (int i = 0; i < N; i++) {
        if (meetings[i].first >= end_time) {
            end_time = meetings[i].second;
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
