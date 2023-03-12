#include<bits/stdc++.h>
using namespace std;
int weight[21] = {0};
int value[21] = {0};
int dp[201][21] = {0};
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        cin>>weight[i]>>value[i];
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(i >= weight[j]) {
                dp[i][j] = max(dp[i][j-1],dp[i-weight[j]][j-1]+value[j]);
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    ans = dp[N][M];
    cout<<ans<<"\n";
    return 0;
}