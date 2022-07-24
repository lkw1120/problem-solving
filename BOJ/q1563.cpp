#include<bits/stdc++.h>
#define DIV 1000000
#define MAX 1001
using namespace std;
int dp[MAX][2][3] = {0};
int N,ans;
void solve() {
	dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
	for(int i=2;i<=N;i++) {
		dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2])%DIV;
		dp[i][0][1] = dp[i-1][0][0]%DIV;
		dp[i][0][2] = dp[i-1][0][1]%DIV;
		dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2] + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2])%DIV;
		dp[i][1][1] = dp[i-1][1][0]%DIV;
		dp[i][1][2] = dp[i-1][1][1]%DIV;
	}
	ans = (dp[N][0][0] + dp[N][0][1] + dp[N][0][2] + dp[N][1][0] + dp[N][1][1] + dp[N][1][2])%DIV;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	ans = 0;
	solve();
	cout<<ans<<"\n";
	return 0;	
}