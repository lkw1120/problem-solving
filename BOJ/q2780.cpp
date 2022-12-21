#include<bits/stdc++.h>
#define DIV 1234567
using namespace std;
int dp[1001][10] = {0};
int T,N,ans;
void preload() {
	for(int j=0;j<10;j++) {
		dp[1][j] = 1;	
	}
	for(int i=2;i<1001;i++) {
		dp[i][1] = (dp[i-1][2] + dp[i-1][4])%DIV;
		dp[i][2] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][5])%DIV;
		dp[i][3] = (dp[i-1][2] + dp[i-1][6])%DIV;
		dp[i][4] = (dp[i-1][1] + dp[i-1][5] + dp[i-1][7])%DIV;
		dp[i][5] = (dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8])%DIV;
		dp[i][6] = (dp[i-1][3] + dp[i-1][5] + dp[i-1][9])%DIV;
		dp[i][7] = (dp[i-1][4] + dp[i-1][8] + dp[i-1][0])%DIV;
		dp[i][8] = (dp[i-1][5] + dp[i-1][7] + dp[i-1][9])%DIV;
		dp[i][9] = (dp[i-1][6] + dp[i-1][8])%DIV;
		dp[i][0] = dp[i-1][7];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>T;
	while(T--) {
		cin>>N;
		ans = 0;
		for(int i=0;i<10;i++) {
			ans = (ans+dp[N][i])%DIV;
		}
		cout<<ans<<"\n";	
	}
	return 0;	
}