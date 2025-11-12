#include<bits/stdc++.h>
using namespace std;
vector<int> adj[21];
bool reach[21][21];
set<int> cycle;
int N,K,A,B,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<K;i++) {
        cin>>A>>B>>X>>Y;
        if(X < Y) {
            adj[B].push_back(A);
        }
        else {
            adj[A].push_back(B);
        }
    }
    for(int i=1;i<=N;i++) {
        queue<int> q;
        vector<bool> visited(N+1,false);
        q.push(i);
        visited[i] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int next: adj[cur]) {
                if(!visited[next]) {
                    visited[next] = true;
                    reach[i][next] = true;
                    q.push(next);
                }
            }
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(i != j && reach[i][j] && reach[j][i]) {
                cycle.insert(i);
                cycle.insert(j);
            }
        }
    }
    ans = cycle.size();
    cout<<ans<<"\n";
    return 0;
}