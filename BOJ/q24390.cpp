#include<bits/stdc++.h>
using namespace std;
int dp[3601] = {0};
string input;
int N,ans;
void solve(int n, bool flag) {
	if(n == N) {
		if(!flag) dp[n]++;
		return ;
	}
	if(n+10 <= N) {
		if(dp[n]+1 < dp[n+10]) {
			dp[n+10] = dp[n]+1;
			solve(n+10,flag);
		}
	}
	if(n+60 <= N) { 
		if(dp[n]+1 < dp[n+60]) {
			dp[n+60] = dp[n]+1;
			solve(n+60,flag);
		}
	}
	if(n+600 <= N) { 
		if(dp[n]+1 < dp[n+600]) {
			dp[n+600] = dp[n]+1;
			solve(n+600,flag);
		}
	}
	if(n+30 <= N) {
		if(dp[n]+1 < dp[n+30]) {
			dp[n+30] = dp[n]+1;
			solve(n+30,true);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	N = 60*stoi(input.substr(0,2)) + stoi(input.substr(3,5));
	fill(dp,dp+3601,INT_MAX);
	ans = INT_MAX;
	if(N) {
		if(N == 30) {
			ans = 1;
		}
		else {
			dp[0] = 0;
			solve(0,false);
			ans = dp[N];
		}
	}
	else {
		ans = 0;
	}
	cout<<ans<<"\n";
	return 0;
}