#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dp[51][51] = {0};
int T,N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
	    v.clear();
		cin>>N>>M;
		v.resize(N);
		for(int i=0;i<N;i++) {
			cin>>v[i];	
		}
	    fill(&dp[0][0],&dp[0][0]+51*51,0);
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
                if(0 < i) dp[i][j] = max(dp[i][j],dp[i-1][j]);
                if(0 < j) dp[i][j] = max(dp[i][j],dp[i][j-1]);
				if(v[i][j] == 'C') dp[i][j]++;
			}
		}
		ans = dp[N-1][M-1];
		cout<<ans<<"\n";
	}
	return 0;
}