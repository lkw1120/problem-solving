#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 5001;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> adj[MAX];
int dist[MAX];
int V,E,P,A,B,C;
int find(int x, int y) {
    fill(dist,dist+MAX,INF);
    pq.push({0,x});
    dist[x] = 0;
    while(!pq.empty()) {
        int a = pq.top().second;
        int c = -pq.top().first;
        pq.pop();
        if(dist[a] < c) continue;
        int size = adj[a].size();
        for(int i=0;i<size;i++) {
            int b = adj[a][i].first;
            int cost = c + adj[a][i].second;
            if(cost < dist[b]) {
                dist[b] = cost;
                pq.push({-cost,b});
            }
        }
    }
    return dist[y];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>V>>E;
    cin>>P;
    for(int i=0;i<E;i++) {
        cin>>A>>B>>C;
        adj[A].push_back({B,C});
        adj[B].push_back({A,C});
    }
    if(find(1,V) == find(1,P)+find(P,V)) {
        cout<<"SAVE HIM"<<"\n";
    }
    else {
        cout<<"GOOD BYE"<<"\n";
    }
    return 0;
}