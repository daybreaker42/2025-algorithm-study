#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

// 세 수가 삼각관계를 만족하는지 확인하는 함수
bool isTriangle(ll a, ll b, ll c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// 주어진 수열이 삼각 수열인지 확인하는 함수
bool isTriangleSequence(const vector<ll>& seq) {
    int n = seq.size();
    if (n < 3) return true; // 원소가 3개 미만이면 무조건 성립
    
    // 모든 가능한 세 원소 조합을 확인
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (!isTriangle(seq[i], seq[j], seq[k])) {
                    return false; // 삼각관계를 만족하지 않는 세 수가 있으면 삼각 수열이 아님
                }
            }
        }
    }
    return true; // 모든 세 수 조합이 삼각관계를 만족하면 삼각 수열임
}

// 비트마스킹을 이용한 모든 부분 수열 검사
int findMaxTriangleSubsequence(const vector<ll>& arr) {
    int n = arr.size();
    int maxLength = 0;
    
    // 2^n개의 모든 부분집합을 검사
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<ll> subsequence;
        
        // 현재 마스크에 대응되는 부분 수열 생성
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subsequence.push_back(arr[i]);
            }
        }
        
        // 생성된 부분 수열이 삼각 수열인지 확인
        if (isTriangleSequence(subsequence)) {
            maxLength = max(maxLength, (int)subsequence.size());
        }
    }
    
    return maxLength;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 길이가 1 또는 2인 수열은 항상 삼각 수열
    if (n <= 2) {
        cout << n << endl;
        return 0;
    }
    
    // 모든 원소가 같은 값인지 확인
    bool allSame = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[0]) {
            allSame = false;
            break;
        }
    }
    
    // 모든 원소가 같은 값이면 항상 삼각 수열
    if (allSame) {
        cout << n << endl;
        return 0;
    }
    
    int result = findMaxTriangleSubsequence(arr);
    cout << result << endl;
    
    return 0;
}
