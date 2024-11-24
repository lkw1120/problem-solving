#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[31][3];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    dp[1][0] = -1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i=2;i<=N;i++) {
        dp[i][0] = dp[i-1][0]-dp[i-1][2];
        dp[i][1] = dp[i-1][1]+dp[i-1][2];
        dp[i][2] = 2*dp[i-1][0]-2*dp[i-1][1]+dp[i-1][2];
    }
    ans = dp[N][0]+dp[N][1]+dp[N][2];
    cout<<ans<<"\n";
    return 0;
}