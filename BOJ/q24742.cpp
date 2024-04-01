#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000007;
const int MAX = 40001;
ll dp[MAX];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    dp[0] = dp[1] = dp[2] = 1;
    for(int i=3;i<=N;i++) {
        dp[i] = (dp[i-1]+dp[i-2])%MOD;
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}