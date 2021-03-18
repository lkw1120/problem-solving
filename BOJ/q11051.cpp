#include<bits/stdc++.h>
#define MAX 1000+1
#define DIV 10007
using namespace std;
int dp[MAX][MAX];
int N, K, ans;
int main() {
    memset(dp,0,sizeof(int)*MAX*MAX);
    scanf("%d %d", &N, &K);
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2;i<=N;i++) {
        dp[i][0] = 1;
        for(int j=1;j<=i;j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%DIV;
        }
    }
    ans = dp[N][K];
    printf("%d\n",ans);
    return 0;
}