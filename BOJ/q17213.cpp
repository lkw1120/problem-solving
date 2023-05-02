#include<bits/stdc++.h>
using namespace std;
int dp[11][31] = {0};
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
    for(int i=1;i<=M;i++) {
		dp[1][i] = 1;
    }
    for(int i=1;i<=N;i++) {
		dp[i][i] = 1;
    }
	for(int i=2;i<=N;i++) {
		for(int j=i;j<=M;j++) {
			dp[i][j] = dp[i][j-1]+dp[i-1][j-1];	
		}
	}
	ans = dp[N][M];
	cout<<ans<<"\n";
	return 0;
}