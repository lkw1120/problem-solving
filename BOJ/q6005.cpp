#include<bits/stdc++.h>
using namespace std;
int arr[25][25];
int dp[25][25];
int R,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R;
	for(int i=0;i<R;i++) {
		for(int j=0;j<=i;j++) {
			cin>>arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for(int i=1;i<R;i++) {
		for(int j=0;j<=i;j++) {
			if(0 < j) {
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
			dp[i][j]+=arr[i][j];
		}
	}
	ans = 0;
	for(int j=0;j<R;j++) {
		ans = max(ans,dp[R-1][j]);
	}
	cout<<ans<<"\n";
	return 0;
}