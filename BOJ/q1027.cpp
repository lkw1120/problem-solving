#include<bits/stdc++.h>
#define INF 1000000001
#define MAX 51
using namespace std;
int dp[MAX] = {0};
int tower[MAX] = {0};
double G,tmp;
int N,H,W,ans;
void solve() {
	for(int i=1;i<=N;i++) {
		tmp = -INF;
		for(int j=i+1;j<=N;j++) {
			H = tower[i]-tower[j];
			W = i-j;
			G = (1.0*H)/W;
			if(G > tmp) {
				tmp = G;
				dp[i]++;
				dp[j]++;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>tower[i];
	}
	solve();
	ans = 0;
	for(int i=1;i<=N;i++) {
		ans = max(ans,dp[i]);
	}
	cout<<ans<<"\n";
	return 0;	
}