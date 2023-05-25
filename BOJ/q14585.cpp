#include<bits/stdc++.h>
using namespace std;
int arr[301][301] = {0};
int dp[301][301] = {0};
int N,M,X,Y,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>X>>Y;
		arr[X][Y] = M;
	}
	for(int i=0;i<=300;i++) {
		for(int j=0;j<=300;j++) {
			if(i) {
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
			}
			if(j) {
				dp[i][j] = max(dp[i][j],dp[i][j-1]);
			}
			if(arr[i][j]) {
				dp[i][j]+=max(0,M-i-j);
			}
		}
	}
	ans = dp[300][300];
	cout<<ans<<"\n";
	return 0;
}