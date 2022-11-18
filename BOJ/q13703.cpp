#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[64][128] = {0};
ll K,N,ans;
void solve() {
	dp[1][K+1] = dp[1][K-1] = 1;
	for(int i=2;i<=N;i++) {
		for(int j=1;j<128;j++) {
			if(1 < j && j < 127) {
				dp[i][j] = dp[i-1][j-1]+dp[i-1][j+1];
			}
			else if(j == 1) {
				dp[i][j] = dp[i-1][j+1];
			}
			else if(j == 127) {
				dp[i][j] = dp[i-1][j-1];	
			}
		}
	}
	for(int j=1;j<128;j++) {
		ans+=dp[N][j];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>K>>N;
	ans = 0;
	if(0 < K) {
		solve();
	}
	cout<<ans<<"\n";
	return 0;	
}