#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e18;
ll dp[1001][320];
ll N,ans;
ll find(ll x, ll y) {
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    if(0 <= x-M_PI*y && x-M_PI*y <= M_PI) {
        return 1;
    }
    dp[x][y] = (find(x-1,y)%MOD + find(x,y+1)%MOD)%MOD;
    return dp[x][y];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&dp[0][0],&dp[1000][320],-1);
    cin>>N;
    ans = find(N,0);
    cout<<ans<<"\n";
    return 0;
}