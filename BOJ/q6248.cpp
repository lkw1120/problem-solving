#include<bits/stdc++.h>
using namespace std;
const int INF = 999999999;
const int MAX = 1001;
vector<pair<int,int>> adj[MAX];
int dist[MAX] = {0};
int N,M,X,A,B,T,ans;
void solve(int start) {
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
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>X;
    for(int i=0;i<M;i++) {
		cin>>A>>B>>T;
		adj[A].push_back({B,T});
		adj[B].push_back({A,T});
    }
	ans = 0;
	solve(X);
	for(int i=1;i<=N;i++) {
		ans = max(ans,dist[i]);
	}
	ans*=2;
	cout<<ans<<"\n";
    return 0;
}