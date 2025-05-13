#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> drinks(n);
    for (int &d : drinks) cin >> d;

    sort(drinks.begin(), drinks.end());
    double total = drinks.back();
    for (int i = 0; i < n - 1; i++)
        total += drinks[i] / 2.0;

    cout << fixed;
    cout.precision(1);
    cout << total << '\n';
}
