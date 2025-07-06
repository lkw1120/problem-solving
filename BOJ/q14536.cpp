#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
vector<pair<int,int>> v;
int dp[201];
int T,N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        v.clear();
        int sum = 0;
        for(int i=0;i<N;i++) {
            int t,w;
            cin>>t>>w;
            v.push_back({t,w});
            sum+=w;
        }
        M = 2*N;
        fill(dp,dp+201,-1*INF);
        dp[0] = 0;
        for(auto [t,w]: v) {
            for(int i=M;i>=t;i--) {
                dp[i] = max(dp[i],dp[i-t]+w);
            }
        }
        ans = M;
        for(int i=0;i<=M;i++) {
            if(0 <= dp[i] && sum <= dp[i]+i) {
                ans = i;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}