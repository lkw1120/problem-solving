#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
int dp[MAX][2]= {0};
string stones;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	cin>>stones;
	if(stones[0] == '.') {
		dp[0][0] = 0;
		dp[0][1] = 1;
	}
	else {
		dp[0][0] = 1;
		dp[0][1] = 0;
	}
	for(int i=1;i<N;i++) {
		if(stones[i] == '.') {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = min(dp[i-1][0]+1,dp[i-1][1]+1);
		}
		else {
			dp[i][0] = dp[i-1][0]+1;
			dp[i][1] = min(dp[i-1][0],dp[i-1][1]);
		}
	}
	ans = min(dp[N-1][0],dp[N-1][1]);
	cout<<ans<<"\n";
	return 0;
}