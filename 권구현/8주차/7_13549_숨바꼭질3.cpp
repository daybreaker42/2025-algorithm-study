#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K; cin>>N>>K;
    const int MAX=100000;
    vector<int> dist(MAX+1,1e9);
    deque<int> dq;
    dist[N]=0; dq.push_back(N);
    while(!dq.empty()){
        int x=dq.front(); dq.pop_front();
        if(x==K) break;
        if(x*2<=MAX && dist[x*2]>dist[x]){
            dist[x*2]=dist[x];
            dq.push_front(x*2);
        }
        if(x-1>=0 && dist[x-1]>dist[x]+1){
            dist[x-1]=dist[x]+1;
            dq.push_back(x-1);
        }
        if(x+1<=MAX && dist[x+1]>dist[x]+1){
            dist[x+1]=dist[x]+1;
            dq.push_back(x+1);
        }
    }
    cout<<dist[K];
    return 0;
}
