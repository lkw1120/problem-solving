#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1000001;
int dp[MAX] = {0};
int T,N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int t=1;t<=T;t++) {
		fill(dp,dp+MAX,INF);
		cin>>N;
		if(1 < N) {
			dp[0] = 0;
			for(int i=1;i<=N;i++) {
				string str = to_string(i);
				reverse(str.begin(),str.end());
				int n = stoi(str);
				dp[i] = min(dp[i],dp[i-1]+1);
				dp[n] = min(dp[n],dp[i]+1);
			}
			ans = dp[N];
		}
		else {
			ans = 1;
		}
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}