#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int arr[MAX][3] = {0};
int dp[MAX][3] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		for(int j=0;j<3;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = INT_MAX;
	for(int k=0;k<3;k++) {
		fill(&dp[0][0],&dp[1000][3],MAX);
		dp[1][k] = arr[1][k];
		for(int i=2;i<=N;i++){
			dp[i][0] = min(dp[i-1][1],dp[i-1][2])+arr[i][0];
			dp[i][1] = min(dp[i-1][0],dp[i-1][2])+arr[i][1];
			dp[i][2] = min(dp[i-1][1],dp[i-1][0])+arr[i][2];
		}
		for(int j=0;j<3;j++) {
			if(k == j) continue;
			ans = min(ans,dp[N][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}