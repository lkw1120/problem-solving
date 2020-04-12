#include<bits/stdc++.h>
#define INF 999999999
#define MAX 801
using namespace std;
vector<pair<int,int>> v[MAX];
int N,E,a,b,c,v1,v2,ans;
int dijkstra(int x, int y) {
    priority_queue<pair<int,int>> pq;
    int dist[MAX];
    fill(dist,dist+MAX,INF);
    pq.push({0,x});
    dist[x] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int nowCost = -pq.top().first;
        pq.pop();
        if(dist[now] < nowCost) continue;
        for(auto node : v[now]) {
            int next = node.first;
            int nextCost = nowCost + node.second;
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({-nextCost,next});
            }
        }
    }
    return dist[y];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>E;
    for(int i=0;i<E;i++) {
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin>>v1>>v2;
    int d = dijkstra(v1,v2);
    ans = min(dijkstra(1,v1)+d+dijkstra(v2,N),dijkstra(1,v2)+d+dijkstra(v1,N));
    if(ans >= INF || ans < 0) ans = -1;
    cout<<ans<<"\n";
    return 0;
}