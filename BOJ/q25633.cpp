#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001][2];
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		dp[i][0] = arr[i];
		dp[i][1] = 1;
	}
	ans = 1;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<i;j++) {
			if(arr[i] <= dp[j][0] && dp[i][1] <= dp[j][1]+1) {
				dp[i][0] = dp[j][0]+arr[i];
				dp[i][1] = dp[j][1]+1;
			}
		}
		ans = max(ans,dp[i][1]);
	}
	cout<<ans<<"\n";
	return 0;
}