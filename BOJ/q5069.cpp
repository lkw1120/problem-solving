#include<bits/stdc++.h>
using namespace std;
int dX[6] = {0,1,1,0,-1,-1};
int dY[6] = {-1,0,1,1,0,-1};
int dp[31][31][15];
int T,N,ans;
int find(int x ,int y, int n) {
    if(n == 0) {
        return (x == 15 && y == 15)? 1:0;
    }
    if(dp[x][y][n] != -1) {
        return dp[x][y][n];
    }
    int &ret = dp[x][y][n];
    ret = 0;
    for(int i=0;i<6;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
        if(0 <= dx && dx <= 30 && 0 <= dy && dy <= 30) {
            ret+=find(dx,dy,n-1);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    fill(&dp[0][0][0],&dp[30][30][15],-1);
    while(T--) {
        cin>>N;
        ans = find(15,15,N);
        cout<<ans<<"\n";
    }
    return 0;
}