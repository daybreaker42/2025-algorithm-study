#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N; double W;
    cin>>N>>W;
    vector<int> deg(N+1);
    for(int i=0;i<N-1;i++){
        int u,v; cin>>u>>v;
        deg[u]++; deg[v]++;
    }
    int leaf=0;
    for(int i=2;i<=N;i++) if(deg[i]==1) leaf++;
    cout.precision(10);
    cout<<fixed<<W/leaf;
}
