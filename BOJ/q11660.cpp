#include<bits/stdc++.h>
using namespace std;
const int MAX = 1025;
int dp[MAX][MAX] = {0};
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>dp[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            dp[i][j] = dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    while(M--) {
        ans = 0;
        int x1,y1,x2,y2;
        cin>>y1>>x1;
        cin>>y2>>x2;
        ans = dp[y2][x2]-dp[y1-1][x2]-dp[y2][x1-1]+dp[y1-1][x1-1];
        cout<<ans<<"\n";
    }
    return 0;
}