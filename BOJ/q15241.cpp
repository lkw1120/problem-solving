#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
vector<string> v;
ll dp[501][501] = {0};
ll N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	for(int i=0;i<N;i++) {
		if(v[i][0] == 'X') break;
		dp[i][0] = 1;
	}
	for(int j=0;j<M;j++) {
		if(v[0][j] == 'X') break;
		dp[0][j] = 1;
	}
	for(int i=1;i<N;i++) {
		for(int j=1;j<M;j++) {
			if(v[i][j] == '.') {
				dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
			}
		}
	}
	ans = dp[N-1][M-1];
	cout<<ans<<"\n";
	return 0;
}