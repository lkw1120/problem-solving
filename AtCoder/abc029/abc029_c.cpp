#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int N;
void dfs(string str) {
    if(str.size() == N) {
        v.push_back(str);
        return ;
    }
    dfs(str+"a");
    dfs(str+"b");
    dfs(str+"c");
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    dfs("");
    for(auto item: v) {
        cout<<item<<"\n";
    }
    return 0;
}