#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v,dp;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    v.resize(N);
    dp.resize(N);
    for(int i=0;i<M;i++) {
        v[i].resize(N+1);
        dp[i].resize(N+1);
        for(int j=1;j<=N;j++) {
            cin>>v[i][j];
        }
    }
    for(int i=0;i<M;i++) {
        dp[i][1] = v[i][1];
    }
    for(int j=2;j<=N;j++) {
        for(int i=0;i<M;i++) {
            dp[i][j] = dp[i][j-1]+v[i][j]/2;
            for(int k=0;k<M;k++) {
                if(i == k) continue;
                dp[i][j] = max(dp[i][j],dp[k][j-1]+v[i][j]);
            }
        }
    }
    ans = 0;
    for(int i=0;i<M;i++) {
        ans = max(ans,dp[i][N]);
    }
    cout<<ans<<"\n";
    return 0;
}