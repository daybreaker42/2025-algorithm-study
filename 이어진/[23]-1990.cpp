#include <iostream>
#include <string>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool isPalindrome(string s) {
	int size = s.length();
	for (int i = 0; i < size / 2; i++) {
		if (s[i] != s[size - 1 - i]) return false;
	}
	return true;
}

int main(void) {
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		if (i >= 10000000) break; //무지성으로 5 1억 박아보니까 천만 넘는거 없길래 걸어봄
		if (isPalindrome(to_string(i))&&isPrime(i)) {
			cout << i << endl;
		}
	}
	cout << "-1" << endl;
}