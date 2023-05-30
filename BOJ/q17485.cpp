#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dp[1002][1002][3] = {0};
int arr[1002][1002] = {0};
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];	
		}
	}
	fill(&dp[0][0][0],&dp[1001][1001][3],INF);
	for(int j=1;j<=M;j++) {
		for(int k=0;k<3;k++) {
			dp[1][j][k] = arr[1][j];
		}
	}
	for(int i=2;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			dp[i][j][0] = min(dp[i-1][j+1][1],dp[i-1][j+1][2])+arr[i][j];
			dp[i][j][1] = min(dp[i-1][j][0],dp[i-1][j][2])+arr[i][j];
			dp[i][j][2] = min(dp[i-1][j-1][0],dp[i-1][j-1][1])+arr[i][j];
		}
	}
	ans = INF;
	for(int j=1;j<=M;j++) {
		for(int k=0;k<3;k++) {
			ans = min(dp[N][j][k],ans);
		}
	}
	cout<<ans<<"\n";
	return 0;
}