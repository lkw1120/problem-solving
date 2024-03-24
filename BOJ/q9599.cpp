#include<bits/stdc++.h>
using namespace std;
int dp[11][156];
int N,K,S,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>N>>K>>S;
        if(!N && !K && !S) break;
        fill(&dp[0][0],&dp[10][156],0);
        dp[0][0] = 1;
        for(int i=1;i<=N;i++) {
            for(int j=S;j>=0;j--) {
                for(int k=1;k<=K;k++) {
                    if(dp[k-1][j]) {
                      dp[k][j+i]+=dp[k-1][j];
                    } 
                }
            }
        }
        ans = dp[K][S];
        cout<<ans<<"\n";
    }
    return 0;
}