#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;
const int MAX = 1e4+1;
vector<pair<int,int>> v;
ll dp[MAX] = {0};
ll H,N,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>H>>N;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		v.push_back({A,B});
	}
	fill(dp,dp+MAX,INF);
	dp[0] = 0;
	for(int i=0;i<=H;i++) {
		for(int j=0;j<N;j++) {
			A = v[j].first;
			B = v[j].second;
			if(H <= i+A) {
				dp[H] = min(dp[H],dp[i]+B);	
			}
			else {
				dp[i+A] = min(dp[i+A],dp[i]+B);
			}
		}
	}
	ans = dp[H];
	cout<<ans<<"\n";
	return 0;
}