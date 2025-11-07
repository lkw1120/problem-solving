#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5+1;
bool sp[MAX_N];
vector<int> adj[MAX_N];
bool visited[MAX_N];
int N,M,S,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>S;
    sp[1] = sp[N] = true;
    if(2 < S) {
        for(int i=0;i<S-2;i++) {
            int x;
            cin>>x;
            sp[x] = true;
        }
    }
    for(int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    visited[1] = true;
    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == N) {
            ans = cnt;
            break;
        }
        for(auto next: adj[cur]) {
            if(!visited[next] && sp[next]) {
                visited[next] = true;
                q.push({next,cnt+1});
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}