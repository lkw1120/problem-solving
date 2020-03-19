#include<bits/stdc++.h>
#define MAX 201
#define DIV 1000000000
using namespace std;
int dp[MAX][MAX] = {0};
int N,K,ans;
int main() {
	ios_base::sync_with_stdio(false);
    cin>>N>>K;
    for(int i=0;i<=N;i++) {
        dp[1][i] = 1;
    }
    for(int k=1;k<=K;k++) {
        for(int i=0;i<=N;i++) {
            for(int j=0;j<=i;j++) {
                dp[k][i] = (dp[k][i]+dp[k-1][i-j])%DIV;
            }
        }
    }
    ans = dp[K][N];
    cout<<ans<<"\n";
	return 0;
}