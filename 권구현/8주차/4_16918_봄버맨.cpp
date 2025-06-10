#include <iostream>
#include <vector>
using namespace std;
int R,C,N;
vector<string> grid, tmp;
int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
void tick(){
    tmp.assign(R,string(C,'O'));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j]=='O'){
                tmp[i][j]='.';
                for(int d=0;d<4;d++){
                    int ni=i+dr[d], nj=j+dc[d];
                    if(ni>=0 && ni<R && nj>=0 && nj<C) tmp[ni][nj]='.';
                }
            }
        }
    }
    grid=tmp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>R>>C>>N;
    grid.resize(R);
    for(int i=0;i<R;i++) cin>>grid[i];
    if(N==1){
        for(auto&s:grid) cout<<s<<"\n"; return 0;
    } else if(N%2==0){
        for(int i=0;i<R;i++) cout<<string(C,'O')<<"\n"; return 0;
    }
    tick();
    if(N%4==3){
        for(auto&s:grid) cout<<s<<"\n"; return 0;
    }
    tick();
    for(auto&s:grid) cout<<s<<"\n";
    return 0;
}
