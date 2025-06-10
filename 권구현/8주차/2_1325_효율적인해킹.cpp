#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M; cin>>N>>M;
    vector<vector<int>> adj(N+1);
    while(M--){
        int a,b; cin>>a>>b;
        adj[b].push_back(a);
    }
    vector<int> cnt(N+1);
    for(int i=1;i<=N;i++){
        vector<bool> vis(N+1);
        queue<int> q; q.push(i); vis[i]=1;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: adj[u]) if(!vis[v]){
                vis[v]=1; cnt[v]++; q.push(v);
            }
        }
    }
    int mx=*max_element(cnt.begin()+1,cnt.end());
    for(int i=1;i<=N;i++) if(cnt[i]==mx) cout<<i<<" ";
    return 0;
}
