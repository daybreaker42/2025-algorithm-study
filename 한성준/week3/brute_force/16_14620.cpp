#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N;
int garden[10][10]; // 화단 배열
int minCost = INT_MAX; // 최소 비용
// 꽃이 피는 방향 (중앙, 상, 하, 좌, 우)
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, -1, 1, 0, 0};

// 해당 위치에 꽃을 심을 수 있는지 확인하는 함수
bool canPlant(vector<vector<bool>>& planted, int x, int y) {
    if (x <= 0 || x >= N-1 || y <= 0 || y >= N-1) return false; // 경계 확인
    
    // 꽃잎이 다른 꽃과 겹치는지 확인
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (planted[nx][ny]) return false;
    }
    return true;
}

// 해당 위치에 꽃을 심는 함수
void plant(vector<vector<bool>>& planted, int x, int y, bool value) {
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        planted[nx][ny] = value;
    }
}

// 해당 위치에 꽃을 심었을 때 비용 계산 함수
int getCost(int x, int y) {
    int cost = 0;
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        cost += garden[nx][ny];
    }
    return cost;
}

// 꽃 3개를 모두 심는 모든 경우를 탐색하는 함수
void dfs(vector<vector<bool>>& planted, int flowers, int cost) {
    // 꽃 3개를 모두 심었으면 최소 비용 갱신
    if (flowers == 3) {
        minCost = min(minCost, cost);
        return;
    }
    
    // 모든 위치에 꽃 심기 시도
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < N-1; j++) {
            if (canPlant(planted, i, j)) {
                int newCost = getCost(i, j);
                plant(planted, i, j, true);
                dfs(planted, flowers + 1, cost + newCost);
                plant(planted, i, j, false);
            }
        }
    }
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> garden[i][j];
        }
    }
    
    vector<vector<bool>> planted(N, vector<bool>(N, false));
    dfs(planted, 0, 0);
    
    cout << minCost << endl;
    
    return 0;
}

/* 
문제 요약: N*N 화단에 3개의 꽃을 심을 때 최소 비용 구하기
- 꽃은 중앙 및 상하좌우에 꽃잎이 피어서 총 5칸을 차지함
- 꽃잎이 서로 겹치거나 화단을 벗어나면 안됨
- 각 칸의 비용이 주어질 때 최소 비용 구하기

접근 방법:
1. 화단의 각 위치에 꽃을 심을 수 있는지 확인
2. 3개의 꽃을 심는 모든 조합을 브루트 포스로 탐색
3. 최소 비용 갱신
*/
