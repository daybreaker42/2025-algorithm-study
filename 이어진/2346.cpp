#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> deq;
	int n;
	cin >> n;

	//원소삽입( front >>> 1 2 3 4 5 >>> back )
	for (int i = 1; i <= n; i++) {
		deq.push_back(i);
	}

	//풍선 속 종이값 입력
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << deq.front()<<" ";
	int temp = deq.front();
	deq.pop_front();
	while (n-- > 1) {
		//풍선 속 종이가 0 이상이면
		if (arr[temp - 1] > 0) {
			for (int i = 1; i < arr[temp - 1]; i++) {
				//Front->Back으로 풍선 이동
				deq.push_back(deq.front());
				deq.pop_front();
			}
			//Front위치에 있는 풍선 출력
			cout << deq.front()<<" ";
			temp = deq.front();
			deq.pop_front();
		}

		//풍선 속 종이가 0 미만이라면
		else if (arr[temp - 1] < 0) {
			for (int i = -1; i > arr[temp - 1]; i--) {
				//Back->Front로 풍선 이동
				deq.push_front(deq.back());
				deq.pop_back();
			}
			//Back 위치에 있는 풍선 출력
			cout << deq.back()<<" ";
			temp = deq.back();
			deq.pop_back();
		}
	}
	
}