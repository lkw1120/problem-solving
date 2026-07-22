#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
bool visited[100001];
int N,M,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    int cnt = 0;
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(visited[i]) continue;
        cnt++;
        visited[i] = true;
        q.push(i);
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(auto next: adj[now]) {
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    ans = cnt-1;
    cout<<ans<<"\n";
    return 0;
}