#include<bits/stdc++.h>
#define DIV 1000000003
#define MAX 1001
using namespace std;
typedef long long ll;
ll dp[MAX][MAX] = {0};
ll N,K,ans;
void init() {
    for(int i=1;i<=3;i++) {
        dp[i][1] = i;
    }
    for(int i=4;i<MAX;i++) {
        int M = i/2;
        for (int j=1;j<=M;j++) {
            if (j == 1) {
                dp[i][j] = i;
            }
            else {
                dp[i][j] = (dp[i-2][j-1] + dp[i-1][j])%DIV;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    init();
    cin>>N>>K;
    ans = dp[N][K];
    cout<<ans<<"\n";
    return 0;
}