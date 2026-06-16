#include<bits/stdc++.h>
using namespace std;
int arr[3][101];
int dp[3][101];
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(int i=1;i<=2;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=2;i++) {
		for(int j=1;j<=N;j++) {
			dp[i][j] = max(dp[i-1][j],dp[i][j-1])+arr[i][j];	
		}
	}
	ans = dp[2][N];
	cout<<ans<<"\n";
	return 0;
}