#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{int r,c,t,hasSword;};
int R,C,T;
vector<string>A;
bool vis[101][101][2];
int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>R>>C>>T;
    A.resize(R);
    for(int i=0;i<R;i++) cin>>A[i];
    queue<Node>q;
    q.push({0,0,0,0}); vis[0][0][0]=1;
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        if(cur.r==R-1 && cur.c==C-1){
            cout<<(cur.t<=T?cur.t:-1);
            return 0;
        }
        for(int d=0;d<4;d++){
            int nr=cur.r+dr[d], nc=cur.c+dc[d];
            if(nr<0||nr>=R||nc<0||nc>=C) continue;
            int ns=cur.hasSword;
            if(A[nr][nc]=='1' && ns==0) continue;
            if(A[nr][nc]=='2') ns=1;
            if(!vis[nr][nc][ns]){
                vis[nr][nc][ns]=1;
                q.push({nr,nc,cur.t+1,ns});
            }
        }
    }
    cout<<-1;
    return 0;
}
