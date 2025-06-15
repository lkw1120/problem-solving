#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int dist[10001];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(dist,dist+10001,-1);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>M;
        while(M--) {
            int a;
            cin>>a;
            adj[i].push_back(a);
        }
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto next: adj[now]) {
            if (dist[next] == -1) {
                dist[next] = dist[now]+1;
                q.push(next);
            }
        }
    }
    bool flag = true;
    ans = INT_MAX;
    for(int i=1;i<=N;i++) {
        if(dist[i] == -1) {
            flag = false;
        }
        else if(adj[i].empty()) {
            ans = min(ans,dist[i]);
        }
    }
    ans++;
    if(flag) {
        cout<<"Y"<<"\n";
    }
    else {
        cout<<"N"<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}