#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    string number;
    
    cin >> N >> K;
    cin >> number;
    
    // 결과 숫자를 저장할 벡터
    vector<char> result;
    int remove_count = 0;
    
    // 그리디 접근: 앞에서부터 탐색하며 현재 숫자보다 작은 이전 숫자들을 제거
    for (int i = 0; i < number.length(); i++) {
        // 아직 제거할 수 있고, result가 비어있지 않으며, 마지막 숫자가 현재 숫자보다 작을 때
        while (!result.empty() && remove_count < K && result.back() < number[i]) {
            result.pop_back();
            remove_count++;
        }
        
        result.push_back(number[i]);
    }
    
    // K개를 모두 제거하지 못한 경우 뒤에서부터 남은 개수만큼 제거
    while (remove_count < K) {
        result.pop_back();
        remove_count++;
    }
    
    // 결과 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}
