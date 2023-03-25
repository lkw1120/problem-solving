#include<bits/stdc++.h>
using namespace std;
vector<int> w,v;
int dp[12881] = {0};
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    w.resize(N);
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>w[i]>>v[i];
    }
    for(int i=0;i<N;i++) {
        for(int j=M;j>=w[i];j--) {
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    ans = dp[M];
    cout<<ans<<"\n";
    return 0;
}