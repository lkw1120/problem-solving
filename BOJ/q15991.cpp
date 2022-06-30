#include<bits/stdc++.h>
#define DIV 1000000009
#define MAX 50001
typedef long long ll;
using namespace std;
ll dp[MAX] = {0};
ll T,N,ans;
void init() {
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<MAX;i++) {
		dp[i] = (dp[i-3]+dp[i-2]+dp[i-1])%DIV;	
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	cin>>T;
	for(int t=0;t<T;t++) {
		cin>>N;
		if(N%2 == 1) {
			ans = (dp[(N-1)/2]+dp[(N-3)/2])%DIV;	
		}
		else {
			ans = (dp[N/2]+dp[(N-2)/2])%DIV;
		}
		cout<<ans<<"\n";
	}
	return 0;	
}