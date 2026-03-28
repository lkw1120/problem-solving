#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[41];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    dp[1] = 1;
    if(N >= 2) dp[2] = 3;
    for(int i=3;i<=N;i++) {
        dp[i] = dp[i-1]+dp[i-2]+1;
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}