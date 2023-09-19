#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
const int MAX = 501;
ll dp[MAX][2] = {0};
ll T,C,V,L,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int t=1;t<=T;t++) {
		fill(&dp[0][0],&dp[MAX-1][2],0);
		cin>>C>>V>>L;
		dp[1][0] = V;
		dp[1][1] = C;
		for(int i=2;i<=L;i++) {
			dp[i][0] = ((dp[i-1][0]+dp[i-1][1])*V)%MOD;
			dp[i][1] = (dp[i-1][0]*C)%MOD;
		}
		ans = dp[L][0];
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}