#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[32][32];
ll H,N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>H>>N;
	if(H == N) {
		ans = 1;	
	}
	else {
		if(N < H) {
			swap(N,H);
		}
		H++,N++;
		dp[H][H] = 1;
		for(int i=H;i<=N;i++) {
			for(int j=H;j<=N;j++) {
				if(j <= i) {
					dp[i][j]+=dp[i-1][j]+dp[i][j-1];
				}
			}
		}
		ans = dp[N][N];
	}
	cout<<ans<<"\n";
	return 0;
}