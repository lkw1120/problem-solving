#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX = 1000001;
int dp[MAX][4];
int A,B,C,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(&dp[0][0],&dp[0][0]+MAX*4,INF);
    cin>>A>>B>>C>>K;
    dp[0][0] = 0;
    for(int i=0;i<=K;i++) {
        for(int j=0;j<4;j++) {
            if(dp[i][j] == INF) continue;
            int cur = dp[i][j];
            if(i+A <= K) {
                int tmp = (j+3)%4;
                dp[i+A][tmp] = min(dp[i+A][tmp],cur+1);
            }
            if(i+B <= K) {
                int tmp = (j+1)%4;
                dp[i+B][tmp] = min(dp[i+B][tmp],cur+1);
            }
            if(i+C <= K) {
                int tmp = (j+2)%4;
                dp[i+C][tmp] = min(dp[i+C][tmp],cur+1);
            }
        }
    }
    ans = dp[K][0];
    if(ans == INF) {
        ans = -1;
    }
    cout<<ans<<"\n";
    return 0;
}