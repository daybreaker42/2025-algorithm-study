#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long long getDEC(string s, int n) {
	long long res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			res += (s[i] - '0') * pow(n, s.length() - i - 1);
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			res += (s[i] - 'a' + 10) * pow(n, s.length() - i - 1);
		}
	}
	return res;
}

//입력값이 'abc'라면 최소 c+1진법으로 표현된 값으로 간주해야함
int getMax(string s) {
	char max = '0';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] > max) max = s[i];
	}
	if (max >= '0' && max <= '9') return(max - '0')+1;
	else if (max >= 'a' && max <= 'z') return(max - 'a' + 10)+1;
	return 0;
}

int main() {
	string a, b;
	int cnt = 0, A, B;
	bool Same = false;

	cin >> a >> b;

	for (int i = getMax(a); i <= 36; i++) {
		if (cnt > 1) break;
		for (int k = getMax(b); k <= 36; k++) {
			long long dec_a = getDEC(a, i);
			long long dec_b = getDEC(b, k);
			if (dec_a == dec_b) {
				cnt++;
				A = i;
				B = k;
				if (A == B) Same = true;
			}
			if (cnt > 1) break;
		}
	}

	if (cnt == 0 || Same) cout << "Impossible" << endl;
	else if (cnt == 1) cout << getDEC(a, A) << " " << A << " " << B << endl;
	else if (cnt > 1) cout << "Multiple" << endl;
}