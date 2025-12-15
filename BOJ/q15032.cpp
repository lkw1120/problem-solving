#include <bits/stdc++.h>
using namespace std;
double dp[401][401];
int N,K;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int j=0;j<=N;j++) {
        dp[0][j] = (double)j;
    }
    for(int i=1;i<=K;i++) {
        for(int j=0;j<=N;j++) {
            double tmp = -1e18;
            if(j < N) {
                tmp = max(tmp,0.5*dp[i-1][j]+0.5*dp[i-1][j+1]);
            }
            if(0 < j) {
                tmp = max(tmp,0.5*dp[i-1][j]+0.5*dp[i-1][j-1]);
            }
            dp[i][j] = tmp;
        }
    }
    ans = dp[K][0];
    cout<<fixed<<setprecision(9)<<ans<<"\n";
    return 0;
}