#include<bits/stdc++.h>
using namespace std;
int arr[201][201];
int dp[201][201];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
            dp[i][j] = arr[i][j]+dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
        }
    }
    ans = INT_MIN;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            for(int k=0;k<i;k++) {
                for(int l=0;l<j;l++) {
                    ans = max(dp[i][j]-dp[k][j]-dp[i][l]+dp[k][l],ans);
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}