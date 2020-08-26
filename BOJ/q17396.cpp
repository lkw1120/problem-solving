#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100001;
const ll INF = 1LL<<60;
vector<pair<ll,ll>> adj[MAX];
vector<ll> v;
ll N,M,a,b,t,ans;
ll dijkstra(ll x, ll y) {
    priority_queue<pair<ll,ll>> pq;
    ll dist[MAX];
    fill(dist,dist+MAX,INF);
    pq.push({0,x});
    dist[x] = 0;
    while(!pq.empty()) {
        ll now = pq.top().second;
        ll nowCost = -pq.top().first;
        pq.pop();
        if(dist[now] < nowCost) continue;
        for(auto node : adj[now]) {
            ll next = node.first;
            ll nextCost = nowCost + node.second;
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
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N>>M;
    v = vector<ll>(N);
    for(int i=0;i<N;i++) cin>>v[i];
    v[N-1] = 0;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>t;
        if(!v[a] && !v[b]) {
            adj[a].push_back({b,t});
            adj[b].push_back({a,t});
        }
    }
    ans = dijkstra(0,N-1);
    if(ans == INF) ans = -1;
    cout<<ans<<"\n";
	return 0;
}