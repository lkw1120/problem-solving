#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[20001];
ll dp[20001];
ll N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        dp[i] = i*K;
    }
    ll low,high;
    for(int i=1;i<=N;i++) {
        low = high = arr[i];
        for(int j=1;j<=M && i+j-1<=N;j++) {
            low = min(arr[i+j-1],low);
            high = max(arr[i+j-1],high);
            dp[i+j-1] = min(dp[i-1]+K+j*(high-low),dp[i+j-1]);
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}