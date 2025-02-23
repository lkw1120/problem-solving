#include<bits/stdc++.h>
using namespace std;
int arr[2002][2001];
int dp[2002][2001];
string str;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>str;
        for(int j=1;j<=M;j++) {
            arr[j][i] = str[j-1]-'0';
        }
    }
    ans = 0;
    for(int i=1;i<=M;i++) {
        for(int j=1;j<=N;j++) { 
            dp[i][j] = max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1])) + arr[i][j];
            ans = max(ans,dp[i][j]-arr[i][j]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}