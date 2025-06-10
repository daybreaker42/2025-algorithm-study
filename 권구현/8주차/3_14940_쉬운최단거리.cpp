#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M; cin>>N>>M;
    vector<vector<int>> A(N, vector<int>(M)), dist(N, vector<int>(M,-1));
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++){
        cin>>A[i][j];
        if(A[i][j]==2){ q.push({i,j}); dist[i][j]=0; }
    }
    int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
    while(!q.empty()){
        auto [r,c]=q.front(); q.pop();
        for(int d=0;d<4;d++){
            int nr=r+dr[d], nc=c+dc[d];
            if(nr<0||nr>=N||nc<0||nc>=M) continue;
            if(A[nr][nc]==1 && dist[nr][nc]==-1){
                dist[nr][nc]=dist[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]==1 && dist[i][j]==-1) cout<<-1<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
