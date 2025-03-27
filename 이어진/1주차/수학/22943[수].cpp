#include <iostream>
#include <string>
#include <cmath>

#define MAX 100001

using namespace std;

//에라토스테네스의 체(소수만 true)
void getPrime(bool* isPrime, int size) {
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i <= size; i++) {
		if (isPrime[i] == false) continue;
		for (int k = i + i; k <= size; k += i) {
			isPrime[k] = false;
		}
	}
	return;
}

//1번 조건
void getNumber(bool* numbers, bool* used, string num, int n, int count) {
	
	if (count == n) {
		numbers[stoi(num)] = true;
		return;
	}
	 
	for (int i = 0; i <= 9; i++) {
		if (count == 0 && i == 0) continue; //첫자리는0 불가능
		if (used[i] == true) continue; //숫자 재사용 불가능

		//사용 가능한 숫자인 경우
		used[i] = true;
		getNumber(numbers, used, num + to_string(i), n, count+1); //재귀함수로 분기점 생성
		used[i] = false; //i를 선택하지 않은 경우를 만들기 위해서 다시 false
	}
}

//2번 조건(숫자 n이 두 소수의 합으로 표현되는지)
void isSum(bool* isPrime, int size, bool* numbers) {

	//각각의 수에 대해서 판단
	for (int i = 1; i < size; i++) {
		if (numbers[i] == false) continue; //1번 조건으로 생성된 수가 아니므로 패스
		numbers[i] = false; //2번 조건을 만족하지 못할 경우 3번에서 굳이 연산할 필요 없으므로 일단 false 처리(맞으면 다시 true)
		
		for (int k = 2; k <= size/2; k++) {
			if (isPrime[k] == false) continue; //합성수면 패스
			if (k!=i-k && (i - k) > 0 &&isPrime[i - k]) { //내가 생각해도 이해 안되는 조건문
				numbers[i] = true; //조건을 만족하면 다시 true 부여.
				break;
			}
		}
	}
	return;
}

//3번 조건(숫자 n을 M으로 나눠떨어지지 않을때까지 나누고, 두 소수의 곱으로 표현되는지)
void isMultiple(int M, bool* isPrime, int size, bool* numbers) {
	for (int i = 1; i < size; i++) {
		if (numbers[i] == false) continue; //1 또는 2의 조건을 만족하지 못한수면 pass
		numbers[i] = false; //일단 조건을 불만족한다고 가정.
		int temp = i;
		while (temp % M == 0) {
			temp /= M;
		}

		for (int k = 2; k * k <= size; k++) {
			if (isPrime[k] == false) continue; //합성수면 패스
			if (temp % k == 0 && isPrime[temp / k]) {
				numbers[i] = true; //조건을 만족하면 true
				break;
			}
		}
	}
	return;
}

int main(void) {

	//1번 조건(K가지 숫자로 번호 생성)
	bool *numbers = new bool[MAX];
	bool *used = new bool[10];//사용한 숫자는 true 처리
	for (int i = 0; i < MAX; i++) {
		if (i < 10) used[i] = false;
		numbers[i] = false;
	}
	int n, M;
	cin >> n >> M;
	getNumber(numbers, used, "", n, 0);

	//소수값 구하기
	int size = pow(10, n); //최대 크기
	bool* isPrime = new bool[size];
	for (int i = 0; i < size; i++) {
		isPrime[i] = true;
	}
	getPrime(isPrime, size);

	//조건 만족하는 수 구하기
	isSum(isPrime, size, numbers);
	isMultiple(M, isPrime, size, numbers);

	//출력
	int count = 0;
	for (int i = 1; i < size; i++) {
		if (numbers[i]) count++;
	}
	cout << count << endl;

	delete[] numbers, used, isPrime;
	numbers, used, isPrime = nullptr;
}