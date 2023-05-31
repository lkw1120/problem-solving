#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> c,d;
int dp[1001][1001] = {0};
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	d.resize(N+1);
	c.resize(M+1);
	for(int i=1;i<=N;i++) {
		cin>>d[i];	
	}
	for(int i=1;i<=M;i++) {
		cin>>c[i];
	}
	fill(&dp[1][0],&dp[1000][1001],INF);
	for(int i=1;i<=N;i++) {
		for(int j=i;j+(N-i)<=M;j++) {
			dp[i][j] = min(dp[i-1][j-1]+d[i]*c[j],dp[i][j-1]);
		}
	}
	ans = INF;
	for(int j=1;j<=M;j++) {
		ans = min(dp[N][j],ans);
	}
	cout<<ans<<"\n";
	return 0;
}