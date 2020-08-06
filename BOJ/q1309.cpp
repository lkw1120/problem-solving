#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
const int MOD = 9901;
int dp[MAX] = {0};
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	dp[0] = 1;
	dp[1] = 3;
	for(int i=2;i<=N;i++) {
		dp[i] = (dp[i-1]*2+dp[i-2])%MOD;
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;
}