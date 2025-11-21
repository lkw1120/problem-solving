#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> adj[1001];
bool visited[1001];
int N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<M;i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<K;i++) {
        int b,c;
        cin>>b>>c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    queue<int> q;
    for(auto item: v) {
        if(!visited[item]) {
            visited[item] = true;
            q.push(item);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next: adj[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        if(visited[i]) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}