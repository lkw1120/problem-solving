#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int arr[100001];
int N,K,ans;
int score(int n) {
    int cnt = 0;
    while(n) {
        cnt+=n%2;
        n/=2;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    dp[1] = 0;
    dp[2] = score(arr[1]^arr[2]);
    dp[3] = score(arr[1]^arr[2]^arr[3]);
    dp[4] = dp[2] + score(arr[3]^arr[4]);
    for(int i=5;i<=N;i++) {
        int a = score(arr[i-1]^arr[i]);
        int b = score(arr[i-2]^arr[i-1]^arr[i]);
        dp[i] = max(dp[i-2]+a,dp[i-3]+b);
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}