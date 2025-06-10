#include <iostream>
#include <vector>
using namespace std;
int N,R;
vector<vector<pair<int,int>>> adj;
int gLen=0, maxLen=0;
void dfs(int u, int p, int len){
    bool isLeaf=true;
    for(auto [v,w]:adj[u]){
        if(v==p) continue;
        isLeaf=false;
        dfs(v,u,len+w);
    }
    if(isLeaf) maxLen=max(maxLen,len);
}
int main(){
    cin>>N>>R;
    adj.resize(N+1);
    for(int i=0;i<N-1;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int cur=R,prev=0;
    while(adj[cur].size()==2){
        for(auto [nxt,w]:adj[cur]){
            if(nxt==prev) continue;
            gLen+=w;
            prev=cur;
            cur=nxt;
            break;
        }
    }
    dfs(cur,prev,0);
    cout<<gLen<<" "<<maxLen;
}
