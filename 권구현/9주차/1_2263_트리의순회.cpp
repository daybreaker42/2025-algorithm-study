#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> in, post;
int idx[100001];
void build(int inL, int inR, int postL, int postR){
    if(inL > inR || postL > postR) return;
    int root = post[postR];
    cout << root << " ";
    int rootIdx = idx[root];
    int left = rootIdx - inL;
    build(inL, rootIdx - 1, postL, postL + left - 1);
    build(rootIdx + 1, inR, postL + left, postR - 1);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    in.resize(n); post.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> in[i];
        idx[in[i]] = i;
    }
    for(int i = 0; i < n; ++i) cin >> post[i];
    build(0, n - 1, 0, n - 1);
    return 0;
}
