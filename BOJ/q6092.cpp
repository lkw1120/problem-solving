#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[13];
int dp[13];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=12;i++) {
        arr[i] = 2*arr[i-1]+1;
    }
    dp[1] = 1;
    for(int i=2;i<=12;i++) {
        dp[i] = INF;
        for(int j=1;j<=i;j++) {
            dp[i] = min(dp[i],arr[j]+2*dp[i-j]);
        }
    }
    for(int i=1;i<=12;i++) {
        cout<<dp[i]<<"\n";
    }
    return 0;
}