#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int dp[21][101] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v1.resize(N+1);
	for(int i=1;i<=N;i++) {
		cin>>v1[i];
	}
	v2.resize(N+1);
	for(int i=1;i<=N;i++) {
		cin>>v2[i];
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		for(int j=100;j>=0;j--) {
			if(j - v1[i] >= 1) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-v1[i]]+v2[i]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;	
}