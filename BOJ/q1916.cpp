#include<bits/stdc++.h>
#define INF 999999999
#define MAX 1001
using namespace std;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> adj[MAX];
int dist[MAX] = {0};
int N,M,u,v,w,from,to,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    for(int i=0;i<MAX;i++) {
        dist[i] = INF;
    }
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    cin>>from>>to;
    pq.push({0,from});
    dist[from] = 0;
    while(!pq.empty()) {
        u = pq.top().second;
        w = -pq.top().first;
        pq.pop();

        if(dist[u] < w) continue;
        
        int size = adj[u].size();
        for(int i=0;i<size;i++) {
            v = adj[u][i].first;
            int cost = w + adj[u][i].second;
            if(cost < dist[v]) {
                dist[v] = cost;
                pq.push({-cost,v});
            }
        }
    }
    ans = dist[to];
    cout<<ans<<"\n";
    return 0;
}