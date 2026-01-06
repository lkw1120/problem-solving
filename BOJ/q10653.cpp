#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int x[501];
int y[501];
int dp[501][501];
int N,K,ans;
int dist(int a, int b) {
 return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>x[i]>>y[i];
    }
    fill(&dp[0][0],&dp[0][0]+501*501,INF);
    dp[0][0] = 0;
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            int tmp = i-j-1;
            if(K < tmp) continue;
            int d = dist(j,i);
            for(int k=tmp;k<=K;k++) {
                if(dp[j][k-tmp] == INF) continue;
                dp[i][k] = min(dp[i][k],dp[j][k-tmp]+d);
            }
        }
    }
    ans = INF;
    for(int k=0;k<=K;k++) {
        ans = min(ans,dp[N-1][k]);
    }
    cout<<ans<<"\n";
    return 0;
}