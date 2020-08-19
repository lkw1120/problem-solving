#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
vector<pair<int,int>> v;
int dp[MAX] = {0};
int N,M,C,P,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double m,p;
	while(true) {
		fill(dp,dp+MAX,0);
		v.clear();
		cin>>N>>m;
		if(N == 0 && m == 0) break;
		M=(int)(m*100+0.5);
		for(int i=0;i<N;i++) {
			cin>>C>>p;
			P = (int)(p*100+0.5);
			v.push_back({P,C});
		}
		for(int i=1;i<=M;i++) {
			for(int j=0;j<N;j++) {
				if(i >= v[j].first) {
					dp[i] = max(dp[i],dp[i-v[j].first]+v[j].second);
				}
			}
		}
		ans = *max_element(dp,dp+M+1);
		cout<<ans<<"\n";
	}
	return 0;
}