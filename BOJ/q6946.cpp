#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int club[33];
int dp[5281];
int D,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>D>>N;
    for(int i=1;i<=N;i++) {
        cin>>club[i];
    }
    fill(dp,dp+5281,INF);
    dp[0] = 0;
    for(int i=1;i<=D;i++) {
        for(int j=1;j<=N;j++) {
            if(0 <= i-club[j] && dp[i-club[j]] != INF) {
                dp[i] = min(dp[i],dp[i-club[j]]+1);
            }
        }
    }
    ans = dp[D];
    if(ans != INF) {
        cout<<"Roberta wins in "<<ans<<" strokes."<<"\n";
    }
    else {
        cout<<"Roberta acknowledges defeat."<<"\n";
    }
    return 0;
}