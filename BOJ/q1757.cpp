#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 10001;
const int MAX_M = 501;
const int INF = -987654321;
int arr[MAX_N];
int dp[MAX_N][MAX_M][2];
int N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=M;j++) {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    dp[0][0][0] = 0;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<=M;j++) {
            for(int k=0;k<2;k++) {
                int tmp = dp[i-1][j][k];
                if(tmp <= INF) continue;
                int x = 0 < j? j-1: 0;
                int y = 0 < x? 1: 0;
                dp[i][x][y] = max(dp[i][x][y],tmp);
                if(k == 0 && j+1 <= M) {
                    dp[i][j+1][0] = max(dp[i][j+1][0],tmp+arr[i]);
                }
            }
        }
    }
    cout<<dp[N][0][0]<<"\n";
    return 0;
}