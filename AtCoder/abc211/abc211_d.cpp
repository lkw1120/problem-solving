#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAX = 200001;
vector<int> adj[MAX];
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
    vector<int> dist(N+1,-1);
    vector<ll> cnt(N+1,0);
    queue<int> q;
    dist[1] = 0;
    cnt[1] = 1;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next: adj[cur]) {
            if(dist[next] == -1) {
                dist[next] = dist[cur]+1;
                cnt[next] = cnt[cur];
                q.push(next);
            }
            else if(dist[next] == dist[cur]+1) {
                cnt[next]+=cnt[cur];
                cnt[next]%=MOD;
            }
        }
    }
    ans = cnt[N];
    cout<<ans<<"\n";
    return 0;
}