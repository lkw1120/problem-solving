#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[1000001] = {0};
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ans = 0;
    for(int i=0;i<6;i++) {
        dp[i] = i;
    }
    for(int i=6;i<=N;i++) {
        dp[i] = 1+dp[i-2]+dp[i-3]-dp[i-5];
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}