#include<bits/stdc++.h>
using namespace std;
int dp[22] = {0};
int T,N,ans;
void init() {
	dp[0] = dp[1] = 1;
	dp[2] = 5;
	dp[3] = 11;
	dp[4] = 36;
	for(int i=5;i<22;i++) {
		dp[i] = dp[i-1]+5*dp[i-2]+dp[i-3]-dp[i-4];	
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
		ans = dp[N];
		cout<<ans<<"\n";
	}
	return 0;
}