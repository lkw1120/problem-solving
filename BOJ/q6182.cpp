#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int dp[101][101];
int R,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			cin>>arr[i][j];	
		}
	}
	dp[1][1] = arr[1][1];
	for(int j=2;j<=C;j++) {
		for(int i=1;i<=R;i++) {
			dp[i][j] = dp[i][j-1];
			if(i != 1) {
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
			}
			if(i != R) {
				dp[i][j] = max(dp[i][j],dp[i+1][j-1]);
			}
			if(dp[i][j]) {
				dp[i][j]+=arr[i][j];
			}
		}
	}
	ans = dp[R][C];
	cout<<ans<<"\n";
	return 0;
}