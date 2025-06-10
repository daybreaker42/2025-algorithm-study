#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
struct Event { int x, id; bool open; bool operator<(Event& o) const { if(x==o.x) return open>o.open; return x<o.x; } };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin>>N;
    vector<Event> ev;
    vector<vector<int>> adj(N+1);
    for(int i=1;i<=N;i++){int id,x,r;cin>>id>>x>>r; ev.push_back({x-r,id,1}); ev.push_back({x+r,id,0});}
    sort(ev.begin(),ev.end());
    stack<int> st;
    for(auto &e:ev){
        if(e.open){
            if(!st.empty()){
                adj[st.top()].push_back(e.id);
                adj[e.id].push_back(st.top());
            }
            st.push(e.id);
        } else st.pop();
    }
    int S,E; cin>>S>>E;
    vector<bool> vis(N+1);
    queue<vector<int>> q;
    q.push({S});
    vis[S]=1;
    while(!q.empty()){
        auto path=q.front();q.pop();
        int u=path.back();
        if(u==E){
            cout<<path.size()<<"\n";
            for(int v:path) cout<<v<<" ";
            return 0;
        }
        for(int v:adj[u]) if(!vis[v]){
            vis[v]=1;
            auto np=path; np.push_back(v);
            q.push(np);
        }
    }
    return 0;
}
