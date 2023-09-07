#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5+1;
vector<pair<int,int>> v;
ll dp[MAX] = {0};
ll D,P,L,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>D>>P;
	for(int i=0;i<P;i++) {
		cin>>L>>C;
		v.push_back({L,C});
	}
	for(auto item: v) {
		L = item.first;
		C = item.second;
		dp[L] = max(dp[L],C);
		for(int i=D;i>0;i--) {
			if(dp[i] && i+L <= D) {
				dp[i+L] = max(min(dp[i],C),dp[i+L]);
			}
		}
	}
	ans = dp[D];
	cout<<ans<<"\n";
	return 0;
}