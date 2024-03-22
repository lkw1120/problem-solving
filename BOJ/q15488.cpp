#include<bits/stdc++.h>
using namespace std;
double dp[51][51][51];
int dX[8] = {1,2,2,1,-1,-2,-2,-1};
int dY[8] = {2,1,-1,-2,-2,-1,1,2};
int N,X,Y,K;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>X>>Y>>K;
    dp[0][X][Y] = 1;
    for(int k=1;k<=K;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                for(int t=0;t<8;t++) {
                    int dx = i+dX[t];
                    int dy = j+dY[t];
                    if(0 < dx && dx <= N && 0 < dy && dy <= N) {
                        dp[k][dx][dy]+=dp[k-1][i][j]/8;
                    }
                }
            }
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            ans+=dp[K][i][j];
        }
    }
    cout.precision(10);
    cout<<fixed;
    cout<<ans<<"\n";
    return 0;
}