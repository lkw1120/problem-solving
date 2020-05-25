#include<bits/stdc++.h>
using namespace std;
const int MAX = 500;
const int INF = 99999999;
int adj[MAX][MAX] = {0};
int dist[MAX] = {0};
vector<int> trace[MAX];
int N,M,S,D,U,V,P,ans;
int dijkstra() {
    fill(dist,dist+MAX,INF);
    for(int i=0;i<N;i++) {
        trace[i].clear();
    }
    priority_queue<pair<int,int>> pq;
    pq.push({0,S});
    dist[S] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int nowDist = -pq.top().first;
        pq.pop();
        if(nowDist > dist[now]) continue;
        for(int i=0;i<N;i++) {
            if(adj[now][i] != 0) {
                int next = i;
                int nextDist = nowDist + adj[now][i];
                if(dist[next] > nextDist) {
                    dist[next] = nextDist;
                    pq.push({-nextDist,next});
                }
                if(dist[next] >= nextDist) {
                    trace[next].push_back(now);
                }
            }
        }
    }
    return dist[D] == INF? -1: dist[D];
}
void remove() {
    queue<int> q;
    q.push(D);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto pre: trace[now]) {
            if(adj[pre][now]!=0 && dist[now] == adj[pre][now] + dist[pre]) {
                q.push(pre);
                adj[pre][now] = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true) {
        fill(&adj[0][0],&adj[MAX-1][0]+MAX,0);
        cin>>N>>M;
        if(N == 0 && M == 0) break;
        cin>>S>>D;
        for(int i=0;i<M;i++) {
            cin>>U>>V>>P;
            adj[U][V] = P;
        }
        int sp = dijkstra();
        ans = sp;
        while(sp == ans && ans != -1) {
            remove();
            ans = dijkstra();
        }
        cout<<ans<<"\n";
    }
    return 0;
}