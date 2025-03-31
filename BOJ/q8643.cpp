#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 500005;
int N,ans;
string str;
int dp[MAX][3];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>str;
    fill(&dp[0][0],&dp[MAX-1][3],INF);
    for(int j=0;j<3;j++) {
        dp[1][j] = (str[0] == char('A'+j))? 0: 1;
    }
    for(int i=2;i<=N;i++) {
        for(int j=0;j<3;j++) {
            int cost = (str[i-1] == char('A'+j))? 0: 1;
            for(int k=0;k<3;k++) {
                if(j == k) continue;
                dp[i][j] = min(dp[i][j],dp[i-1][k]+cost);
            }
        }
    }
    ans = min({dp[N][0],dp[N][1],dp[N][2]});
    cout<<ans<<"\n";
    return 0;
}