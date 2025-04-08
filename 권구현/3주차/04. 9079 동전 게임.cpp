#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 8개의 가능한 연산(3개 행, 3개 열, 2개 대각선)
int operations[8][9] = {
    {1,1,1,0,0,0,0,0,0}, // 첫 번째 행
    {0,0,0,1,1,1,0,0,0}, // 두 번째 행
    {0,0,0,0,0,0,1,1,1}, // 세 번째 행
    {1,0,0,1,0,0,1,0,0}, // 첫 번째 열
    {0,1,0,0,1,0,0,1,0}, // 두 번째 열
    {0,0,1,0,0,1,0,0,1}, // 세 번째 열
    {1,0,0,0,1,0,0,0,1}, // 주 대각선 (\)
    {0,0,1,0,1,0,1,0,0}  // 부 대각선 (/)
};

// 모든 동전이 같은 면인지 확인
bool allSame(vector<char>& coins) {
    return all_of(coins.begin(), coins.end(), [&](char c) { return c == coins[0]; });
}

// 브루트 포스로 최소 연산 횟수 찾기
int findMinOperations(vector<char> coins) {
    int min_ops = -1;
    
    // 모든 가능한 연산 조합 시도 (각 연산은 최대 한 번만 사용)
    for (int mask = 0; mask < (1 << 8); mask++) {
        vector<char> temp_coins = coins;
        int ops_count = 0;
        
        for (int i = 0; i < 8; i++) {
            if (mask & (1 << i)) {
                ops_count++;
                for (int j = 0; j < 9; j++) {
                    if (operations[i][j]) {
                        // 동전 뒤집기
                        temp_coins[j] = (temp_coins[j] == 'H') ? 'T' : 'H';
                    }
                }
            }
        }
        
        // 모든 동전이 같은 면인지 확인
        if (allSame(temp_coins)) {
            if (min_ops == -1 || ops_count < min_ops) {
                min_ops = ops_count;
            }
        }
    }
    
    return min_ops;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        vector<char> coins(9);
        for (int i = 0; i < 9; i++) {
            cin >> coins[i];
        }
        
        cout << findMinOperations(coins) << endl;
    }
    
    return 0;
}
