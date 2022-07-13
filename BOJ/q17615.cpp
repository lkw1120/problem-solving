#include<bits/stdc++.h>
#define MAX 500001
using namespace std;
int dp[MAX][2] = {0};
string input;
int B,R,N,ans;
void solve() {
	B = R = 0;
	if(input[0] == 'R') {
		dp[0][0] = 1;
	}
	else {
		dp[0][1] = 1;
	}
	for(int i=1;i<N;i++) {
		if(input[i] == 'R') {
			if(input[i-1] == 'B') {
				B += dp[i-1][1];
			}
			dp[i][0] = dp[i-1][0]+1;
		}
		else {
			if(input[i-1] == 'R') {
				R += dp[i-1][0];
			}
			dp[i][1] = dp[i-1][1]+1;
		}
	}
	ans = min(R,B);
	memset(dp,0,sizeof(dp));
	R = B = 0;
	if(input[N-1] == 'R') {
		dp[N-1][0] = 1;
	}
	else {
		dp[N-1][1] = 1;
	}
	for(int i=N-2;i>=0;i--) {
		if(input[i] == 'R') {
			if(input[i+1] == 'B') {
				B += dp[i+1][1];
			}
			dp[i][0] = dp[i+1][0]+1;
		}
		else {
			if(input[i+1] == 'R') {
				R += dp[i+1][0];
			}
			dp[i][1] = dp[i+1][1]+1;
		}
	}
	ans = min(min(R,B),ans);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	cin>>input;
	ans = 0;
	solve();
	cout<<ans<<"\n";
	return 0;	
}