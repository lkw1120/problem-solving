#include<bits/stdc++.h>
using namespace std;
int arr[101][2];
double dp[101][2];
int N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    dp[0][0] = 100.0;
    dp[0][1] = 0.0;
    for(int i=1;i<=N;i++) {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]/arr[i][1]*100);
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]*arr[i][0]/100);
    }
    ans = dp[N][0];
    cout.precision(2);
    cout<<fixed;
    cout<<ans<<"\n";
    return 0;
}