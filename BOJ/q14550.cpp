#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[202];
int dp[202][202];
int N,S,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true) {
        cin>>N;
        if(!N) break;
        cin>>S>>T;
        fill(&dp[0][0],&dp[201][202],-INF);
        fill(arr,arr+202,0);
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
        }
        for(int i=1;i<=S;i++) {
            dp[i][1] = arr[i];
        }
        for(int j=2;j<=T;j++) {
            for(int i=j;i<=N+1;i++) {
                for(int k=1;k<=S;k++) {
                    if(0 < i-k) {
                        dp[i][j] = max(dp[i][j],dp[i-k][j-1]+arr[i]);
                    }
                }
            }
        }
        ans = -INF;
        for(int j=1;j<=T;j++) {
            ans = max(ans,dp[N+1][j]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}