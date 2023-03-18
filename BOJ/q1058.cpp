#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dp[51][51] = {0};
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        string input;
        cin>>input;
        for(int j=0;j<N;j++) {
            if(i == j) continue;
            if(input[j] == 'Y') {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = INF;
            }
        }
    }
    for(int j=0;j<N;j++) {
        for(int i=0;i<N;i++) {
            for(int k=0;k<N;k++) {
                if(i == j || i == k || j == k) continue;
                if(dp[i][j]+dp[j][k] < dp[i][k]) {
                    dp[i][k] = dp[i][j]+dp[j][k];
                }
            }
        }
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        int cnt = 0;
        for(int j=0;j<N;j++) {
            if(i == j) continue;
            if(dp[i][j] <= 2) cnt++;
        }
        ans = max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}