#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<string>A;
vector<vector<int>> dist;
int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    A.resize(N);
    for(int i=0;i<N;i++) cin>>A[i];
    dist.assign(N, vector<int>(M,0));
    queue<pair<int,int>>q;
    q.push({0,0});
    dist[0][0]=1;
    while(!q.empty()){
        auto [r,c]=q.front(); q.pop();
        for(int d=0;d<4;d++){
            int nr=r+dr[d], nc=c+dc[d];
            if(nr<0||nr>=N||nc<0||nc>=M) continue;
            if(A[nr][nc]=='1'&&dist[nr][nc]==0){
                dist[nr][nc]=dist[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
    cout<<dist[N-1][M-1];
    return 0;
}
