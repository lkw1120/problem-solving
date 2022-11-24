#include<bits/stdc++.h>
#define MAX 1516
#define DIV 1000000007
typedef long long ll;
using namespace std;
ll dp[MAX] = {0};
int N,K;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	dp[0] = 0;
	dp[2] = dp[3] = 1;
	for(int i=4;i<=N;i++) {
		dp[i] = (dp[i-1]+dp[i-2])%DIV;
		dp[i] = (dp[i]+dp[i-2])%DIV;	
	}
	cout<<dp[N]<<"\n";
	return 0;
}