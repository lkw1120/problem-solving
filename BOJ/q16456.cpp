#include<bits/stdc++.h>
#define MAX 50001
#define DIV 1000000009
using namespace std;
int dp[MAX] = {0};
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	dp[1] = dp[2] = 1;
	dp[3] = 2;
	for(int i=4;i<=N;i++) {
		dp[i] = (dp[i-1]+dp[i-3])%DIV;
	}
	cout<<dp[N]<<"\n";
	return 0;	
}