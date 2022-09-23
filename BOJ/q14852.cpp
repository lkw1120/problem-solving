#include<bits/stdc++.h>
#define MAX 1000001
#define DIV 1000000007
typedef long long ll;
using namespace std;
ll dp[MAX] = {0};
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 7;
	for(int i=3;i<=N;i++) {
		dp[i] = (dp[i-1]*3 + dp[i-2] - dp[i-3])%DIV;
	}
	if(dp[N] < 0) {
		dp[N]+=DIV;
	}
	cout<<dp[N]<<"\n";
	return 0;
}