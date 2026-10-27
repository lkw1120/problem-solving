#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dp[2][100001];
string input;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>input;
    fill(&dp[0][0],&dp[1][100001],INF);
    int size = input.size();
    if(input[0] == 'W') {
        dp[0][0] = 0;
        dp[1][0] = 1;
    }
    else {
        dp[0][0] = 1;
        dp[1][0] = 0;
    }
    for(int i=1;i<size;i++) {
        if(input[i] == 'W') {
            dp[0][i] = min(dp[0][i-1],dp[1][i-1]+1);
            dp[1][i] = min(dp[0][i-1]+1,dp[1][i-1]+2);
        }
        else {
            dp[0][i] = min(dp[0][i-1]+2,dp[1][i-1]+1);
            dp[1][i] = min(dp[0][i-1]+1,dp[1][i-1]);
        }
    }
    ans = min(dp[0][size-1],dp[1][size-1]);
    cout<<ans<<"\n";
    return 0;
}