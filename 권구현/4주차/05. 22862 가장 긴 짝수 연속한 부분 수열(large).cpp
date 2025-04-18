#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int left = 0, right = 0;
    int cnt = 0;         // 홀수 개수
    int maxLen = 0;

    while (right < N) {
        if (A[right] % 2 == 1) cnt++;

        // 홀수가 K보다 많아지면 왼쪽 포인터 이동
        while (cnt > K) {
            if (A[left] % 2 == 1) cnt--;
            left++;
        }

        // 짝수 개수만 카운트 (전체 길이 - 홀수 개수)
        maxLen = max(maxLen, right - left + 1 - cnt);
        right++;
    }

    cout << maxLen << '\n';
    return 0;
}
