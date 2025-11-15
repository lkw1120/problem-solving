#include<bits/stdc++.h>
using namespace std;
vector<int> adj[5005];
int check[5005];
int N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<M;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<K;i++) {
        int x;
        cin>>x;
        check[x] = -1;
    }
    queue<int> q;
    q.push(1);
    check[1] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next: adj[cur]) {
            if(check[next] != 0) continue;
            check[next] = 1;
            q.push(next);
        }
    }
    ans = 0;
    for(int i=2;i<=N+1;i++) {
        if(check[i] == 1) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}