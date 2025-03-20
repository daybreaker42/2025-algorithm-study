#include <iostream>

using namespace std;

int gcd(int a, int b) {
	return (a % b) ? gcd(b, a % b) : b;
}

int main(void) {
	int n, size;
	cin >> n;

	while (n-- > 0) {
		//이거를 처음부터 자료형 판단하려면 100_C_2값을 계산해야함?
		long long sum = 0;

		cin >> size;
		int* arr = new int[size];

		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}

		//모든 경우를 계산
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				sum+=gcd(arr[i], arr[j]);
			}
		}
		cout << sum << endl;
		delete[] arr;
		arr = nullptr;
	}
}