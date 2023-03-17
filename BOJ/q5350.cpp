#include<bits/stdc++.h>
using namespace std;
int T,N,W,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>W;
        vector<int> v(N),w(N),dp(W+1);
        for(int i=0;i<N;i++) {
            cin>>w[i]>>v[i];
        }
        for(int i=0;i<N;i++) {
            for(int j=W;j>=1;j--) {
                if(w[i] <= j) {
                    dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
                }
            }
        }
        ans = dp[W];
        cout<<ans<<"\n";
    }
    return 0;
}