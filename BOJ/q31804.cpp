#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1e6+1;
int dp[MAX][2];
int A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B;
    fill(&dp[0][0],&dp[0][0]+MAX*2,INF);
    queue<pair<int,int>> q;
    q.push({A,0});
    dp[A][0] = 0;
    while(!q.empty()) {
        int a = q.front().first;
        int used = q.front().second;
        q.pop();
        if(a == B) break;
        if(a+1 <= B && dp[a][used]+1 < dp[a+1][used]) {
            dp[a+1][used] = dp[a][used]+1;
            q.push({a+1,used});
        }
        if(a*2 <= B && dp[a][used]+1 < dp[a*2][used]) {
            dp[a*2][used] = dp[a][used]+1;
            q.push({a*2,used});
        }
        if(a*10 <= B && dp[a][used]+1 < dp[a*10][1] && !used) {
            dp[a*10][1] = dp[a][used]+1;
            q.push({a*10,1});
        }
    }
    ans = min(dp[B][0],dp[B][1]);
    cout<<ans<<"\n";
    return 0;
}