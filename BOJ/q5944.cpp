#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 999999999;
const int MAX = 100001;
vector<pair<int,int>> adj[MAX];
int dist[MAX] = {0};
int C,P,S,A,B,X,Y,D;
ll ans;
int solve(int start, int fin) {
	fill(dist,dist+MAX,INF);
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
	return dist[fin];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>C>>P>>S>>A>>B;
    for(int i=0;i<C;i++) {
		cin>>X>>Y>>D;
		adj[X].push_back({Y,D});
		adj[Y].push_back({X,D});
    }
	ans = 0;
	ll a,b,c;
	a = solve(S,A);
	b = solve(S,B);
	c = solve(A,B);
	ans = min(min(a+c,b+c),min(a*2+b,b*2+a));
	cout<<ans<<"\n";
    return 0;
}