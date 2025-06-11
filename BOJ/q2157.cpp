#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NEG_INF = LLONG_MIN/2;
vector<pair<int,int>> adj[301];
ll dp[301][301];
ll N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<K;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        if(a < b) {
            adj[a].push_back({b,c});
        }
    }
    fill(&dp[0][0],&dp[0][0]+301*301,NEG_INF);
    dp[1][1] = 0;
    for(int i=2;i<=M;i++) {
        for(int j=1;j<=N;j++) {
            if(dp[i-1][j] == NEG_INF) continue;
            for(auto [b,c]: adj[j]) {
                dp[i][b] = max(dp[i][b],dp[i-1][j]+c);
            }
        }
    }
    ans = 0;
    for(int i=2;i<=M;i++) {
        if(dp[i][N] != NEG_INF) {
            ans = max(ans,dp[i][N]);
        }
    }
    if(ans != 0) {
        cout<<ans<<"\n";
    }
    else {
        cout<<"0"<<"\n";
    }
    return 0;
}