#include<bits/stdc++.h>
using namespace std;
int dp[77];
int N,ans;
void init() {
	dp[3] = 1;
	dp[4] = dp[5] = 2;
	for(int i=6;i<77;i++) {
		dp[i] = dp[i-2]+dp[i-3];	
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t = 1;
	while(true) {
		cin>>N;
		if(!N) break;
		ans = dp[N]+dp[N-1];
		cout<<"Case #"<<t++<<": "<<ans<<"\n";
	}
	return 0;
}