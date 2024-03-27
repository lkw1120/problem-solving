#include<bits/stdc++.h>
using namespace std;
bool cat[26][26];
int dp[26][26];
int R,C,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>R>>C;
    cin>>K;
    for(int i=0;i<K;i++) {
        int r,c;
        cin>>r>>c;
        cat[r][c] = true;
    }
    dp[1][1] = 1;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            if(cat[i][j]) continue;
            dp[i][j]+=dp[i][j-1]+dp[i-1][j];
        }
    }
    ans = dp[R][C];
    cout<<ans<<"\n";
    return 0;
}