#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main(){
    map<string, int> data;
    int n, k, index=1;
    string pkm[100001];
    cin >> n >> k;

    for(int i=0; i<n; i++){
        string pkm_name;
        cin >> pkm_name;
        data.insert(make_pair(pkm_name, index));
        pkm[i+1]=pkm_name;
    }
    while(k-->0){
        string input_name;
        cin>>input_name;

        if(isdigit(input_name[0])!=0){
            cout << pkm[stoi(input_name)] << '\n';   
        }

        else{
            cout << data.find(input_name)->second <<'\n';
        }
    }
}