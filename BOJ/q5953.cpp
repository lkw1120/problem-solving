#include<bits/stdc++.h>
using namespace std;
vector<int> v,dp;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(N);
    dp.resize(N,INT_MIN);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    dp[0] = v[0];
    for(int i=1;i<N;i++) {
        if(v[i] < dp[i-1]+v[i]) {
            dp[i] = dp[i-1]+v[i];
        }
        else {
            dp[i] = v[i];
        }
    }
    ans = INT_MIN;
    for(int i=0;i<N;i++) {
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}