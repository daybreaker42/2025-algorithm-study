#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(){
    int u,v,tc=1;
    while(1){
        map<int,int> indeg;
        set<int> nodes;
        bool isTree=true;
        while(cin>>u>>v, u||v){
            if(u<0&&v<0) return 0;
            if(++indeg[v]>1) isTree=false;
            nodes.insert(u); nodes.insert(v);
        }
        if(nodes.empty()) cout<<"Case "<<tc++<<" is a tree.\n";
        else{
            int root=0;
            for(auto x:nodes) if(indeg[x]==0) root++;
            if(root!=1) isTree=false;
            int sum=0;
            for(auto x:nodes) sum+=indeg[x];
            if(sum!=nodes.size()-1) isTree=false;
            cout<<"Case "<<tc++<<(isTree?" is a tree.\n":" is not a tree.\n");
        }
    }
}
