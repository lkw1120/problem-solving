#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 100001;
ll arr[MAX_N];
ll dp[MAX_N];
ll N,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    for(int i=2;i<=N;i++) {
        dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}