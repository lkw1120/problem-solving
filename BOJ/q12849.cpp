#include<bits/stdc++.h>
#define DIV 1000000007
using namespace std;
int campus[8][8] = {
    {0,1,1,0,0,0,0,0},
    {1,0,1,1,0,0,0,0},
    {1,1,0,1,1,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,1,1,0,1,0,1},
    {0,0,0,1,1,0,1,0},
    {0,0,0,0,0,1,0,1},
    {0,0,0,0,1,0,1,0}
};
int dp[100001][8] = {0};
int D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>D;
    dp[1][1] = dp[1][2] = 1;
    for(int i=2;i<=D;i++) {
        for(int j=0;j<8;j++) {
            if(dp[i-1][j]) {
                for(int k=0;k<8;k++) {
                    if(campus[j][k]) {
                        dp[i][k]=(dp[i][k]+dp[i-1][j])%DIV;
                    }
                }
            }
        }
    }
    ans = dp[D][0];
    cout<<ans<<"\n";
    return 0;
}