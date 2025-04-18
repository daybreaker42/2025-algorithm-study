#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> solutions(n);
    for (int i = 0; i < n; ++i) {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    long long min_sum = -1;
    long long result_left = solutions[0];
    long long result_right = solutions[n - 1];

    int left = 0;
    int right = n - 1;

    while (left < right) {
        long long current_sum = solutions[left] + solutions[right];

        if (min_sum == -1 || abs(current_sum) < abs(min_sum)) {
            min_sum = current_sum;
            result_left = solutions[left];
            result_right = solutions[right];
        }

        if (current_sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    cout << result_left << " " << result_right << endl;

    return 0;
}