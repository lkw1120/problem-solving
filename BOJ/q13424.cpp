#include<bits/stdc++.h>
#define INF 99999999
#define N_MAX 101
#define M_MAX 5051
using namespace std;
int T,N,M,K,a,b,c,k,sum,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>T;
    while(T--) {
        priority_queue<pair<int,int>> pq;
        vector<pair<int,int>> v[N_MAX];
        vector<int> room;
        int dist[M_MAX];
        cin>>N>>M;
        for(int i=0;i<M;i++) {
            cin>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        cin>>K;
        for(int i=0;i<K;i++) {
            cin>>k;
            room.push_back(k);
        }
        sum = INF;
        for(int i=1;i<=N;i++) {
            fill(dist,dist+M_MAX,INF);
            pq.push({0,i});
            dist[i] = 0;
            while(!pq.empty()) {
                int now = pq.top().second;
                int nowCost = -pq.top().first;
                pq.pop();
                if(dist[now] < nowCost) {
                    continue;
                }
                for(auto node : v[now]) {
                    int next = node.first;
                    int nextCost = nowCost + node.second;
                    if(dist[next] > nextCost) {
                        dist[next] = nextCost;
                        pq.push({-nextCost,next});
                    }
                }
            }
            int d = 0;
            for(auto n : room) {
                d+=dist[n];
            }
            if(sum > d) {
                sum = d;
                ans = i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}