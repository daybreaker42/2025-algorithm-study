#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<vector<int>> adj;
vector<bool> vis;
bool found=false;
void dfs(int u,int depth){
    if(depth==4){ found=true; return;}
    vis[u]=true;
    for(int v: adj[u]){
        if(!vis[v]){
            dfs(v, depth+1);
            if(found) return;
        }
    }
    vis[u]=false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    adj.assign(N, {});
    int u,v;
    while(M--){cin>>u>>v; adj[u].push_back(v); adj[v].push_back(u);}
    vis.assign(N,false);
    for(int i=0;i<N;i++){
        dfs(i,0);
        if(found) break;
    }
    cout<<(found?1:0);
    return 0;
}
