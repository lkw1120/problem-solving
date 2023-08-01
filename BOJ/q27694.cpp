#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+9;
const int MAX = 1e5+1; 
ll dp[2][MAX] = {0};
ll T,N,ans;
void init() {
	dp[0][0] = dp[1][0] = 1;
	dp[0][1] = dp[1][1] = 1;
	dp[0][2] = dp[1][2] = 2;
	dp[0][3] = 3;
	dp[1][3] = 4;
	for(int i=4;i<MAX;i++) {
		dp[0][i] = (dp[0][i-1]+dp[0][i-2])%MOD;
		dp[1][i] = (dp[1][i-1]+dp[1][i-2]+dp[1][i-3]+dp[1][i-4])%MOD;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>T;
	while(T--) {
		cin>>N;
		cout<<dp[0][N]*dp[1][N]%MOD<<"\n";
	}
	return 0;
}