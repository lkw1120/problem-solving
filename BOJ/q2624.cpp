#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int dp[10001][101] = {0};
int T,K,P,N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    cin>>K;
    for(int i=0;i<K;i++) {
        cin>>P>>N;
        v.push_back({P,N});
    }
    for(int i=1;i<=K;i++) {
        P = v[i-1].first;
        N = v[i-1].second;
        dp[0][i-1] = 1;
        for(int j=1;j<=N;j++) {
            for(int k=P*j;k<=T;k++) {
                dp[k][i]+=dp[k-(P*j)][i-1];
            }
        }
        for(int j=1;j<=T;j++) {
            dp[j][i] += dp[j][i-1];
        }
    }
    ans = dp[T][K];
    cout<<ans<<"\n";
    return 0;
}