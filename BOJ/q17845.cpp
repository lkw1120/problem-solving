#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int dp[1001][10001];
int N,K,I,T,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<K;i++) {
		cin>>I>>T;
		v.push_back({I,T});
	}
	ans = 0;
	for(int i=1;i<=K;i++) {
		for(int j=0;j<=N;j++) {
            if(v[i-1].second <= j) {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i-1].second]+v[i-1].first);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
		}
	}
	ans = dp[K][N];
	cout<<ans<<"\n";
	return 0;	
}