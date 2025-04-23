#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[32];
ll prefix[32];
ll N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    dp[0] = 1;
    for(int i=1;i<=M;i++) {
        prefix[0] = dp[0];
        for(int j=1;j<=N;j++) {
            prefix[j] = prefix[j-1]+dp[j];
        }
        for(int j=0;j<=N;j++) {
            ll tmp = prefix[j];
            if(0 <= j-K-1) {
                tmp-=prefix[j-K-1];
            }
            dp[j] = tmp;
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}