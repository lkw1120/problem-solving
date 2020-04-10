#include<bits/stdc++.h>
#define INF 99999999
#define MAX 1001
using namespace std;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> v[MAX];
int dist[MAX];
int parent[MAX];
int N,M,from,to,cost;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    fill(dist,dist+MAX,INF);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>from>>to>>cost;
        v[from].push_back({to,cost});
        v[to].push_back({from,cost});
    }
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int nowCost = pq.top().first;
        pq.pop();
        if(dist[now] < nowCost) continue;
        int size = v[now].size();
        for(int i=0;i<size;i++) {
            int next = v[now][i].first;
            int nextCost = v[now][i].second + nowCost;
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({nextCost,next});
                parent[next] = now;
            }
        }
    }
    cout<<N-1<<"\n";
    for(int i=2;i<=N;i++) {
        cout<<parent[i]<<" "<<i<<"\n";
    }
    return 0;
}