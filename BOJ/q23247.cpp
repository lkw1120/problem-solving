#include<bits/stdc++.h>
using namespace std;
int dp[301][301] = {0};
int arr[301][301] = {0};
int N,M,ans;
void find(int n, int m) {
	for(int i=n-1;i>=0;i--) {
		for(int j=m-1;j>=0;j--) {
			int sect = dp[n][m]-dp[i][m]-dp[n][j]+dp[i][j];
			if(sect == 10) ans++;
			if(10 <= sect) break;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];
			dp[i][j] = arr[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			find(i,j);
		}
	}
	cout<<ans<<"\n";
	return 0;
}