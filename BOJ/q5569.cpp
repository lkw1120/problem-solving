#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
const int MOD = 100000;
int dp[MAX][MAX][2][2] = {0};
int W,H,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>W>>H;
	for(int i=2;i<MAX;i++) {
		dp[i][1][0][0] = 1;
		dp[1][i][1][0] = 1;
	}
	for(int i=2;i<MAX;i++){
		for(int j=2;j<MAX;j++){
			dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][0][1])%MOD;
			dp[i][j][0][1] = dp[i-1][j][1][0];
			dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1])%MOD;
			dp[i][j][1][1] = dp[i][j-1][0][0];
		}
	}
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			ans = (ans+dp[W][H][i][j])%MOD;
		}
	}
	cout<<ans<<"\n";
	return 0;
}