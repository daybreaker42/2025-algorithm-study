#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPerfectSquare(long long num) {
    if (num < 0) return false;
    long long sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> table(N);
    for (int i = 0; i < N; i++) {
        cin >> table[i];
    }
    
    long long maxPerfectSquare = -1;
    
    // 시작 위치와 공차를 모두 시도
    for (int startRow = 0; startRow < N; startRow++) {
        for (int startCol = 0; startCol < M; startCol++) {
            for (int rowDiff = -N + 1; rowDiff < N; rowDiff++) {
                for (int colDiff = -M + 1; colDiff < M; colDiff++) {
                    // 행과 열의 공차가 둘 다 0인 경우는 건너뛰기 (1개의 칸만 선택하는 경우)
                    if (rowDiff == 0 && colDiff == 0) continue;
                    
                    string numStr = "";
                    int row = startRow, col = startCol;
                    int count = 0;
                    
                    // 표 범위 내에서 등차수열을 따라 숫자 이어붙이기
                    while (0 <= row && row < N && 0 <= col && col < M) {
                        numStr += table[row][col];
                        row += rowDiff;
                        col += colDiff;
                        count++;
                    }
                    
                    // 적어도 1개 이상의 칸을 선택해야 함
                    if (count > 0) {
                        long long num = stoll(numStr);
                        if (isPerfectSquare(num)) {
                            maxPerfectSquare = max(maxPerfectSquare, num);
                        }
                    }
                }
            }
        }
    }
    
    cout << maxPerfectSquare << endl;
    return 0;
}
