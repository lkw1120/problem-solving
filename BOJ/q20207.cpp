#include<bits/stdc++.h>
#define MAX 367
using namespace std;
int dp[MAX] = {0};
int N,S,E,W,H,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>S>>E;
		for(int j=S;j<=E;j++) {
			dp[j]++;
		}
	}
	ans = W = H = 0;
	for(int i=1;i<MAX;i++) {
		if(dp[i-1] == 0 && dp[i] != 0) {
			S = i;
		}
		H = max(dp[i],H);
		if(dp[i-1] != 0 && dp[i] == 0) {
			E = i;
			ans += H*(E-S);
			H = 0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}