#include<bits/stdc++.h>
#define INF 99999999
#define MAX 50001
using namespace std;
vector<pair<int,int>> v[MAX];
priority_queue<pair<int,int>> pq;
int dist[MAX] = {0};
int N,M,a,b,c,ans;
int main() {
    ios_base::sync_with_stdio(false);
    fill(dist,dist+MAX,INF);
	cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int nowCost = -pq.top().first;
        pq.pop();
        for(auto node : v[now]) {
            int next = node.first;
            int nextCost = node.second + nowCost;
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({-nextCost,next});
            }
        }
    }
    ans = dist[N];
	cout<<ans<<"\n";
    return 0;
}