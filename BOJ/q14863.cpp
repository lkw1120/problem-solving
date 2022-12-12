#include<bits/stdc++.h>
using namespace std;
int dp[101][100001] = {0};
vector<pair<int,int>> v[2];
int N,K,a,b,c,d,n,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++) {
		cin>>a>>b>>c>>d;
		v[0].push_back({a,b});
		v[1].push_back({c,d});
	}
	dp[0][v[0][0].first] = v[0][0].second;
	dp[0][v[1][0].first] = max(dp[0][v[1][0].first],v[1][0].second);
	for(int i=1;i<N;i++) {	
		for(int j=0;j<=K;j++) {
			if(dp[i-1][j] != 0) {
				if(j+v[0][i].first <= K) {
					dp[i][j+v[0][i].first] = 
						max(dp[i][j+v[0][i].first],dp[i-1][j]+v[0][i].second);
				}
				if(j+v[1][i].first <= K) {
					dp[i][j+v[1][i].first] = 
						max(dp[i][j+v[1][i].first],dp[i-1][j]+v[1][i].second);	
				}
			}
		}
	}
	ans = -1;
	for(int i=1;i<=K;i++) {
		ans = max(ans,dp[N-1][i]);	
	}
	cout<<ans<<"\n";
	return 0;	
}