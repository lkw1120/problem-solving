#include<bits/stdc++.h>
using namespace std;
const int MAX = 5001;
vector<int> v;
int dp[MAX][MAX] = {0};
int N,ans;
int solve(int l, int r) {
	if(l>r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	if(v[l] == v[r]) {
		dp[l][r] = solve(l+1,r-1);
	}
	else {
		dp[l][r] = 1 + min(solve(l+1,r),solve(l,r-1));
	}
	return dp[l][r];
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&dp[0][0],&dp[MAX-1][MAX],-1);
	cin>>N;
	v = vector<int>(N);
	for(int i=0;i<N;i++) cin>>v[i];
	ans = solve(0,N-1);
	cout<<ans<<"\n";
	return 0;
}