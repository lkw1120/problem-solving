#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll dp[1001];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ans = 0;
    if(N%2 == 0) {
        dp[0] = 1;
        dp[2] = 3;
        ll sum = 0;
        for(int i=4;i<=N;i+=2) {
            sum+=dp[i-4]*2;
            sum%=MOD;
            dp[i] = (dp[i-2]*3+sum)%MOD;
        }
        ans = dp[N];
    }
    cout<<ans<<"\n";
    return 0;
}