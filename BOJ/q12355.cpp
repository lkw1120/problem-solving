#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[1001] = {0};
int T,N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int t=1;t<=T;t++) {
		fill(dp,dp+1001,0);
		v.clear();
		cin>>N;
		v.resize(N+1);
		for(int i=1;i<=N;i++) {
			cin>>v[i];	
		}
		dp[1] = v[1];
		int len = 1;
		for(int i=2;i<=N;i++) {
			if(dp[len] < v[i]) {
				dp[++len] = v[i];
			}
			else {
				int idx = lower_bound(dp+1,dp+len+1,v[i])-dp;
				dp[idx] = v[i];
			}
		}
		ans = N-len;
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}