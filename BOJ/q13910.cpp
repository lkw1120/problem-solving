#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1e5+1;
int dp[MAX] = {0};
set<int> tic;
vector<int> wok;
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	wok.resize(M);
	for(int i=0;i<M;i++) {
		cin>>wok[i];
	}
	for(int i=0;i<M;i++) {
		for(int j=0;j<M;j++) {
			if(i == j) {
				tic.insert(wok[i]);
			}
			else {
				tic.insert(wok[i]+wok[j]);
			}
		}
	}
	fill(dp,dp+MAX,INF);
	dp[0] = 0;
	for(auto item: tic) {
		for(int i=N;i>=0;i--) {
			if(i == 0 || dp[i]) {
				for(int j=1;i+item*j<=N;j++) {
					int tmp = i+item*j;
					dp[tmp] = min(dp[tmp],dp[i]+j);
				}
			}
		}
	}
	ans = (dp[N] != INF)? dp[N]: -1;
	cout<<ans<<"\n";
	return 0;
}