#include<bits/stdc++.h>
using namespace std;
vector<int> v[100001];
int dist[100001];
int N,M,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>X>>Y;
        v[X].push_back(Y);
    }
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()) {
        int now = q.front().first;
        int d = q.front().second;
        q.pop();
        for(auto next: v[now]) {
            if(dist[next] == 0 || d+1 < dist[next]) {
                dist[next] = d+1;
                q.push({next,d+1});
            }
        }
    }
    ans = -1;
    if(0 < dist[N]) {
        ans = dist[N];
    }
    cout<<ans<<"\n";
    return 0;
}