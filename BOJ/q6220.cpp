#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[1001] = {0};
int C,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    fill(dp,dp+1001,INT_MAX);
    dp[0] = 0;
    for(int i=0;i<=C;i++) {
        for(int j=0;j<N;j++) {
            if(i+v[j] <= C) {
                dp[i+v[j]] = min(dp[i]+1,dp[i+v[j]]);
            }
        }
    }
    ans = dp[C];
    cout<<ans<<"\n";
    return 0;
}