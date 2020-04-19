#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int dp[MAX][MAX] = {0};
int N,M,ans;
int main() {
    string str1, str2;
    cin>>str1>>str2;
    N = str1.size();
    M = str2.size();
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
    stack<char> lcs;
    int i=N, j=M;
    while (i > 0 && j > 0) {
        if (dp[i][j] > dp[i-1][j-1] && dp[i][j] > dp[i][j-1] && dp[i][j] > dp[i-1][j]) {
            i--;
            j--;
            lcs.push(str2[j]);
        }
        else if (dp[i][j] == dp[i][j-1]) {
            j--;
        }
        else {
            i--;
        }
    }
    while(!lcs.empty()) {
        cout<<lcs.top();
        lcs.pop();
    }
    return 0;
}