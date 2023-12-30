#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
const int MAX = 191230;
ll dp[MAX];
ll T,N;
void init() {
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<MAX;i++) {
		dp[i] = (dp[i-1]+dp[i-2])%MOD;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>T;
	while(T--) {
		cin>>N;
		cout<<dp[N]<<"\n";
	}
	return 0;
}