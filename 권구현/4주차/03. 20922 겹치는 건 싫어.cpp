#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    unordered_map<int, int> freq;
    int left = 0, right = 0;
    int max_len = 0;

    while (right < N) {
        freq[A[right]]++;

        // 만약 어떤 수가 K 초과로 등장하면, 왼쪽 포인터를 이동
        while (freq[A[right]] > K) {
            freq[A[left]]--;
            left++;
        }

        // 현재 윈도우 길이 갱신
        max_len = max(max_len, right - left + 1);
        right++;
    }

    cout << max_len << endl;
    return 0;
}
