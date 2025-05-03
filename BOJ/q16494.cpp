#include <bits/stdc++.h>
using namespace std;
int arr[21];
int prefix[21];
int dp[21][21];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        prefix[i] = prefix[i-1]+arr[i];
    }
    for(int i=0;i<=M;i++) {
        for(int j=0;j<=N;j++) {
            dp[i][j] = (i == 0? 0: INT_MIN);
        }
    }
    for(int i=1;i<=M;i++) {
        for(int j=1;j<=N;j++) {
            dp[i][j] = dp[i][j-1];
            for(int k=1;k<=j;k++) {
                if(dp[i-1][k-1] == INT_MIN) continue; 
                int sum = prefix[j]-prefix[k-1];
                dp[i][j] = max(dp[i][j],dp[i-1][k-1]+sum);
            }
        }
    }
    ans = dp[M][N];
    cout<<ans<<"\n";
    return 0;
}