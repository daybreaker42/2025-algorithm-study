#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int a[201];
bool dp[201];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];

    dp[1] = true;
    for (int i=2; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if (dp[j] && (j - i)*(j - i) <= k * abs(a[i] - a[j])) {
                dp[i] = true;
                break;
            }
        }
    }

    cout << (dp[n] ? "YES" : "NO") << '\n';
}
