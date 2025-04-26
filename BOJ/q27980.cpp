#include<bits/stdc++.h>
using namespace std;
int dp[5001][2];
string B,W;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    cin>>B>>W;
    for(int i= 0;i< N;i++) {
        dp[i][0] = W[0] == B[i]? 1: 0;
    }
    for(int i=1;i<M;i++) {
        int x = i%2;
        int y = 1-x;
        char ch = W[i];
        for(int j=0;j<N;j++) {
            int tmp = 0;
            if(0 < j) {
                tmp = max(tmp,dp[j-1][y]);
            }
            if(j+1 < N) {
                tmp = max(tmp,dp[j+1][y]);
            }
            dp[j][x] = tmp+(ch == B[j]? 1: 0);
        }
    }
    int last = (M-1)%2;
    for(int i=0;i<N;i++) {
        ans = max(dp[i][last],ans);
    }
    cout<<ans<<"\n";
    return 0;
}