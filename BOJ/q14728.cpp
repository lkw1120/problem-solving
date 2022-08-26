#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int dp[MAX] = {0};
vector<pair<int,int>> v;
int N,T,K,S,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>T;
	for(int i=1;i<=N;i++) {
		cin>>K>>S;
		v.push_back({K,S});
	}
	for(auto item: v) {
		K = item.first;
		S = item.second;
		for(int i=T;i>=K;i--) {
			dp[i] = max(dp[i],dp[i-K]+S);	
		}
	}
	ans = dp[T];
	cout<<ans<<"\n";
	return 0;
}