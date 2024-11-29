#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v1[17],v2[17];
queue<pair<int,int>> q;
set<int> st1,st2;
int N,M,A,B,C,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B>>C>>D;
        v1[A].push_back({B,C});
        v2[A].push_back({B,D});
    }
    q.push({1,0});
    while(!q.empty()) {
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(auto [n,p]: v1[now]) {
            if(n == N) {
                st1.insert(cost+p);
            }
            q.push({n,cost+p});
        }
    }
    q.push({1,0});
    while(!q.empty()) {
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(auto [n,p]: v2[now]) {
            if(n == N) {
                st2.insert(cost+p);
            }
            q.push({n,cost+p});
        }
    }
    ans = INT_MAX;
    for(auto item: st1) {
        if(st2.count(item)) {
            ans = item;
            break;
        }
    }
    if(ans != INT_MAX) {
        cout<<ans<<"\n";
    }
    else {
        cout<<"IMPOSSIBLE"<<"\n";    
    }
    return 0;
}