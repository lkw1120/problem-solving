#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
const int INF = 999999999;
vector<pair<int,int>> v[MAX];
priority_queue<pair<int,int>> pq;
stack<int> trace;
int cost[MAX] = {0};
int from[MAX] = {0};
int N,M,start,finish;
int main() {
    ios_base::sync_with_stdio(false);
    fill(cost,cost+MAX,INF);
    cin>>N>>M;
    int a,b,c;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    cin>>start>>finish;
    pq.push({0,start});
    cost[start] = 0;
    while(!pq.empty()) {   
        int nowCost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(cost[now] < nowCost) continue;
        for(auto city: v[now]) {
            int nextCost = nowCost + city.second;
            int next = city.first;
            if(cost[next] > nextCost) {
                cost[next] = nextCost;
                from[next] = now;
                pq.push({-nextCost,next});
            }
        }
    }
    int t = finish;
    while(t) {
        trace.push(t);
        t = from[t];
    }
    cout<<cost[finish]<<"\n";
    cout<<trace.size()<<"\n";
    while(!trace.empty()) {
        cout<<trace.top()<<" ";
        trace.pop();
    }
    cout<<"\n";
    return 0;
}