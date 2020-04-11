#include<bits/stdc++.h>
#define INF 99999999
#define MAX 201
using namespace std;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> adj[MAX];
int cost[MAX];
int N,M,x,y,z;
int ans[MAX][MAX] = {0};
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    for(int i=1;i<=N;i++) {    
        fill(cost,cost+MAX,INF);
        pq.push({0,i});
        cost[i] = 0;
        while(!pq.empty()) {
            int now = pq.top().second;
            int nowCost = -pq.top().first;
            pq.pop();
            if(cost[now] < nowCost) continue;
            for(auto node : adj[now]) {
                int next = node.first;
                int nextCost = node.second + nowCost;
                if(cost[next] > nextCost) {
                    cost[next] = nextCost;
                    ans[next][i] = now;
                    pq.push({-nextCost,next});
                }
            }
        }
        
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(i!=j) {
                cout<<ans[i][j]<<" ";
            }
            else {
                cout<<"-"<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}