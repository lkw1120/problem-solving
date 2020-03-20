#include<bits/stdc++.h>
#define MAX 16
using namespace std;
int matrix[MAX][MAX] = {};
int dp[MAX][MAX] = {};
int N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M>>K;
    int cnt = 1, x = 0, y = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(cnt == K) {
                x = i, y = j;
            }
            matrix[i][j] = cnt;
            cnt++;
        }
    }
    dp[1][1] = 1;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if((i == x && j > y) || (i > x && j == y)) {
                dp[i][j] = dp[x][y];
            }
            else {
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
            }
        }
    }
    ans = dp[N][M];
    cout<<ans<<"\n";
    return 0;
}