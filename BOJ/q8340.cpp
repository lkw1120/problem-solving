#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[2][101];
vector<int> adj[101];
bool check[101];
ll N,ans;
void bfs(int n) {
    queue<int> q;
    q.push(n);
    check[n] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next: adj[cur]) {
            if(!check[next]) {
                check[next] = true;
                q.push(next);
            }
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<2;i++) {
        for(int j=0;j<N;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<N;i++) {
        int a,b;
        a = arr[0][i];
        b = arr[1][i];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        if(!check[i]) {
            ans++;
            bfs(i);
        }
    }
    ans = 1LL<<ans;
    cout<<ans<<"\n";
    return 0;
}