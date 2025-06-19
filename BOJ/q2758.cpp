#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 11;
const int MAX_M = 2001;
ll dp[MAX_N][MAX_M];
ll ps[MAX_M];
ll T,N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>M;
        fill(&dp[0][0],&dp[0][0]+MAX_N*MAX_M,0);
        for(int j=1;j<=M;j++) {
            dp[1][j] = 1;
        }
        for(int i=2;i<=N;i++) {
            ps[0] = 0;
            for(int j=1;j<=M;j++) {
                ps[j] = ps[j-1]+dp[i-1][j];
            }
            for(int j=1;j<=M;j++) {
                dp[i][j] = ps[j/2];
            }
        }
        ans = 0;
        for(int j=1;j<=M;j++) {
            ans+=dp[N][j];
        }
        cout<<ans<<"\n";
    }
    return 0;
}