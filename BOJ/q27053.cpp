#include<bits/stdc++.h>
using namespace std;
const int MAX = 150001;
const int INF = 1e9;
int arr[MAX];
int dp[MAX][2];
int P,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>P;
    for(int i=1;i<=P;i++) {
        cin>>arr[i];
    }
    fill(&dp[0][0],&dp[0][0]+MAX*2,-INF);
    dp[0][0] = 0;
    dp[0][1] = arr[1];
    for(int i=1;i<=P;i++) {
        dp[i][0] = max(dp[i][0],dp[i-1][0]);
        dp[i][1] = max(dp[i][1],dp[i-1][1]);
        dp[i][1] = max(dp[i][1],dp[i-1][0]+arr[i]);
        dp[i][0] = max(dp[i][0],dp[i-1][1]-arr[i]);
    }
    ans = dp[P][1];
    cout<<ans<<"\n";
    return 0;
}