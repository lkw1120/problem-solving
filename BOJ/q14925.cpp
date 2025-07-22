#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int M,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N;
    ans = 0;
    for(int i=1;i<=M;i++) {
        for(int j=1;j<=N;j++) {
            int x;
            cin>>x;
            if(x == 0) {
                dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                ans = max(dp[i][j],ans);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}