#include<bits/stdc++.h>
using namespace std;
const int INF = 999999999;
const int MAX = 101;
vector<pair<int,int>> adj[MAX];
int dist[MAX] = {0};
int N,K,A,B,C,ans;
int solve(int start, int end) {
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
	return dist[end];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
    for(int i=0;i<K;i++) {
		cin>>A;
		if(A) {
			cin>>A>>B>>C;
			adj[A].push_back({B,C});
			adj[B].push_back({A,C});
		}
		else {
			cin>>A>>B;
			ans = solve(A,B);
			if(ans == INF) ans = -1;
			cout<<ans<<"\n";
		}
    }
    return 0;
}