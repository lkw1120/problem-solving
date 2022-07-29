#include<bits/stdc++.h>
#define MAX 1001
#define DIV 1000000009
using namespace std;
int dp[MAX][MAX] = {0};
int T,N,M,ans;
void preload() {
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[3][1] = 1;
	dp[2][2] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;
	for(int i=4;i<MAX;i++) {
		dp[i][i] = 1;
		for(int j=2;j<i;j++) {
			dp[i][j] = (dp[i][j] + dp[i-1][j-1])%DIV;
			dp[i][j] = (dp[i][j] + dp[i-2][j-1])%DIV;
			dp[i][j] = (dp[i][j] + dp[i-3][j-1])%DIV;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	preload();
	cin>>T;
	while(T--) {
		cin>>N>>M;
		ans = dp[N][M];
		cout<<ans<<"\n";
	}
	return 0;	
}