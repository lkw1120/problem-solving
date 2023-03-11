#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<string> v;
string word;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {-1,-1,0,1,1,1,0,-1};
ll dp[201][201][101] = {0};
ll H,W,L,ans;
ll dfs(int x, int y, int d) {
    if(0 <= dp[x][y][d]) {
        return dp[x][y][d];
    }
    if(v[x][y] == word[L-1] && d == L-1) {
        return dp[x][y][d] = 1;   
    }
    dp[x][y][d] = 0;
    for(int i=0;i<8;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
        if(0 <= dx && dx < H && 0 <= dy && dy < W) {
            if(word[d+1] == v[dx][dy]) {
                dp[x][y][d]+=dfs(dx,dy,d+1);
            }
        }
    }
    return dp[x][y][d];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>H>>W>>L;
    v.resize(H);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<H;i++) {
        cin>>v[i];
    }
    cin>>word;
    ans = 0;
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            if(v[i][j] == word[0]) {
                ans+=dfs(i,j,0);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}