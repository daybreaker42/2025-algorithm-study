#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end()); // 정렬 필수

    int left = 0, right = N - 1;
    int min_sum = 2e9 + 1;
    int ans1 = 0, ans2 = 0;

    while (left < right) {
        int sum = A[left] + A[right];
        if (abs(sum) < min_sum) {
            min_sum = abs(sum);
            ans1 = A[left];
            ans2 = A[right];
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    cout << ans1 << " " << ans2 << endl;
    return 0;
}
