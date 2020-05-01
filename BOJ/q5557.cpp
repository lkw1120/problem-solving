#include<bits/stdc++.h>
#define MAX 101
using namespace std;
long long dp[MAX][21] = {0};
int num[MAX] = {0};
int N,M;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>num[i];
    }
    dp[0][num[0]] = 1;
    for(int i=1;i<N-1;i++) {
        for(int j=0;j<21;j++) {
            if(j+num[i] <= 20) {
                dp[i][j+num[i]] += dp[i-1][j];
            }
            if(0 <= j-num[i]) {
                dp[i][j-num[i]] += dp[i-1][j];
            }
        }
    }
    cout<<dp[N-2][num[N-1]]<<"\n";
    return 0;
}