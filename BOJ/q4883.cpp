#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100001;
ll graph[MAX][3] = {0};
ll dp[MAX][3] = {0};
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(true) {
		cin>>N;
		if(N == 0) break;
		for(int i=0;i<N;i++) {
			for(int j=0;j<3;j++) {
				cin>>graph[i][j];
				dp[i][j] = INT_MAX;
			}
		}
		dp[1][0] = graph[1][0]+graph[0][1];
		dp[1][1] = graph[1][1]+min(min(dp[1][0],graph[0][1]),graph[0][1]+graph[0][2]);
		dp[1][2] = graph[1][2]+min(min(dp[1][1],graph[0][1]),graph[0][1]+graph[0][2]);
		for(int i=2;i<N;i++) {
			dp[i][0] = graph[i][0]+min(dp[i-1][0],dp[i-1][1]);
			dp[i][1] = graph[i][1]+min(min(dp[i][0],dp[i-1][0]),min(dp[i-1][1],dp[i-1][2]));
			dp[i][2] = graph[i][2]+min(min(dp[i][1],dp[i-1][1]),dp[i-1][2]);
		}
		ans = dp[N-1][1];
		cout<<++T<<". "<<ans<<"\n";
	}
	return 0;
}