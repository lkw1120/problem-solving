#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[100001] = {0};
int T,N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true) {
		fill(dp,dp+100001,0);
		v.clear();
		cin>>N;
		if(cin.eof()) break;
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
		ans = len;
		cout<<ans<<"\n";
	}
	return 0;
}