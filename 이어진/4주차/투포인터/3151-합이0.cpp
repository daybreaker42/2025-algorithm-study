#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long count = 0;

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        int target = -arr[i];

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                if (arr[left] == arr[right]) {
                    long long num_elements = right - left + 1;
                    count += num_elements * (num_elements - 1) / 2;
                    break;
                } else {
                    int left_val = arr[left];
                    int right_val = arr[right];
                    long long left_count = 0;
                    long long right_count = 0;

                    while (left < right && arr[left] == left_val) {
                        left++;
                        left_count++;
                    }
                    while (left < right && arr[right] == right_val) {
                        right--;
                        right_count++;
                    }
                    count += left_count * right_count;
                }
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << count << endl;

    return 0;
}