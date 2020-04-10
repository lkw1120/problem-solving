#include<bits/stdc++.h>
#define INF 99999999
#define MAX 10001
using namespace std;
int T,N,D,C,A,B,S,cnt,sec;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>T;
    while(T--) {
        priority_queue<pair<int,int>> pq;
        vector<pair<int,int>> adj[MAX];
        int dist[MAX];
        fill(dist,dist+MAX,INF);
        cin>>N>>D>>C;
        for(int i=0;i<D;i++) {
            cin>>A>>B>>S;
            adj[B].push_back({A,S});
        }
        dist[C] = 0;
        pq.push({0,C});
        cnt = 1;
        sec = 0;
        while(!pq.empty()) {
            int now = pq.top().second;
            int nowCost = -pq.top().first;
            pq.pop();
            if(dist[now] < nowCost) continue;
            for(auto i: adj[now]) {
                int next = i.first;
                int nextCost = i.second + nowCost;
                if(dist[next] > nextCost) {
                    if(dist[next] == INF) cnt++;
                    dist[next] = nextCost;
                    pq.push({-nextCost,next});   
                }
            }
        }
        for(int i=0;i<=N;i++) {
            if(dist[i] != INF) sec = max(sec,dist[i]);
        }
        cout<<cnt<<" "<<sec<<"\n";
    }
    return 0;
}