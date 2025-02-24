#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+1;
ll arr[MAX];
ll dp[MAX];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ll sum = 0;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[2];
    for(int i=3;i<=N;i++) {
        dp[i] = max(dp[i-2],dp[i-3])+arr[i];
    }
    ans = sum-max(dp[N],dp[N-1]);
    cout<<ans<<"\n";
    return 0;
}