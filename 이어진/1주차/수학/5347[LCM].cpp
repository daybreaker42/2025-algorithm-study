#include<iostream>
using namespace std;
int n;
long long find(long long a, long long b);
int main() {
	cin >> n;
	for (int x = 0; x < n; x++) {
		long long a, b;
		cin >> a >> b;
		long long res = find(a, b);
		cout << (a * b) / res << "\n";
	}
}
long long find(long long a, long long b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		long long res = a % b;
		a = b;
		b = res;

	}
	return a;

}