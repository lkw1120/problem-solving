#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX_W = 10001;
const int MAX_N = 501;
int arr[MAX_N][2];
int dp[MAX_W];
int T,E,F,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>E>>F>>N;
        for(int i=0;i<N;i++) {
            cin >>arr[i][0]>>arr[i][1];
        }
        int W = F-E;
        fill(dp,dp+MAX_W,INF);
        dp[0] = 0;
        for (int i=0;i<N;i++) {
            int a = arr[i][0];
            int b = arr[i][1];
            for (int j=b;j<=W;j++) {
                if (dp[j-b]+a < dp[j]) {
                    dp[j] = dp[j-b]+a;
                }
            }
        }
        ans = dp[W];
        if(INF <= ans) {
            cout<<"This is impossible."<<"\n";
        }
        else {
            cout<<"The minimum amount of money in the piggy-bank is "<<ans<<"."<<"\n";
        }
    }
    return 0;
}