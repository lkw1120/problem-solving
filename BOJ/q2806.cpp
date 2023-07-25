#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dp[2][1000001] = {0};
string input;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>input;
	fill(&dp[0][0],&dp[1][1000001],INF);
	if(input[0] == 'A') {
		dp[0][0] = 0;
		dp[1][0] = 1;
	}
	else {
		dp[0][0] = 1;
		dp[1][0] = 0;
	}
	for(int i=1;i<N;i++) {
		if(input[i] == 'A') {
			dp[0][i] = min(dp[0][i-1],dp[1][i-1]+1);
			dp[1][i] = min(dp[0][i-1]+1,dp[1][i-1]+1);	
		}
		else {
			dp[0][i] = min(dp[0][i-1]+1,dp[1][i-1]+1);
			dp[1][i] = min(dp[0][i-1]+1,dp[1][i-1]);
		}
	}
    ans = dp[0][N-1];
	cout<<ans<<"\n";
	return 0;
}