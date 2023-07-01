#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true) {
		cin>>N;
		if(!N) break;
		vector<int> v(N),dp(N);
		for(int i=0;i<N;i++) {
			cin>>v[i];
		}
		dp[0] = v[0];
		for(int i=1;i<N;i++) {
			dp[i] = max(dp[i-1]+v[i],v[i]);
		}
		ans = *max_element(dp.begin(),dp.end());
		cout<<ans<<"\n";
	}
	return 0;
}