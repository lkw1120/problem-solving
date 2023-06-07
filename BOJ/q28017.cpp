#include<bits/stdc++.h>
using namespace std;
int arr[501][501] = {0};
int dp[501][501] = {0};
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
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			dp[i][j] = INT_MAX;	
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			for(int k=1;k<=M;k++) {
				if(j == k) continue;
				dp[i][j] = min(dp[i][j],dp[i-1][k]+arr[i][j]);
			}
		}
	}
	ans = INT_MAX;
	for(int j=1;j<=M;j++) {
		ans = min(ans,dp[N][j]);
	}
	cout<<ans<<"\n";
	return 0;
}