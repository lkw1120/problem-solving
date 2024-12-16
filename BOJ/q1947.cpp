#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9;
const ll MAX = 1e6+1;
ll dp[MAX];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    dp[0] = 1;
    dp[1] = 0;
    for(int i=2;i<=N;i++) {
        dp[i] = (i-1)*(dp[i-1]+dp[i-2])%MOD;
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}