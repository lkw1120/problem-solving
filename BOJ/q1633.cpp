#include<bits/stdc++.h>
using namespace std;
int dp[1001][16][16] = {0};
vector<pair<int,int>> v;
int A,B,ans;
int solve(int n, int a, int b) {
	if((a == 15 && b == 15) || n == v.size()) {
		return 0;
	}
	if(dp[n][a][b] != 0) {
		return dp[n][a][b];
	}
	int res = solve(n+1,a,b);
	if(a < 15) {
		res = max(res,solve(n+1,a+1,b)+v[n].first);
	}
	if(b < 15) {
		res = max(res,solve(n+1,a,b+1)+v[n].second);
	}
	dp[n][a][b] = res;
	return dp[n][a][b];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>A>>B) {
		v.push_back({A,B});	
	}
	ans = solve(0,0,0);
	cout<<ans<<"\n";
	return 0;	
}