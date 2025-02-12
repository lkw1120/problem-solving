#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string A,B;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B;
    N = A.size();
    M = B.size();
    for(int i=0;i<=N;i++) {
        dp[i][0] = i;
    }
    for(int j=0;j<=M;j++) {
        dp[0][j] = j;
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } 
            else {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
            }
        }
    }
    ans = dp[N][M];
    cout<<ans<<"\n";
    return 0;
}