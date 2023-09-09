#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 6e4+1;
int dp[101][MAX] = {0};
vector<pair<int,int>> v;
int N,H,P,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>H;
	for(int i=0;i<N;i++) {
		cin>>P>>C;
		v.push_back({P,C});
	}
	fill(&dp[0][0],&dp[100][MAX],INF);
	dp[0][0] = 0;
	for(int i=1;i<=N;i++) {
		P = v[i-1].first;
		C = v[i-1].second;
		for(int j=0;j<MAX;j++) {
			if(P <= j) {
				dp[i][j] = min(dp[i-1][j],dp[i][j-P]+C);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	ans = INF;
	for(int j=H;j<MAX;j++) {
		ans = min(ans,dp[N][j]);
	}
	cout<<ans<<"\n";
	return 0;
}