#include<bits/stdc++.h>
using namespace std;
int weight[101] = {0};
int value[101] = {0};
int dp[100001][101] = {0};
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>weight[i]>>value[i];
    }
    for(int i=1;i<=K;i++) {
        for(int j=1;j<=N;j++) {
            if(i >= weight[j]) {
                dp[i][j] = max(dp[i][j-1],dp[i-weight[j]][j-1]+value[j]);
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    ans = dp[K][N];
    cout<<ans<<"\n";
    return 0;
}