#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    string number;
    cin >> N >> K;
    cin >> number;
    
    // 발상: 스택을 이용하여 앞 자리에 큰 수가 오도록 만드는 그리디 알고리즘
    // 현재 숫자보다 작은 이전 숫자들을 제거하면 최대값을 만들 수 있음
    
    vector<char> result;
    int remove_count = 0;
    
    for (int i = 0; i < N; i++) {
        // 이전에 넣은 숫자가 현재 숫자보다 작으면 제거
        while (!result.empty() && result.back() < number[i] && remove_count < K) {
            result.pop_back();
            remove_count++;
        }
        
        result.push_back(number[i]);
    }
    
    // K개를 모두 제거하지 못한 경우 뒤에서부터 제거
    while (remove_count < K) {
        result.pop_back();
        remove_count++;
    }
    
    // 결과 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << '\n';
    
    return 0;
}