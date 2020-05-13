#include<bits/stdc++.h>
using namespace std;
const int MAX = 16;
const int INF = 999999999;
int W[MAX][MAX] = {0};
int dp[MAX][1<<MAX] = {0};
int N,ans;
int tsp(int city,int visited) {
    if(visited == (1<<N)-1) {
        if(W[city][0] == 0) return INF;
        return W[city][0];
    }
    if(dp[city][visited] != INF) {
        return dp[city][visited];
    }
    for(int i=0;i<N;i++) {
        if(W[city][i] == 0 || (visited&1<<i)) continue;
        dp[city][visited] = min(dp[city][visited],tsp(i,(visited|1<<i))+W[city][i]);
    }
    return dp[city][visited];
}
int main() {
    ios_base::sync_with_stdio(false);
    fill(&dp[0][0],&dp[MAX-1][0]+(1<<MAX),INF);
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>W[i][j];
        }
    }
    ans = tsp(0,1);
    cout<<ans<<"\n";
    return 0;
}