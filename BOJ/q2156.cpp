#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int wine[MAX] = {0};
int dp[MAX] = {0};
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>wine[i];
    }
    dp[1] = wine[1];
    dp[2] = wine[1]+wine[2];
    for(int i=3;i<=N;i++) {
        dp[i] = max(max(dp[i-2]+wine[i],dp[i-3]+wine[i-1]+wine[i]),dp[i-1]);
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}