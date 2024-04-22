#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
const int INF = INT_MAX;
vector<pair<int,int>> adj[MAX];
int dist[MAX] = {0};
int N,M,S,C,A,B,V,ans;
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
	while(true) {
		cin>>N>>M>>S>>C;
		if(!N && !M && !S && !C) break;
		fill(dist,dist+MAX,INF);
		for(int i=0;i<MAX;i++) {
		    adj[i].clear();
		}
		for(int i=0;i<M;i++) {
			cin>>A>>B>>V;
			adj[A].push_back({B,V});
		}
		ans = solve(S,C);
		cout<<ans<<"\n";
	}
    return 0;
}