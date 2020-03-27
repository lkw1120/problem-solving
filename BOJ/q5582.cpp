#include<bits/stdc++.h>
#define MAX 4001
using namespace std;
int dp[MAX][MAX] = {0};
int main() {
    ios_base::sync_with_stdio(false);
    string s1,s2;
    cin>>s1>>s2;
    int N,M,ans = 0;
    N = s1.size();
    M = s2.size();
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
             if (s1[i] == s2[j]) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}