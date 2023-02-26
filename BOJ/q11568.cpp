#include<bits/stdc++.h>
using namespace std;
vector<int> v,dp;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(N);
    dp.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        dp[i] = 1;
        for(int j=0;j<i;j++) {
            if(v[j] < v[i]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}