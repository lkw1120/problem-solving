#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[26][2] = {0};
int dp[26][2] = {0};
int N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<N;i++) {
		cin>>arr[i][0]>>arr[i][1];
	}
	cin>>K;
	fill(&dp[0][0],&dp[25][2],INF);
	dp[1][0] = dp[1][1] = 0;
	for(int i=1;i<N;i++) {
		dp[i+1][0] = min(dp[i+1][0],dp[i][0]+arr[i][0]);
		dp[i+2][0] = min(dp[i+2][0],dp[i][0]+arr[i][1]);
		dp[i+1][1] = min(dp[i+1][1],dp[i][1]+arr[i][0]);
		dp[i+2][1] = min(dp[i+2][1],dp[i][1]+arr[i][1]);
		dp[i+3][1] = min(dp[i+3][1],dp[i][0]+K);
	}
	ans = min(dp[N][0],dp[N][1]);
	cout<<ans<<"\n";
	return 0;
}