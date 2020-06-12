#include<bits/stdc++.h>
using namespace std;
int dp[101][2][21] = {0};
string scroll;
string stone[2];
int N,M,ans;
int solve(int col, int row, int idx) {
    if(idx == scroll.size()) return 1;
    int& result = dp[row][col][idx];
    if(result != -1) return result;
    result = 0;
    for(int i=row;i<stone[0].size();i++) {
        if(stone[col][i] == scroll[idx]) {
            result += solve(1-col,i+1,idx+1);
        }
    }
    return result;
}
void init() {
    memset(dp,-1,sizeof(dp));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cin>>scroll;
    cin>>stone[0];
    cin>>stone[1];
    ans = solve(0,0,0)+solve(1,0,0);
    cout<<ans<<"\n";
    return 0;
}