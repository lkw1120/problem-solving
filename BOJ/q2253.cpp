#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX_N = 10001;
const int MAX_K = 151;
bool blocked[MAX_N];
int dp[MAX_N][MAX_K];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    fill(blocked,blocked+MAX_N,false);
    for(int i=0;i<M;i++) {
        int x;
        cin>>x;
        blocked[x] = true;
    }
    if(blocked[2]) {
        ans = -1;
    }
    else {
        fill(&dp[0][0],&dp[0][0]+MAX_N*MAX_K,INF);
        dp[2][1] = 1;
        for(int i=2;i<=N;i++) {
            for(int k=1;k<MAX_K;k++) {
                if(dp[i][k] == INF) continue;
                for(int t=-1;t<=1;t++) {
                    int nk = k+t;
                    int ni = i+nk;
                    if (nk >= 1 && nk < MAX_K && ni <= N && !blocked[ni]) {
                        dp[ni][nk] = min(dp[ni][nk],dp[i][k]+1);
                    }
                }
            }
        }
        ans = INF;
        for (int k=1;k<MAX_K;k++) {
            ans = min(ans,dp[N][k]);
        }
    }
    if(ans == INF) {
        cout<<-1<<"\n";
    }
    else {
        cout<<ans<<"\n";
    }
    return 0;
}