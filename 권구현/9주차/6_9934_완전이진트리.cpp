#include <iostream>
#include <vector>
using namespace std;
int K;
vector<int> tree[11];
void build(int d, int l, int r, vector<int>& A){
    if(l>r) return;
    int m=(l+r)/2;
    tree[d].push_back(A[m]);
    build(d+1,l,m-1,A);
    build(d+1,m+1,r,A);
}
int main(){
    cin>>K;
    int n=(1<<K)-1;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    build(0,0,n-1,A);
    for(int i=0;i<K;i++){
        for(int x:tree[i]) cout<<x<<" ";
        cout<<"\n";
    }
}
