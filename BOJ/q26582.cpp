#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
vector<int> dp;
int T,N,M,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N>>M;
		dp.resize(M+1);
		for(int i=0;i<N;i++) {
			cin>>A>>B;
			v.push_back({A,B});
		}
		ans = 0;
		for(auto item: v) {
			for(int i=M;i>=0;i--) {
				if(dp[i] || i == 0) {
					if(i+item.second <= M) {
						dp[i+item.second] = 
							max(dp[i]+item.first,dp[i+item.second]);
					}
				}
			}
		}
		for(int i=1;i<=M;i++) {
			ans = max(ans,dp[i]);	
		}
		cout<<ans<<"\n";
		v.clear();
		dp.clear();
	}
	return 0;
}