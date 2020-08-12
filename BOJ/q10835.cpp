#include<bits/stdc++.h>
using namespace std;
const int MAX = 2001;
vector<int> v1,v2;
int dp[MAX][MAX] = {0};
int N,ans;
int solve(int i, int j){
	if(N <= i || N <= j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = max(solve(i+1, j),solve(i+1, j+1));
	if(v1[i] > v2[j]) {
		dp[i][j] = max(dp[i][j], solve(i, j+1)+v2[j]);
	}
	return dp[i][j];
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&dp[0][0],&dp[MAX-1][MAX],-1);
	cin>>N;
	v1 = vector<int>(N);
	v2 = vector<int>(N);
	for(int i=0;i<N;i++) cin>>v1[i];
	for(int i=0;i<N;i++) cin>>v2[i];
	ans = solve(0,0);
	cout<<ans<<"\n";
	return 0;
}