#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int X, int num) {
	if (X < num) {
		int temp = X;
		X = num;
		num = temp;
	}
	return (X % num) ? gcd(num, X % num) : num;
}

int main(void) {
	int n, X;
	double sum = 0, cnt=0;
	vector<int> vec;

	cin >> n;

	while (n-- > 0) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	cin >> X;

	for(int num:vec){
		if (gcd(X, num) == 1) {
			cnt++;
			sum += num;
		}
	}
	cout << sum/cnt << endl;
}