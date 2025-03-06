#include<bits/stdc++.h>
using namespace std;
int tmp[201];
int arr[201][3];
int dp[201][201];
int D,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>D>>N;
    for(int i=1;i<=D;i++) {
        cin>>tmp[i];
    }
    for(int i=1;i<=N;i++) {
        for(int j=0;j<3;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<=D;i++) {
        for(int j=0;j<=N;j++) {
            dp[i][j] =INT_MIN;
        }
    }
    for(int j=1;j<=N;j++) {
        if(arr[j][0] <= tmp[1] && tmp[1] <= arr[j][1]) {
            dp[1][j] = 0;
        }
    }
    for(int i=2;i<=D;i++) {
        for(int j=1;j<=N;j++) {
            if(arr[j][0] <= tmp[i] && tmp[i] <= arr[j][1]) {
                for(int k=1;k<=N;k++) {
                    if(arr[k][0] <= tmp[i-1] && tmp[i-1] <= arr[k][1]) {
                        dp[i][j] = max(dp[i][j],dp[i-1][k]+abs(arr[j][2]-arr[k][2]));
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j=1;j<=N;j++) {
        ans = max(ans,dp[D][j]);
    }
    cout<<ans<<"\n";
    return 0;
}