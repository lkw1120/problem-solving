#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;
const int MAX_N = 500004;
ll buy[MAX_N];
vector<ll> sell[MAX_N];
ll dp[MAX_N];
ll N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>buy[i];
        int k = min(M,N-i+1);
        sell[i].resize(k+1);
        for(int j=1;j<=k;j++) {
            cin>>sell[i][j];
        }
    }
    fill(dp,dp+MAX_N,INF);
    dp[N+1] = 0;
    for(int i=N;i>=1;i--) {
        int k = min(M,N-i+1);
        for(int j=1;j<=k;j++) {
            dp[i] = min(dp[i],buy[i]-sell[i][j]+dp[i+j]);
        }
    }
    ans = dp[1];
    cout<<ans<<"\n";
    return 0;
}