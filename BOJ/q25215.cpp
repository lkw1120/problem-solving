#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dp[3001][2];
string str;
int ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	int size = str.size();
	fill(&dp[0][0],&dp[3000][2],INF);
	if(islower(str[0])) {
		dp[1][0] = 1;
	}
	else {
		dp[1][0] = 2;
		dp[1][1] = 2;
	}
	for(int i=2;i<=size;i++) {
		if(islower(str[i-1])) {
			dp[i][0] = min(dp[i-1][0]+1,dp[i-1][1]+2);
			dp[i][1] = min(dp[i-1][0]+2,dp[i-1][1]+2);
		}
		else {
			dp[i][0] = min(dp[i-1][0]+2,dp[i-1][1]+2);
			dp[i][1] = min(dp[i-1][0]+2,dp[i-1][1]+1);
		}
	}
	ans = min(dp[size][0],dp[size][1]);
	cout<<ans<<"\n";
	return 0;
}