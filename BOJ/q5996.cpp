#include<bits/stdc++.h>
using namespace std;
const int MAX = 2501;
const int INF = 999999999;
vector<pair<int,int>> adj[MAX];
int dist[MAX] = {0};
int T,C,S,E,U,V,W,ans;
int solve(int start, int end) {
	priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        if(dist[now] < d) continue;
        int size = adj[now].size();
        for(int i=0;i<size;i++) {
            int next = adj[now][i].first;
            int cost = d + adj[now][i].second;
            if(cost < dist[next]) {
                dist[next] = cost;
                pq.push({-cost,next});
            }
        }
    }
	return dist[end];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	fill(dist,dist+MAX,INF);
    cin>>T>>C>>S>>E;
    for(int i=0;i<C;i++) {
        cin>>U>>V>>W;
        adj[U].push_back({V,W});
        adj[V].push_back({U,W});
    }
	ans = solve(S,E);
	cout<<ans<<"\n";
    return 0;
}