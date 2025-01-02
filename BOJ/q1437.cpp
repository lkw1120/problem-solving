#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
const int MOD = 10007;
int dp[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for(int i=5;i<=N;i++) {
        dp[i] = (dp[i-3]*3)%MOD;
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}