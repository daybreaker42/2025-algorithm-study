#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> adj;
vector<int> par;
void dfs(int u){
    for(int v : adj[u]){
        if(par[v] == 0){
            par[v] = u;
            dfs(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    adj.resize(N+1);
    par.resize(N+1);
    for(int i=0;i<N-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i=2;i<=N;i++) cout<<par[i]<<"\n";
}
