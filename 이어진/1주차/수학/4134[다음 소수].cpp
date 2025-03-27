#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		unsigned int temp;
		cin >> temp;

		bool find_prime = false;
		while (!(find_prime)) {

			bool isPrime = true;
			if (temp == 1 || temp == 0) {
				cout << "2" << endl;
				break;
			}
			for (int j = 2; j <= sqrt(temp); j++) {
				if (temp % j == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime == true) {
				cout << temp << endl;
				find_prime = true;
			}
			temp++;
		}
	}
}