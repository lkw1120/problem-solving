#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
int dp[MAX][MAX][2] = {0};
int T,N,K,ans;
void init() {
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    for(int i=2;i<MAX;i++) {
        for(int j=0;j<i;j++) {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cin>>T;
    while(T--) {
        cin>>N>>K;
        ans = dp[N][K][0] + dp[N][K][1];
        cout<<ans<<"\n";
    }
    return 0;
}