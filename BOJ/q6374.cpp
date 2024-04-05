#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int dp[101][101];
int N,ans;
void find(int x, int y) {
    for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++) {
            ans = max(ans,dp[x][y]-dp[i][y]-dp[x][j]+dp[i][j]);
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
        }
    }
    ans = INT_MIN;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            find(i,j);
        }
    }
    cout<<ans<<"\n";
    return 0;
}