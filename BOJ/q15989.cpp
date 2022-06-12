#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int dp[MAX] = {0};
int T,N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	for(int i=1;i<=5;i++) dp[i] = i;
	for(int i=6;i<MAX;i++) {
		dp[i] = 1 + dp[i-2] + dp[i-3] - dp[i-5];	
	}
	for(int t=0;t<T;t++) {
		cin>>N;
		cout<<dp[N]<<"\n";
	}
	return 0;
}