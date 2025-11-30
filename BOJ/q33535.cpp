#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int dp[10001];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(dp,dp+10001,-1);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        int p,h;
        cin>>p>>h;
        v.push_back({p,h});
    }
    dp[0] = 0;
    for(auto [p,h]: v) {
        for(int i=M-p;i>=0;i--) {
            if(dp[i] != -1) {
                dp[i+p] = max(dp[i+p],dp[i]+h);
            }
        }
    }
    ans = *max_element(dp,dp+M+1);
    cout<<ans<<"\n";
    return 0;
}