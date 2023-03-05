#include<bits/stdc++.h>
using namespace std;
int K,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>K;
    for(int k=1;k<=K;k++) {
        cin>>N;
        vector<int> v(N+1),dp(N+1);
        for(int i=1;i<=N;i++) {
            cin>>v[i];
        }
        
        if(N == 1) { 
            ans = v[1];
        }
        else {
            dp[1] = v[1];
            dp[2] = v[2];
            ans = max(dp[1],dp[2]);
            for(int i=3;i<=N;i++) {
                dp[i] = max(dp[i-2]+v[i],dp[i-3]+v[i]);
                ans = max(ans,dp[i]);
            }
        }
        cout<<"Data Set "<<k<<":"<<"\n";
        cout<<ans<<"\n\n";
    }
    return 0;
}