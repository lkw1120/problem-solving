#include<bits/stdc++.h>
using namespace std;
int arr[17][17] = {0};
int dp[3][17][17] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];	
		}
	}
	dp[0][1][2] = 1;
	for(int i=3;i<=N;i++) {
		if(arr[1][i]) break;
		dp[0][1][i] = dp[0][1][i-1];
	}
	for(int i=2;i<=N;i++) {
		for(int j=2;j<=N;j++) {
			if(!arr[i][j]) {
				dp[0][i][j] = dp[2][i][j-1]+dp[0][i][j-1];
				dp[1][i][j] = dp[2][i-1][j]+dp[1][i-1][j];
			}
			if(!arr[i-1][j] && !arr[i][j-1] && !arr[i][j]) {
				dp[2][i][j] = dp[0][i-1][j-1]+dp[1][i-1][j-1]+dp[2][i-1][j-1];
			}
		}
	}
	ans = dp[0][N][N]+dp[1][N][N]+dp[2][N][N];
	cout<<ans<<"\n";
	return 0;
}