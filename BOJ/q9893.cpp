#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[100];
bool visited[100];
int N,M,A,B,C,ans;
int find() {
    vector<pair<int,int>> res;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});
    visited[0] = true;
    while(!q.empty()) {
        int now = q.front().first;
        int dist = q.front().second.first;
        int sum = q.front().second.second;
        q.pop();
        for(auto item: v[now]) {
            int cost = item.first;
            int next = item.second;
            if(next == 1) {
                res.push_back({dist+1,sum+cost});
            }
            if(!visited[next]) {
                visited[next] = true;
                q.push({next,{dist+1,sum+cost}});
            }
        }
    }
    sort(res.begin(),res.end());
    return res[0].second;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>M>>N;
    for(int i=0;i<N;i++) {
        cin>>A>>B>>C;
        v[A].push_back({C,B});
    }
    for(int i=0;i<M;i++) {
        sort(v[i].begin(),v[i].end());
    }
    ans = find();
    cout<<ans<<"\n";
    return 0;
}