#include<bits/stdc++.h>
using namespace std;
int arr[21];
int dp[10001];
int N,M,ans;
void dfs(int n, int cnt, int sum) {
    if(sum != 0 && cnt <= M) {
        dp[sum] = 1;
    }
    if(cnt < M) {
        for(int i=n;i<=N;i++) {
            dfs(i,cnt+1,sum+arr[i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    ans = 0;
    dfs(1,0,0);
    for(int i=1;i<10001;i++) {
        if(dp[i]) {
            dp[i]+=dp[i-1];
        }
        ans = max(dp[i],ans);
    }
    cout<<ans<<"\n";
    return 0;
}