#include<bits/stdc++.h>
using namespace std;
int dp[100001] = {0};
int N,K,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    ans = 0;
    if(0 < K) {
        while(N--) {
            cin>>C;
            for(int i=K;i>=0;i--) {
                if(dp[i] || i == 0) {
                    dp[i+C] = dp[i+C] == 0? dp[i]+1: min(dp[i+C],dp[i]+1);
                }
            }
        }
        ans = dp[K] == 0? -1: dp[K];
    }
    cout<<ans<<"\n";
    return 0;
}