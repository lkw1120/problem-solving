#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e6+1;
ll arr[MAX_N];
ll dp[MAX_N];
ll N,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>A>>B;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    fill(dp,dp+MAX_N,LONG_LONG_MAX);
    dp[0] = 0;
    ll M = LONG_LONG_MAX;
    for(int i=1;i<=N;i++) {
        M = min(M,dp[i-1]-B*arr[i-1]);
        dp[i] = (2*A+B*arr[i-1])+M;
    }
    ans = dp[N];
    if(ans%2 == 0) {
        cout<<ans/2<<"\n";
    }
    else {
        cout<<ans/2<<".5"<<"\n";
    }
}