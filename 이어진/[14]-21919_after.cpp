#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000

using namespace std;

int main() {
	int n, max=0;
	long long result = 1;
	bool isPrime[MAX] = { false, };

	cin >> n;

	//에라토스테네스 체
	isPrime[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (isPrime[i] == true) continue;
		for (int k = i + i; k <= MAX; k += i) {
			isPrime[k] = true;
		}
	}

	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
		//소수이면서, 중복되지 않은 수면
		if (isPrime[temp] && (result % temp == 0)) {
			result *= temp;
		}
	}

	if (result == 1) cout << "-1" << endl;
	else cout << result << endl;
}