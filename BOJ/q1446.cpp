#include<bits/stdc++.h>
#define MAX 13
#define DIST 10001
using namespace std;
vector<pair<pair<int,int>,int>> v;
int dp[DIST] = {0};
int N,D,x,y,z,ans;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin>>N>>D;
	for(int i=0;i<N;i++) {
		cin>>x>>y>>z;
		v.push_back({{x,y},z});
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=D;i++) {
		dp[i] = dp[i-1]+1;
		for(auto dist : v) {
			x = dist.first.first;
			y = dist.first.second;
			z = dist.second;
			if(y > D || y-x < z) continue;
			if(y == i) dp[i] = min(dp[x]+z,dp[i]);
		}
	}
	ans = dp[D];
	cout<<ans<<"\n";
	return 0;
}