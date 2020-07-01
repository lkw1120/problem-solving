#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int dp[MAX][3] = {0};
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<3;j++) {
            cin>>dp[i][j];
        }
    }
    for(int i=1;i<N;i++) {
        dp[i][0] += min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0],dp[i-1][1]);
    }
    ans = min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]));
    cout<<ans<<"\n";
    return 0;
}