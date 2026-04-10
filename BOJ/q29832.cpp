#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
const int MAX_N = 100001;
vector<ll> M,K,R;
ll dp[MAX_N][2];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    M.resize(N+1);
    K.resize(N+1);
    R.resize(N+1);
    for(int i=1;i<=N;i++) {
        cin>>M[i]>>K[i];
        R[i] = M[i]-K[i]+1;
    }
    fill(&dp[0][0],&dp[0][0]+MAX_N*2,INF);
    dp[1][0] = llabs(1LL-K[1]);
    dp[1][1] = 1LL+R[1];
    for(int i=2;i<=N;i++) {
        dp[i][0] = min(
            dp[i-1][0]+llabs(K[i-1]-K[i]),
            dp[i-1][1]+llabs(R[i-1]-K[i])
        );
        dp[i][1] = min(
            dp[i-1][0]+K[i-1]+R[i],
            dp[i-1][1]+R[i-1]+R[i]
        );
    }
    ans = min(dp[N][0],dp[N][1]);
    cout<<ans<<"\n";
    return 0;
}