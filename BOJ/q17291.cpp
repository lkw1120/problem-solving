#include<bits/stdc++.h>
using namespace std;
int dp[21] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	dp[0] = dp[1] = 1;
	for(int i=2;i<=20;i++) {
		dp[i] = dp[i-1]*2;
		if(3 < i && (i-3)%2 == 1) {
			dp[i]-=dp[i-4];
		}
		if(4 < i && (i-4)%2 == 0) {
			dp[i]-=dp[i-5];
		}
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;
}