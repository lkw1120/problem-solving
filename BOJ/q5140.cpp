#include<bits/stdc++.h>
using namespace std;
double arr[101][101];
double dp[101][101];
int K,N,M,B;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    for(int tc=1;tc<=K;tc++) {
        fill(&dp[0][0],&dp[0][0]+101*101,-1.0);
        cin>>N>>M>>B;
        for(int i=1;i<=N;i++) {
            for(int j=0;j<=M;j++) {
                cin>>arr[i][j];
            }
        }
        dp[0][0] = 0.0;
        for(int i=1;i<=N;i++) {
            for(int b=0;b<=B;b++) {
                if(dp[i-1][b] != -1) {
                    for(int j=0;j<=M;j++) {
                        if(B < b+j) break;
                        dp[i][b+j] = max(dp[i][b+j],dp[i-1][b]+arr[i][j]);
                    }
                }
            }
        }
        ans = 0.0;
        for(int b=0;b<=B;b++) {
            ans = max(ans,dp[N][b]);
        }
        cout<<"Data Set "<<tc<<":"<<"\n";
        cout<<fixed<<setprecision(2)<<ans<<"\n\n";
    }
    return 0;
}