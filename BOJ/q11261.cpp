#include<bits/stdc++.h>
using namespace std;
int arr[2][51];
int dp[5001];
int T,N,W,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>W;
        for(int i=0;i<2;i++) {
            for(int j=1;j<=N;j++) {
                cin>>arr[i][j];
            }
        }
        fill(dp,dp+5001,0);
        for(int i=1;i<=N;i++) {
            for(int j=W;j>=0;j--) {
                if(j == 0 || dp[j]) {
                    int t = j+arr[0][i];
                    dp[t] = max(dp[t],dp[j]+arr[1][i]);
                }
            }
        }
        ans = *max_element(dp+1,dp+W+1);
        cout<<ans<<"\n";
    }
    return 0;
}