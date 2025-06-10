#include <iostream>
using namespace std;
struct Node{ char left, right; };
Node tree[26];
void pre(char c){
    if(c=='.') return;
    cout<<c;
    pre(tree[c-'A'].left);
    pre(tree[c-'A'].right);
}
void in(char c){
    if(c=='.') return;
    in(tree[c-'A'].left);
    cout<<c;
    in(tree[c-'A'].right);
}
void post(char c){
    if(c=='.') return;
    post(tree[c-'A'].left);
    post(tree[c-'A'].right);
    cout<<c;
}
int main(){
    int N; cin>>N;
    while(N--){
        char p,l,r; cin>>p>>l>>r;
        tree[p-'A']={l,r};
    }
    pre('A'); cout<<"\n";
    in('A'); cout<<"\n";
    post('A'); cout<<"\n";
}
