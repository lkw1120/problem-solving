#include<bits/stdc++.h>
using namespace std;
int dp[1001];
int N,M,C,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>C>>D;
    for(int i=C;i<=N;i++) {
        dp[i] = max(dp[i],dp[i-C]+D);
    }
    for(int i=0;i<M;i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int tmp = a/b;
        for(int j=0;j<tmp;j++) {
            for(int k=N;k>=c;k--) {
                dp[k] = max(dp[k],dp[k-c]+d);
            }
        }
    }
    ans = 0;
    for(int i=0;i<=N;i++) {
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}