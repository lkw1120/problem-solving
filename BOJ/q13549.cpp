#include<bits/stdc++.h>
#define INF 99999999
#define MAX 100001
using namespace std;
int dist[MAX] = {0};
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(false);
    fill(dist,dist+MAX,INF);
    cin>>N>>K;
    priority_queue<pair<int,int>> pq;
    pq.push({0,N});
    dist[N] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int nowCost = -pq.top().first;
        pq.pop();
        if(dist[now] < nowCost) continue;
        int next, nextCost;
        if(now < MAX-1) {
            next = now+1;
            nextCost = nowCost+1;
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({-nextCost,next});
            }
        }
        if(now > 0) {
            next = now-1;
            nextCost = nowCost+1;
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({-nextCost,next});
            }
        }
        if(now*2 < MAX) {
            next = now*2;
            nextCost = nowCost;
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({-nextCost,next});
            }
        }
    }
    ans = dist[K];
    cout<<ans<<"\n";
    return 0;
}