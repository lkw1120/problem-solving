#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dp[5001];
int arr[5001][4];
int L,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>L>>T;
    for(int i=0;i<T;i++) {
        for(int j=1;j<=3;j++) {
            cin>>arr[i][j];
        }
    }
    fill(dp,dp+5001,INF);
    dp[0] = 0;
    for(int i=0;i<T;i++) {
        for(int j=L;j>=0;j--) {
            if(dp[j] != INF) {
                for(int k=1;k<=3;k++) {
                    if(L < j+k) break;
                    dp[j+k] = min(dp[j+k],dp[j]+arr[i][k]);
                }
            }
        }
    }
    ans = dp[L];
    cout<<ans<<"\n";
    return 0;
}