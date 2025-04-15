#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> visits(N);
    for (int i = 0; i < N; ++i) {
        cin >> visits[i];
    }

    // 초기 윈도우 합
    int window_sum = 0;
    for (int i = 0; i < X; ++i) {
        window_sum += visits[i];
    }

    int max_sum = window_sum;
    int count = 1;

    for (int i = X; i < N; ++i) {
        window_sum += visits[i] - visits[i - X]; // 윈도우 이동
        if (window_sum > max_sum) {
            max_sum = window_sum;
            count = 1;
        } else if (window_sum == max_sum) {
            count++;
        }
    }

    if (max_sum == 0) {
        cout << "SAD" << endl;
    } else {
        cout << max_sum << '\n' << count << '\n';
    }

    return 0;
}
