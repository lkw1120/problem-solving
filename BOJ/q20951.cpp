#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int MAX_N = 1e5+1;
ll dp[MAX_N][2];
ll N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    vector<vector<int>> adj(N+1);
    for(int i=0;i<M;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<=N;i++) {
        dp[i][0] = 1L;
        dp[i][1] = 0L;
    }
    for(int d=1;d<=7;d++) {
        for(int i=1;i<=N;i++) {
            dp[i][1] = 0;
            for(int j: adj[i]) {
                dp[i][1] = (dp[i][1]+dp[j][0])%MOD;
            }
        }
        for(int i=0;i<=N;i++) {
            swap(dp[i][0],dp[i][1]);
        }
    }
    for(int i=1;i<=N;i++) {
        ans = (ans+dp[i][0])%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}