#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX_N = 2e5+1;
vector<pair<int,int>> adj[MAX_N];
int dist[MAX_N][2];
int N,E,A,B,V,ans;
int bfs(int start) {
    fill(&dist[0][0],&dist[0][0]+MAX_N*2,INF);
    queue<pair<int,int>> q;
    dist[0][start] = 0;
    q.push({0,start});
    while(!q.empty()) {
        int cur = q.front().first;
        int v = q.front().second;
        q.pop();
        int d = dist[cur][v];
        for(auto [next,w]: adj[cur]) {
            if(w != v) continue;
            if(dist[next][1-w] == INF) {
                dist[next][1-w] = d + 1;
                q.push({next,1-w});
            }
        }
    }
    return min(dist[N-1][0],dist[N-1][1]); 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>E;
    for(int i=0;i<E;i++) {
        cin>>A>>B>>V;
        adj[A].push_back({B,V});
        adj[B].push_back({A,V});
    }
    ans = min(bfs(0),bfs(1));
    if(ans == INF) ans = -1;
    cout<<ans<<"\n";
    return 0;
}