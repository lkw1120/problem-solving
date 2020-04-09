#include<bits/stdc++.h>
#define INF 999999
#define MAX 20001
using namespace std;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> adj[MAX];
int dist[MAX] = {0};
int V,E,K,u,v,w;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    for(int i=0;i<MAX;i++) {
        dist[i] = INF;
    }
    cin>>V>>E;
    cin>>K;
    for(int i=0;i<E;i++) {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    pq.push({0,K});
    dist[K] = 0;
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
    for(int i=1;i<=V;i++) {
        if(dist[i] == INF) {
            cout<<"INF"<<"\n";
        }
        else {
            cout<<dist[i]<<"\n";
        }
    }
    return 0;
}