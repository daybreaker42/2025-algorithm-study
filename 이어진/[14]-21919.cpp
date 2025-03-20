#include <iostream>

using namespace std;

bool isPrime(const int& n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

//문제 풀고나서: 소수끼리 곱하면 최소공배수라 굳이 이 연산이 필요가 없음..
//Q. 에라토스테네스가 더 빠른가?
long long gcd(long long a, long long b) {
	return (a % b) ? gcd(b, a % b) : b;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	int n, cnt=0;
	long long L=0; //최소공배수
	cin >> n;

	//n칸 배열 생성
	int* arr = new int[n];
	
	//배열 원소 입력
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (isPrime(arr[i])) cnt++;

		if (cnt == 1 && isPrime(arr[i])) L = arr[i];
		else if (cnt > 1 && isPrime(arr[i]) && L%arr[i]!=0) L = lcm(L, arr[i]);
	}

	delete[] arr;
	arr = nullptr;

	if (cnt == 0) cout << "-1" << endl;
	else cout << L << endl;
}