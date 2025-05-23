#include <bits/stdc++.h>
#define SIZE 100
#define LIMIT 100001

using namespace std;

typedef struct item{
    int weight;
    int value;
};

item itemArray[SIZE];
int dp[LIMIT];  // 각 weight마다 넣을 수 있는 최대 value 저장
bool isUsed[LIMIT][SIZE];

int main(){
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> itemArray[i].weight >> itemArray[i].value;
    }

    // solving
    int ans = 0;
    // sort(itemArray, itemArray + n, cmp);
    for(int i = 0; i < k; i++){
        // 0에서 k - 1까지 반복하면서, 물건 하나씩을 채워가며 dp[]를 갱신할 수 있는지 확인
        for(int j = 0; j < n; j++){
            item nextItem = itemArray[j];
            int next = i + nextItem.weight;
            if(next <= k && dp[next] < dp[i] + nextItem.value && !isUsed[i][j]){
                memmove(isUsed[next], isUsed[i], SIZE * sizeof(bool));
                isUsed[next][j] = true;
                dp[next] = dp[i] + nextItem.value;
                ans = max(ans, dp[next]);
            }
        }
    }

    cout << ans;
    
    // // debugging
    // cout << endl;
    // for(int i = 0; i <= k; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
}