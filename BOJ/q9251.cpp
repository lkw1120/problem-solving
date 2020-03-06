#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int dp[MAX][MAX] = {0,};
int main() {
    ios_base::sync_with_stdio(false);
    string str1;
    string str2;
    cin>>str1>>str2;
    int N = str1.size();
    int M = str2.size();
    int ans = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(str1[i] == str2[j]) {
                dp[i+1][j+1] += dp[i][j]+1;    
            }
            else {
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=M;j++) {
            if(dp[i][j] > ans) ans = dp[i][j];
        }
    }
    cout<<ans<<"\n";
    return 0;
}