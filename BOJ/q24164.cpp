#include<bits/stdc++.h>
using namespace std;
vector<int> v[10001];
bool visited[10001];
int N,M,A,B,ans;
void bfs(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto next: v[now]) {
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        if(!visited[i]) {
            ans++;
            bfs(i);
        }
    }
    cout<<--ans<<"\n";
    return 0;
}