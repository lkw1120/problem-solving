#include<bits/stdc++.h>
using namespace std;
vector<int> adj[21];
int N,B,ans;
int dfs(int now) {
    if(adj[now].empty()) {
        return 1;
    }
    int mn = INT_MAX;
    int mx = 0;
    for(auto next: adj[now]) {
        int tmp = dfs(next);
        mn = min(mn,tmp);
        mx = max(mx,tmp);
    }
    return mn+mx+1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=2;i<=N;i++) {
        cin>>B;
        adj[B].push_back(i);
    }
    ans = dfs(1);
    cout<<ans<<"\n";
    return 0;
}