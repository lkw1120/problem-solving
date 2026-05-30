#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    graph.resize(N+1);
    visited.resize(N+1);
    for(int i=0;i<M;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt = 0;
    for(int i=1;i<=N;i++) {
        if(visited[i]) continue;
        cnt++;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto next: graph[cur]) {
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    ans = M-(N-cnt);
    cout<<ans<<"\n";
    return 0;
}