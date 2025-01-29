#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[101];
ll L,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>L>>K;
    dp[1] = dp[K] = 1;
    for(int i=2;i<=L;i++) {
        dp[i]+=dp[i-2];
        if(K < i) {
            dp[i]+=dp[i-K-1];
        }
    }
    ans = 0;
    for(int i=1;i<=L;i++) {
        ans+=dp[i];
    }
    cout<<ans<<"\n";
    return 0;
}