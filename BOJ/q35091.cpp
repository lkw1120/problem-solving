#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int check[100001];
int N,M,A,B,ans;
void bfs(int n) {
    vector<bool> visited(N+1,false);
    queue<int> q;
    q.push(n);
    visited[n] = true;
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
    for(int i=1;i<=N;i++) {
        if(visited[i]) check[i]++;
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    cin>>A>>B;
    bfs(A);
    bfs(B);
    ans = -1;
    for(int i=1;i<=N;i++) {
        if(check[i] == 2) {
            ans = i;
            break;
        }
    }
    if(ans == -1) {
        cout<<"no"<<"\n";
    }
    else {
        cout<<"yes"<<"\n";
        cout<<ans<<"\n";
    }
    return 0;
}