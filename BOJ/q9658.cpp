#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
bool dp[MAX];
int N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(dp,dp+MAX,true);
	cin>>N;
	dp[1] = dp[3] = false;
	for(int i=5;i<=N;i++) {
		if(dp[i-1] && dp[i-3] && dp[i-4]) {
			dp[i] = false;
		}
	}
	if(dp[N])
		cout<<"SK"<<"\n";
	else
		cout<<"CY"<<"\n";
	return 0;	
}